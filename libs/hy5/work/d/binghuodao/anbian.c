#include <ansi.h>

inherit ROOM;

void rtaohua( object ob ) ;

void create()
{
    set("short", "冰火岛");
    set("long", @LONG
冰火岛的海滩竟是一个极大的岛屿。岛屿西部都是尖石嶙峋的山峰
，形怪样，莫可名状。岛东却是一望不到尽头的原野。该处虽然地近北
极，但因火山万年不灭，岛上气候便和长白山、黑龙江一带相似，高山
处玄冰白雪，草地上却极目青绿，苍松翠柏，高大异常，更有诸般奇花
异树，皆为中土所无。
LONG );
    set("outdoors", "binghuodao");
set("exits", ([
"north" : __DIR__"road1",
"northeast" : "/d/binghuo/haitan",	
]));
    setup();
}

