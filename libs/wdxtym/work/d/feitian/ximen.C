// Room: d/kyoto/ximen
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "西门");
set("long", @LONG
这里就是东京的西门，在这里已经可以感受东京的繁华。高耸的城门
两边站着全副武装的守卫。
LONG );
set("exits",  ([
        "east"  : __DIR__"guangchang",
        "west"  : __DIR__"path2",
      ]));
        setup();
        replace_program(ROOM);
}