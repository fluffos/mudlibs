#include <std.h>
#include <radyne.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("rogue");
   set_short("The thieves hall");
   set_long("You have entered the Thief Hall. This is "
      "simply a small room of a shack. This place has been "
      "set up as a place of practice for thieves.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("thief");
   ob->set_location(ROOMS "rogue/thief/thief_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Theft Board");
   ob->set_long("Thieves come here to post amongst themselves.");
   ob->set_name("subclass");
   set_exits(([ "out" : ROOMS "rogue/thief/thief_join" ]));
}
