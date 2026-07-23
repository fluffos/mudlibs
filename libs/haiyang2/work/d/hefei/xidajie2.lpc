
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是合肥的西大街。往西走就是合肥的西门了。南边有一家裁缝
店。只见西边有几个官兵正对进城的百姓做严格的搜查。裁缝店的生意
很冷清，虽然据说裁缝的手艺不错，但现在光顾那里的人是越来越少了。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"xidajie1",
  "west":__DIR__"xidajie3",
  "south":__DIR__"caifengdian",
     ]));
     
  set("objects",([
  	__DIR__"npc/zhangxiaojie":1,
  ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

