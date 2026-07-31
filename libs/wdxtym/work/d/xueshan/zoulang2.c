//      zoulang2.c 走廊
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是雪山寺内的走廊。这里有点幽暗，天花板上有
一些不知道确切含义的雕刻，墙壁上则是很通俗的佛经故
事壁画了。壁上点着几碗大海灯照明。
LONG );
	set("exits", ([
		"south"   : __DIR__"cedian2",
		"east"   : __DIR__"dating",
		"northeast" : __DIR__"zoulang3",
	]));
	set("item_desc", ([
		"【雕刻】" : "一些不知道含义的雕刻，认真观察(kan)仿佛又有哪些不同。\n"
		ZJOBACTS2"观察:kan\n",
	]));
	setup();
}

void init()
{
	add_action("do_watch", "kan");
}

int do_watch()
{
	object ob = this_player();
	int lvl = ob->query_skill("mingwang-jian", 1);

	if ((int)ob->query_skill("force") < 100)
	{
		write("你的内功火候不够，无法理解上面刻的是什么。\n");
		return 1;
	}

	if ((int)ob->query_skill("mingwang-jian", 1) > 135)
	{
		write("你的不动明王剑修为已经超越壁上所刻了。\n");
		return 1;
	}

	if ((int)ob->query_skill("mingwang-jian", 1) < 50)
	{
		write("你的不动明王剑修为太浅，无法理解壁上所刻。\n");
		return 1;
	}

	if (! ob->can_improve_skill("mingwang-jian"))
	{
		write("你的实战修为不足，无法领悟壁上内容。\n");
		return 1;
	}

	if (ob->query("jing") < 40)
	{
		 write("你太累了，现在无法领悟壁上内容。\n");
		 return 1;
	}

	message_vision("$N面对着壁上图案揣摩良久，似有所悟。\n",ob);
	ob->improve_skill("mingwang-jian", 1 + random(ob->query("int")));
	ob->receive_damage("jing", 20 + random(20));
	return 1;
}
