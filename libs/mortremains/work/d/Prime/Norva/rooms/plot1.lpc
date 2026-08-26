// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Parking Lot P-1, Naval Station Norva.");
  set("long", @ENDLONG
You stand in Parking Lot P-1 on the Naval Station Norva.  This appears to be
the main parking area for the Enlisted Club and Port Ops.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(portops),
    "east" : ROOMS(base13),
    "west" : ROOMS(base7),   
  ]) ) ;
  set("objects", ([
     "guy" : MON(motorcycle_guy) ,
  ]) ) ;
  ::create();
  reset();
}
