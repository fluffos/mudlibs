#include <mudlib.h>
#include "../defs.h"

inherit ROOM; 
inherit DOORS;

void create() {
  seteuid(getuid());
  set("short", "A passageway.");
  set("long", @ENDLONG
Three passageways lead out of this area, one southwest, one south, and
one southeast. 
ENDLONG
  );
  set("smell", ([ "default" : "You can smell dried blood.\n",
  ]) );
  set("listen", ([ 
  "default" : "You can hear some screaming to the south.\n",
  ]) );
  set("exits", ([
    "south" : ROOMS(temple11),
   "southwest" : ROOMS(temple9),
  "southeast" : ROOMS(temple8),
  ]) );
  set("objects", ([
  "warrior" : MON(henchman1),
  "dog" : MON(wardog),
  ]) ) ;
/* Just a reminder for me.  
//  create_door() -   arguments:  "west", "east", "It's a wooden door.", 
//  "closed" "grey_key", 15);
*/
  create_door("south", "north", "It's a sturdy oak door",
    "locked", "Iron_key", 32);
  ::create();
}
