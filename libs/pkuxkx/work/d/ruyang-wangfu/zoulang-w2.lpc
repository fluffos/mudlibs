//zouliang_x.c走廊
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"走廊"NOR);
  set("long", @LONG
你正走在汝阳王府的走廊上，周围没有一个人，四周也静悄悄的，突
然来到如此肃静的环境，你心中不禁掠过一丝担忧，不由得加快了脚步，
想尽快离开这里。
LONG
  );

  set("exits", ([     
      "east" : __DIR__"yishiting",
      "west" : __DIR__"yibinguan",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
