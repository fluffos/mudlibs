// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Pacific Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Pacific Avenue on Naval Station Norva.
The Recreation Center is to the east and the piers are to the north.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base11),
    "south" : ROOMS(base13),
    "east"  : ROOMS(rec_cen),  
  ]) ) ;
  ::create();
  reset();
}
