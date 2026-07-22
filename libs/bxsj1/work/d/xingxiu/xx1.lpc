// Room: /d/xingxiu/xx1.c
// Update by caiji@SJ 8/24/2000
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
    set("short", "山前荒地");
    set("long", @LONG
这里是一座石山前的荒地，平常人迹罕至，放眼望去尽是枯树败草，十分
荒凉，一阵朔风萧杀，令人心惊胆颤。路边有几个星宿弟子在练功，同时在盯
着行人的一举一动。你没事还是快走吧。
LONG);
	set("outdoors", "星宿");
	set("objects", ([
		__DIR__"npc/feitian" : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("exits", ([
		"northup" : __DIR__"ryd1",
		"northwest" : __DIR__"xx2",
		"south" : __DIR__"xxh2",
		"northeast" : __DIR__"rukou",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if (dir =="northup" && present("feitian zi", environment(me))
	 && me->query("family/family_name") != "星宿派"
	 && me->query("combat_exp") < 100000)
		return notify_fail("飞天子挡住你道：“像你这样糟糕的邪派弟子，怎么可以去拜见我师傅？”\n");

	return ::valid_leave(me, dir);
}
