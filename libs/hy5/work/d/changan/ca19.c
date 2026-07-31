
// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIY "钟楼" NOR);
    set("long", @LONG
钟楼建于明洪武一十三年。青条石为方基，巨木为塔楼。楼内悬
挂巨钟一口，用以报时，钟楼因此得名。
LONG
);
    set("exits", ([
       "south":__DIR__"ca18",
]));
    setup();
    replace_program(ROOM);
}
