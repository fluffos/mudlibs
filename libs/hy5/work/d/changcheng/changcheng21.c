// Room: /d/wizhome/incahome/changcheng22.c
// Date: inca 98/08/13

#include <ansi.h>

inherit ROOM;

void create()
{

        set("short",WHT"长城"NOR);
        set("long", WHT@LONG
由于长期受到风沙的侵蚀，不少城墙已经倒塌。墙角的黄沙中有许多
从城墙上掉下来的青砖。前面不远处就是长城的终点--嘉峪关。由于这里
是西域通往关内的必经之路，所以人也多了起来。只见许多碧眼金发的商
人带着他们的商队匆匆向离去。
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "southwest"      :"/d/jyguan/wall.c",
                "east"           :__DIR__"changcheng20.c",
        ]));

        setup();
        replace_program(ROOM);
}
