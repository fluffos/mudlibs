// Room: d/kyoto/xiaoxiang1
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "小巷");
set("long", @LONG
这里就是当年绯村剑心同新撰组发生激战的地方，也是幕末时期最惊
心动魄的一场战斗，“拔刀斋”绯村剑心对“壬生之狼”斋藤一，同为战
国古剑术流的飞天御剑流同一刀流免许的较量。两旁石壁上剑气造成的划
痕依然深入石壁。让人肃然起敬。
LONG );
set("exits",  ([
        "north"  : __DIR__"qianbending2",
        "south"  : __DIR__"fuyewenquan",
      ]));
        setup();
        replace_program(ROOM);
}