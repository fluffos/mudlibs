// /d/xiangyang/outsroad3.c

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
你走在鄂湘交界的土路上，偶尔会有人骑着马匆匆而过。往南就是湖南境
内了，北边通向襄阳城。
LONG
	);
        set("outdoors", "xiangyang");

	set("exits", ([
		"north" : __DIR__"outsroad2",
                "westup" : __DIR__"conglin1", 
	]));

	setup();
	replace_program(ROOM);
}

