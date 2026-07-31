// Room: d/kyoto/shangyuan1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "上原");
set("long", @LONG
这里就是上原，往南就是京都最繁华的中心，熙熙攘攘的人群不断从
身边擦身而过，两边店铺的叫卖声不绝于耳。从这里往北便是昔日皇宫所
在。
LONG );
set("exits",  ([
        "north"  : __DIR__"jinqiao1",
        "south"  : __DIR__"shangyuan2",
      ]));
        setup();
        replace_program(ROOM);
}