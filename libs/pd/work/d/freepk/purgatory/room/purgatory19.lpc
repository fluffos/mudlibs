#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("South Rigor Road");
     set_short("South Rigor Road");
     set_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, few adults venture so far south "
"%^BOLD%^%^BLACK%^of their city as this. A couple townsmen gather here to "
"%^BOLD%^%^BLACK%^protect their homes from invaders. The Purgatory square is "
"%^BOLD%^%^BLACK%^visible to the north. A pair of strange looking gates can be "
"%^BOLD%^%^BLACK%^seen to the south.");
     set_night_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
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
 set_exits( (["north" : ROOMS"purgatory14", 
              "south" : ROOMS"purgatory22"]) );



}
