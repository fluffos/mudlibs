//jiaomen-w.c -- 西角门
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"西角门"NOR);
  set("long", @LONG
这里是汝阳王府的西角门，平时很少开放，只有在王府有重大庆典的
时候，为了方便杂役出入，才偶尔打开。
LONG
  );

  set("exits", ([     

      "east" : __DIR__"weiqiang-w",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}

