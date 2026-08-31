#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory24n");
     set_short("Purgatory24n");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Polished and chisled obsidian make up the castle gates, which "
"%^BOLD%^%^BLACK%^capture some unseen light. Beyond the gates a  menacing "
"%^BOLD%^%^BLACK%^castle sprouts from the ground, looking like someone had "
"%^BOLD%^%^BLACK%^tunneled into a huge mountain of black stone. A sense of doom "
"%^BOLD%^%^BLACK%^and utter hopelessness creeps outward from the stones. ");
     set_night_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Barely visible in the dark of night, an Obsidian Castle "
"%^BOLD%^%^BLACK%^sprouts from the ground to the north. A pair of gates twinkle "
"%^BOLD%^%^BLACK%^at the edge of vision.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
        "no peace"    : 1,

]));
    set_listen("default", "The wails of tortured souls are coming from the north.");
    set_smell("default", "A strange sent wafts in from the north.");
 set_exits( (["gates" : ROOMS"gatehousen", 
              "south" : ROOMS"purgatory17"
]) );



}

void reset() {
 ::reset();
  if (!present("skeleton", this_object()))
    new(MOBS"skeleton" )->move(this_object());

 if (!present("skeleton 2", this_object()))
    new(MOBS"skeleton" )->move(this_object());

 if (!present("skeleton 3", this_object()))
    new(MOBS"skeleton" )->move(this_object());


}
