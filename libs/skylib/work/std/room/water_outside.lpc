/**
 * Standard outside water room inheritable.  This is mainly just a mux
 * for the functions that are defined in both /std/outside and
 * /std/room/basic/water.
 * @author Presto, Jeremy
 * @see /std/room/outside.c
 * @see /std/room/basic/water.c
 */

inherit OUTSIDE_OBJ;
inherit "/std/room/basic/water";

/**
 * This method is called whenever something enters the room.  See
 * the general event_exit() documentation for details.  The event_enter()
 * in BASIC_WATER is called first, then BASE_ROOM.
 * @see event_exit()
 */
void event_exit( object ob, string mess, object to )  {
  water::event_exit(ob, mess, to);
  outside::event_exit(ob, mess, to);
}

/**
 * This method is called by an object when in enters the room.  See the
 * general init() documentation for details.  The init() in
 * BASIC_WATER is called first, then BASE_ROOM.
 * @see init()
 */
void init() {
  water::init();
  outside::init();
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



