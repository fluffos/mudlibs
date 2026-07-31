// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "昆明当铺");
	set("long", @LONG
这是一家很有些历史的老当铺了，高高的柜台后面座着当铺的老
板，正用一种奇怪的眼光看着你，一个伙计正在劈劈啪啪的打着算盘
，见你来了，也不招呼一下。柜台的顶上挂着一块牌子(paizi)。
LONG
	);
	set("no_fight", 1);
	set("no_beg",1);

	set("item_desc", ([
		"paizi" : "公平交易\n",
	]));
	set("objects", ([
		__DIR__"npc/liu" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandajie1",
	]));

	setup();
	replace_program(ROOM);
}

