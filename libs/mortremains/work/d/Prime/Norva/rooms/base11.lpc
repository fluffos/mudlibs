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
To the north is Pier 2.
To the south lies Pacific Avenue.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(pier2-1) ,
    "south" : ROOMS(base12),
    "east"  : ROOMS(base25),
    "west" : ROOMS(base10),
  ]) ) ;
  set("objects", ([
    "sailor" : MON(drunk_sailor),
  ]) ) ;
  ::create();
  reset();
}
