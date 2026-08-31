#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory17n");
     set_short("Purgatory17n");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^The castle towers over everything else even though it is "
"%^BOLD%^%^BLACK%^still a short walk north. A foolish child as wandered tward "
"%^BOLD%^%^BLACK%^the castle to see whats going on.");
     set_night_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Most people arent stupid enough to wander this far north. It "
"%^BOLD%^%^BLACK%^would be in everyone's best interest to turn around.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
    set_listen("default", "The wails of tortured souls are coming from the north.");
    set_smell("default", "A strange sent wafts in from the north.");
 set_exits( (["north" : ROOMS"purgatory24", 
              "south" : ROOMS"purgatory16"]) );



}

void reset() {
 ::reset();
  if (!present("skeleton", this_object()))
    new(MOBS"skeleton" )->move(this_object());

 if (!present("child", this_object()))
    new(MOBS"pmalechild" )->move(this_object());
}
