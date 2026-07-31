// /d/zhuojun/road6.c
// Room in 涿郡
// modify by yang

inherit ROOM;


void create()
{
	set("short", "湘江山路");
	set("long", @LONG
你走在一条青石大道上，边上是滚滚的湘江,此处人
群稀少，四周也静悄悄的。
LONG );
	set("exits", ([
		"north" : "/d/nanchang/nanmen",
		"east" : __DIR__"road7",
	]));

 	set("outdoors", "zhuojun");
	setup();
	replace_program(ROOM);
}



