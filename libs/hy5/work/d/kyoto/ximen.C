// Room: d/kyoto/ximen
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "西门");
set("long", @LONG
这里就是京都的西门，在这里已经可以感受京都的繁华。高耸的城门
两边站着全副武装的守卫，时刻提醒着人们，这里曾经是天皇的都城。从
这里东行就是京都最繁华的街区千本町。
LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending1",
      ]));
        setup();
        replace_program(ROOM);
}