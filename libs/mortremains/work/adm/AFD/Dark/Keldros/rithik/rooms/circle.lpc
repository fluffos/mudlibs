#include "../defs.h"

inherit ROOM;   

void create() {
  seteuid(getuid());   
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The southernmost portion of the path.");
set("long", @ENDLONG
Victory lane stops here, in a circular court.  Houses line the outside 
of the court in an unorganized fashion.  But the houses are not what 
have gotten your attention.  In the center of the circle a tall crucifix 
has been erected, pinned on the cross is an elf, bloodied.  You believe
this may be the town's public execution area.
ENDLONG
);

set("item_desc", ([
"elf" : "This elf has been tortured to death, he once was a handsome humanoid
dressed in fine cloth garb.\n",

"court" : "This is a circular clearing in the town with houses lining the outside 
of the lane.\n",

"circle" : "This is a circular clearing in the town with houses lining the outside 
of the lane.\n",


"crucifix" : "It is a tall wooden cross built to torture a prisoner to death by nailing 
his wrists and ankles to the thick wood it is built of.\n",

"cross" : "It is a tall wooden cross built to torture a prisoner to death by nailing 
his wrists and ankles to the thick wood it is built of.\n",

"houses" : "These homes look quite well-kept and quite quaint.\n",

]) );
set("objects", ([ MON(igor) : 1, ]));
  set("exits", ([ "north" : ROOMS(lane), ]) );
  ::create();  
}
