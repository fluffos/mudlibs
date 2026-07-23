
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","当铺");
  set ("long", @LONG
这里是南昌的当铺。老板冷冷地站在柜台后，对来典卖东西的人向
来毫不留情。有几个人站在那里，正在犹豫是否典卖手里的东西。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie2",
        ]));
  set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

