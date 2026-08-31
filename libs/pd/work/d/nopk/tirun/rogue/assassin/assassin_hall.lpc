#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("rogue");
   set_short("The assassin hall");
   set_long("Hitmen, assassins, murderers, whatever you call them, "
     "they come here to talk. Welcome to the Assassin Hall. "
     "The doorway leads out, back into the rogue hall.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("assassin");
   ob->set_location(ROOMS "rogue/assassin/assassin_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Assassination Board");
   ob->set_long("Assassins come here to post amongst themselves.");
   ob->set_name("subclass");
   ob->set_edit_ok(({"nulvect"}));
   set_exits(([ "out" : ROOMS "rogue/assassin/assassin_join" ]));
}
