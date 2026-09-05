// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"雪积古道"NOR);
        set("long", @LONG
天，阴郁，铅灰而低沉。
    雪，漫天，狂风迷人眼。
    左侧是万丈的高崖，陡峭不见顶；
    右侧是不测的山谷，深邃不见底。
    小径，上雪山必经之路。
LONG 
        );

        set("exits", ([

                "southeast" : __DIR__"xuejigudao2",
                "southwest" : __DIR__"xuelingquan",
        ]));
        set("objects", ([
                __DIR__"npc/xuebao" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

