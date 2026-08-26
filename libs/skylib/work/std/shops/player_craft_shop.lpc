/**
 * This is just like a normal craft shop, except it to be used by players.
 * It handles things like messing with the descriptions and so on, it is
 * mostly designed to be used in places like club rooms and things.
 * @author Pinkfish
 * @started Mon Sep 20 19:28:22 PDT 1999
 */
#include <config.h>
#include <player_handler.h>

inherit ROOM_OBJ;
inherit "/std/shops/inherit/player_craft_shop";


/** @ignore yes */
void create() {
   basic_room::create();
   player_craft_shop::create();
   add_help_file("craft_shop");
   add_help_file("craft_shop_category");
   add_help_file("player_craft_shop");
} /* create() */

/** @ignore yes */
void init() {
   basic_room::init();
   player_craft_shop::init();
} /* init() */

/** @ignore yes */
void dest_me() {
   basic_room::dest_me();
   player_craft_shop::dest_me();
} /* dest_me() */

/**
 * @ignore yes
 * Set this up to catch the directory set and setup both the save files...
 */
void set_save_dir(string dir) {
  // set_save_file(dir + "_main");
} /* set_save_dir() */

/**
 * This method tells us if the person is allowed to use this shop.
 * @param name the name of the person
 */
int is_allowed(string name) {
   if ( creatorp(name) )  {
      return 1;
   }

   if (lower_case(name) == lower_case(query_owner())) {
      return 1;
   }

   if (member_array(lower_case(name), query_allowed()) != -1) {
      return 1;
   }
   return 0;
} /* is_allowed() */

/** @ignore yes */
void event_exit(object ob, string mess, object to) {
   basic_room::event_exit(ob, mess, to);
   player_craft_shop::event_exit(ob, mess, to);
} /* event_exit() */
