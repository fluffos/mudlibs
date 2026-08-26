// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Main Gate");
  set("long", @ENDLONG
You are at the Main Gates of Naval Station Norva.
There is a large metal fence surrounding the base and a guard shack
where the sentries can allow access to authorized personnel.
ENDLONG
  );
  set("item_desc", ([
   "fence" : "You probably wouldn't be able to climb it or anything..\n",
    "guard shack" : "It's where sentries tend to sleep.",
    "shack" : "It's where sentries tend to sleep.",
  ]) ) ;
  set("exits", ([
    "east" : ROOMS(base1),
  ]) ) ;
  set("objects", ([
    MON(sentry) : 2,
  ]) ) ;
  ::create();
  reset();
}
