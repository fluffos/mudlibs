/**
 * This handler keeps track of things buried in rooms.
 * Loosely based on Pinkfish's burial effect.
 * @author Sandoz, 2002.
 * @changed Added recycling of objects - Sandoz, 09/09/2002.
 */

#define BURY_TIMEOUT  300 // 5 min.
#define NO_BURY       "DNB_ME"

private mapping burial_containers;
private object *recycled;
private int call_id, hits, misses;

private void expire_buried();

void create() {
    burial_containers = ([ ]);
    recycled = ({ });
} /* create() */

/**
 * This method buries an object in a room.
 * @param room the room burying the object
 * @param ob the object to bury
 */
void bury_object( object room, object ob ) {
    if( room && ob ) {
        object cont;

        if( !cont = burial_containers[room] ) {
            if( sizeof( recycled -= ({ 0 }) ) ) {
                burial_containers[room] = cont = recycled[0];
                recycled = recycled[1..];
                hits++;
            } else {
                cont = clone_object("/std/container");
                cont->add_property("burial object", 1 );
                burial_containers[room] = cont;
                misses++;
            }
        }

        ob->move( cont );
        ob->add_property( NO_BURY, 1, BURY_TIMEOUT - 1 );

        if( !call_id )
            call_id = call_out( (: expire_buried :), BURY_TIMEOUT );
    }

} /* bury_object() */

/**
 * This method is called by the room object when it is dested.
 * It will get rid of the buried objects.
 */
void room_dested() {
    object room, cont;

    room = PO;

    if( room && ( cont = burial_containers[room] ) ) {
        INV(cont)->move("/room/rubbish");
        if( !sizeof(INV(cont)) )
            recycled += ({ cont });
        else
            cont->dest_me();
        map_delete( burial_containers, room );
    }

    if( !sizeof(burial_containers) ) {
        remove_call_out(call_id);
        call_id = 0;
    }

} /* room_dested() */

/**
 * This method is called by the recover command after
 * a successful recover to do some maintenance stuff.
 * @param room the room recover was used in
 */
void event_recover( object room ) {
    object cont;

    if( room && ( cont = burial_containers[room] ) && !sizeof( INV(cont) ) ) {
        recycled += ({ cont });
        map_delete( burial_containers, room );
    }

} /* event_recover() */

/** @ignore */
mapping query_burial_containers() { return burial_containers; }

/** @ignore */
private void expire_buried() {
    object room, cont, *obs;

    call_id = 0;

    foreach( room, cont in burial_containers ) {
        if( !cont ) {
            map_delete( burial_containers, room );
            continue;
        }

        if( !room ) {
            INV(cont)->move("/room/rubbish");
            if( !sizeof(INV(cont)) )
                recycled += ({ cont });
            else
                cont->dest_me();
            map_delete( burial_containers, room );
            continue;
        }

        obs = filter( INV(cont), (: !$1->query_property(NO_BURY) :) );
        if( sizeof( obs ) )
            obs->move("/room/rubbish");

        if( !sizeof( obs = INV(cont) ) ) {
            recycled += ({ cont });
            map_delete( burial_containers, room );
        }
    }

    if( sizeof(burial_containers) )
        call_id = call_out( (: expire_buried :), BURY_TIMEOUT );

} /* expire_buried() */

/**
 * This method returns all the stuff buried in the specified room.
 * @param room the room to get the burial objects from
 * @return the array of buried objects
 */
object* query_buried_objects( object room ) {
    if( room && burial_containers[room] )
        return INV( burial_containers[room] );
    return ({ });
} /* query_buried_objects() */

/**
 * This method returns the container for a specific room,
 * that has all the buried items in it.
 * @param room the room to get the burial object for
 * @return the container with the buried items
 */
object query_buried_container( object room ) {
    return burial_containers[room];
} /* query_buried_container() */

/** @ignore yes */
void dest_me() {
    object cont;

    foreach( cont in values(burial_containers) ) {
        if( cont ) {
            INV(cont)->move("/room/rubbish");
            cont->dest_me();
        }
    }

} /* dest_me() */

/** @ignore yes */
mixed stats() {
    return ({
        ({"burial containers", sizeof(burial_containers) }),
        ({"recycled containers", sizeof(recycled) }),
        ({"recycle hits", hits }),
        ({"recycle misses", misses }),
    });
} /* stats() */
