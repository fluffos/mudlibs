//xiangfang-south.c -- 南厢房
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"南厢房"NOR);
  set("long", @LONG
这里是宝相精舍的南厢房。屋内除了一张大炕，只有一个衣柜、一张
小桌、一把椅子。东面的大窗，此刻开着，从这里就能闻到小院内的阵阵
花香。

LONG
  );

  set("exits", ([     
      "north" : __DIR__"baoxiang-jingshe",
  ]));

  setup();
  replace_program(ROOM);
}
