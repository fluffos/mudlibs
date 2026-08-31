#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("North Rigor Road");
     set_short("North Rigor Road");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, children are playing alongside "
"%^BOLD%^%^BLACK%^the gutters. The townspeople keep an eye out for their "
"%^BOLD%^%^BLACK%^charges. To the west there is a strange shop with human limbs "
"%^BOLD%^%^BLACK%^hanging in the windows. To the east there is a building in "
"%^BOLD%^%^BLACK%^the recesses of a shadow, what could be there? A large statue can be "
"%^BOLD%^%^BLACK%^seen to the south, with open road to the north.");
     set_night_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, only the dumber children and "
"%^BOLD%^%^BLACK%^parents have stayed out to this late hour. Everything is "
"%^BOLD%^%^BLACK%^shrouded in darkness.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "plain"       : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"purgatory6", 
              "south" : ROOMS"purgatorysquare"]) );



}
