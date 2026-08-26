
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   

  set("author", "Gendor");  

  set("light", 1);


  set("short", "The town square.");
  
set("long", @ENDLONG
Standing here, you can see all of the town.  To the north, is a pub.  There is a 
lot of noise coming from the pub.  To the east, is a few houses and a lake.  To 
the south, is a forest path.  West of here, there is a temple and a rather large
house.
ENDLONG
   );

  set("item_desc", ([
  "pub" : "Dorothy's Place is packed with people.\n",
    "lake" : "Sunlight sends sparkles dancing over the crystal-clear water.\n",
	"path" : "A path leads south into the forest.\n",
	"temple" : "A large shrine rises into the sky, looming over the town like a vulture awaiting the death of the misfortunate.\n",
	"house" : "A house like this must belong to someone important.\n",
   ]) );
  
  set("smell", ([
    "default" : "You smell a sickening odor in the air.\n",
    "odor"  : "The air is leaden with the disgusting stench of a burned meat.\n",
    
  ]) );
  set("listen", ([
   "default" : "The sounds of celebration emanating from the pub intrigue you.\n",
    
  ]) );
  
  set("exits", ([
    
    "north" : ROOMS(pub),
    "south" : ROOMS(outskirts),
		"east" : ROOMS(lake),
    "west" : ROOMS(maytem),


  ]) );
set("objects", ([
    MON(child) : 1,
		MON(dog) : 1,
  ]) );    
  ::create();  
}
