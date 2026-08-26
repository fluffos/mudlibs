/**
 * This file contains all the bits needed to handle rooms, plus the code to
 * handle following when moving.
 * @author Pinkfish
 * @changed Deutha Who knows
 * Severely changed, move the follow code in here from the living object
 * @changed Sandoz - 09/09/02
 * Added recycling for chatters, doors and items.
 * @changed Zrutu - 13/10/04
 * Added support for functions in exit / enter mess
 * @see /std/room/basic_room.c
 * @see recycle_chatter()
 * @see recycle_door()
 * @see recycle_item()
 * @see get_chatter()
 * @see get_door()
 * @see get_item()
 */

#include <climate.h>
#include <player.h>
#include <room.h>

#define CHATSIZE 80
#define DOORSIZE 60

private mapping exit_types, door_types, opposite;
private mixed chatters, doors;
private nosave object *recycled_chatters, *recycled_doors, *recycled_items;
private nosave object *queued_doors, *queued_chatters;
private nosave int chatter_hits, door_hits, item_hits;
private nosave int chatter_misses, door_misses, item_misses;
private nosave int chatter_id, door_id;

private void housekeeping();
private void clean_chatters();
private void clean_doors();

void create() {
    seteuid( master()->creator_file( file_name( TO ) ) );
    // ({ mess, obv, size, func })
    exit_types = ([
        "standard" :({ 0, 1,   400, 0 }),
        "corridor" :({ 0, 1,   250, 0 }),
        "plain"    :({ 0, 1, 10000, 0 }), /* very large */
        "door"     :({ 0, 1,   300, 0 }),
        "stair"    :({ 0, 1,   300, 0 }), /* going up? */
        "hidden"   :({ 0, 0,   300, 0 }), /* hidden non door exit */
        "secret"   :({ 0, 0,   300, 0 }), /* secret door */
        "gate"     :({ 0, 1,   450, 0 }),
        "road"     :({ 0, 1,  1300, 0 }),
        "path"     :({ 0, 1,   800, 0 }),
        "window"   :({ "$N climb$s through a window.\n", 0, 75, 0 }),
        ]);

    door_types = ([
        "door"      : ({ 0, 0, "generic_key", 2, 0, 0 }),
        "secret"    : ({ 0, 0, "generic_key", 3, 1, 0 }),
        "gate"      : ({ 1, 0, "generic_key", 1, 0, 1 }),
        "window"    : ({ 1, 0, "generic_key", 1, 0, 1 }),
        ]);

    opposite = ([
        "north" : ({ 0, "$R$[the ]+south$R$" }),
        "south" : ({ 0, "$R$[the ]+north$R$" }),
        "east" : ({ 0, "$R$[the ]+west$R$" }),
        "west" : ({ 0, "$R$[the ]+east$R$" }),
        "northeast" : ({ 0, "$R$[the ]+southwest$R$" }),
        "southwest" : ({ 0, "$R$[the ]+northeast$R$" }),
        "southeast" : ({ 0, "$R$[the ]+northwest$R$" }),
        "northwest" : ({ 0, "$R$[the ]+southeast$R$" }),
        "up": ({ 0, "below"}), "down" : ({ 0, "above"}),
        "out": ({ 0, "inside"}), "in" : ({ 0, "outside"}),
        "exit": ({ 0, "inside"}), "enter" : ({ 0, "outside"}),
        "hubward": ({ 0, "rimward"}), "rimward" : ({ 0, "hubward"}),
        "turnwise": ({ 0, "widdershins"}),
        "widdershins": ({ 0, "turnwise"}),
        ]);

    chatters = allocate( CHATSIZE );
    doors = allocate( DOORSIZE );

    queued_doors = ({ 0 });
    queued_chatters = ({ 0 });

    recycled_doors = recycled_chatters = recycled_items = ({ });

    call_out( (: housekeeping :), 4 );


} /* create() */

/**
 * This method returns the current list of rooms that are enabled for
 * chatting.
 * @return the current chatters
 */
mixed query_chatters() { return chatters; }

/**
 * This method returns the current list of doors handled by the room
 * handler.
 * @return the current array of doors
 */
mixed query_doors() { return doors; }

