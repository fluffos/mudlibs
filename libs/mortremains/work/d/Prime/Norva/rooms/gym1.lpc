// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The Gym.");
  set("long", @ENDLONG
You stand in the middle of the Gym, surrounded by weight machines
and treadmills.
ENDLONG
  );
  set("item_desc", ([
  "machines#weight machines" : "There are too many to mention.\n",
  "treadmills" : "There are about 20 of them.  This place is huge.\n",
  ]) ) ;
  set("exits", ([
    "west" : ROOMS(gym),
   ]) ) ;
  set("objects", ([
   "guy" : MON(ripped),
  ]) ) ;
  ::create();
  reset();
}
