// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Pier 2 South.");
  set("long", @ENDLONG
You stand on the south end of Pier 2 on Naval Station Norva.
The pier extends further to the north.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
     "north" : ROOMS(pier2-2),   
     "south" : ROOMS(base11),   
  ]) ) ;
  ::create();
  reset();
}
