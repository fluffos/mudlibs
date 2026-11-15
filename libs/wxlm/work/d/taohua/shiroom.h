// xiakedao 石室

int do_study(string arg)
{
	object me;
	int lvl;

	if (arg != "wall")
		return notify_fail("你想研究什么？\n");

	me = this_player();

	if (me->query("combat_exp") < 200001)
	{
		write("你看了半天，只恨自己实战经验太浅薄，无法领悟上面的高深知识。\n");
		return 1;
	}

	if (me->is_busy())
	{
		write("你现在正忙，没空研究上面的诗句。\n");
		return 1;
	}

	if ((me->query("potential") - me->query("learned_points")) < 50)
		return notify_fail("你目前的潜能不足，无法从石壁上感悟到更多内容。\n");

	if ( me->query_skill("taixuan-gong",1) >= 180)
		return notify_fail("你已经掌握太玄功的精髓了,接下来慢慢研究去吧。\n");

	if ( me->query("qi")<101 || me->query("jing") < 101)
		return notify_fail("你目前的精神不佳，还是等会再观摩吧。\n");

	me->receive_damage("qi", 100);
	me->receive_damage("jing", 100);
	me->start_busy(1);

	lvl = me->query_skill("literate", 1);
	if (lvl >= 200)
		write("你看了半天，觉得这首诗写的很好，不过似乎没什么特别之处。\n");
	else
	if (lvl >= 100)
		write("你觉得这上面的诗大有寓意，不由的尽心苦思。\n");
	else
	if (lvl >= 1)
		write("你心中暗想：这定是前辈高手留下的秘籍，这些词句可要好好分析。\n");
	else
	if (random(10)>2 && SKILL_D("taixuan-gong")->valid_learn(me))
	{
		write("你望着上面的笔划，逐渐进入一个玄妙的境界，全身随之舞动，对《太玄功》开始有所感悟。\n");

	            me->add("learned_points", 50);
	            me->improve_skill("taixuan-gong", 100 + random(me->query("int")*50));
	} else
		write("你潜心琢磨上面的笔划，似有所悟，偏偏又抓不住要领。\n");

	return 1;
}

void init()
{
	add_action("do_study", "think");
	add_action("do_study", "study");
}
