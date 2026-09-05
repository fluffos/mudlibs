// File     : bingeast4.c
// Created By   : iszt@pkuxkx, 2006-09-04

#include <ansi.h>;

inherit ROOM;

void create()
{
    set("short", RED"兵器铺"NOR);
    set("long", @LONG
凌霄城中，几乎人人好武，所以兵器铺最受欢迎的所在。四面墙上挂着
各种兵器，从柴刀到金轮，一应俱全，当然，凌霄城以剑见长，因此，种类
最多、数量最大、质量最好的，还是一柄柄长剑。
LONG);

    set("indoors", "凌霄城");
    set("exits", ([
        "west" : __DIR__"bingjie4",
    ]));
    set("objects", ([
        __DIR__"npc/dizi_free" : 1,
        __DIR__"npc/dizi" : 1,
        __DIR__"npc/skweapon" : 1,
    ]));

    setup();
    replace_program(ROOM);
}

