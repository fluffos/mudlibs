// Room: d/kyoto/yuqiao
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "玉桥");
set("long", @LONG
这是京都护城河上的金桥，整座桥由汉白玉制成，故称作玉桥，护栏上
绕的就是［京都御所］，是昔日天皇的行宫。过了玉桥就是御所的正门雕刻
着精美的图案，让人不禁去触摸，感受昔日的情怀，护城河环，往西则是天
下闻名的京都第一古寺［清水寺］。
LONG );
set("exits",  ([
        "south"  : __DIR__"huchenghe3",
        "north"  : __DIR__"huchenghe1",
        "east"  : __DIR__"yusuogate",
        "west"  : __DIR__"gaoye",
      ]));
        setup();
        replace_program(ROOM);
}