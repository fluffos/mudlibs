#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory16n");
     set_short("Purgatory16n");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Looming larger in the north, the castle dosent look like the "
"%^BOLD%^%^BLACK%^prime vacation spot for anybody. It might be a good idea to "
"%^BOLD%^%^BLACK%^turn back now.");
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

 set_exits( (["north" : ROOMS"purgatory17", 
              "south" : ROOMS"purgatory11"]) );



}
