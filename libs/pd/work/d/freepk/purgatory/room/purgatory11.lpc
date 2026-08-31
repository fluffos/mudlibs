#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("North Rigor Road");
     set_short("North Rigor Road");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling on Rigor Road, the children have scampered off as "
"%^BOLD%^%^BLACK%^if afraid of what lies ahead. In the distance to the north a "
"%^BOLD%^%^BLACK%^large castle can be seen rising from the darkness. Far to the "
"%^BOLD%^%^BLACK%^south lies the square.");
     set_night_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Only the townsmen of Purgatory travel this far north, for "
"%^BOLD%^%^BLACK%^anybody else it would mean certain death at night....");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"purgatory16", 
              "south" : ROOMS"purgatory6"]) );



}

void reset() {
 ::reset();
  if (!present("man", this_object()))
    new(MOBS"townsman" )->move(this_object());

 if (!present("man 2", this_object()))
    new(MOBS"townsman" )->move(this_object());
}
