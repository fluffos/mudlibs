
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器店");
  set ("long", @LONG
这里是兵器店，这里打造的兵器质量优良，价格便宜。铁匠在那里
满头大汗地挥舞着铁锤，只听乒乓声中，又一件兵器打造好了。
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie2",
         ]));

set("objects",([
	__DIR__"npc/tiejiang":1,
//	__DIR__"obj/tiekuai":2,
	]));
  
  set("valid_startroom", 1);
  setup();
 
}

