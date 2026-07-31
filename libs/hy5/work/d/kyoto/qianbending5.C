// Room: d/kyoto/qianbending5
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "千本町");
set("long", @LONG
这里就是千本町，贯穿京都东西的大动脉，也是最繁华的街区，两边
行馆店铺鳞次栉比。南面是一间书院，可以听到里面传出的朗朗书声，虽
然叽哩瓜啦都是日语，北面是老字号藤尾药铺，老板藤尾雄一向来享有手
到病除的美名。

LONG );
set("exits",  ([
        "east"  : __DIR__"qianbending6",
        "west"  : __DIR__"qianbending4",
        "south"  : __DIR__"shanggeshuyuan",
        "north"  : __DIR__"tengweiyaoshe",
      ]));
        setup();
        replace_program(ROOM);
}