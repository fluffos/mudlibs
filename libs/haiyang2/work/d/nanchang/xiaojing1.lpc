
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小径");
  set ("long", @LONG
这里是一条小径。南边就是南昌的北门了。这里的行人很多，都是
去南昌旅游的。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"beimen",
  "northeast":__DIR__"xiaojing2",
        ]));
  set("objects",([
	  __DIR__"npc/youke3":1,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

