#include <config.h>
#include "zyrin.h"
#include <mudlib.h>

inherit ROOM;


void create(){
  ::create();
    seteuid(getuid());
  set( "light", 1 );
set("short","Path to Ksyua village");
  set( "long", @EndText
The path turns into more of a fine sandy dirt and the treeline receeds a
a few feet back. Short rays of light peek through the treetops, giving this
path an erie feeling to it. Small, red beaty eyes leer at you from behind
bushes and strange and colorful birds sing their strange song as you walk
past them. To the east you can see the path widens into a clearing and
further north is a small village.
EndText
  );
  set( "exits", ([
"north" : "vilenter",
"southeast" : "path2"
  ]) );
   set ("item_desc", ([
   ]) );
reset();
}
