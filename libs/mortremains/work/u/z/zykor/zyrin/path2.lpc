#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short","Along the path to Ksyua village");
  set( "long", @EndText
The path narrows even further here, will the flora and fauna still astound
you. It is hard to believe that such a place could exist, with all the
diverse life around the immediate area. You feel almost compelled to touch
all the colorful flowers and plants as you walk by.

You hear creaking noises coming from the north.
EndText
  );
  set( "exits", ([
"northwest" : "path3",
"southwest" : "path1",
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
