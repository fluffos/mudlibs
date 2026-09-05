// Room: /d/beijing/picai.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"辟才胡同"NOR);
        set("long",
CYN"一条热闹繁华的胡同，离皇城只有几步之遥。住这里的多半是在外省京
官的家眷，其余多少也都扯得上关系，生活富足，无忧无虑。东边有一个极
巨大的牌楼，有数个官兵守卫着，没有人敢走近那里。\n"NOR
        );
        set("outdoors", "beijing");

        set("exits", ([
                "south" : __DIR__"tianshui",
                "east" : __DIR__"tiantan/xitianmen",
                "west" : __DIR__"qianmen2",
        ]));
	set("no_clean_up", 0);
//	set("cost", 2);
        setup();
        replace_program(ROOM);
}

