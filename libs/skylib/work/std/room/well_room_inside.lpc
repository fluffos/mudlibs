/**
 * This is indoors well inherit.  Why not?
 * @author Sandoz, 15th September 2001.
 */

inherit ROOM_OBJ;
inherit ROOM_DIR "/inherit/well_room";

/** @ignore yes */
void init() {
    well_room::init();
    basic_room::init();
} /* init() */

/** @ignore yes */
void dest_me() {
    well_room::dest_me();
    basic_room::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed *stats() {
  return basic_room::stats() + well_room::stats();
} /* stats() */
