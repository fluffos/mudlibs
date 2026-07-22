// Room: /dali/dating.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "王府大厅");
	set("long", @LONG
放眼望这大厅，只见正中一块横匾，写着“帮国柱石”四个大字，下首署
着“丁卯御笔”四个小字，楹柱中堂上悬满了字画，一时也看不了这么许多。
这就是镇南王接待江湖朋友的地方!
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"lang1",
	    "north" : __DIR__"damen",
	     "east" : __DIR__"lang2",
	]));
	set("objects", ([
	    __DIR__"npc/fusigui" : 1,
	    "/d/dali/npc/bing" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mixed *local;

	local = localtime(time() * 60);

	if (me->query("family/family_name") != "天龙寺"
	&& (dir == "west" || dir == "east")
	&& (local[2] < 5 || local[2] >= 20)) {
		//if (objectp(present("fu sigui", environment(me))))
			//return notify_fail("傅思归拦住你，说道：镇南王府内不得随意进出。\n");
		if (objectp(present("dali guanbing", environment(me))))
			return notify_fail("大理官兵拦住你，说道：镇南王府内不得随意进出。\n");
	}
	return ::valid_leave(me, dir);
}
