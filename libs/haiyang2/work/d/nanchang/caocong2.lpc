
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草丛");
  set ("long", @LONG
这里是个草丛，四面都望不见出路。这里没什么人。这里静悄悄，
不知道有没有盗贼。
LONG);

  set("exits", ([ 
 "west":__DIR__"caocong1",
 "east":__DIR__"caocong2",
      ]));
set("objects",([
	__DIR__"npc/she":2,
	]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

