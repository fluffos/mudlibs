// Room: d/kyoto/nanmen
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "南门");
set("long", @LONG
这里就是京都的南门，整座门在维新运动成功后新建，由花岗石制成
，门拱足有四层楼高，宽可供十乘并行，充分显示了京都的繁华大气，让
人敬意顿生，往前就是京都的主干道之一，上原。
LONG );
set("exits",  ([
        "north"  : __DIR__"shangyuan5",
      ]));
        setup();
        replace_program(ROOM);
}