// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄土地"NOR);
        set("long", @LONG
这里是靠近黄河源头的一片广袤的平原，黄河之水行进至此因地势平缓，
河面骤然展宽，流速也变缓，四处流淌的河水，使这里形成大片沼泽和众多的
湖泊。一个牧羊人正在这里放牧，北面是一片狭长的盆地，雾气缭绕中，看得
并不真切。
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"shanjiao",
            "north" : __DIR__"xxgate",
            "westup" : __DIR__"tianroad3",
]));
        set("objects", ([
                __DIR__"npc/herdsman" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

