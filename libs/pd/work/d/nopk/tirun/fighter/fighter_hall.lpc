#include <std.h>
#include <tirun.h>

inherit HALL;

void create() {
  object ob;
  ::create();
  set_type("fighter");
  set("short", "The inner sanctum of the Hall of Fighters");
  set("long",
      "Welcome to the inner sanctum of the Hall of Fighters!\n"
      "Fighters gather here to advance in the art of combat and in life.  "
      "In this hall, a fighter may <advance>, <cost>, <list (number)>, "
      "<improve stat>, <train skill amount>, and <roll stats>.  Down "
      "through a stairway guarded by a shimmering %^BLUE%^blue%^RESET%^ "
"light is the entrance to the hall. ");
   set_exits(([
      "down" : ROOMS"fighter/fighter_join",
      "south" : ROOMS"fighter/fighter_vote"]));
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "glory board" }) );
    ob->set_board_id("fighter_board");
    ob->set_max_posts(50);
    ob->set_location(ROOMS"fighter/fighter_hall");
    ob->set("short", "Glory Board of Fighters");
    ob->set("long",
        "The Fighters of our reality post tales of their glorious "
        "adventures here, as well as info on the dangers out there.\n");
}
