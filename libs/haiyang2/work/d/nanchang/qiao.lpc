
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","桥");
  set ("long", @LONG
这里是一座桥上，从这里可以领略整个鄱阳湖的风光。桥下不断有小
船穿过，湖水看起来宛如一面镜子，铺在桥下。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"dongan1",
 "southdown":__DIR__"nanan2",
        ]));
  set("objects",([
	  __DIR__"npc/beauty":1,
	  "/clone/npc/man":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

