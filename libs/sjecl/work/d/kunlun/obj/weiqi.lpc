// weiqi.c 围棋

inherit ITEM;

void create()
{
	set_name("围棋", ({ "wei qi", "weiqi", "qi", "go" }));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long",
			"这是一副围棋，棋盘用磁铁所制，棋子用铁铸成。\n");
		set("value", 5000);
		set("no_sell", 1);
		set("material", "steel");
	}
}

void init()
{
	if (environment() == this_player())
		add_action("do_play", "play");
}

int do_play(string arg)
{
	object me = this_player();
	object env;

	if (!arg || !id(arg))
		return notify_fail("你想做什么？\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	env = environment(me);
	if (env->query("sleep_room"))
		return notify_fail("卧室不能修练，会影响别人休息。\n");

	if (env->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (env->query("pending"))
		return notify_fail("此地不宜修练！\n");

	if (env->query("no_fight"))
		return notify_fail("这里不准战斗，也不准修练。\n");

	if (me->query("qi") < 20 || me->query("jing") < 30)
		return notify_fail("你太累了，还是先休息会把。\n");
	if (random(10) > 7) {
		message_vision("$N摆出一张棋盘，想研究围棋，却总觉得心烦意乱，定不下神来。\n", me);
		me->receive_damage("jing", random(10));
		me->receive_damage("qi", random(10));
		return 1;
	}
	me->receive_damage("jing", 20);
	me->receive_damage("qi", 5);
	me->add_busy(!random(3));
	if (me->query_skill("art",1) < 120)
		me->improve_skill("art", me->query_int()/4 + me->query_skill("art", 1)/10);
	write("你摆出一张棋盘，研究起围棋来，只觉得心平气和，很快就仿佛入定了。\n");
	tell_room(env,
		"只见" + me->name() +"雅兴大发，竟打起棋谱来，对外界仿佛不闻不问，一副莫测高深的模样。\n", me
	);
	return 1;
}
