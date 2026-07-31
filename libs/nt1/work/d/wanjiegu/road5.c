// Room: /d/wanjiegu/road5
#include <ansi.h>
inherit ROOM;

void create()
{
        set ("short", "小路");
        set ("long", @LONG
无量山山中小路。
LONG);

        set("exits", ([ /* sizeof() == 2 */
                "southeast" : __DIR__"wuliangshan",
                "west" : __DIR__"road6",
        ]));
        set("outdoors", "/d/wanjiegu");
        setup();
        replace_program(ROOM);
}
