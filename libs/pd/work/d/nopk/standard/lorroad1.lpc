#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "The southern end of Lore Road");
    set("day long", 
      "The southern end of Lore Road goes into a semi residential area of Tirun. "
      "Lore Road only goes north, but feeds into Honin Road south. The road "
      "leading north is an old dirt road. Huts line the road on both the eastern "
      "and western sides.");
    set("night long",
      "The area north of Lore Road is residential, huts line the dirt road on "
      "both eastern and western sides. Most of the resisdents of the huts have "
      "most likely gone to bed by now. The dirt road leads only north, this is "
      "the furthest southern end of Lore Road.");
    set_items(
	(["road" : "Lore Road goes north.",
	  "huts" : "They look like peasant's huts."
	  ]) );
    set_exits( 
	      (["north" : ROOMS"lorroad2",
		"south" : ROOMS"whonin3"]) );
}

