// Room: d/kyoto/shangyuan4
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "上原");
set("long", @LONG
这里就是上原，往北就是京都最繁华的中心，熙熙攘攘的人群不断从
身边擦身而过，两边店铺的叫卖声不绝于耳。东西各有一条小巷，不知道
同往什么地方。往南是一座大石桥，往北便是繁华的京都中心。

LONG );
set("exits",  ([
        "south"  : __DIR__"dashiqiao",
        "north"  : __DIR__"shangyuan3",
        "west"  : __DIR__"xiaoxiang2",
        "east"  : __DIR__"xiaoxiang3",
      ]));
        setup();
        replace_program(ROOM);
}