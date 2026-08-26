/**
 * This is the handler which deals with parcels that are being sent
 * from player to player, or, as it may be, from post office to
 * post office.
 *
 * These are the things I want to do here:<br>
 * - Each PO should have coordinates.
 * <br>
 * - One should be able to pick which PO to send the parcel to, and
 *   the cost of posting a parcel should depend on the weight of the
 *   parcel and the distance between this PO and the destination PO.
 * <br>
 * - It should take time for the parcel to arrive at the destination
 *   based on the distance between the starting PO and destination PO.
 * <br>
 * - If no-one has collected the parcel within 30 days from the arrival,
 *   send it back to the sender, if there is one.  Then if the sender
 *   doesn't come to collect it within a month, discard the parcel.
 * <br>
 * - We are going to wrap the things in a special envelope/packet,
 *   and use that as a container, which will disappear when unwrapped.
 * <br>
 * @see /std/shops/parcel_office.c
 * @author Sandoz, 2002.
 */

#define AUTO_LOAD_H       "/global/player/auto_load"

/** This is the minimum shipping cost. */
#define MIN_SHIPPING_COST 2000
/** This value is used to round all the cost calculations. */
#define ROUND_DENOMINATOR 100

#define DAY               (60*60*24)
#define MONTH             (30*DAY)

#define FAIL(x)           do_fail_mess( npc, x )
#define MS(x,y)           (string)MONEY_H->money_value_string(x,y)

#define PARCEL_SAVE_DIR   SAVE_DIR "/parcels/"
#define SHIP_DIR          PARCEL_SAVE_DIR "shipping/"

/**
 * This class stores the data for a single parcel.
 * @member from the name of the player the parcel is from
 * @member from_office the parcel office the parcel was sent from
 * @member autoload the autoload info of the parcel
 * @member expiry_time the time the parcel should be either
 * discarded or returned to the sender
 * @member returned whether or not the parcel is being returned
 */
class parcel_data {
    string from;
    string from_office;
    mixed autoload;
    int expiry_time;
    int returned;
}

/**
 * This class stores the data for a single parcel that is being shipped.
 * @member to the person this parcel is for
 * @member to_office the post office this parcel was sent to
 * @member due the time the parcel should reach its destination
 */
class shipping_data {
    string to;
    string to_office;
    int due;
}

/**
 * This class stores the data for a single post office.
 * You can make a restricted office by setting the restricted flag,
 * this is good for testing purposes, so that players can't send
 * parcels to offices you're still in the middle of setting up.
 * @member coords the coordinates of the office
 * @member data the mapping of parcel expiry times for players
 * @member restricted a flag that can be set to make the office restricted
 */
class office_data {
    int *coords;
    mapping data;
    int restricted;
}

nosave string cur_player, cur_office;
nosave class parcel_data *player_data;

private mapping offices, shipping;
private int check_time;

private void do_hourly_check();

/** @ignore */
private void create() {
    function f;

    if( !unguarded( (: dir_exists, PARCEL_SAVE_DIR :) ) )
        unguarded( (: mkdir, PARCEL_SAVE_DIR :) );

    if( !unguarded( (: dir_exists, SHIP_DIR :) ) )
        unguarded( (: mkdir, SHIP_DIR :) );

    if( unguarded( (: file_exists, PARCEL_SAVE_DIR+"main.o" :) ) )
        unguarded( (: restore_object, PARCEL_SAVE_DIR+"main.o" :) );

    if( !mapp(offices) )
        offices = ([ ]);

    if( !mapp(shipping) )
        shipping = ([ ]);

    f = function( function func ) {
            call_out( func, 3600, func );
            do_hourly_check();
        };

    call_out( f, 60, f );

} /* create() */

/** @ignore */
private void save_me() {
    unguarded( (: save_object, PARCEL_SAVE_DIR+"main.o" :) );
} /* save_me() */

/**
 * This method returns the mapping of all post office specific data.
 * @return a mapping which contains the office specific data
 */
mapping query_offices() { return offices;}

/**
 * This method returns the array of all restricted post offices.
 * @return all restricted post offices
 */
string *query_restricted_offices() {
    return keys( filter( offices, (: $2->restricted :) ) );
} /* query_restricted_offices() */

/**
 * This method returns the array of all unrestricted post offices.
 * @return all unrestricted post offices
 */
string *query_unrestricted_offices() {
    return keys( filter( offices, (: !$2->restricted :) ) );
} /* query_restricted_offices() */

