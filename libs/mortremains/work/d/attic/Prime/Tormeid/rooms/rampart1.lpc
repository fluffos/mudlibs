#include <mudlib.h>
#include "../defs.h"

inherit ROOM; 
inherit DOORS;

void create() {
  seteuid(getuid());
  set("short", "On the ramparts.") ;
  set("long", @ENDLONG
On the ramparts above the gate.
ENDLONG
  );
  set_outside("Light") ;
  set("exits", ([
  "south" : ROOMS(rampart0),
  "north" : ROOMS(rampart2),
    "east" : ROOMS(uhall1),
  ]) );
  set("search_desc", ([
  "gate" : "How do you intend to search the gate from up here?\n",
  ]) ) ;
  set("item_desc", ([
   "gate" : "You are directly above the gate.\n",
  ]) ) ;
/* Just a reminder for me.  
//  create_door() -   arguments:  "west", "east", "It's a wooden door.", 
//  "closed" "grey_key", 15);
*/
  create_door("east", "west", "It's a strong wooden door.", "closed", "--", 40) ;
  ::create();
}
