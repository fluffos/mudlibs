// Room: d/kyoto/hongqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "虹桥");
set("long", @LONG
这是京都护城河上的虹桥，整座桥由七彩石制成，形似彩虹，故称作虹桥，
是京都御所四桥中最美的一座桥，宛若天边的彩虹降落人间。雨后初晴之时与
天边彩虹相映成辉，让人分不清是人间还是仙境。
LONG );
set("exits",  ([
        "north"  : __DIR__"huchenghe2",
        "south"  : __DIR__"huchenghe4",
        "west"  : __DIR__"yusuogate",
        "east"  : __DIR__"juechuan",
      ]));
        setup();
        replace_program(ROOM);
}