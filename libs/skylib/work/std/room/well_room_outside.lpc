/**
 * This is outside well inherit.
 * @author Sandoz, 15th September 2001.
 */

inherit OUTSIDE_OBJ;
inherit ROOM_DIR "/inherit/well_room";

/** @ignore yes */
void init() {
    well_room::init();
    outside::init();
} /* init() */

/** @ignore yes */
void dest_me() {
    well_room::dest_me();
    outside::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed *stats() {
  return outside::stats() + well_room::stats();
} /* stats() */
