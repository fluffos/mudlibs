// Room: /d/beijing/fenshen.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"丰盛胡同"NOR);
        set("long",
CYN"一条热闹繁华的胡同，离皇城只有几步之遥。住这里的多半是在外省
京官的家眷，其余多少也都扯得上关系，生活富足，无忧无虑。\n"NOR
        );
        set("outdoors", "beijing");

        set("exits", ([
                "west" : __DIR__"youandajie",
                "south": __DIR__"xiajia",
                "east" : __DIR__"qianmen2",
        ]));
	set("no_clean_up", 0);
//	set("cost", 2);
        setup();
        replace_program(ROOM);
}


