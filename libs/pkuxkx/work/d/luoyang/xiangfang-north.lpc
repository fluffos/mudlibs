//xiangfang-north.c -- 北厢房
//Zone: 万安寺
//Created by ddid
//2009-6-17

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"北厢房"NOR);
  set("long", @LONG
这里是宝相精舍的北厢房。屋内除了一张大炕，只有一个衣柜、一张
小桌、一把椅子。东面的大窗此刻紧闭着，只有靠北的小窗，开了条缝。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"baoxiang-jingshe",
  ]));

  setup();
  replace_program(ROOM);
}
