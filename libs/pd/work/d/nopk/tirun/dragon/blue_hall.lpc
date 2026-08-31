#include <std.h>
#include <tirun.h>

inherit HALL;

void create() {
  object ob;
  ::create();
  set_type("dragon");
    set_properties( ([ "indoors" : 0]) );
  set("short", "The inner sanctum of the blue.");
  set("long",
      "Welcome to the inner sanctum of the Blue Dragon!\n"
      "Blue Dragons gather here to discuss various things as well as train.  "
      "In this hall, a dragon may <advance>, <cost>, <list (number)>, "
      "<improve stat>, <train skill amount>, and <roll stats>.");
   set_exits((["out" : ROOMS"dragon_hall"]));
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "blue board" }) );
    ob->set_board_id("blue_board");
    ob->set_max_posts(99);
    ob->set_location(ROOMS"dragon/blue_hall");
    ob->set("short", "Blue's board of ice.");
    ob->set("long",
        "The Blue Dragons come here to talk amongst themselves.\n");
}