/**
 * This method adds an exit type to the current list of available exit types.
 * This is used when the room handler is setup to add all the used exit
 * types.
 * @param type the name of the exit type
 * @param message the message to display when going through the exit
 * @param obvious if the exit is obvious or not
 * @param size the size of the exit (used for heigh restrictions)
 * @param func the function to call when using the exit
 * @return 1 if successfuly added, 0 if not
 * @see remove_exit_type()
 */
int add_exit_type( string type, mixed message, mixed obvious,
                   int size, mixed func ) {
    if( exit_types[type] )
        return 0;

    exit_types[type] = ({ message, obvious, size, func });
    return 1;

} /* add_exit_type() */

/**
 * This method remove the named exit from the type list.
 * @param type the name of the exit type to remove
 * @return always returns 1
 * @see add_exit_type()
 */
int remove_exit_type( string type ) {
    map_delete( exit_types, type );
    return 1;
} /* remove_exit_type() */

/** @ignore yes */
void add_door( object thing ) {
    int number;

    number = random( DOORSIZE );

    if( !pointerp( doors[ number ] ) )
        doors[ number ] = ({ thing });
    else
        doors[ number ] += ({ thing });

} /* add_door() */

/**
 * This method returns information about the door type, the door has
 * extra information associated with it than the standard exit type.
 * This function does a double job of trying to find the corresponding
 * door on the other side of the room.
 * @param type the type of the door
 * @param direc the direction the door points
 * @param dest the destination of the door
 * @return the door type array of information
 */
mixed query_door_type( string type, string direc, mixed dest ) {
    if( !door_types[type] )
        return 0;

    if( functionp(dest) )
        error("Cannot use function pointer destinations with doors.\n");

    // If there isn't a door on the other side.  We don't join.
    call_out("check_door", 1, ({ PO, direc }) );
    return door_types[type] + ({ 0 });

} /* query_door_type() */

/**
 * This method checks to see if the door exists or not.
 * It is passed in the room we are going from and the direction the
 * exit faces in the array.<br>
 * <pre>({ room_from, direction })</pre><br>
 * This is the function which generates those door xx not found messages.
 * @param args the arguements passed into the function
 * @see query_door_type()
 */
void check_door( mixed args ) {
    int ignore;
    string direc, dest;

    if( !args[ 0 ] )
        return;

    args[ 0 ]->set_destination( args[ 1 ] );
    dest = args[ 0 ]->query_destination( args[ 1 ] );

    if( !dest ) {
        tell_room( args[ 0 ], "Error: "+args[ 1 ]+" is no longer an exit.\n");
        return;
    }

    if( !find_object( dest ) ) {
        ignore = 1;
        if( catch( call_other( dest, "??" ) ) ) {
            tell_room( args[ 0 ], "Error: "+dest+" does not exist or does "
                "not load.\n" );
            args[ 0 ]->modify_exit( args[ 1 ], ({ "undoor", 0 }) );
            return;
        }
    }

    direc = dest->query_door( args[ 0 ] );

    if( !direc && !args[ 0 ]->call_door( args[ 1 ], "query_one_way") ) {
        tell_room( args[ 0 ], "Error: "+dest+" does not have a door coming "
            "back here.\n" );
        args[ 0 ]->modify_exit( args[ 1 ], ({ "undoor", 0 }) );
        return;
    }

    args[ 0 ]->modify_exit( args[ 1 ], ({ "other", direc }) );

    // If the other side wasn't loaded anyway, don't bother.
    if( ignore )
        return;

    // This makes sure that whatever the states of the two sides,
    // they'll both end up the same.  Think about it...
    args[ 0 ]->modify_exit( args[ 1 ], ({
        "closed", dest->call_door( direc, "query_closed"),
        "locked", dest->call_door( direc, "query_locked"),
        "closed", dest->call_door( direc, "query_closed") }) );

    if( !args[ 0 ]->call_door( args[ 1 ], "query_closed") &&
        args[ 0 ]->query_property("location") == "outside" )
        add_door( args[ 0 ]->query_door_control( args[ 1 ] ) );

} /* check_door() */

/**
 * This method returns the information associated with the exit type.
 * @param type the exit type to query
 * @param dir the direction the type information is for
 * @return a huge amount of info as specified above
 */
