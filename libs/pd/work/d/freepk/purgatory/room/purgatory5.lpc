#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("East Mortis Road");
     set_short("East Mortis Road");
     set_long("%^BOLD%^%^WHITE%^East Mortis Road\n"
"%^BOLD%^%^BLACK%^Traveling along Mortis Road, children are playing alongside "
"%^BOLD%^%^BLACK%^the gutters. The townspeople keep an eye out for their "
"%^BOLD%^%^BLACK%^charges. An odd looking shop stands to the north, animal "
"%^BOLD%^%^BLACK%^parts and other strange things hang from the windows. To the "
"%^BOLD%^%^BLACK%^south rises a shop just as strange looking, with things better left "
"%^BOLD%^%^BLACK%^unsaid hanging in its windows. Rigor road leads on east and west.");
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
 set_exits( (["east" : ROOMS"purgatory10", 
              "west" : ROOMS"purgatory4",
              "south" : ROOMS"pstoneshop",
              "north" : ROOMS"poilshop"]) );



}
