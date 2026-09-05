// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "湖边小路");
        set("long", @LONG
天湖湖边的一条小路，向前望不到尽头，不知道通向那里。路边野花芬芳，
蝴蝶飞舞，除了你自己的脚步声，四下里只听见一声高一声低的鸟鸣。
LONG
        );

        set("exits", ([

                "east"     : __DIR__"hubianxiaolu3",
                "northwest"     : __DIR__"hubianxiaolu2",

        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc2" : 1,
        ]));
        set("outdoors", "dalunsi");
        setup();
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


