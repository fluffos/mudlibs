// File     : xuejie1.c
// Created By   : iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
    set("short", WHT"小屋"NOR);
    set("long", @LONG
这里是人来人往,不知在忙些何事。
LONG);

    set("indoors", "凌霄城");
    set("exits", ([
        "west" : __DIR__"bingjie1",
        ]));
    set("objects", ([
//      __DIR__"npc/dizifr" : 2,
        __DIR__"npc/dizixl" : 1,
    ]));

    setup();
    replace_program(ROOM);
}

