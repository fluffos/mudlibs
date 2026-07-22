
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","平安小吃店");
  set ("long", @LONG
这里是家小吃店，近来这里的生意很好，店小二跑来跑去忙个不停。
只见门口挂着一个大红灯笼，每到晚上就点起来高高挂起，其上的平安二
字隔着两条街都看得清清楚楚。
LONG);

  set("exits", ([ 
  "east":__DIR__"beidajie2",
       ]));

  set("objects",([
	  __DIR__"npc/xiaoer":1,
  ]));
  set("valid_startroom", 1);
  setup();
 
}

