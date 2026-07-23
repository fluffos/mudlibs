
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是南昌的南大街。南边是南昌的南门了。东边有一家钱庄。几
个游客从你的身旁走过，正在谈论着鄱阳湖的风光。只见一辆大马车从你
的身旁驶过，看样子是去李财主家比武招亲去了。
LONG);

  set("exits", ([ 

  "south":__DIR__"nanmen",
  "north":__DIR__"nandajie1",
  "east":__DIR__"qianzhuang",
        ]));
  set("objects",([
	  __DIR__"npc/man":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

