// Room: d/kyoto/qianbending4
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "千本町");
set("long", @LONG
这里就是千本町，贯穿京都东西的大动脉，也是最繁华的街区，两边
行馆店铺鳞次栉比。南面是一间老字号的面食点，出售各种面食，北面是
一间当铺，可以典当各种物品。

LONG );
set("exits",  ([
        "north"  : __DIR__"dangpu",
        "south"  : __DIR__"mianshidian",
        "west"  : __DIR__"shangyuan2",
        "east"  : __DIR__"qianbending5",
      ]));
        setup();
        replace_program(ROOM);
}