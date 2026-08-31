#include <std.h>
#include <tirun.h>

inherit HALL;

void create() {
  object ob;
  ::create();
  set_type("dragon");
    set_properties( ([ "indoors" : 0]) );
  set("short", "The inner sanctum of the Black");
  set("long",
      "Welcome to the inner sanctum of the Black Dragon!\n"
      "Black Dragons gather here to discuss various things as well as train.  "
      "In this hall, a dragon may <advance>, <cost>, <list (number)>, "
      "<improve stat>, <train skill amount>, and <roll stats>.");
   set_exits((["out" : ROOMS"dragon_hall"]));
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "black board" }) );
    ob->set_board_id("black_board");
    ob->set_max_posts(99);
    ob->set_location(ROOMS"dragon/black_hall");
    ob->set("short", "Black's board of chaos.");
    ob->set("long",
        "The Black Dragons come here to talk amongst themselves.\n");
}
