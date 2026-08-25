

#include "path.h"
inherit "/std/room";
object man,woman;

void reset()
{
    if (!man)
    {
	man = clone_object(NPCS+"man");
	man->move(this_object());
    }
    if (!woman)
    {
	woman = clone_object(NPCS+"woman");
	woman->move(this_object());
    }
}

void setup() {
    set_light(80);
    set_short("Market Street");
    set_zone("town");
    set_long(
      "You are on a wide street in the small coastal town of Belgar's "
      "Haven. The street is paved with dirt, and you can tell that it is "
      "well worn, for there are deep ruts where the wheels of wagons pass "
      "through here. However, there don't seem to be any wagons now. The "
      "town is a quiet place now. There is none of the bustling about that "
      "you would expect in a town, even one this small. You don't even see "
      "many people here...it seems like the town of Belgar's Haven is on "
      "its last legs, and dying. "
      "You can see that the street leads off to the South, and the gates of "
      "the city open up to the Northeast. To the East is a small tavern.\n");

    add_property("no_undead",1);

    add_exit("north",HERE+"con01","path");
    add_exit("south", HERE+"intersection", "path");
    add_exit("east", HERE+"tavern", "door");

    add_item("street", 
      "The street is dirt-paved and worn, although most of the tracks are "
      "old. It doesn't see much use anymore.\n");
    add_item("people",
      "You can't see any people on the road here right now.\n");
    add_item("tavern",
      "The tavern looks pretty run-down, and is not very large either. It "
      "has a look of cleanliness, though, and is surprisingly well kept.\n");
}

dest_me()
{
    if (man)
	man->dest_me();
    if (woman)
	woman->dest_me();
}
