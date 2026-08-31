#include <std.h>
#include <radyne.h>
inherit HALL;
void create() {
 object ob;
 ::create();
   set_type("rogue");
   set_short("The Thug Hall");
   set_long("A basic room with no frills.  This is the Thug Hall.  "
            "Being here means absolutely nothing to a thug.");
   ob = new(BBOARD);
   ob->set_max_posts(70);
   ob->set_board_id("thug");
   ob->set_location(ROOMS "rogue/thug/thug_hall");
   ob->set_id(({ "board" }));
   ob->set_short("The Thug Board");
   ob->set_long("Thugs come here to post amongst themselves.");
   ob->set_name("subclass");
   set_exits(([ "out" : ROOMS "rogue/thug/thug_join" ]));
}
