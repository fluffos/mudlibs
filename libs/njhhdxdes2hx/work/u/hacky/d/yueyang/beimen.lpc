
// Room: /city/beimen.c
// YZC 1995/12/04

#include <room.h>
#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
     set("short", BLK "北门" NOR);
        set("long", @LONG
        这是北城门，因为曾经失火，到现在城墙还是黑乎乎的，因此白
纸黑字的官府告示(gaoshi)就显得特别现眼。北方是一片崇山峻岭，一条
黄土小径在山里蜿蜒而上。
LONG
        );

        set("exits", ([
                "south" : __DIR__"beidajie2",
        ]));
        set("objects", ([
                __DIR__"npc/bing" : 2,
        ]));
        set("outdoors", "city");
        setup();
}

