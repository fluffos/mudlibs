// Room: d/kyoto/qianbending3
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "千本町");
set("long", @LONG
这里就是千本町，贯穿京都东西的大动脉，也是最繁华的街区，两边
行馆店铺鳞次栉比。从南面的茶室不断传来热血青年评论维新政府得失的
各种言论，也有人谈论幕末时期各派成名剑客的传说，其中最神奇的就是
被人称为“拔刀斋”的绯村剑心的传奇。

LONG );
set("exits",  ([
        "east"  : __DIR__"shangyuan2",
        "west"  : __DIR__"qianbending2",
        "north"  : __DIR__"kuiwu",
        "south"  : __DIR__"chashi",
      ]));
        setup();
        replace_program(ROOM);
}