// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Atlantic Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Atlantic Avenue on Naval Station Norva.
Pier 5 lies to the north, and the street leads back to the west.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(pier5-1),
    "west" : ROOMS(base29) ,
  ]) ) ;
  ::create();
  reset();
}
