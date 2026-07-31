
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"北门"NOR);
  set ("long", @LONG
这里是九江的北门。这里地处繁华地带。北边就是码头了。来来往
往有很多行人和商人，所以热闹得很。许多小商小贩推着车从这里走过，
叫卖着自己的商品。有几个官兵正在这里检查着来往的行人。
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie1",
  "north":__DIR__"matou",
         ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","jiujiang");
  
  set("valid_startroom", 1);
  setup();
 
}

