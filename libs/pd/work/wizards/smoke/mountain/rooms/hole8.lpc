#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 0, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("There are cave paintings on the walls that seem to be drawn "
          "in blood. Aside from that, this room is pretty bare except "
         "for the fairly think layer of dust that covers it.");
 set_listen("default", "A low chanting can be heard from nearby.");
    set_items(([
({"paintings", "blood", "walls"}) : "There are some primative looking paintings
" 
         "here drawn on the wall here. They appear to be drawn in "
         "%^RED%^blood%^RESET%^ and a %^GREEN%^green%^RESET%^ which was probably made"
         "from some sort of plant. The pictures depict a pack of six humanoid"
         " creatures hunting a large, %^ORANGE%^brown%^RESET%^ primitive elephant.",
    ]));
    set_exits( ([ 
       "east" :  "/wizards/smoke/mountain/rooms/hole9",
       "southwest" :  "/wizards/smoke/mountain/rooms/hole7"
    ]) );
}
void reset() {
    if(!present("ogre"))
        new("/wizards/smoke/mountain/monsters/caveman")->move(this_object());
        new("/wizards/smoke/mountain/monsters/caveman")->move(this_object());
}
