// Room: /d/suzhou/dangpu.c
// Date: May 31, 98  Java

inherit F_HOCKSHOP;

void create()
{
	set("short", "宝和记");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在
你的面前，柜台上摆着一个牌子(sign)，柜台后坐着位老板，
一双精明的眼睛上上下下打量着你。
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("exits", ([
		"north"  : __DIR__"dongdajie1",
	]));

	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	setup();
	unique_id=3;
	setup_shop();
	set("item_desc", ([
		"paizi" : (:use_help:),
	]));	
}

