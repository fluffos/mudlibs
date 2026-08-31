#include <std.h>
#include <radyne.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("rogue");
   set_short("The Scout Hall");
   set_long("A basic room with no frills.  This is the Scout Hall.  "
            "Being here means absolutely nothing to a Scout.");
   ob = new(BBOARD);
   ob->set_max_posts(99);
   ob->set_board_id("scout");
   ob->set_location(ROOMS "rogue/scout/scout_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Scout Board");
   ob->set_long("Scouts come here to post amongst themselves.");
   ob->set_name("subclass");
   set_exits(([ "out" : ROOMS "rogue/scout/scout_join" ]));
}
