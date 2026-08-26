
// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Main Street, Naval Station Norva.");
  set("long", @ENDLONG
You are on the main street on Naval Station Norva.
The main gate lies to the west, and this road continues to the east,
heading towards the piers.
To the south is Independence Street.
ENDLONG
  );
  set("item_desc", ([    
  ]) ) ;
  set("exits", ([
    "east" : ROOMS(base6),
    "west" : ROOMS(maingate),
    "south" : ROOMS(base2),
  ]) ) ;
  ::create();
  reset();
}              
