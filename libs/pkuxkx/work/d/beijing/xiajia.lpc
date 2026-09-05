// Room: /d/beijing/xiajia.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"夏家胡同"NOR);
        set("long",
CYN"这条胡同曲里拐弯，道路也非常狭小。路两旁的房子低矮简陋，见到的
路人衣着破破烂烂，面有菜色。看来这里的老百姓生活非常艰辛。在胡同的
西面有一家包子店，生意特别好。\n"NOR
        );
        set("outdoors", "beijing");

        set("exits", ([
                "west"  : __DIR__"baozidian",
                "north" : __DIR__"fenshen",
                "east" : __DIR__"qianmen1",
        ]));
	set("no_clean_up", 0);
//	set("cost", 2);
        setup();
        replace_program(ROOM);
}

