#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     add_pre_exit_function("stairs","go_stairs");
     set_name("guest10");
     set_short("The Guest Quarters");
     set_long("%^ORANGE%^The Guest Quarters are where many of the visiting Royal "
"%^ORANGE%^families live while they enjoy their stay in Purgatory. On "
"%^ORANGE%^either side of this hallway hang many tapestries to make the "
"%^ORANGE%^families feel more at home. A small walkway leads to the "
"%^ORANGE%^north and northwest. Stairs trail their way back to the "
"%^ORANGE%^castle grounds.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"guest11",
              "northwest" : ROOMS"guest9",
              "stairs" : ROOMS"castle13"]) );

    set_items( ([
        "tapestry" : "%^BOLD%^%^ORANGE%^This fine tapestry brings to light the playfulness of childhood.",
        "walkway" : "%^BOLD%^%^BLACK%^Many dark stones form a walkway into the guest quarters, years of use have polished the stone to a high sheen."
      ]) );

}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }

