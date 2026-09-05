// Room: /city/dangpu.c
// YZC 1995/12/04 

#include <ansi.h>
//int do_none();

inherit F_HOCKSHOP;

void create()
{
    unique_id = 1;
    setup_shop();

	set("short", "当铺");
	set("long",
"这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台上
摆着一个牌子"YEL"(paizi)"NOR"，柜台后坐着唐老板，一双精明的眼睛上上下下打量着你。
");
	set("no_beg",1);
	set("no_steal", 1);
//	set("no_fight", 1);
	set("item_desc", ([
		"paizi" : (:use_help:),
	]));
	set("objects", ([
		"/d/city/npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
		"south" : __DIR__"rbz",
	]));

    setup();

}
/*
void init()
{
        add_action("do_none",({"study","learn","tuna","exercise","dz","apprentice","research","practice","dazuo"}));
}
int do_none()
{
        write("对不起，这是当铺，人流太密集，去别的地方练功吧。\n");
        return 1;
}
*/
