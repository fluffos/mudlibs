// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"雪积古道"NOR);
        set("long", @LONG
略显开阔，已入深山。
    积雪松林，屏蔽在道边。
    怪鸟掠过头顶，阵阵怪叫，不绝于耳；
    异兽躲于林中，暗中窥视，杀机四伏。
LONG 
        );

        set("exits", ([

                "northwest" : __DIR__"xuejigudao1",
                "eastup" : __DIR__"xuejigudao3",
        ]));
        set("objects", ([
//                __DIR__"npc/baoxiang" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