/**
 * This method returns the mapping of all shipment specific data.
 * @return a mapping which contains the shipment specific data
 */
mapping query_shipping() { return shipping; }

/** @ignore yes */
private int compare_coords( int *i, int *j ) {
    return i[0] == j[0] && i[1] == j[1] && i[2] == j[2];
} /* compare_coords() */

/**
 * This method queries whether or not the input string is a valid
 * post office.
 * @param name the name of the post office to test
 */
int query_post_office( string name ) { return !undefinedp( offices[name] ); }

/**
 * This method adds a post office into the handler.
 * It will make sense to have a 'main' post office with
 * 0, 0, 0 coords, relative to which all the other offices'
 * coordinates should be set.
 * @param name the name of the post office
 * @param coords the coordinates of the post office
 * @param restricted whether or not this is a restricted office
 * @return 1 upon success, 0 upon failure
 * @see remove_office()
 * @see change_coords()
 */
int add_office( string name, int *coords, int restricted ) {
    if( !adminp( previous_object(-1) ) ) {
        printf("Sorry, only admin can add post offices.\n");
        return 0;
    }

    if( !stringp(name) || !sizeof(name) ) {
        printf("Invalid office name.\n");
        return 0;
    }

    if( query_post_office(name) ) {
        printf("A post office by that name already exists.\n");
        return 0;
    }

    if( !pointerp(coords) || sizeof(coords) != 3 ||
        sizeof( filter( coords, (: !intp($1) :) ) ) ) {
        printf("Invalid coordinates; must be an integer array of three "
            "elements.\n");
        return 0;
    }

    if( sizeof( filter( values(offices),
        (: compare_coords( $1->coords, $2 ) :), coords ) ) ) {
        printf("An office with those coordinates already exists.\n");
        return 0;
    }

    offices[name] = new( class office_data,
                         coords     : coords,
                         data       : ([ ]),
                         restricted : restricted );
    save_me();

    return 1;

} /* add_office() */

/**
 * This method changes a post office's coordinates.
 * @param name the name of the post office
 * @param coords the new coordinates of the post office
 * @return 1 upon success, 0 upon failure
 * @see remove_office()
 */
int change_coords( string name, int *coords ) {
    if( !adminp( previous_object(-1) ) ) {
        printf("Sorry, only admin can change post office coordinates.\n");
        return 0;
    }

    if( !stringp(name) || !sizeof(name) ) {
        printf("Invalid office name.\n");
        return 0;
    }

    if( !query_post_office(name) ) {
        printf("There is no post office by that name.\n");
        return 0;
    }

    if( !pointerp(coords) || sizeof(coords) != 3 ||
        sizeof( filter( coords, (: !intp($1) :) ) ) ) {
        printf("Invalid coordinates; must be an integer array of three "
            "elements.\n");
        return 0;
    }

    if( compare_coords( offices[name]->coords, coords ) ) {
        printf("That office already has those coordinates.\n");
        return 0;
    }

    if( sizeof( filter( values(offices),
        (: compare_coords( $1->coords, $2 ) :), coords ) ) ) {
        printf("An office with those coordinates already exists.\n");
        return 0;
    }

    offices[name]->coords = coords;
    save_me();

    return 1;

} /* change_coords() */

/**
 * This method sets the restricted flag of the post office.
 * @param name the name of the office to set the restricted flag for
 * @param restrict whether or not we should be a restricted office
 * @see add_office()
 * @see remove_office()
 * @see change_coords()
 */
int restrict_office( string name, int restrict ) {
    if( !adminp( previous_object(-1) ) ) {
        printf("Sorry, only admin can change the restricted flag of post "
            "offices.\n");
        return 0;
    }

    if( !stringp(name) || !sizeof(name) ) {
        printf("Invalid office name.\n");
        return 0;
    }

    if( !query_post_office(name) ) {
        printf("There is no post office by that name.\n");
        return 0;
    }

    offices[name]->restricted = restrict;

    save_me();
    return 1;

} /* restrict_office() */

/**
 * This method changes a post office's coordinates.
 * @param name the name of the post office
 * @return 1 upon success, 0 upon failure
 * @see add_office()
 */
