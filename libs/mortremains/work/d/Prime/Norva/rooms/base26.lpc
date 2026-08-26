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
Pier 3 is to the north and Saipan Avenue is to the south.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(pier3-1),
    "south" : ROOMS(base24),    
    "east" : ROOMS(base27),
    "west" : ROOMS(base25),
  ]) ) ;
  ::create();
  reset();
}
