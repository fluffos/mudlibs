// Room: gbdixiaowu.c

inherit ROOM;
void create()
{
	set("short", "林间小屋");
	set("long", @LONG
你走进了一间小屋。四周墙壁都由青竹篾编成，窗外是一望无际的竹林。
屋里的桌椅、床铺均为竹制。但一阵扑鼻而来的狗肉香味，却显得与这清雅的
气纷格格不入。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"gbandao",
		"out"  : __DIR__"ml7",
		"east" : "/d/gaibang/undertre.c"
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/hong" : 1,
		__DIR__"obj/zhubang": 1,
		__DIR__"obj/gourou": 1,
		__DIR__"obj/jiudai": 1,
		__DIR__"obj/jitui": 1
	]));

	set("valid_startroom", 1);
	set("sleep_room", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (dir == "west" && me->query("family/family_name") != "丐帮" &&
	    objectp(ob = present("hong qigong", this_object())) &&
	    living(ob))
		return notify_fail("洪七公拦住你：别乱走。\n");

	return ::valid_leave(me, dir);
}
