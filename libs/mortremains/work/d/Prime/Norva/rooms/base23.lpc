// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Saipan Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Saipan Avenue on Naval Station Norva.
The piers are to the north, and a parking lot is to the west.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base24),
    "south" : ROOMS(base22),    
    "west"  : ROOMS(plot2),
  ]) ) ;
  ::create();
  reset();
}


