
inherit ROOM_OBJ;
inherit "/std/shops/engrave_inherit";

/** @ignore yes */
void create() {
   engrave_inherit::create();
   basic_room::create();
} /* create() */

/** @ignore yes */
void init() {
   basic_room::init();
   engrave_inherit::init();
} /* init() */

/** @ignore yes */
mixed stats() { return basic_room::stats() + engrave_inherit::stats(); }
