// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "Independence Avenue, Naval Station Norva.");
  set("long", @ENDLONG
You are on Independence Avenue on Naval Station Norva.
The Bachelor Enlisted Quarters are to the east and the Bachelor
Officer Quarters are to the west.
ENDLONG
  );
  set("exits", ([
    "north" : ROOMS(base2),
    "south" : ROOMS(base4),
    "east"  : ROOMS(beq),
    "west"  : ROOMS(boq),
  ]) ) ;
  ::create();
  reset();
}
