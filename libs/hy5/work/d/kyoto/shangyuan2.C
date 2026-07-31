// Room: d/kyoto/shangyuan2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "上原");
set("long", @LONG
这里就是京都最繁华的中心，上原与千本町的交汇处，熙熙攘攘的人
群不断从身边擦身而过，两边店铺的叫卖声不绝于耳。东西两边就是千本
町，是京都的东西大动脉，也是最繁华的街区，行馆店铺鳞次栉比。
LONG );
set("exits",  ([
        "south"  : __DIR__"shangyuan3",
        "north"  : __DIR__"shangyuan1",
        "west"  : __DIR__"qianbending3",
        "east"  : __DIR__"qianbending4",
      ]));
        setup();
        replace_program(ROOM);
}