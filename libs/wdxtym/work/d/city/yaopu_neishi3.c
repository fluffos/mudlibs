// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "北药室");
	set("long", @LONG
这是药铺的北药室，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。一名小伙计站在柜台后招呼着顾客。
LONG );
	
	set("objects", ([
		__DIR__"npc/sell_yao3" : 1,
	]));
	set("no_fight", 1);     
	set("no_sleep_room", 1);
	set("exits", ([
		"south" : __DIR__"yaopu_neishi",

	]));
	setup();
}
