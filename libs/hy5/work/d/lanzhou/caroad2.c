// caroad2.c
// by xws

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
远远的北边就能看到兰州了，南边通往长安。
LONG
	);
        set("outdoors", "lanzhou");

	set("exits", ([
		"north" : __DIR__"caroad1",
		"south" : __DIR__"caroad3",
	]));

	setup();
	replace_program(ROOM);
}
