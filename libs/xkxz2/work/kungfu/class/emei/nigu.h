// emei nigu apprentice
// made by jackie

void init()
{
	add_action("do_kneel", "kneel");
}

mixed ask_for_join()
{
	object me;

	me = this_player();

	if( (int)me->query("combat_exp", 1) > 10000 && (string)me->query("title") != "峨嵋派俗家弟子")
		return "峨眉山可容不下施主这么武功高强的人。\n";
        if (me->query("marry"))
		return notify_fail("你尘缘未了，何谈出家呢？\n");

	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟贫尼开这等玩笑？\n";
	
	if( (string)me->query("gender") != "女性") 
		return "阿弥陀佛！我不收男弟子。施主还是请回吧。\n";

	if( (string)me->query("gender") != "女性" )
		return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去嵩山少林寺受戒。\n";

	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "文", "仪", "妙"});

	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的一缕青丝尽数剃去。\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("smile");
	command("recruit " + me->query("id"));
	command("chat " + me->query("title") + me->query("name") + 
		"于今日" + NATURE_D->game_time() + "在峨眉山受戒出家，取法名" + new_name + "！\n");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
        me->set("shen", 0);
	if (me->query("family/family_name") == "峨嵋派")
		me->set("title", "峨嵋派第五代弟子");

	return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

 // string name, new_name;

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "峨嵋派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能跟我学艺。");
		return;
	}

	if ( ob_fam["generation"] == 0 )
	{
		command("say 阿弥陀佛！贫尼就收下你做我的弟子了。");
		command("recruit " + ob->query("id"));
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫尼哪里敢当 !");
		return;
	}

	return;
}
