// Room: d/kyoto/xijingting1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "西京町");
set("long", @LONG
这是就西京町，是京都的主要居住区，自从明治维新之后十年，大家慢
慢过上了平静幸福的生活，再也不用惶惶渡日。北面是一个杂货屋，里面可
以买到各式各样的物品。往东是河原，是京都的交通中心之一。
LONG );
set("exits",  ([
        "north"  : __DIR__"zahuowu",
        "west"  : __DIR__"xijingting2",
        "east"  : __DIR__"heyuan1",
      ]));
        setup();
        replace_program(ROOM);
}