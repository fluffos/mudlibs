// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Parking Lot P-2, Naval Station Norva.");
  set("long", @ENDLONG
You stand in Parking Lot P-2 on the Naval Station Norva.  This appears to be
the main parking area for the Enlisted Recreation Center to the north.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(rec_cen),
    "east" : ROOMS(base23),
    "west" : ROOMS(base13),
 ]) ) ;
  ::create() ;
   reset() ;
}
