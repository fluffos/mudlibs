// Room: d/kyoto/qianbending6
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "千本町");
set("long", @LONG
这里就是千本町，贯穿京都东西的大动脉，也是最繁华的街区，两边
是民宅。往西就是闹市，东面则要出城了。
LONG );
set("exits",  ([
        "west"  : __DIR__"qianbending5",
        "east"  : __DIR__"dongmen",
      ]));
        setup();
        replace_program(ROOM);
}