mixed query_exit_type( string type, string dir ) {
    mixed s;

    if( !s = opposite[dir] )
        s = ({ 0, "elsewhere" });

    if( !exit_types[type] )
        return exit_types["standard"] + ({ s, 0, 0, 0, 0, 0, 0, 0, 0, 0 });

    return exit_types[ type ] + ({ s, 0, 0, 0, 0, 0, 0, 0, 0, 0 });

} /* query_exit_type() */

/**
 * This is the code that actually moves the thing around the place.
 * It handles all the weirdness involved with dragging things and other
 * such stuff.
 * @param thing what is being moved
 * @param dir the direction we are going
 * @param dest the destination room
 * @param exit the exit name
 * @param enter the enter name
 * @param move the string to tell the object when it moves
 * @return 1 on success, 0 on failure
 */
int move_thing( object thing, string dir, mixed dest, mixed exit,
                mixed enter, string move ) {
    int ret;
    string arrive, leave;
    object dragging;

    dragging = thing->query_dragging();

    if( dragging && ENV(dragging) != ENV(thing)) {
        thing->reset_dragging();
        dragging = 0;
    }

    if( exit != "none" || objectp( dragging ) ) {
        if( stringp( enter ) )
            enter = ({ 1, enter });
        else if ( !pointerp( enter ) )
            enter = ({ 0, "somewhere"});

        switch ( enter[ 0 ] ) {
          case 0 :
            arrive = replace( thing->query_msgin(), "$F", enter[1] );
          break;
          default :
            arrive = enter[ 1 ];
        }

        if( stringp( exit) )
            leave = exit;
        else if( pointerp( exit ) )
            leave = exit[ 0 ];
        else
            leave = thing->query_msgout();

        leave = replace( leave, "$T", "$R$-"+ dir +"$R$" );
    }

    // Check position...
    if( thing->query_position() != "crouching")
        thing->return_to_default_position(1);

    if( arrive || objectp( dragging ) ) {
        thing->remove_hide_invis("hiding");
        if( stringp( arrive ) && objectp( dragging ) ) {
            arrive += "\n$C$"+thing->query_pronoun()+" drags "+
                dragging->a_short()+" in behind "+thing->HIM+".";
        }

        if( stringp( leave ) && objectp( dragging ) ) {
            leave += "\n$C$"+thing->HE+" drags "+
                dragging->the_short()+" away behind "+thing->HIM+".";
        }

        if( stringp( move ) )
            tell_object( thing, move );

        ret = thing->move( dest, arrive, leave );

        if( !ret && objectp( dragging ) ) {
            if( !dragging->move(ENV(thing)) ) {
                tell_object( thing, "You drag "+
                    dragging->the_short() +" behind you.\n");
                thing->adjust_time_left( -DEFAULT_TIME );
            } else {
                tell_object( thing, "You fail to drag "+
                    dragging->the_short()+" behind you.\n");
            }
        }
    } else {
        if( stringp(move) )
            tell_object( thing, move );
        ret = thing->move( dest );
    }

    return !ret;

} /* move_thing() */

/**
 * @ignore yes
 * This function performs the door checks for exit_move(). It is called
 * for the object moving and each of its followers.  It returns 1 if
 * the player can move or 0 if not, 2 if the player was dead
 */
int exit_move_door_checks( object thing, mixed closed ) {

    closed->force_other();

    if( closed->query_open() )
        return 1;

    if( thing->query_property("demon") || thing->query_property("dead") )
        return 2;

    if( thing->no_use_doors() ) {
        tell_object( thing, "You cannot go through closed doors.\n");
        return notify_fail("");
    }

    if( closed->query_locked() && !closed->moving_unlock(thing) ) {
        // It is locked and invisible...
        if( !closed->query_visible(thing) )
            return 0;

        tell_object( thing, closed->the_short()+" "+
            ({"is", "are"})[closed->query_how_many()] +" locked.\n");
        return notify_fail("");
    }

    if( !closed->moving_open(thing) )
        return 0;

    return 1;

} /* exit_move_door_checks() */

/**
 * @ignore yes
 * This function performs the function checks for exit_move().
 * It returns 1 if the player can move or 0 if not.
 */
