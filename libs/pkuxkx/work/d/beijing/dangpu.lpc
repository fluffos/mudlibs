// Room: 皇城当铺

#include <ansi.h>
inherit F_HOCKSHOP;

void create()
{
        set("short", HIC"皇城当铺"NOR);
        set("long",
CYN"这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子(paizi)，柜台后面有五个大柜子，分别陈列着各式武器、护具穿戴、
药物、书藉、和其它各式杂物。柜台后坐着当铺老板，一双精明的眼睛上上下下打
量着你。\n"NOR
        );
        set("no_beg",1);

        set("objects", ([
			 __DIR__"npc/dangpuhuoji" : 1,
        ]));
        set("exits", ([
		       "east" : __DIR__"fuchengdajie_n",
        ]));

        setup();
		unique_id=6;
		setup_shop();
	set("item_desc", ([
		"paizi" : (:use_help:),
	]));
}

