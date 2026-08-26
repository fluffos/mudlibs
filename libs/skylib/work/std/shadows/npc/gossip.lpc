/**
 * This is the gossip effect shadow for gossiping children, etc.
 */

#include <gossip.h>

#define MAX_BUFFER 4

inherit "/std/effect_shadow";

private class gossip_data *gossip = ({ });
private int last;

/** @ignore yes */
void event_person_say( object ob, string start, string mess, string lang ) {
    class gossip_data data;

    player->event_person_say( ob, start, mess, lang );

    // We only want players' gossip, which is somewhat meaningful...
    if( !interactive(ob) || !stringp(mess) || sizeof(mess) > 100 ||
        sizeof( explode( mess, " ") ) < 3 || creatorp(ob) ||
        strsrch( mess, "fuck") != -1 ||
        strsrch( mess, "cunt") != -1 ||
        strsrch( mess, "bitch") != -1 ||
        strsrch( mess, "shit") != -1 )
        return;

    data = new( class gossip_data,
                who  : ob->query_cap_name(),
                what : mess );

    if( !sizeof(gossip) || gossip[<1]->who != data->who ||
        gossip[<1]->what != data->what ) {
        int i;

        gossip += ({ data });

        if( ( i = sizeof(gossip) ) > MAX_BUFFER )
            gossip = gossip[i-MAX_BUFFER..];
    }

    if( !random(32) )
        GOSSIP_H->add_gossip( data );

} /* event_person_say() */

/** @ignore yes */
void do_gossip_say( string str ) {
    class gossip_data data;
    int i, chance;

    if( !str )
        str = "$name$ said: $mess$";

    if( !intp( chance = arg() ) )
        chance = 4;

    i = sizeof(gossip);

    if( !random(chance) || !i || ( i == 1 && !last ) )
        data = GOSSIP_H->query_random_gossip();

    if( data ) {
        last = -1;
    } else if( !data && i ) {
        chance = random( i );
        if( chance == last )
            chance = ( chance + 1 ) % i;
        last = chance;
        data = gossip[chance];
    }

    if( !data )
        return;

    str = replace( str, ({ "$name$", data->who,
                           "$mess$", data->what }) );

    player->do_command("'"+str);

} /* do_gossip_say() */

/** @ignore yes */
class gossip_data *query_gossip_says() { return gossip; }