int exit_move_func_checks( string verb, string special, object thing,
                           mixed func, object place ) {
    if( stringp(func) )
        return call_other( place, func, verb, thing, special );

    if( functionp(func) )
        return evaluate( func, verb, thing, special );

    if( pointerp(func) )
        return call_other( func[0], func[1], verb, thing, special );

    return 1;

} /* exit_move_func_checks() */

/**
 * This is the main code for moving someone.  The move_thing code above
 * should not be called directly.  This code handlers all the followers
 * and any other things that need to be handled.
 * @param verb the movement verb
 * @param extra extra information
 * @param special special information
 * @param thing the thing to move
 * @return 1 on success, 0 on failure
 */
int exit_move( string verb, string extra, string special, object thing ) {
    int open, flag;
    string leave;
    object place, follower;
    object *okay, *all_followers, *tmp_followers, *more_followers;
    mixed closed, func, dest_other, destination;

    // Find the exit infomation.
    place = ENV( thing );
    verb = place->expand_alias( verb );
    place->set_destination( verb );

    // This checks that the destination is correctly set.
    dest_other = (mixed)place->query_dest_other( verb );
    if( !pointerp(dest_other) )
        return 0;

    if( thing->cannot_walk() )
        return notify_fail("");

    // This checks that the door exists if there should be one.
    if( closed = place->query_door_control( verb ) )
        open = closed->query_open();

    if( objectp(closed) && !open &&
        !( flag = exit_move_door_checks( thing, closed ) ) )
        return 0;

    // Check exit functions.
    func = dest_other[ROOM_FUNC];
    if( func && !thing->query_property("demon") &&
        !exit_move_func_checks( verb, special, thing, func, place ) )
        return 0;

    if( place->query_relative( verb ) )
        leave = thing->find_rel( verb, 0 );
    else
        leave = verb;

    // Check height.
    if( thing->query_height() > dest_other[ ROOM_SIZE ] &&
        !( thing->query_position() == "crouching" &&
        thing->query_height() / 3 <= dest_other[ ROOM_SIZE ] ) ) {
        tell_object( thing, "You are too tall to go that way.\n");
        return notify_fail("");
    }

    // Now actually move.
   
    if(functionp( dest_other[ ROOM_EXIT ]))
        special = evaluate(dest_other[ ROOM_EXIT ]);
    else
    special = dest_other[ ROOM_EXIT ];
    
    destination = dest_other[ ROOM_DEST ];

    if( functionp(destination) )
        destination = evaluate( destination, thing );

    if(functionp(dest_other[ROOM_ENTER])){
       if( !move_thing( thing, verb, destination, special,
                evaluate(dest_other[ROOM_ENTER]), dest_other[ ROOM_MESS ] ) )
           return 0;        
    }else{
           if( !move_thing( thing, verb, destination, special,
                     dest_other[ROOM_ENTER], dest_other[ ROOM_MESS ] ) )
           return 0;         
     }
    
    // exit_move_door_checks() retuned 2 - the player is dead.
    if( flag == 2 )
        tell_object( thing, "You ghost through "+closed->the_short()+".\n");

    thing->return_to_default_position(1);

    okay = ({ });

    if( place && !dest_other[ ROOM_NO_FOLLOW ] ) {
        // Get all the followers of the followers.
        all_followers = thing->query_followers();
        more_followers = all_followers;
        do {
            tmp_followers = ({ });
            foreach( follower in more_followers ) {
                // We only follow people that are actually here.
                // Also make sure we don't end up with duplicates.
                if( follower && ENV( follower ) == place )
                    tmp_followers |= follower->query_followers();
            }
            // Make sure we do not get repeated followers.
            more_followers = tmp_followers - all_followers;
            all_followers |= tmp_followers;
        } while( sizeof(more_followers) );

        // Move all those people following us too!
        foreach ( follower in all_followers ) {
            if( !objectp( follower ) ) {
                thing->remove_follower( follower );
                continue;
            }

            // Make sure they are in the start room and if they are a user
            // they are interactive and the person they are following is
            // visible and they aren't passed out and can walk.
            if( ENV(follower) != place ||
                ( userp(follower) && !interactive(follower) ) ||
                ( !thing->query_visible(follower) || special == "none") ||
                follower->query_property(PASSED_OUT) ||
                follower->cannot_walk() )
                continue;

            // Do the door checks.
            if( objectp(closed) && !open &&
                !exit_move_door_checks( follower, closed ) )
                continue;

            // Do the function checks.
            if( func && !follower->query_property("demon") &&
                !exit_move_func_checks( verb, special, follower, func, place ) )
                continue;

            if( place->query_relative( verb ) ) {
                leave = follower->find_rel( verb, 0 );
                follower->reorient_rel( leave );
            } else {
                leave = verb;
            }

            if( follower->query_height() > dest_other[ ROOM_SIZE ] &&
                !( follower->query_position() == "crouching" &&
                follower->query_height() / 3 <= dest_other[ ROOM_SIZE ] ) ) {
                tell_object( follower, "You are too tall to follow "+
                    thing->the_short()+" "+leave+".\n" );
                continue;
            }

            if( function_exists("check_doing_follow", follower ) &&
                !follower->check_doing_follow( thing, verb, special ) )
                continue;

             if(functionp(dest_other[ROOM_ENTER])){
              if( move_thing( follower, verb, destination, special,
                evaluate(dest_other[ROOM_ENTER]), dest_other[ ROOM_MESS ] ) && 
              living(follower) ){
                 tell_object( follower, "You follow "+
                    thing->the_short()+" "+leave+".\n");

                if( follower->query_visible(thing) )
                    okay += ({ follower });

                follower->return_to_default_position(1);
                follower->adjust_time_left( -DEFAULT_TIME );
              } else {
                tell_object( follower, "You fail to follow "+
                    thing->the_short()+" "+leave+".\n");       
              }
              
             }else{
              if( move_thing( follower, verb, destination, special,
                dest_other[ROOM_ENTER], dest_other[ ROOM_MESS ] ) &&
                living(follower) ) {
                tell_object( follower, "You follow "+
                    thing->the_short()+" "+leave+".\n");

                if( follower->query_visible(thing) )
                    okay += ({ follower });

                follower->return_to_default_position(1);
                follower->adjust_time_left( -DEFAULT_TIME );
            } else {
                tell_object( follower, "You fail to follow "+
                    thing->the_short()+" "+leave+".\n");
            }
          }
        }
    }

    // Move everyone then do the look.  Fix up problems with followers
    // that have light, like the fireflies and blue lights.
    thing->room_look();

    if( sizeof(okay) ) {
        okay->room_look();
        tell_object( thing, query_multiple_short(okay)+" $V$0=follows,"
            "follow$V$ you.\n");
    }

    if( objectp(closed) && !open )
        closed->moving_close(thing);

    return 1;

} /* exit_move() */

