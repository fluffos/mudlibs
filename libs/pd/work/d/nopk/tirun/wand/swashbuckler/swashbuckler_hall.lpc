#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("wanderer");
   set_short("The Swashbuckler Hall");
   set_long("Welcome to the Swashbuckler Hall! Pictures of "
     "pirates, ships, and colorfully dressed adventurers doing various deeds "
     "fill the walls. The walls and ground are "
     "many various colours, ranging from green to blue resembling the sea.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("swashbuckler");
   ob->set_location(ROOMS "wand/swashbuckler/swashbuckler_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Swashbuckler Board of Adventure");
   ob->set_long("Swashbucklers come here to post amongst themselves.");
   ob->set_name("subclass");
   set_exits(([ "out" : ROOMS "wand/swashbuckler/swashbuckler_join" ]));
}
