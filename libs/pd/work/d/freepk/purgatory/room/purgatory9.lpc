#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("South Rigor Road");
     set_short("South Rigor Road");
     set_long("%^BOLD%^%^WHITE%^South Rigor Road\n"
"%^BOLD%^%^BLACK%^Traveling along Rigor Road, another batch of those strange "
"%^BOLD%^%^BLACK%^children poke along the gutter looking for something to play "
"%^BOLD%^%^BLACK%^with. The Purgatory square is visible to the north.");
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
 set_exits( (["north" : ROOMS"purgatory8", 
              "south" : ROOMS"purgatory14"]) );



}

