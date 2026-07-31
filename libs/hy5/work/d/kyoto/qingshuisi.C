// Room: d/kyoto/qingshuisi
// created by keinxin's roommaker

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", "清水寺");
set("long", @LONG
这是京都最古老的寺院，建于公元七九八年，是慈恩大师创建，据说他
是唐僧的第一个弟子，正殿建在悬崖边，前部是悬空的“舞台”，下面由一
百三十九根高大圆木支撑，高达数十米。寺院建筑精美，结构非常巧妙，未
使用一根钉子。寺中六层巨木筑成的木台为日本所罕有。
LONG );
set("exits",  ([
        "east"  : __DIR__"gaoye",
      ]));
        setup();
        replace_program(ROOM);
}