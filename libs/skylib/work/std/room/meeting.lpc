/**
 * This file is the inheritable for a meeting room.  It handles the floor
 * and a few other things neatly.
 * @author Pinkfish
 * @started 25th of June
 */
inherit ROOM_OBJ;
inherit "/std/room/inherit/meeting";

/** @ignore yes */
void create() {
   add_help_file("meeting");
   basic_room::create();
   meeting::create();
} /* create() */

/** @ignore yes */
void init() {
   basic_room::init();
   meeting::init();
} /* init() */

/** @ignore yes */
void event_exit(object ob,
                string mess,
                object to) {
   basic_room::event_exit(ob, mess, to);
   meeting::event_exit(ob, mess, to);
} /* event_exit() */
