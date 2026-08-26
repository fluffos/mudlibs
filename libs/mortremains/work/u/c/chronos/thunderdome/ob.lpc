/* Thunderdome Observation Room */
#include <mudlib.h>
#include "./td.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("short", "The ThunderDome Observation Room.") ;
  set("long", @ENDLONG
In this room, you can view all the events that take place in the ThunderDome
safely.
ENDLONG
  ) ;
  set("exits", ([
     "west" : TD+"main"
  ]) ) ;
  set("safe", 1) ;
  ::create() ;
  reset() ;
}