/** @ignore yes */
void add_chatter( object thing, int number ) {
    number /= 4;

    if( number > CHATSIZE - 1 )
        number = CHATSIZE - 1;

    if( !pointerp( chatters[ number ] ) )
        chatters[ number ] = ({ thing });
    else
        chatters[ number ] += ({ thing });

} /* add_chatter() */

/** @ignore yes */
void check_chatters() {
    object *things;

    things = chatters[ 0 ];
    chatters[0..<2] = chatters[1..<1];
    chatters[<1] = 0;

    if( pointerp( things ) ) {
        things -= queued_chatters;
        map( things, (: $1->make_chat() :) );
    }

} /* check_chatters() */

/** @ignore yes */
void check_doors() {
    int wind;
    string dest, other, mess;
    object mine, thing, *things;

    things = doors[ 0 ];
    doors[0..<2] = doors[1..<1];
    doors[<1] = 0;

    if( pointerp( things ) ) {
        things -= queued_doors;
        foreach( thing in things ) {
            if( thing->query_closed() || thing->query_stuck() )
                continue;

            dest = thing->query_dest();
            other = thing->query_other_id();
            mine = thing->query_my_room();
            wind = WEATHER_H->calc_actual( mine, WINDSP );

            if( random( 25 ) > wind ) {
                add_door( thing );
                return;
            }

            switch( wind ) {
              case -1000 .. 20 :
                mess = "blow$s shut in the breeze.\n";
              break;
              case 21 .. 40 :
                mess = "blow$s shut in the wind.\n";
              break;
              default :
                mess = "slam$s shut in the wind.\n";
            }

            if( find_object( dest ) ) {
                dest->modify_exit( other, ({"closed", 1 }) );
                dest->tell_door( other, "The $D "+mess, 0 );
            }

            thing->set_closed( 1 );
            thing->tell_door("The $D "+mess, 0 );

        }
    }

} /* check_doors() */

