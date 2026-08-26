// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

object runner ;
inherit ROOM ;

void create() {
  seteuid(getuid()) ;
  set("author", "chronos");
  set("light", 1) ;
  set("short", "The east side of the track.");
  set("long", @ENDLONG
You stand on the east side of a mile-long track used for PT on the base.
ENDLONG
  );
  set("item_desc", ([
  ]) ) ;
  set("exits", ([
    "north" : ROOMS(base5),
    "west" : ROOMS(track1),
  ]) ) ;
  ::create();
  reset();
}

void reset() {
  if (!runner) {
    runner=clone_object(MON(runner)) ;
    runner->move(this_object()) ;
    runner->run_your_ass_off() ;
  }
  ::reset() ;
}
