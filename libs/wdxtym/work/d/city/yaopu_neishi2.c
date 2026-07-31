// Room: /city/yaopu_neishi2.c
// YZC 2010/02/16 

inherit ROOM;

void create()
{
	set("short", "西药室");
	set("long", @LONG
这是药铺的西药室，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。一名小伙计站在柜台后招呼着顾客。

LONG );
	set("objects", ([
		__DIR__"npc/sell_yao2" : 1,
	]));
	set("no_fight", 1);     
	set("no_sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"yaopu_neishi",

	]));
	setup();
}
