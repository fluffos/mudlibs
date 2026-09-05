//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "汉水");
        set("long", @LONG
汉水河道曲折，自古有“曲莫如汉”之说。远远望去，汉水有如游蛇蜿蜒，
河岸丛林密布，一篇郁郁葱葱的景象。
LONG
        );

        set("exits", ([
                "southeast" : "/d/shaolin/hanshui1",
                "west" : __DIR__"hanshui1",
        ]));
        set("no_task",1);
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}
