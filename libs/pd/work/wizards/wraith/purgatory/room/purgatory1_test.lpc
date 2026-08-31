#include <std.h>
#include <purgatory.h>
inherit ROOM;
void create() {
    ::create();
     set_properties( ([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "town"        : 1,
        "no steal"    : 1,
]) );
     set_name("Purgatory6n");
     set_short("Purgatory6n");
     set_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
              "%^BOLD%^%^BLACK%^Traveling north along Rigor Road, children are playing "
              "%^BOLD%^%^BLACK%^alongside the gutters. The townspeople keep an eye out for "
              "%^BOLD%^%^BLACK%^their charges. To the west there is a strange shop with human "
              "%^BOLD%^%^BLACK%^limbs hanging in the windows. To the east there is a building "
              "%^BOLD%^%^BLACK%^in the recesses of a shadow, what could be there? A large statue can be "
              "%^BOLD%^%^BLACK%^seen to the south, with open road to the north.");
     set_night_long("%^BOLD%^%^WHITE%^North Rigor Road\n"
                    "%^BOLD%^%^BLACK%^Traveling north along Rigor Road, only the dumber children"
                    "%^BOLD%^%^BLACK%^ and parents have stayed out to this late hour."
                    "%^BOLD%^%^BLACK%^ Everything is shrouded in darkness.");
     set_exits( ([ "south" : ROOMS+"purgatorysquare", "north" : ROOMS+"purgatory6", ]) );
 }
void reset() {
 ::reset();
  if (!present("child", this_object()))
    new(MOBS"pchild")->move(this_object());
 if (!present("woman", this_object()))
    new(MOBS"townswoman")->move(this_object());
}
