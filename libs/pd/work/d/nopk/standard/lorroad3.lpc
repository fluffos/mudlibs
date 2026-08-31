#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_short("The north end of Lore Road");
   set_day_long(
     "The furthest north end of the dirt road, Lore Road, ends at a hut. The "
     "hut's doorway faces towards the street, giving a good view down the entire "
     "road from inside. The dirt road leads only south now. Far south, Lore Road "
     "feeds into Honin Road."
   );
   set_night_long(
     "Night falls upon the north end of Lore Road. This dirt road ends at the "
     "front of a hut at the far north end of the path. The hut faces down the "
     "street, giving an excellent view down the entire road from inside the hut. "
     "Far to the south, past many sleepy huts, Lore Road feeds into the larger "
     "Honin Road."
   );
   set_items(([
     "hut"   : "A small hut, not unlike the others around it.",
     "honin" : "Honin Road can be seen far to the south.",
     "road"  : "Lore Road feeds into Honin further south."
   ]));
   set_exits(([
	"south" : ROOMS"lorroad2",
        "enter" : ROOMS"monk"
   ]));
}
