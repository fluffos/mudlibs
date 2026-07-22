#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "一面湖水");
        set("long", @LONG
你掉到山谷中的湖水里面，只见水色碧绿，清澈见底，只是在
瀑布流水的冲击下水流有些急，湖很大，你定了定神，向前方
游去！
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "north" : __DIR__"hushui1",
             ]));
        set("no_clean_up", 0);
        setup();
}


