// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "中央药材室");
	set("long", @LONG
这是药铺内室，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小
抽屉里散发出来的。一名小伙计站在柜台后招呼着顾客。
LONG );
	
	set("objects", ([
		__DIR__"npc/sell_yao" : 1,
	]));
	set("no_fight", 1);     
	set("no_sleep_room", 1);
	set("exits", ([
		 "south" : __DIR__"yaopu",
		 "east" : __DIR__"yaopu_neishi1",
		 "west" : __DIR__"yaopu_neishi2",
		 "north" : __DIR__"yaopu_neishi3",
	]));
	setup();
}
