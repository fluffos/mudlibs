// /d/xiangyang/hunanroad2.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在湘鄂交界的土路上，偶尔会有人骑着马匆匆而过。这里已经是湖南
地界，往东北进入湖北境内。南边是一个小镇。
LONG
	);
        set("outdoors", "tiezhang");

	set("exits", ([
		"northeast" : __DIR__"hunanroad1",
		"south" : "/d/tiezhang/lx",
	]));

	setup();
	replace_program(ROOM);
}

