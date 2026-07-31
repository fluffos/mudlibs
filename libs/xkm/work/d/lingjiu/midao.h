// By xuanyuan
// road: /d/lingjiu/midao1

int do_study(string);

void init()
{
	add_action("do_study", "study");
	add_action("do_study", "du");
	add_action("do_study", "lingwu");
}
int do_study(string arg)
{
	object me;
        mapping fam;

	me = this_player();

	if ( !arg || arg != "fuhao" )
		return notify_fail("什么？\n");

        if (!mapp(fam = me->query("family")) || (string)me->query("family/family_name") != "灵鹫宫") 
		return notify_fail("你不是灵鹫宫子弟，领悟不到石壁中所刻的怪异符号。\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if (me->query("jing") < 60)
		return notify_fail("你的精力不够！\n");

	me->receive_damage("jing", random(60), "心力绞瘁死了");

	message_vision("$N正专心研读石壁上的怪异符号。\n", me);

	if (   (int)me->query_skill("bahuang-gong", 1) < 120
		&& (int)me->query_skill("liuyang-zhang", 1) < 120
		&& (int)me->query_skill("zhemei-shou", 1) < 120
		&& (int)me->query_skill("tianyu-qijian", 1) < 120){
		message_vision("$N手扶石壁，脸色大变，摇摇欲坠。\n", me);
		message_vision("忽然$N“啊、啊”两声惊呼，身形晃动，跟着摔倒在地。\n", me);
		me->unconcious();
		return 1;
		}

	switch( random(3) ) 
	{
	    case 0:
		if ( (int)me->query_skill("liuyang-zhang", 1) < 200)
		{
			me->improve_skill("liuyang-zhang", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对天山六阳掌有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 1:
		if ( (int)me->query_skill("zhemei-shou", 1) < 200)
		{
			me->improve_skill("zhemei-shou", me->query_int());
			write("你对着石壁琢磨了一回儿，似乎对天山折梅手有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	    case 2:
		if ( (int)me->query_skill("tianyu-qijian", 1) < 200)
		{
			me->improve_skill("tianyu-qijian", me->query("int"));
			write("你对着石壁琢磨了一回儿，似乎对天羽奇剑有点心得。\n");
			me->set_temp("shibi1_learned",1);
		}
	}

	if ( !me->query_temp("shibi1_learned") )
	{
		write("你对着石壁琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}
	return 1;
}