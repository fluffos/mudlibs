
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是合肥的西大街。东边是合肥的中心了。北边有一家药铺，那
里传来了阵阵的药香。几个伤兵正从你的身旁走过，嘴里不知道在嘟囔
着什么，掀开药铺的门帏瘸瘸拐拐地走了进去。
LONG);

  set("exits", ([ 
	  "northwest":__DIR__"yaopu",
  "northeast":__DIR__"center",
  "southwest":__DIR__"xidajie2",
     ]));
     
  set("objects",([
  	__DIR__"npc/shangbing":2,
  ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

