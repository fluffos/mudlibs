#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
   object ob;
 ::create();
   set_short("Inside a temple to Omicron");
   set_long("You have entered the great hall of monks. This is the "
            "west wing of the hall of peace. To the far east, "
            "past the hall of peace, is the cleric wing. A passageway "
            "leads east, back into the hall of peace.");
   set_exits(([ "east" : ROOMS"peace_hall" ]));
   ob = new(BBOARD);
   ob->set_name("board");
   ob->set_id( ({ "board", "monk_board" }) );
   set_property("light", 2);
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   ob->set_board_id("monk_board");
   ob->set_max_posts(75);
   ob->set_edit_ok("inferno");
   ob->set_location(ROOMS"monk_wing");
   ob->set("short", "the monks board of faith");
   ob->set("long", "Monks come here to post.");
}
