// Room: /d/wanjiegu/wuliangshan
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", "无量山");
        set ("long", @LONG
这里就是无量山了。
LONG);

        set("exits", ([ /* sizeof() == 1 */
                "southup" : __DIR__"riverside4",
                "northwest" : __DIR__"road5",
        ]));
        set("no_magic", 1);
        set("outdoors", "/d/wanjiegu");
        set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}
