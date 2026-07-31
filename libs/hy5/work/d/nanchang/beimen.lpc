
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"北门"NOR);
  set ("long", @LONG
这里是南昌的北门。南昌是旅游胜地，所以这里的行人很多。这里
有两个官兵，在检查着来往的行人。
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie1",
  "north":__DIR__"lvyinlu",
  "northeast":__DIR__"xiaojing1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

