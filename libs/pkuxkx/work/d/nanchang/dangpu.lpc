// Room: /city/dangpu.c


#include <ansi.h>


inherit F_HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long",
"这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子"YEL"(paizi)"NOR"。
");
	set("no_beg",1);
	set("no_steal", 1);
//	set("no_fight", 1);
    set("no_sleep_room",1);

	set("objects", ([
		"/d/nanchang/npc/zhanggui3" : 1,
	]));
	set("exits", ([
        "east" : __DIR__"southstreet",
	]));

	setup();
    unique_id = 205;
    setup_shop();
	set("item_desc", ([
		"paizi" : (:use_help:),
	]));	
}

