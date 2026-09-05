// D:\xkx\d\liuxiu-shanzhuang\dangpu.c当铺
// labaz  2012/10/21
#include <room.h>
#include <ansi.h>
inherit F_HOCKSHOP;

#include "newbie_village.h"

void create()
{
        set("short", "当铺");
        set("long", 
	"这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子"+YEL"(paizi)"NOR+"，柜台后坐着唐老板，一双精明的眼睛上上下下打量着你。\n"
        );
        set("no_beg",1);
        set("no_sleep_room", "1");

        set("objects", ([
                __DIR__"npc/tang" : 1,
        ]));
        set("exits", ([
                "east" : __DIR__"shanzhuang-damen",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
		unique_id = 30;
		setup_shop();
	set("item_desc", ([
		"paizi" : (:use_help:),
	]));
}

void init()
{
	::init();
	add_action("show_quest", "quest");
}
