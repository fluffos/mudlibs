inherit ROOM;

void create()
{
	set("short", "山崖");
	set("long", @LONG
这里是玉女祠山下的陡峭山崖，离前边的山崖比较远，看来想要爬过
去并不容易。
LONG );
	set("outdoors", "huashan");
	set("action_list", ([
		"爬崖" : "climb",
	]));
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb()
{
	object me;
	int n = this_player()->query_skill("dodge", 1);

	me = this_player();

	message_vision("$N深吸了一口气，慢慢沿着山壁向上爬。\n", this_player());
	if (n > 100)
	{
		message_vision("$N爬了半天，手肘膝盖都已被坚石割得鲜血淋漓，终于爬了上来。\n", this_player());
		this_player()->move(__DIR__"kuihua_1");
	}
	else
	{
		message_vision("$N爬了一会，一个不留神，跌了下去（轻功等级低于100级，不满足条件）。\n", this_player());
		me->unconcious(); 
	}
	return 1;
}