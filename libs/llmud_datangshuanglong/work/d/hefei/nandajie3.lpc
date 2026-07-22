
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是合肥的南大街。南边就是合肥的南门了。东边有一家戏院。
这里可以听到里面热闹的声音。戏院的生意不比从前，只见戏院的招牌
已经落满了灰尘，伙计也在门口打着呵欠。
LONG);

  set("exits", ([ 
	  "north":__DIR__"nandajie2",
  "south":__DIR__"nanmen",
  "east":__DIR__"xiyuan",
   ]));
   
   set("objects",([
     __DIR__"npc/xiaohunhun":1,
   ]));
   
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

