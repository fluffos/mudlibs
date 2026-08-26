/**
 * This effect is for the nice people who own a transport.
 * @author Pinkfish
 * @started Fri Sep 24 1:00:00 1999
 * @classification mudlib.riding.owned
 */

#include <player.h>

inherit "/std/basic/virtual_quit_control";

class riding {
    object *transport;
    string *environments;
    mixed save_stuff;
}

private nosave int _transport_id;

void create() {
    _transport_id = random(3000) + 1;
} /* create() */

/** @ignore yes */
string query_classification() {
    return "mudlib.riding.owned";
} /* query_classification() */

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
class riding beginning( object player, object transport, int id ) {
    class riding bing;

    bing = new( class riding );
    bing->transport = ({ transport });
    bing->save_stuff = 0;

    transport->set_transport_id( _transport_id++ );

    return bing;

} /* begining() */

/** @ignore yes */
class riding merge_effect( object player, class riding arg, object transport ) {
    if( member_array( transport, arg->transport ) == -1 ) {
        if( !transport->query_transport_id() ) {
            while( sizeof( filter( arg->transport,
                (: $1 && $1->query_transport_id() == $2 :),
                _transport_id ) ) )
            _transport_id++;

            transport->set_transport_id( _transport_id++ );

        } else if( sizeof( filter( arg->transport,
            (: $1 && $1->query_transport_id() == $2 :),
            transport->query_transport_id() ) ) ) {
            transport->dest_me();
            return arg;
        }

        if( member_array( transport, arg->transport ) != -1 )
            error("Trying to add the same transport twice.\n");

        arg->transport += ({ transport });

    }

    return arg;

} /* merge_effect() */

/** @ignore yes */
void end( object player, class riding arg ) {
} /* end() */

/** @ignore yes */
void restart( object player, class riding arg ) {
    int i;
    object *obs;

    obs = arg->transport - ({ 0 });

    if( !sizeof(obs) && arg->save_stuff ) {
        obs = AUTO_LOAD_OB->load_auto_load_to_array( arg->save_stuff, player );
        i = sizeof( obs );

        while( i-- ) {
            if( obs[i] ) {
                arg->transport[i] = obs[i];
                arg->transport[i]->move( arg->environments[i],
                    "$N appear$s with a puff of fluff.");
            }
        }
    }

    arg->save_stuff = 0;

} /* restart() */

/** @ignore yes */
void clear_thingy( class riding arg ) {
    arg->save_stuff = 0;
} /* clear_thingy() */

/** @ignore yes */
void saving( object player, class riding arg ) {
    arg->transport -= ({ 0 });
    arg->environments = map( arg->transport,
        (: find_start_pos( $1, ENV($1) ) :) );

    arg->save_stuff = AUTO_LOAD_OB->create_auto_load( arg->transport );

    call_out( (: clear_thingy :), 2, arg );

} /* saving() */

/** @ignore yes */
void quiting( object player, class riding arg ) {
    call_out( (: $1->retire() :), 2, arg->transport );
} /* quiting() */

/**
 * This method removes the specified transport from the list of
 * current transports on the player.
 * @param player the player the transport is removed from
 * @param bing the class!
 * @param id the id of the effect
 * @param trans the transport to remove
 */
void remove_owner( object player, class riding arg, int id, object trans ) {
    arg->transport -= ({ trans });

    if( !sizeof( arg->transport ) )
        player->delete_effect(id);

} /* remove_owner() */
