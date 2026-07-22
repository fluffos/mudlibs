
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","戏院");
  set ("long", @LONG
这里是一家戏院，平时有很多人来这里看戏。据说今天正在上演好
戏。现在这里做了很多人，但比较以前，还是逊色了不少。戏院里有很
多卖东西的小贩，趁着戏还没开始，这里充满了叫卖的声音，乱成了一
片。
LONG);

  set("exits", ([ 
	  "west":__DIR__"nandajie3",
  ]));

set("objects",([
	__DIR__"npc/xiyou":1,
	]));
  set("valid_startroom", 1);
  setup();
 
}

