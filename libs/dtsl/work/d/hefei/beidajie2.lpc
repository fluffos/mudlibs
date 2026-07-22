
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是合肥的北大街，北边是合肥的北门。西边有一家小吃店，里
面传来了阵阵菜香，只见店小二在门口热情地招呼着来往的行人。有几
个穷苦百姓正坐在小吃店门口吃着馒头，衣衫褴褛，已经狼狈不堪了。
LONG);

  set("exits", ([ 
	  "north":__DIR__"beimen",
  "south":__DIR__"beidajie1",
  "west":__DIR__"xiaochidian",
       ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

