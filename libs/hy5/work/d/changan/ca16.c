
// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIW "碑林" NOR);
    set("long", @LONG
这里便是天下闻名的长安碑林。相传建于北宋元佑年间。碑林里
碑石墓志林立，自汉至清，荟萃各代名家手笔。真草隶篆，琳琅满目
。更有昭陵六骏浮雕石刻，直看得你眼花缭乱。
LONG
);
    set("exits", ([
       "east": __DIR__"ca13",
       "north":__DIR__"ca23",
]));
    setup();
    replace_program(ROOM);
}
