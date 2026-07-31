// sanjie tianmoorest.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "卧室");
  set ("long", @LONG
	
神仙也要睡觉，更何况你也不是神仙，还是在这里偷懒一下
休息休息为妙。
LONG);

  set("exits", ([
  "north" : __DIR__"tianmodian5",
]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  set("sleep_room",1);
  set("if_bed",1);

  setup();
  replace_program(ROOM);
}
