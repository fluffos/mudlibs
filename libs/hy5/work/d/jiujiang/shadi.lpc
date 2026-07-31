
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","沙地");
  set ("long", @LONG
这里是一片沙地。这里没有什么人。地上杂草丛生，只有几块碎石
头散乱地放在地上。向远处望去，可以看到几个破旧的渔村。
LONG);

  set("exits", ([ 

  "south":__DIR__"xiaolu2",
         ]));
  set("objects",([
	  __DIR__"obj/stone":2,
	  ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}

