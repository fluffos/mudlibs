//ROM yuanzi

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long",
	     "这就是闻名天下的『白驼山庄』的大门。大门梁上雕龙刻凤，美奂\n"
	 "美仑，不知凝聚着多少能工巧匠的心血。更显出庄主的富有与显贵。门\n"
	 "前左右各蹲着一只威武庄严的石狮子。\n"
	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"yuanzi",
		"southdown" : __DIR__"shijie",
	]));
	set("objects",([
		__DIR__"npc/menwei" : 2,
	]));
	set("valid_startroom",1);
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (objectp(guarder = present("men wei", this_object())) &&
		dir == "north")
	{
		return guarder->permit_pass(me, dir);
	}

	return 1;
}
