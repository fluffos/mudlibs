
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","药铺");
  set ("long", @LONG
这里是一家药铺。这家药铺在合肥有很好的声誉，再加上是战乱年
代，所以这里的生意一直很好。
LONG);

  set("exits", ([ 
	  "southeast":__DIR__"xidajie1",
   ]));

  set("objects",([
	  __DIR__"npc/ding":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

