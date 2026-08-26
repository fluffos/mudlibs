#include <mudlib.h>

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("light", 1) ;
  set("short", "Default room") ;
  set("long", @ENDLONG
  default room.
ENDLONG
  );
  ::create() ;
  reset() ;
}
