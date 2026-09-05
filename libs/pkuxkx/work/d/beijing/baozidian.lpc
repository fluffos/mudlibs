// Room: /d/beijing/baozidian.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"梅记包子铺"NOR);
        set("long",
CYN"一进门，堂中挂着的“梅记包子铺”金漆招牌金光闪闪，特别引人注目，
据说当今皇上在这儿吃过包子后，赞不绝口，特御赐此金字招牌，从此生意
越来越好，不少达官贵人都来光顾，分店越开越多，遍布中原各地。\n"NOR
        );

        set("exits", ([
                "east" : __DIR__"xiajia",
        ]));

        set("objects", ([
         __DIR__"npc/mei" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

