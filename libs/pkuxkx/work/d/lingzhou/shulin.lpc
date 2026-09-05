// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片茂密的树林，大树参天，你一走进来，仿佛迷失了方向。
LONG
        );

        set("exits", ([
//                "north" : __DIR__"dalu2",
//                "southwest"   : __DIR__"hubianxiaolu1",
                "northwest" : __DIR__"huangyangtan",
                "southwest" :__DIR__"shulin",
                "northeast" :__DIR__"shulin",
                "southeast" :__DIR__"shulin",
        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc2" : 1,
        ]));
//        set("outdoors", "dalunsi");
        setup();
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


