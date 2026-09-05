// File     : xuejie1.c
// Created By   : iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
    set("short", WHT"山货店"NOR);
    set("long", @LONG
这里是凌霄城的山货店。
LONG);

    set("indoors", "凌霄城");
    set("exits", ([
        "north" : __DIR__"xuejie3",
        ]));
    set("objects", ([
//      __DIR__"npc/dizifr" : 2,
        __DIR__"npc/dizixl" : 1,
    ]));

    setup();
    replace_program(ROOM);
}

