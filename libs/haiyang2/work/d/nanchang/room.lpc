
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","闺房");
  set ("long", @LONG
这里是李财主女二的闺房。这里很干净，看来刚刚有人打扫过。床
头的梳妆台放着几件装饰品，看起来非常名贵。
LONG);

  set("exits", ([ 

  "out":__DIR__"guifang",
    ]));

  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

	