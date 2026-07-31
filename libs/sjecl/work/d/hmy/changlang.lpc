// /d/hmy/changlang.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一路走过，只见走廊上数百武士排列两旁，手中各挺一把明晃晃的长刀，
交叉平举，往来之人都要弓腰低头而过，数百柄长刀中只要有一柄突然砍落，
便不免身首异处。
LONG
	);
	set("exits", ([
		"east" : __DIR__"dadian",
		"south" : __DIR__"fleitang",
		"north" : __DIR__"baihutang",
		"west" : __DIR__"qiandian",
	]));
	set("objects", ([ 
		__DIR__"npc/chou" : 1,
	]));

	setup();
}
