
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"北门"NOR);
  set ("long", @LONG
这里是合肥的北门。这里的行人不少。这里有几个官兵正在检查来
往的百姓。旁边还站着几个军官，耀武扬威地站在那里，不停地指手画
脚。
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie2",
  "north":"/d/cangzhou/nroad3",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

