// Room: d/kyoto/xiaoxiang2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "小巷");
set("long", @LONG
走在一条小巷上，昏昏暗暗的，一边是上原，北面是茶室，三教九流
的再那里喝茶聊天，抒发对明治政府的不满，西面是福野温泉，在那里人
们泡着温泉，洗去一天的疲惫，也可以叫卡瓦伊的小姐来享受一下特殊服
务。

LONG );
set("exits",  ([
        "east"  : __DIR__"shangyuan4",
        "north"  : __DIR__"chashi",
        "west"  : __DIR__"fuyewenquan",
      ]));
        setup();
        replace_program(ROOM);
}