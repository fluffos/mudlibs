/**
 * This is the ball room inherit, here we can dance with each other.
 * @author Sandoz 12th October 2001.
 */

string dance_floor;

class dance_data {
    object initiator;
    object recipient;
}

int do_dance( object *obs );
int do_accept( string name );

/**
 * This method returns the dance floor room associated with this room.
 * @return the dance floor
 */
object query_dance_floor() {
    if( !dance_floor || dance_floor == "" )
        return 0;
    return find_object( dance_floor ) || load_object( dance_floor );
} /* query_dance_floor() */

/**
 * This method returns the dancers array from the dance floor room.
 * @return the dancers array
 */
object query_dancers() {
    object floor;
    if( !floor = query_dance_floor() )
        return 0;
    return floor->query_dancers();
} /* query_dancers() */

/**
 * This method sets the room to use as the dance floor.
 * It will be the place people dancing will be moved into.
 * @param str the file name of the dance floor room
 */
void set_dance_floor( string str ) { dance_floor = str; }

/** @ignore yes */
void create() {
    TO->add_extra_look(TO);
} /* create() */

/** @ignore yes */
void init() {
    TP->add_command( "dance", TO, "with <indirect:living:here'person'>",
                  (: do_dance($1) :) );
    TP->add_command( "accept", TO, "dance from <indirect:living:here'person'>",
                  (: do_accept($1) :) );
} /* init() */

/** @ignore yes */
void dest_me() {
    object ob;
    if( stringp(dance_floor) && ( ob = find_object(dance_floor) ) &&
        !sizeof( INV(ob) ) )
        ob->dest_me();
} /* dest_me() */

/** @ignore yes */
int do_dance( object *obs ) {
    object ob, floor;
    class dance_data data;

    if( !floor = query_dance_floor() ) {
        add_failed_mess("Oh my god!  There is no dance floor!.\n");
        return 0;
    }

    if( sizeof(obs) > 1 ) {
        add_failed_mess("C'mon, you can't dance with more than one person "
            "at a time, make up your mind.\n");
        return 0;
    }

    ob = obs[0];

    if( ob == TP ) {
        add_failed_mess("It is no fun dancing with yourself, believe me.\n");
        return 0;
    }

    data = new( class dance_data );
    data->initiator = TP;
    data->recipient = ob;
    ob->add_respond_command( "dance", TP, data );
    tell_object( ob, "You can accept the dance by typing:\n"
        "accept dance from "+TP->query_name()+"\n");
    add_succeeded_mess(({ "You bow gracefully and ask $I to dance with "
        "you.\n", "$N bow$s gracefully and ask$s $I to dance with $o.\n" }),
        obs );
    return 1;

} /* do_dance() */

/** @ignore yes */
int do_accept( object *obs ) {
    object ob, floor;
    class dance_data data;

    if( !floor = query_dance_floor() ) {
        add_failed_mess("Oh my god!  There is no dance floor!.\n");
        return 0;
    }

    if( sizeof(obs) > 1 ) {
        add_failed_mess("You cannot accept a dance from more than one "
            "person.\n");
        return 0;
    }

    ob = obs[0];

    if( ob == TP ) {
        add_failed_mess("It is no fun dancing with yourself, believe me.\n");
        return 0;
    }

    data = new( class dance_data );

    if( ( data = TP->query_respond_command("dance", ob ) ) &&
        data->initiator == ob && data->recipient == TP ) {
        floor->add_couple( ob, TP );
        tell_object( ob, TP->the_short()+" accepts your dance offer, and you "
            "step onto the dance floor, hand in hand.\n");
        tell_room( TO, TP->the_short()+" accepts the dance offer from "+
            ob->the_short()+", and they step onto the dance floor, "
            "hand in hand.\n", ({ TP, ob }) );
        tell_room( floor, ob->the_short()+" and "+TP->the_short()+" arrive "
            "onto the dance floor, hand in hand.\n", ({ TP, ob }) );
        add_succeeded_mess( ({ "$N accept $I's dance offer and you step onto "
            "the dance floor, hand in hand.\n", "" }), obs );
        ( ({ TP, ob }) )->move(floor);
        ( ({ TP, ob }) )->set_position("dancing here");
        ( ({ TP, ob }) )->room_look();
        TP->remove_respond_command( "dance", ob );
        return 1;
    }

    add_failed_mess("As sad as it may sound, $I has not asked you to dance "
        "with $o, perhaps you should ask $o yourself?.\n", obs );
    return 0;

} /* do_accept() */

/** @ignore yes */
string extra_look() {
    object floor, *dancers;
    string *ret;
    int i;

    if( ENV(TP) != TO || !( floor = query_dance_floor() ) ||
        !sizeof( dancers = floor->query_dancers() ) )
        return "";

    ret = ({ });

    for( i = 0; i < sizeof(dancers); i += 2 ) {
      if( !dancers[i] || !dancers[i+1] ) {
          floor->remove_dancer( i );
          continue;
      }
      ret += ({ dancers[i]->short(0) +"$D$"+ dancers[i+1]->short(0) });
    }

    if( !sizeof(ret) )
        return "";

    return replace( query_multiple_short(ret), ({ "$D$" ," is dancing "
           "with " }) )+" amongst the people on the dance floor.\n";

} /* extra_look() */
