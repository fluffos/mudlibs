#include <mudlib.h>

inherit ROOM;

void create() {
  seteuid(getuid()) ;
  set("short", "A pier.") ;
  set("long", @ENDLONG
You are on a long pier.
ENDLONG
  );
  set("exits", ([
  ]) ) ;
  set("light",1);
  ::create() ;
  reset() ;
}

