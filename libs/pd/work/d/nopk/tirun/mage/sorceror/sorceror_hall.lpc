#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("mage");
   set_short("The Sorceror Hall");
   set_long("Welcome to the Sorceror Hall. The "
            "strong presence of magic can be felt all around you. "
            "The main, and only, passageway leads back into the "
            "heart of the mage tree. An old board floats in mid "
            "air.");
   set_smell("default", "The smell of magic and old books fills the room.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("sorc");
   ob->set_location(ROOMS "mage/sorceror/sorceror_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Sorceror Board of Psionics");
   ob->set_long("This old board floats in mid air.");
   ob->set_name("subclass");
    set_exits( 
         (["east" : ROOMS"mage/sorceror/sorceror_join"]) );
}
