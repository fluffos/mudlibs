
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"西门"NOR);
  set ("long", @LONG
这里是合肥的西门。这里的行人不少。这里有几个官兵正在检查来
往的百姓。趁着如今混乱，有很多官兵也在这里敲诈老百姓的钱财。
LONG);

  set("exits", ([ 

  "east":__DIR__"xidajie3",
  "southwest":__DIR__"wguanlu1",
       ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

