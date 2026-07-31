//room: qinyun.c

inherit ROOM;

void create()
{
	set("short","琴韵小筑");
	set("long",@LONG
这是一间小巧玲珑的房舍，颇为精雅。周围稀稀落落的四五间小房
屋，建造在一个不知是小岛还是半岛上。
LONG );
	set("exits", ([
		"westdown" : __DIR__"muti",
		"east"     : __DIR__"xiaoting",
		"south"    : __DIR__"neitang",
	]));

	set("objects", ([
	 	__DIR__"npc/bao"  : 1,
		__DIR__"npc/feng" : 1,
	]));

	set("valid_startroom", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (dir != "east")
		return 1;

	if (guarder = present("bao butong", this_object()))
		return guarder->permit_pass(me, dir);

	if (guarder = present("feng boe", this_object()))
		return guarder->permit_pass(me, dir);

	return 1;
}
