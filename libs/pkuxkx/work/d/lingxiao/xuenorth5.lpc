// File     : xuejie1.c
// Created By   : iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
    set("short", WHT"药铺"NOR);
    set("long", @LONG
这里是凌霄城的药铺。
LONG);

    set("indoors", "凌霄城");
    set("exits", ([
        "south" : __DIR__"xuejie5",
        ]));
    set("objects", ([
//      __DIR__"npc/dizifr" : 2,
        __DIR__"npc/dizixl" : 1,
    ]));

    setup();
    replace_program(ROOM);
}

