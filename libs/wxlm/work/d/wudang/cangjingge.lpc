// cangjingge.c 藏经阁
inherit ROOM;

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "藏经阁");
	set("long", @LONG
这里是藏经阁，靠墙是一排书架，摆满了道教的典籍。中央有一个长方
形的大桌子，上面也堆满了书。一个道童正在整理书籍。由几个老道盘
膝而做，若有所思，看来是在静修(jingxiu)。
LONG );
	set("exits", ([
		"southdown" : __DIR__"xilang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 1,
		"/clone/book/"+books[random(sizeof(books))] : 1,
		"/clone/book/"+books[random(sizeof(books))] : 1
	]));
	set("item_desc", ([
		"【牌子】" : "道家静修之地，请保持安静。\n"
		ZJOBACTS2"静修:jingxiu1\n",
	]));
	set("no_fight", 1);
	set("sleep_room", 1);

	setup();
}

void init()
{
	add_action("do_jingxiu", "jingxiu1");
}

int do_jingxiu(string arg)
{
	object me;
	int cost;

	me = this_player();
	if (me->is_busy())
		return notify_fail("等你忙完了手头的事情再说！\n");

	if (me->query("jing") < me->query("max_jing") * 7 / 10)
		return notify_fail("你现在的静不够，无法静修。\n");

	if (me->query_skill("taoism", 1) < 250)
		return notify_fail("你对道学心法理解太浅，静修获得不了什么进境。\n");

	if (! arg || ! sscanf(arg, "%d", cost))
            return notify_fail(INPUTTXT("请输入消耗多少潜能来进行静修：","jingxiu1 $txt#")+"\n");
		//return notify_fail("你要花多少潜能进行静修？\n");

	if (cost >= me->query("potential") - me->query("learned_points"))
		return notify_fail("你现在没有这么多的潜能！\n");

	if (cost < 100)
		return notify_fail("这点也太少了吧？至少要花一百点潜能才能有所进步。\n");

	message_vision("$N找了一个地方坐了下来，闭目冥神，开始专心研究道学心法。\n", me);

	me->set_temp("pending/jingxiu", 1);
	me->set_temp("potential_cost", cost);
	me->set_short_desc("正坐在地下冥神静修。");
	me->start_busy((:call_other, __FILE__, "jingxiu" :),
		       (:call_other, __FILE__, "halt_jingxiu" :));
	return 1;
}

int jingxiu(object me)
{
	int cost;

	cost = me->query_temp("potential_cost");
	if (cost > 0)
	{
		cost = random(cost) + 1;
		if (cost > 50) cost = 50;
	} else
		cost = 0;

	me->improve_skill("taoism", random(me->query_int()) + me->query_skill("taoism", 1) * cost / 3);
	me->add("learned_points", cost);
	if (me->add_temp("potential_cost", -cost) > 0)
		return 1;

	me->set_temp("pending/jingxiu", 0);
	me->set_short_desc(0);
	message_vision("$N静修完毕，面露微笑，站了起来。\n", me);
	return 0;
}

int halt_jingxiu(object me)
{
	tell_object(me, "你睁开眼睛，站了起来。\n");
	tell_room(environment(me), me->name() + "慢慢的睁开了双眼，站了起来。\n", me);
	me->set_temp("pending/jingxiu", 0);
	me->delete_temp("potential_cost");
	me->set_short_desc(0);
	return 1;
}
