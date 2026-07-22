#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "一面湖水");
        set("long", @LONG
这是一面湖水，你使劲力气游呀！只见水色碧绿，清澈见底
只是在瀑布流水的冲击下水流有些急，湖很大，你定了定神
向前方游去！
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"hushui",
              "north" :__DIR__"dongkou",
             ]));
        set("no_clean_up", 0);
        setup();
}


