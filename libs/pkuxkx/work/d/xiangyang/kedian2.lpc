inherit ROOM;
void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。屋内有一条大木床,可供十几个人用
不少客人正和衣而卧，满屋子都是呼呼的打酣声。西边有一块空地,可以供你睡.
你蹑手蹑脚地走了过去。
LONG
	);

        set("sleep_room", "1");
	set("no_fight", "1");
	set("exits", ([
		"down" : __DIR__"kedian",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "down" ) me->delete_temp("rent-paid");

	return ::valid_leave(me, dir);
}


