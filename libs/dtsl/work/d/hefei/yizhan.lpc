
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","驿站");
  set ("long", @LONG
这里是合肥的驿站，给来往的官兵休息之用。有几个士兵正在这里
休息。旁边还喂养着几匹马，但是缺于照料，已经瘦骨嶙峋了。
LONG);

  set("exits", ([ 
   "south":__DIR__"xidajie3",
     ]));
  set("objects",([
	  __DIR__"npc/bing2":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

