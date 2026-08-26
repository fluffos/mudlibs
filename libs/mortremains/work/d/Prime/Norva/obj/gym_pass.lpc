#include <mudlib.h>

inherit OBJECT ;

void create() {
  seteuid(getuid()) ;
  set("short", "a gym pass") ;
  set("id", ({ "pass", "gym pass", "#GYM_PASS#" }) ) ;
  set("long", @ENDLONG
The gym pass reads:

              NAVAL STATION NORVA GYMNASIUM PRIVILEGE PASS
 --------------------------------------------------------------------------
                 -- Present pass upon entrance to Gym --
ENDLONG
  );
}

