// Room: /d/beijing/qianmen1.c
#include <ansi.h>
inherit ROOM;


void fix_exits_for_night(int is_night)
{
    if (is_night) {
        set("exits", ([
                "east"  : __DIR__"tianshui",
                "west"  : __DIR__"xiajia",
                "north" : __DIR__"qianmen2",
        ]));
    }else{
        set("exits", ([
                "south" : __DIR__"yonganmen",
                "east"  : __DIR__"tianshui",
                "west"  : __DIR__"xiajia",
                "north" : __DIR__"qianmen2",
        ]));
    }
}
void create()
{
        set("short", HIC"正阳门外大街"NOR);
        set("long",
CYN"街上两旁开着许多的店铺，还有许多的大小摊档，耍猴卖艺的都有几档
，围满了人在观看，从西面的胡同里传出阵阵的包子香，东面可以看到
天坛祈年殿的殿顶，南面是永安门。\n"NOR
        );
        set("outdoors", "beijing");

        fix_exits_for_night(0);

        set("objects", ([
        __DIR__"npc/miscseller":1,
        __DIR__"npc/captain2":1,
	]));
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"yonganmen",
                "east"  : __DIR__"tianshui",
                "west"  : __DIR__"xiajia",
                "north" : __DIR__"qianmen2",
        ]));
        set("cost", 2);
        setup();
}

string GATE_OUT_DIR1 = "south";
string GATE_OUT_DIR2 = "";
#include "gate.h"