/** @ignore yes */
private void housekeeping() {
    call_out( (: check_doors :), 2 );
    call_out( (: housekeeping :), 4 );
    check_chatters();
} /* housekeeping() */

/** @ignore yes */
private object *clean_array( object *obs, object *minus ) {
    if( sizeof(obs) )
        obs -= minus;
    return obs;
} /* clean_array() */

/** @ignore yes */
private void clean_doors() {
    door_id = 0;
    doors = map( doors, (: clean_array( $1, $2 ) :), queued_doors );
    queued_doors = ({ 0 });
} /* clean_doors() */

/** @ignore yes */
private void clean_chatters() {
    chatter_id = 0;
    chatters = map( chatters, (: clean_array( $1, $2 ) :), queued_chatters );
    queued_chatters = ({ 0 });
} /* clean_chatters() */

/**
 * This method recycles a chatter object and is used by rooms.
 * It calls reload_object() on the chatter, removes it from the
 * chatters array and adds it to the recycled_chatters array.
 * It can then be re-used by using get_chatter().
 * Only objects whose base_name is CHATTER_OBJECT can be recycled.
 * @param ob the chatter object to recycle
 * @return 1 if successfully recycled, 0 if not
 * @see get_chatter()
 */
int recycle_chatter( object ob ) {
    if( base_name(ob) == CHATTER_OBJECT ) {
        if( !chatter_id )
            chatter_id = call_out( (: clean_chatters :), 15 );
        reload_object(ob);
        queued_chatters += ({ ob });
        recycled_chatters += ({ ob });
        return 1;
    }

    return 0;

} /* recycle_chatter() */

/**
 * This method gets a recycled chatter from the handler,
 * or clones a new one, if needed.  This is used by rooms.
 * @return a chatter object
 * @see recycle_chatter()
 */
object get_chatter() {
    object ret;

    if( sizeof( recycled_chatters -= ({ 0 }) ) ) {
        ret = recycled_chatters[0];
        recycled_chatters = recycled_chatters[1..];
        chatter_hits++;
        if( chatter_id ) {
            remove_call_out(chatter_id);
            clean_chatters();
        }
    } else {
        ret = clone_object(CHATTER_OBJECT);
        chatter_misses++;
    }

    return ret;

} /* get_chatter() */

/**
 * This method recycles a door object and is used by rooms.
 * It calls reload_object() on the door, removes it from the
 * doors array and adds it to the recycled_doors array.
 * It can then be re-used by using get_door().
 * Only objects whose base_name is DOOR_OBJECT can be recycled.
 * @param ob the door object to recycle
 * @return 1 if successfully recycled, 0 if not
 * @see get_door()
 */
int recycle_door( object ob ) {
    if( base_name(ob) == DOOR_OBJECT ) {
        if( !door_id )
            door_id = call_out( (: clean_doors :), 15 );
        reload_object(ob);
        queued_doors += ({ ob });
        recycled_doors += ({ ob });
        return 1;
    }

    return 0;

} /* recycle_door() */

/**
 * This method gets a recycled door from the handler,
 * or clones a new one, if needed.  This is used by rooms.
 * @return a door object
 * @see recycle_door()
 */
object get_door() {
    object ret;

    if( sizeof( recycled_doors -= ({ 0 }) ) ) {
        ret = recycled_doors[0];
        recycled_doors = recycled_doors[1..];
        door_hits++;
        if( door_id ) {
            remove_call_out(door_id);
            clean_doors();
        }
    } else {
        ret = clone_object(DOOR_OBJECT);
        door_misses++;
    }

    return ret;

} /* get_door() */

/**
 * This method recycles an item object and is used by rooms.
 * It calls reload_object() on the item and puts it in the
 * recycled_items array.
 * It can then be re-used by using get_item().
 * Only objects whose base_name is ITEM_OBJECT can be recycled.
 * @param ob the item object to recycle
 * @return 1 if successfully recycled, 0 if not
 * @see get_item()
 */
