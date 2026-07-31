// ximen.c
inherit ROOM;
void create()
{
	set("short","西门");
	set("long",
		"这是个山庄的西门。拱月形的竹门分外雅致，门上挂着\n"
		"一块竹牌(pai)。西门外面杂草丛生。\n"
	);

	set("exits",([
		"west" : __DIR__"cao1",
		"east" : __DIR__"changlang",
	]));

	set("item_desc",([
		"pai" : "西门外面有毒蛇出没，慎行。\n" ,
	]));

	set("objects",([
		__DIR__"npc/menwei" : 1,
	]));

	set("outdoors", "baituo");
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (! objectp(guarder = present("men wei", this_object())))
		return 1;

	if (dir == "east")
		return guarder->permit_pass(me, dir);

	if (dir == "west"
	   && (int)me->query("combat_exp") < 600
	   && guarder )
		return notify_fail("门卫把手一拦：你的经验太低，会被"
				   "毒蛇咬死的！还是不要乱闯的好。\n");

	return 1;
}
