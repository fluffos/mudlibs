#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("Large bugs are scattered throughout the cavern. Some arctic ferns "
          "grow here despite the cold. Interesting rock formations line the "
          "walls. Loose rocks litter the floor, which has a sharp slant to it.");
 set_listen("default", "Wind whistles through the cavern.");
    set_items(([
({"bugs", "walls"}) : "Some nasty looking bugs climb the walls making some wierd"
	" noises.",
({"fern", "ferns"}) : "The arctic ferns can grow in the most extreme temperatures."
	" The plant is all white and appears very brittle.",
({"rock", "rocks"}) : "The rock formations inside the cavern are amazing. They "
	"stretch up to the top of the mountain. It appears way to steep to climb."	
    ]));
    set_exits( ([ 
       "north" :  "/wizards/smoke/mountain/rooms/5",
       "southeast" :  "/wizards/smoke/mountain/rooms/3"
    ]) );
}
void reset() {
    if(!present("goat"))
        new("/wizards/smoke/mountain/monsters/mgoat")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mtroll")->move(this_object());
}
