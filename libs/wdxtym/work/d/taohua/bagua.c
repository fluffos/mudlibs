// /d/xiakedao/shiroom01.c 侠客岛 石室1

inherit ROOM;

void create()
{
	set("short", "八卦亭");
	set("long", "这是一个小亭子，亭子中央有一个八卦石盘，年代似乎非常久远，上面一些刻画已经有些模糊不清。" );
	set("exits", ([
		"west" : __DIR__"tao_out",
	]));
	set("item_desc", ([
		"八卦盘" : "石盘上的刻画有些地方已经有些模糊不清，但是仔细观察(guanmo bugua)之下似乎其中暗藏玄机。\n"
		ZJOBACTS2"观摩:guanmo bagua\n",
	]));

	set("no_fight", 1);
	setup();
}

void init()
{
	add_action("do_study", "guanmo");
}

int do_study(string arg)
{
	object me;
	int lvl;

	if (arg != "bagua")
		return notify_fail("你想研究什么？\n");

	me = this_player();

	if (me->query("combat_exp") < 2000000)
	{
		write("你看了半天，只恨自己实战修为(200w)太浅薄，无法领悟上面的高深知识。\n");
		return 1;
	}

	if (me->is_busy())
	{
		write("你现在正忙，没空研究。\n");
		return 1;
	}

	if (me->query("family/family_name")!="桃花岛" && me->query_skill("count",1)>379)
	{
		write("你已经不是桃花弟子了，怎么还好意思在这里继续研读下去？\n");
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 10)
		return notify_fail("你目前的潜能不足，无法从八卦盘上感悟到更多内容。\n");

	if ( me->query_skill("count",1) < 200)
		return notify_fail("你对阴阳八卦的理解还不够(200)，很难从八卦盘上感悟到更多内容。\n");

	if (me->query("int")<38&&(int)me->query_skill("count", 1) > (int)me->query("int")*10)
		return notify_fail("你的先天悟性不够，无法理解更深奥的阴阳八卦。\n");

	if ( me->query("qi")<101 || me->query("jing") < 101)
		return notify_fail("你目前的精神不佳，还是等会再观摩吧。\n");

	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->start_busy(1);

	if (random(10)>2)
	{
		write("你望着上面的八卦纹路，逐渐进入一个玄妙的境界，对《阴阳八卦》开始有所感悟。\n");
        me->add("learned_points", 10);
        me->improve_skill("count", 10 + random(me->query("int")*3));
	} else
		write("你潜心琢磨上面的纹路，似有所悟，偏偏又抓不住要领。\n");

	return 1;
}
