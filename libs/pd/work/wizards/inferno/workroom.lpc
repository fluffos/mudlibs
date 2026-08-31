#include <locations.h>
#include <locations.h>
#include <std.h>
inherit ROOM;

void create() {
 object ob;
 ::create();
   set_short("Within the folds of time");
   set_long("%^BOLD%^%^WHITE%^"
     "T%^BLACK%^i%^WHITE%^m%^BLACK%^e shifts and ripples about your body "
     "like a calming wave. "
     "Glimpses of the past and the future flash before your eyes. "
     "%^RESET%^%^ORANGE%^The air is very humid and very hot. "
     "Dizzyness overcomes your body. %^BOLD%^"
     "Shimmering rift-like doorways lead various directions.%^RESET%^"
   );
   set_listen("default", "Hushed voices fill the air.");
   set_listen("voices", "They sound like they come from far away.");
   set_exits(([
     "out" : SQUARE_LOC,
     "up" : "/wizards/inferno/portals",
     "tower" : "/wizards/inferno/tower",
     "down" : "/wizards/inferno/bank",
     "north" : "/wizards/inferno/lounge",
     "south" : "/wizards/inferno/outfit",
     "east" : "/wizards/inferno/cafe",
     "lodos" : "/d/lodos/square"
   ]));
   set_property("no teleport", 1);
   ob = new(BBOARD);
   ob->set_name("forge");
   ob->set_location("/wizards/inferno/workroom");
   ob->set_id( ({ "board", "forge", "iron board" }) );
   ob->set_board_id("forge_ideas");
   ob->set_max_posts(50);
   ob->set_short("an iron board");
   ob->set_long("The iron forge of Inferno.");
}

int check_up() {
   if ("/wizards/inferno/tower"->query_exit("up") == "/d/standard/void")
   "/wizards/inferno/tower"->create();
   return 0;
}

void init() {
 ::init();
   add_action("check_up", "tower");
}
