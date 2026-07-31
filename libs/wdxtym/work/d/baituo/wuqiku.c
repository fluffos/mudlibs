//wuqiku.c

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long",
	     "这里是『白驼山』弟子的武器库，『白驼山』弟子可以到此\n"
	 "拿取练功用的各种武器。不过别派弟子是不允许进来的。\n"
	);
	set("exits", ([
		"east" : __DIR__"yuanzi",
	]));
	set("objects",([
	     __DIR__"npc/shiwei" : 1,
	     __DIR__"obj/shezhang" : 1,
	     "/clone/weapon/gangzhang" : 2,
	     __DIR__"obj/zheng" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object *inv;

	inv = deep_inventory(me);
	inv = filter_array(inv, (: $1->query("id") == "gangzhang" :));

	if (sizeof(inv) > 1)
		return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一条钢杖就够啦。\n");

	return ::valid_leave(me, dir);
}
