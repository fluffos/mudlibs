/**
 * Standard inside water room inheritable.  This is mainly just a mux
 * for the functions that are defined in both /std/room and
 * /std/room/basic/water.
 * @author Presto, Jeremy
 * @see /std/room.c
 * @see /std/room/basic/water.c
 */

inherit ROOM_OBJ;
inherit "/std/room/basic/water";

/**
 * This method is called whenever something enters the room.  See
 * the general event_exit() documentation for details.
 * @see event_exit()
 */
void event_exit( object ob, string mess, object to )  {
 // water::event_exit(ob, mess, to);
}

/**
 * This method is called whenever something enters the room.  See
 * the general event_exit() documentation for details.
 * @see event_exit()
 */
void event_enter( object ob, string mess, object to )  {
  water::event_enter(ob, mess, to);
}

/**
 * This method is called by an object when in enters the room.  See the
 * general init() documentation for details.  The init() in
 * BASIC_WATER is called first, then BASE_ROOM.
 * @see init()
 */
void init() {
  water::init();
  basic_room::init();
}

/**
 * See the documentation for the method in BASIC_WATER.
 */
int is_allowed_position(string poss) {
  return water::is_allowed_position(poss);
}

/**
 * See the documentation for the method in BASIC_WATER.
 */
mixed *query_default_position(object ob) {
  return water::query_default_position(ob);
}

/**
 *
 */
 varargs int add_exit(string direc, mixed dest, string type){
    basic_room::add_exit( direc, dest, type);
    return water::add_exit(direc, dest, type);
 }
