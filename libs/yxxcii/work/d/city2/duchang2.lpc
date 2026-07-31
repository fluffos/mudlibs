//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "赌场");
	set("long", @LONG
这里是赌场二楼，有四条走廊通向不同的房间。一阵阵吵闹声，叫喝
声，破骂声搅和在一起，震耳欲聋，一看，这一定是一片鱼龙混杂之地。
LONG
);
	set("exits", ([
		"east"  : "/d/city2/eproom",
		"west"  : "/d/city2/wproom",
		"south" : "/d/city2/sproom",
		"north" : "/d/city2/nproom",
		"down"  : __DIR__"duchang",
	]));

	setup();
	replace_program(ROOM);
}

