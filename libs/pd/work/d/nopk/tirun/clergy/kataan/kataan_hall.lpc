#include <std.h>
#include <tirun.h>
#include <daemons.h>
inherit HALL;
void create() {
  object ob;
  ::create();
  set_type("clergy");
  set("short", "The central chamber of the kataans");
  set("long",
   "Welcome to the central chamber of the kataans! "
   "Kataans come here to advance in the arts of combat and magic. "
   "The available commands are <cost>, <advance>, <list (number)>, "
   "<improve stat>, <train skill amount>, and <roll>. Down through "
   "a stairway "
   "guarded by a shimmering %^BLUE%^blue%^RESET%^ light is the "
   "entrance to the hall. "
   "<help skills> will list the full names of all skills. "
   //   "Once you leave this room, you must go down in the monument to return."
  );
  set_exits(([
//    "out" : "/d/nopk/standard/cemetary/building",
    "out" : "/d/nopk/tirun/clergy/kataan/kataan_join",
  ]));
  ob = new("/std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board", "board of despair" }) );
  ob->set_board_id("kataan_board");
  ob->set_edit_ok(({"nulvect"}));
  ob->set_max_posts(100);
  ob->set_location(ROOMS "clergy/kataan/kataan_hall");
  ob->set("short", "Kataans' Board of Despair");
  ob->set("long", 
   "The Kataans of our reality post stories of treachery and "
   "demonic myths for all to see here.\n");
}
