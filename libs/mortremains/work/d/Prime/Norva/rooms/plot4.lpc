// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Parking Lot P-3, Naval Station Norva.");
  set("long", @ENDLONG
You stand in the south end of Parking Lot P-3 on the Naval Station Norva.  
This appears to be the main parking area for the Gymnasium.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(plot3),
    "south" : ROOMS(track1),   
    "east" : ROOMS(base5),
  ]) ) ;
  ::create();
  reset();
}
