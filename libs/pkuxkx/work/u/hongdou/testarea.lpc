// Room: workroom.c
// hongdou 98.9

inherit ROOM;

void create()
{
	set("short", "测试区域");
	set("long", @LONG
	这里是测试区域，从这里可以设计你要去的场景。
LONG
	);

	set("objects", ([
		__DIR__"ren" : 1
	]));

//	set("valid_startroom",1);

	set("exits", ([
		"northeast" : "/u/hongdou/dyd/haitan1",
		"home" : "/u/hongdou/workroom",
	]));

	setup();
	replace_program(ROOM);
}

