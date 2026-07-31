// /d/xiangyang/outsroad1.c

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时有人骑着马匆匆而过。
大道往南进入湖南境内。北边通向襄阳城。
LONG
	);
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"outsroad2",
		"north" : "d/xiangyang/caodi2",
	]));

	setup();
	replace_program(ROOM);
}

