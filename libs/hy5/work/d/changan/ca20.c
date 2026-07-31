
// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIY "鼓楼" NOR);
    set("long", @LONG
鼓楼建于明洪武一十三年。青条石为基，青砖为楼，稳重厚实。
门楼内安放大鼓一张，相传当年天子在此击鼓点将，连扬州城都能听
到。
LONG
);
    set("exits", ([
       "south":__DIR__"ca17",
]));
    setup();
    replace_program(ROOM);
}
