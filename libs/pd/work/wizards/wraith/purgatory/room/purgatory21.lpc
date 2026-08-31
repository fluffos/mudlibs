#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("Purgatory21w");
     set_short("Purgatory21w");
     set_long("%^BOLD%^%^WHITE%^West Mortis Road\n"
"%^BOLD%^%^BLACK%^A large black gatehouse stands in the middle of the road. "
"%^BOLD%^%^BLACK%^Past the gatehouse a large mountain cascades down the "
"%^BOLD%^%^BLACK%^landscape. Strange dots hovering over the very top of the "
"%^BOLD%^%^BLACK%^mountain can be seen from this road.");
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
 set_exits( (["gates" : ROOMS"gatehousew", 
              "east" : ROOMS"purgatory20"]) );



}
void reset() {
 ::reset();
  if (!present("skeleton", this_object()))
    new(MOBS"skeleton" )->move(this_object());

  if (!present("skeleton 2", this_object()))
    new(MOBS"skeleton" )->move(this_object());




}
