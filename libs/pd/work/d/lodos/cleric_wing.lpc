#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
   object ob;
 ::create();
   set_short("Inside a temple to Omicron");
   set_long("You have entered the cleric's hall of health. "
            "This is the east wing of the hall of peace. "
            "The west wing is the monk hall. A passage leads "
            "west back into the hall of peace.");
   set_exits(([ "west" : ROOMS"peace_hall" ]));
   set_properties(([ "light" : 2, "town" : 1, "indoors" : 1,
     "building" : 1 ]));
   ob = new(BBOARD);
   ob->set_name("board");
   ob->set_id( ({ "board", "cleric board" }) );
   ob->set_board_id("cleric_board");
   ob->set_max_posts(75);
   ob->set_edit_ok("inferno");
   ob->set_location(ROOMS"cleric_wing");
   ob->set("short", "the clerics board of health");
   ob->set("long", "Clerics come here to post.");
}