int remove_office( string name ) {
    if( !adminp( previous_object(-1) ) ) {
        printf("Sorry, only admin can remove post offices.\n");
        return 0;
    }

    if( !query_post_office( name) ) {
        printf("There is no post office by that name.\n");
        return 0;
    }

    map_delete( offices, name );
    save_me();

    return 1;

} /* remove_office() */

/** @ignore yes */
string normalize_name( string name ) {
    int i;

    name = lower_case(name);

    for( i = 0; i < strlen(name); i++ ) {
        if( name[i] == ''' ) {
            name = name[0..i-1] + name[i+1..];
            i--;
            continue;
        }

        if( name[i] < 'a' || name[i] > 'z')
            name[i] = '_';
    }

    return implode( explode( name, "_") - ({ 0, "" }), "_");

} /* normalize_name() */

/** @ignore yes */
string query_real_office_name( string name ) {
    string bit, tmp;

    if( query_post_office( name ) )
        return name;

    tmp = lower_case(name);

    foreach( bit in keys( offices ) )
        if( tmp == lower_case(bit) )
            return bit;

    return name;

} /* query_real_office_name() */

private string query_office_save_dir( string office ) {
    office = normalize_name( office );
    return PARCEL_SAVE_DIR+office+"/";
} /* query_office_save_fir() */

/** @ignore yes */
private void reset_player_data() {
    cur_office = 0;
    cur_player = 0;
    player_data = 0;
} /* reset_player_data() */

/** @ignore yes */
private void save_player_data() {
    string dir;

    if( !cur_player || !cur_office || !player_data ) {
        error("Attempted to save with no cur_player, cur_office or "
            "player_data.\n");
        return;
    }

    dir = query_office_save_dir(cur_office);

    if( !unguarded( (: dir_exists, dir :) ) )
        unguarded( (: mkdir, dir :) );

    unguarded( (: write_file, dir+cur_player+".o",
        save_variable(player_data), 1 :) );

} /* save_player_data() */

/** @ignore yes */
private void load_player_data( string office, string player ) {
    string data;

    if( cur_office == office && cur_player == player )
        return;

    data = query_office_save_dir(office)+player+".o";

    if( unguarded( (: file_exists, data :) ) ) {
        data = unguarded( (: read_file, data :) );
        if( stringp(data) )
            player_data = restore_variable(data);
    }

    if( !pointerp(player_data) )
        player_data = ({ });

    cur_player = player;
    cur_office = office;

} /* load_player_data() */

/**
 * This method calculates the distance between two post offices
 * based on their coordinates.
 * @param from the starting post office
 * @param to the destination post office
 * @return the distance between the post offices
 */
int query_distance( string from, string to ) {
    int *i, *j;

    i = offices[from]->coords;
    j = offices[to]->coords;

    return 10 * sqrt( ( ( i[0] - j[0] ) * ( i[0] - j[0] ) ) +
                      ( ( i[1] - j[1] ) * ( i[1] - j[1] ) ) +
                      ( ( i[2] - j[2] ) * ( i[2] - j[2] ) ) );

} /* query_distance() */

/**
 * This method calculates the shipping cost of a parcel from one
 * post office to another based on their coordinates and the
 * weight of the parcel.  This will be rounded up using the
 * ROUND_DENOMINATOR define.
 * @param ob the object we are trying to ship
 * @param from the starting post office
 * @param to the destination post office
 * @return the shipping cost
 */
int query_shipping_cost( object ob, string from, string to ) {
    int i, j, k;

    if( k = query_distance( from, to ) ) {
        if( k < MIN_SHIPPING_COST )
            k = MIN_SHIPPING_COST;
        if( j = ( k % ROUND_DENOMINATOR ) )
            k += ROUND_DENOMINATOR - j;
    }

    i = ( ob->query_complete_weight() + 1 ) * 20;

    if( i < MIN_SHIPPING_COST )
        i = MIN_SHIPPING_COST;

    if( j = ( i % ROUND_DENOMINATOR ) )
        i += ROUND_DENOMINATOR - j;

    return i + k;

} /* query_shipping_cost() */

/**
 * This method calculates the shipping time from one
 * post office to another based on their coordinates.
 * @param from the starting post office
 * @param to the destination post office
 * @return the shipping time in seconds, or 0 if there
 * are no such post offices
 */
int query_shipping_time( string from, string to ) {
    return 60 * query_distance( from, to );
} /* query_shipping_time() */

/** @ignore yes */
private int do_fail_mess( object servant, string mess ) {
    if( servant ) {
        servant->do_command("'"+mess );
        return notify_fail("");
    }

    add_failed_mess( mess+"\n");
    return 0;

} /* do_fail_mess() */

/**
 * This method deals with the actual shipping command.
 * If the command is successful, event_parcel_sent()
 * will be called on the post office room, that should
 * give a message to the player about success.
 * The arguments passed to the function are the name of the
 * person who we sent the parcel to, the name of the post
 * office we sent the parcel to, and the time they should
 * receive the parcel.
 * Note : the objects we send MUST have query_is_postage_parcel()
 * return 1 on them, so that we can know they are properly
 * packed packages.
 * @param obs the things we are trying to send
 * @param to the person the parcel is to
 * @param where the name of the post office to send it to
 * @param from the post office we are sending the parcel from
 * @param loc the location for currency calculations
 * @param npc the NPC serving the player, if there is any
 * @return 1 upon success, 0 upon failure
 */
int do_send( object *obs, string to, string where, string from,
             string loc, object npc ) {
    class parcel_data data;
    int ship, id, cost;
    string mess;
    object ob;

    if( !PO->query_parcel_office() ) {
        add_failed_mess("You can only send parcels from post offices.\n");
        return 0;
    }

    if( sizeof(obs) > 1 )
        return FAIL("You can only send one parcel at a time.");

    if( !query_post_office( where ) ||
        ( !creatorp(TP) && offices[where]->restricted ) )
        return FAIL( where+" doesn't appear to be a valid post office.  "
            "Please 'list offices' to get a list of post offices you can "
            "send parcels to.");

    ob = obs[0];
    to = lower_case(to);

    if( to == TP->query_name() )
        return FAIL("You can't send "+ob->the_short()+" to yourself, silly!");

    if( !PLAYER_H->test_user( to ) )
        return FAIL("There is no player by that name!");

    if( MULTIPLAYER_H->member_denied_parcel( TP->query_name() ) )
        return FAIL("You are not allowed to send parcels to anyone.");

    if( MULTIPLAYER_H->member_denied_parcel( to ) )
        return FAIL( CAP(to)+" is not allowed to receive parcels from "
            "anyone.");

    if( !ob->query_is_postage_parcel() )
        return FAIL( ob->the_short()+" "+( query_group(ob) ?
            "do not appear to be proper parcels." :
            "does not appear to be a proper parcel.")+"  You can only send "
            "things in packets, sealed envelopes or similar containers.");

    cost = query_shipping_cost( ob, from, where );

    if( TP->query_value_in(loc) < cost )
        return FAIL("You cannot afford to send "+ob->the_short()+" to "+
            where+" for "+CAP(to)+".  It would cost "+MS( cost, loc )+".");

    ship = query_shipping_time( from, where ) + time();

    mess = sprintf("%'* '=*s\n*%' '=*s\n", 78, "", 76, "*");
    mess += sprintf("%*-s*\n", 76, sprintf("*%+=*s%-=*s", 10, "TO : ", 76,
        CAP(to)+" "+where ) );
    mess += sprintf("%*-s*\n", 76, sprintf("*%+=*s%-=*s", 10, "FROM : ", 76,
        TP->query_cap_name()+" "+from ) );
    mess += sprintf("*%' '=*s\n%'* '=*s\n", 76, "*", 78, "");

    obs->add_read_mess(mess);

    data = new( class parcel_data,
                from        : TP->query_name(),
                from_office : from,
                autoload    : AUTO_LOAD_H->create_auto_load( ({ ob }), 0 ),
                expiry_time : ship + MONTH,
                returned    : 0 );

    if( ob->move("/room/rubbish") ) {
        ob->remove_read_mess(mess);
        return FAIL("You cannot let go of "+ob->the_short()+" for some "
            "reason.");
    }

    while( !undefinedp( shipping[++id] ) );

    if( !unguarded( (: write_file, SHIP_DIR+id+".o",
        save_variable(data), 1 :) ) ) {
        ob->remove_read_mess(mess);
        ob->move(TP);
        return FAIL("Something went wrong with sending "+
            ob->the_short()+" to "+CAP(to)+", sorry.");
    }

    if( npc )
        npc->do_command("'That will be "+MS( cost, loc )+", please.");
    else
        tell_object( TP, "That will cost "+MS( cost, loc )+".\n");

    TP->pay_money( MONEY_H->create_money_array( cost, loc ), loc );

    mess = ( npc ? npc->the_short() : "the parcel clerk");

    tell_object( TP, "You hand the money to "+mess+".\n");
    tell_room( ENV(TP), TP->the_short()+" $V$0=hands,hand$V$ some money to "+
        mess+".\n", TP );

    shipping[id] = new( class shipping_data,
                        to        : to,
                        to_office : where,
                        due       : ship );

    save_me();

    PO->event_parcel_sent( to, where, ship );

    return 1;

} /* do_send() */

/**
 * This method prints the cost of sending a specific parcel to
 * somewhere for the player.
 * @param obs the objects to get the shipping costs for
 * @param from the office we are sending from
 * @param to the destination we are sending to
 * @param loc the location for currency calculations
 * @param npc the servant NPC, if there is one
 * @return 1 upon success, 0 upon failure
 */
int do_cost( object *obs, string from, string to, string loc, object npc ) {
    object ob;

    if( !PO->query_parcel_office() ) {
        add_failed_mess("You can only send parcels from post offices.\n");
        return 0;
    }

    if( sizeof(obs) > 1 )
        return FAIL("You can only check the shipping costs of one parcel "
            "at a time.");

    if( !query_post_office( to ) ||
        ( !creatorp(TP) && offices[to]->restricted ) )
        return FAIL( to+" doesn't appear to be a valid post office.  "
            "Please 'list offices' to get a list of post offices you can "
            "send parcels to.");

    ob = obs[0];

    if( !ob->query_is_postage_parcel() )
        return FAIL( ob->the_short()+" "+( query_group(ob) ?
            "do not appear to be proper parcels." :
            "does not appear to be a proper parcel.")+"  You can only send "
            "things in packets, sealed envelopes or similar containers.");

    to = "It would cost "+MS( query_shipping_cost( ob, from, to ), loc )+" "+
         "to send "+ob->the_short()+" to "+to+".";

    if( npc )
        npc->do_command("'"+to );
    else
        tell_object( TP, to+"\n");

    return 1;

} /* do_cost() */

/** @ignore yes */
private int sort_classes( int one, int two ) {
    if( one > two )
        return 1;

    if( one < two )
        return -1;

    return 0;

} /* sort_classes() */

/** @ignore yes */
private void log_and_save_current_player() {
    string file;
    class parcel_data parcel;

    map_delete( offices[cur_office]->data, cur_player );
    file = query_office_save_dir(cur_office)+cur_player+".o";

    if( !sizeof( player_data ) ) {
        log_file("PARCELS", "%s - removed - %s - no data left.\n",
            ctime(time()), file );

        unguarded( (: rm, file :) );

        reset_player_data();

    } else {
        log_file("PARCELS", "%s - saved - %s - %i parcels.\n",
            ctime(time()), file, sizeof(player_data) );

        foreach( parcel in player_data )
            if( !offices[cur_office]->data[cur_player] ||
                offices[cur_office]->data[cur_player] > parcel->expiry_time )
                offices[cur_office]->data[cur_player] = parcel->expiry_time;

        save_player_data();
    }

} /* log_and_save_current_player() */

/**
 * This method collects a parcel for a player, it will collect the
 * parcel with the earliest expiry date.
 * This is done one parcel at a time so that players wouldn't
 * fumble stuff.
 * If the command is successful, event_parcel_collected()
 * will be called on the post office room, that should
 * give a message to the player about success.
 * The arguments passed to the function are an array of
 * objects that should be moved to the player (or a shelf/their
 * env if they're too burdened) and the number of parcels that
 * are left for the player.
 * @param office the name of the parcel office we are at
 * @param npc the servant NPC, if we have one
 * @return 1 if there are parcels, and 0 if there are not
 */
int do_collect( string office, object npc ) {
    object *obs;
    string name;
    class parcel_data parcel;

    if( !PO->query_parcel_office() ) {
        add_failed_mess("You can only collect parcels at post offices.\n");
        return 0;
    }

    name = (string)TP->query_name();

    if( MULTIPLAYER_H->member_denied_parcel( name ) )
        return FAIL("You are not allowed to collect parcels.\n");

    if( undefinedp( offices[office]->data[name] ) )
        return FAIL("There are no parcels waiting for you here.");

    load_player_data( office, name );

    if( !sizeof(player_data) )
        return FAIL("Something has gone wrong with storing your parcel data, "
            "please contact a creator immediately.");

    player_data = sort_array( player_data,
        (: sort_classes( $1->expiry_time, $2->expiry_time ) :) );

    parcel = player_data[0];
    player_data = player_data[1..];

    obs = AUTO_LOAD_H->load_auto_load_to_array( parcel->autoload, TP );
    PO->event_parcel_collected( obs, sizeof(player_data) );

    if( npc && parcel->expiry_time < time() )
        npc->do_command("'You are lucky, "+TP->query_cap_name()+", for we "
            "were just about to throw away that parcel.");

    log_file("PARCELS", "%s - %s collected a parcel from %s.\n",
        ctime(time()), CAP(name), office );

    log_and_save_current_player();

    save_me();

    return 1;

} /* do_collect() */

/**
 * This method prints all the post offices they can send parcels
 * to for a player.
 * @param npc the servant NPC, if there is one
 * @return always returns 1
 */
int do_list( object npc ) {
    string *str;

    if( !creatorp(TP) )
        str = query_unrestricted_offices();
    else
        str = keys(offices);

    str = sort_array( str, 1 );

    if( npc ) {
        npc->do_command("'The post offices to which you can send parcels "
            "from here are the following - "+query_multiple_short( str )+
            ".");
    } else {
        printf("The post offices to which you can send parcels from here "
            "are:\n%-*#s\n", (int)TP->query_cols(), implode( str, "\n") );
    }

    return 1;

} /* do_list() */

/** @ignore yes */
private void do_office_check( string office ) {
    int expiry_time;
    string player;
    class parcel_data data;

    foreach( player, expiry_time in offices[office]->data ) {
        if( expiry_time < time() ) {
            load_player_data( office, player );
            foreach( data in player_data ) {
                if( data->expiry_time < time() ) {
                    if( data->returned ) {
                        MAIL_H->do_mail_message( player, "the parcel clerk",
                            "Parcel Discard Notification", "", "Dear "+
                            CAP(player)+",\n\nWe are sorry to inform you "
                            "that the parcel at "+office+" returned to you "
                            "from "+data->from_office+" has been discarded."
                            "\n\nThe Parcel Clerk,\n"+office, 0, 0 );

                        log_file("PARCELS", "%s - discarded returned parcel "
                            "in %s - %s.\n", ctime(time()), office,
                            CAP(player) );

                        player_data -= ({ data });
                        continue;
                    }

                    if( PLAYER_H->test_user(data->from) ) {
                        int ship, id;
                        class parcel_data parcel;

                        MAIL_H->do_mail_message( player, "the parcel clerk",
                            "Parcel Return Notification", "", "Dear "+
                            CAP(player)+",\n\nWe are sorry to inform you "
                            "that the parcel at "+office+" sent to you from "+
                            data->from_office+" by "+CAP(data->from)+" has "
                            "been returned to the sender.\n\n"
                            "The Parcel Clerk,\n"+office, 0, 0 );

                        ship = query_shipping_time( office,
                            data->from_office ) + time();

                        parcel = new( class parcel_data,
                                      from        : player,
                                      from_office : office,
                                      autoload    : data->autoload,
                                      expiry_time : ship + MONTH,
                                      returned    : 1 );

                        while( !undefinedp( shipping[++id] ) );

                        unguarded( (: write_file, SHIP_DIR+id+".o",
                            save_variable(parcel), 1 :) );

                        shipping[id] = new( class shipping_data,
                                            to        : data->from,
                                            to_office : data->from_office,
                                            due       : ship );

                        log_file("PARCELS", "%s - returned parcel from %s to "
                            "%s (%s).\n", ctime(time()), office,
                            data->from_office, CAP(data->from) );

                        player_data -= ({ data });
                        continue;
                    }

                    MAIL_H->do_mail_message( player, "the parcel clerk",
                        "Parcel Discard Notification", "", "Dear "+
                        CAP(player)+",\n\nWe are sorry to inform you "
                        "that the parcel at "+office+" sent to you from "+
                        data->from_office+" by "+CAP(data->from)+" has "
                        "been discarded.\n\n"
                        "The Parcel Clerk,\n"+office, 0, 0 );

                    log_file("PARCELS", "%s - discarded parcel from %s (%s) "
                        "to %s (%s) - no user to return to.\n", ctime(time()),
                        data->from_office, CAP(data->from), office,
                        CAP(player) );

                    player_data -= ({ data });
                    continue;
                }
            }

            log_and_save_current_player();

        }
    }

} /* do_office_check() */

/** @ignore yes */
private void do_hourly_check() {
    int id;
    class shipping_data data;
    class parcel_data parcel;

    foreach( id, data in shipping ) {
        if( !PLAYER_H->test_user( data->to ) ) {
            unguarded( (: rm, SHIP_DIR+id+".o" :) );
            map_delete( shipping, id );
            continue;
        }

        if( data->due < time() ) {
            string player, office;

            player = data->to;
            office = data->to_office;

            parcel = restore_variable( unguarded( (: read_file,
                SHIP_DIR+id+".o" :) ) );

            load_player_data( office, player );

            player_data += ({ parcel });

            if( !offices[office]->data[player] ||
                offices[office]->data[player] > parcel->expiry_time )
                offices[office]->data[player] = parcel->expiry_time;

            save_player_data();

            if( !parcel->returned ) {
                MAIL_H->do_mail_message( player, "the parcel clerk",
                    "Parcel Deposit Notification", "", "Dear "+
                    CAP(player)+",\n\nPlease come to the "+office+" parcel "
                    "counter to collect the parcel which has been sent to "
                    "you from "+parcel->from_office+" by "+
                    CAP(parcel->from)+".  If you have not collected the "
                    "parcel by "+ctime(parcel->expiry_time)+", it will be "+
                    ( PLAYER_H->test_user(parcel->from) ?
                    "returned to the sender" : "discarded")+".\n\n"
                    "The Parcel Clerk,\n"+office, 0, 0 );
                log_file("PARCELS", "%s - parcel from %s (%s) arrived at "
                    "%s (%s).\n", ctime(time()), parcel->from_office,
                    CAP(parcel->from), office, CAP(player) );
            } else {
                MAIL_H->do_mail_message( player, "the parcel clerk",
                    "Parcel Deposit Notification", "", "Dear "+
                    CAP(player)+",\n\nPlease come to the "+office+" parcel "
                    "counter to collect the parcel which has been returned "
                    "to you from "+parcel->from_office+".  If you have not "
                    "collected the parcel by "+ctime(parcel->expiry_time)+", "
                    "it will be discarded.\n\n"
                    "The Parcel Clerk,\n"+office, 0, 0 );
                log_file("PARCELS", "%s - parcel to %s (%s) arrived back to "
                    "%s (%s) - RETURNED.\n", ctime(time()),
                    parcel->from_office, CAP(parcel->from), office,
                    CAP(player) );
            }

            unguarded( (: rm, SHIP_DIR+id+".o" :) );
            map_delete( shipping, id );
        }
    }

    if( check_time < time() ) {
        check_time = time() + DAY;
        map( keys(offices), (: do_office_check($1) :) );
    }

    save_me();

} /* do_hourly_check() */

/**
 * This method should be called by the refresh handler each
 * time a player refreshes, or is deleted.  This will delete
 * all parcels meant for the player.
 * @param player the player being refreshed or deleted
 */
void player_refreshed( string player ) {
    class shipping_data data;
    string office;
    int id, flag;

    if( PO != find_object(REFRESH_H) )
        return;

    foreach( id, data in shipping ) {
        if( data->to == player ) {
            flag = 1;
            unguarded( (: rm, SHIP_DIR+id+".o" :) );
            map_delete( shipping, id );
        }
    }

    foreach( office in keys(offices) ) {
        if( !undefinedp( offices[office]->data[player] ) ) {
            flag = 1;
            unguarded( (: rm, query_office_save_dir(office)+player+".o" :) );
            map_delete( offices[office]->data, player );
        }
    }

    if( cur_player == player )
        reset_player_data();

    save_me();

    if( flag )
        log_file("PARCELS", "%s - %s refreshed.\n", ctime(time()),
            CAP(player) );

} /* player_refreshed() */

/** @ignore yes */
int query_check_time() { return check_time; }

/** @ignore yes */
void reset_check_time() {
    if( adminp( previous_object(-1) ) )
        check_time = 0;
} /* reset_check_time() */

/** @ignore yes */
void dest_me() { destruct(TO); }

/** @ignore yes */
mixed stats() {
    return ({
        ({"post offices", sizeof(offices) }),
        ({"restricted", sizeof( query_restricted_offices() ) }),
        ({"shipping", sizeof(shipping) }),
        ({"next check", ctime(check_time)+" ("+check_time+")" }),
    });
} /* stats() */
