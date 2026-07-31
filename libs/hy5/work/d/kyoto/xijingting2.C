// Room: d/kyoto/xijingting2
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "西京町");
set("long", @LONG
这是就西京町，是京都的主要居住区，自从明治维新之后十年，大家慢
慢过上了平静幸福的生活，再也不用惶惶渡日。北面是一栋民宅。
LONG );
set("exits",  ([
        "east"  : __DIR__"xijingting1",
        "west"  : __DIR__"xijingting3",
      ]));
        setup();
        replace_program(ROOM);
}