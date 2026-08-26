/**
 * This is the default item shop code.  An item shop is a shop that only
 * sells specific items.
 * @author Pinkfish
 * @started Wed Oct 14 16:42:21 PDT 1998
 * @see /std/shops/inherit/item_shop
 */

inherit ROOM_OBJ;
inherit "/std/shops/inherit/item_shop";

void create() {
  item_shop::create();
  basic_room::create();
} /* create() */

/** @ignore yes */
void init() {
   basic_room::init();
   item_shop::init();
} /* init() */

/** @ignore yes */
void dest_me() {
   item_shop::dest_me();
   basic_room::dest_me();
} /* dest_me() */

/** @ignore yes */
mixed stats() { return basic_room::stats() + item_shop::stats(); }

/** @ignore yes */
int query_keep_room_loaded() { return 1; }
