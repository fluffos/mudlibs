// 大轮寺
//by kiden

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIW"雪积古道"NOR);
        set("long", @LONG
峰回路转。
    远望山顶，冰雕雪塑，隐约有庙舍。
    近踩积雪，深可及膝，举步为艰。
    风势尤劲，夹杂着冰雪，如刀割面。
LONG 
        );

        set("exits", ([

                "northwest" : __DIR__"shanmen",
                "westdown" : __DIR__"xuejigudao2",
                "eastdown" : __DIR__"houzidong",
        ]));
        set("objects", ([
//                __DIR__"npc/baoxiang" : 1,

        ]));
        set("outdoors", "dalunsi");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

