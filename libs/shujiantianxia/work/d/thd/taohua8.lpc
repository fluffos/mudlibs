// Room: /u/jpei/thd/taohua.c

inherit ROOM;

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(4) + 9;
	thd2 = random(4) + 5;
	thd3 = random(4) + 5;
	thd4 = random(4) + 5;
	set("short", "桃花阵");
	set("long", @LONG
这是一片茂密的桃花丛，你一走进来就迷失了方向。
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"taohua" + thd4,
	]));
	set("outdoors","桃花岛");
	setup();
}

void init()
{
	object ob=this_player();

	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("你在阵中累得精疲力尽，终因体力不支而昏了过去！\n");
		write("迷迷胡胡中似乎有人把你抬出了阵，仿佛有个威严的声音喝道：“扔到海里去”。\n");
		ob->unconcious();
          ob->move(__DIR__"haibin", 1);
		message("vision", "忽然一个大潮涌了过来，将一个被水泡得半死的家伙冲到了岸边。\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
}

