#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory2w");
     set_short("Purgatory2w");
     set_long("%^BOLD%^%^WHITE%^East Mortis Road\n"
"%^BOLD%^%^BLACK%^Traveling along Mortis Road, children are playing alongside "
"%^BOLD%^%^BLACK%^the gutters. The townspeople keep an eye out for their "
"%^BOLD%^%^BLACK%^charges. To the south there is a strange shop with one %^RESET%^%^ORANGE%^rusted "
"%^BOLD%^%^BLACK%^blade hanging on a sign out front.  A large statue can be "
"%^BOLD%^%^BLACK%^seen to the west, with open road to the east.");
     set_night_long("%^BOLD%^%^WHITE%^West Mortis Road\n"
"%^BOLD%^%^BLACK%^Traveling along Mortis Road, only the dumber children and "
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
 set_exits( (["east" : ROOMS"purgatory5", 
              "west" : ROOMS"purgatorysquare",
              "north" : ROOMS"ptavern",
              "south" : ROOMS"pshop"]) );



}
