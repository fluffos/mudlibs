#include "../defs.h"
inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Gendor");

  set("light", 0);


  set("short", "In the temple.");

set("long", @ENDLONG
The inside of the temple is somthing out of your worst nightmare.  Paintings 
of the death and total destruction of humanoids line the walls.  Skeletal
warriors feasting apon flesh of the fallen grace most paintings.
On one wall, a mural depicting a demonic horde advancing apon a town
can be seen.  The tiles of the floor are a blood-crimson color, while,
on the ceiling, a portrait of a dark figure wrapped in black shrouds
can be seen.
ENDLONG
   );

  set("item_desc", ([
				"paintings" : "These paintings are of death and destruction.\n",
				"mural" : "A large battallion of demons is ravaging a town.\n",
				"tiles" : "Blood colored tiles.\n",
				"ceiling" : "A portrait of a figure, wrapped in dark robes.\n"         
   ]) );

  set("smell", ([
    "default" : "The smell in here is almost unbearable.\n",

  ]) );
  set("listen", ([
   "default" : "You hear the sounds of a ceremony coming through the
southern wall.\n",

  ]) );

  set("exits", ([
    "east" : ROOMS(maytem),
    "west" : ROOMS(temple1),

          ]) );
set("objects", ([
    MON(wounded2) : 1,
  ]) );


  ::create();
}