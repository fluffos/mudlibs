
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是合肥的南大街。这里的行人不是很多。南边可以望到合肥的
南门了。只见一股股人群从南边涌来，合肥的情况目前还比较稳定，所
以很多人都到这里逃难来了。
LONG);

  set("exits", ([ 
	  "north":__DIR__"nandajie1",
  "south":__DIR__"nandajie3",
   ]));
  
  set("objects",([
     __DIR__"npc/daoke":1,
   ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

