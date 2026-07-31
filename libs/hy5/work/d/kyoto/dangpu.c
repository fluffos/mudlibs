// Room: d/kyoto/dangpu
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "当铺");
set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面
前，柜台上摆着一个牌子(paizi)，柜台后坐着上杉老板，一双精明
的上上下下打量着你。
LONG );
set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "这儿可以用的命令有如下：
value  估价
pawn 当东西
redeem 赎回东西
sell 卖东西
",
]));
set("exits",  ([
        "south"  : __DIR__"qianbending4",
      ]));
set("objects",  ([
        "d/kyoto/npc/shangshan.c" : 1
        ]));
        setup();
        replace_program(ROOM);
}