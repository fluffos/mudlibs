// Room: /jyguan/dangpu.c
// YZC 1995/12/04 Shark Edit 10/08/1998

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家不地道的当铺，敢收纳各种物品一个五尺高的柜台挡在你的面前，柜台
上摆着一个牌子(paizi)，柜台后坐着当铺老板，一双精明的眼睛上上下下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);

	set("item_desc", ([
		"paizi" : "来者不拒\n",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"townroad1",
	]));

	setup();
	replace_program(ROOM);
}