int recycle_item( object ob ) {
    if( base_name(ob) == ITEM_OBJECT ) {
        reload_object(ob);
        recycled_items += ({ ob });
        return 1;
    }

    return 0;

} /* recycle_item() */

/**
 * This method gets a recycled item object from the handler,
 * or clones a new one, if needed.  This is used by rooms.
 * @return an item object
 * @see recycle_item()
 */
object get_item() {
    object ret;

    if( sizeof( recycled_items -= ({ 0 }) ) ) {
        ret = recycled_items[0];
        recycled_items = recycled_items[1..];
        item_hits++;
    } else {
        ret = clone_object(ITEM_OBJECT);
        item_misses++;
    }

    ret->set_my_room(PO);

    return ret;

} /* get_item() */

/** @ignore yes */
object *query_recycled_chatters() { return recycled_chatters; }

/** @ignore yes */
object *query_recycled_doors() { return recycled_doors; }

/** @ignore yes */
object *query_recycled_items() { return recycled_items; }

/** @ignore yes */
void dest_me() {
    if( sizeof( recycled_chatters -= ({ 0 }) ) )
        recycled_chatters->dest_me();
    if( sizeof( recycled_doors -= ({ 0 }) ) )
        recycled_doors->dest_me();
    if( sizeof( recycled_items -= ({ 0 }) ) )
        recycled_items->dest_me();
    destruct(TO);
} /* dest_me() */

/**
 * @ignore yes
 * Survive the updates.
 */
mapping query_dynamic_auto_load() {
    return ([
        "exit_types" : exit_types,
        "door_types" : door_types,
        "opposite"   : opposite,
        "chatters"   : chatters,
        "doors"      : doors,
    ]);
} /* query_dynamic_auto_load() */

/**
 * @ignore yes
 * Survive the updates.
 */
void init_dynamic_arg( mapping maps ) {
    if( maps["exit_types"] )
        exit_types = maps["exit_types"];
    if( maps["door_types"] )
        door_types = maps["door_types"];
    if( maps["opposite"] )
        opposite = maps["opposite"];
    if( maps["chatters"] )
        chatters = maps["chatters"];
    if( maps["doors"] )
        doors = maps["doors"];
} /* init_dynamic_arg() */

/** @ignore yes */
mixed stats() {
    int door_count, chatter_count;
    int doors_missing, chatters_missing, items_missing;
    mixed temp;

    foreach( temp in chatters )
        chatter_count += sizeof( temp );

    foreach( temp in doors )
        door_count += sizeof( temp );

    doors_missing -= sizeof( children(DOOR_OBJECT) -
        ({ find_object(DOOR_OBJECT) }) ) - door_misses;
    chatters_missing -= sizeof( children(CHATTER_OBJECT) -
        ({ find_object(CHATTER_OBJECT) }) ) - chatter_misses;
    items_missing -= sizeof( children(ITEM_OBJECT) -
        ({ find_object(ITEM_OBJECT) }) ) - item_misses;

    return ({
        ({"exit types", sizeof( exit_types ) }),
        ({"door types", sizeof( door_types ) }),
        ({"opposites",  sizeof( opposite ) }),
        ({"chatters",  chatter_count }),
        ({"doors", door_count }),
        ({"recycled chatters", sizeof(recycled_chatters) }),
        ({"recycled doors", sizeof(recycled_doors) }),
        ({"recycled items", sizeof(recycled_items) }),
        ({"chatter hits", chatter_hits }),
        ({"door hits", door_hits }),
        ({"item hits", item_hits }),
        ({"chatter misses", chatter_misses }),
        ({"door misses", door_misses }),
        ({"item misses", item_misses }),
        ({"missing chatters", chatters_missing > 0 ? chatters_missing : 0 }),
        ({"missing doors", doors_missing > 0 ? doors_missing : 0 }),
        ({"missing items", items_missing > 0 ? items_missing : 0 }),
        ({"total hits", chatter_hits + door_hits + item_hits }),
        ({"total misses", chatter_misses + door_misses + item_misses }),
    });

} /* stats() */



