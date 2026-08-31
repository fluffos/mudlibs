#include <locations.h>
#include <std.h>
inherit ROOM;
void create() {
::create();
set_short("Event room.");
set_long("My event room, go away!! \n\n"
"Mobs involved: "
"ghoul, ghost, goblin, witch, scarecrow, spook, pumpkinhead \n"
"Alias commands: \n"
"halloweenbegin     holloweenfirst     holloweensecond     "
"halloweenthird     holloweenfourth     holloweenfifth     holloweensixth \n\n"
);
   set_properties(([
        "light" : 1,
        "night light" : 1,
        ]));
    set_exits( ([ 
         "down" :  SQUARE_LOC,
         "helgrath" :  "/d/helgrath/rooms/wilndursquare",
         "shadow" :  "/d/shadow/rooms/tene10",
         "lodos" :  "/d/lodos/square",
         "roston" : "/d/roston/rooms/roston"
 ]) );
}
