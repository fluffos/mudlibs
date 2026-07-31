void init()
{
	object me;
	me = this_player();

	call_out("check",1,me);

	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	object me;
	me = this_object();

	if( (string)ob->query("gender") != "男性" )
	{
		command("say 阿弥陀佛！这位施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！");

	if ( ob->query("combat_exp") > 10000 && ob->query("family/family_name") != "少林派")
	{
		command("say 这位施主已是江湖成名人士，小寺不敢相容，施主若真心向佛，心中有佛也就是了。");
		return;
	}

	if ((int)ob->query("shen") < -1000)
	{
		command("say 这位施主入魔道已深，若真心向善，多作些善事再来皈依我佛不迟。");
		return;
	}

	if( (string)ob->query("class")!="bonze" )
	{
		ob->set_temp("pending/join_bonze", 1);
		command("say 施主若真心皈依我佛，请跪下(kneel)受戒。");
		return;
	}

	if ( me->query("family/generation") >= ob->query("family/generation") && ob->query("family/family_name") == "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	command("recruit " + ob->query("id"));
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "石", "金" });
	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;

	message_vision(
		"$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say 从今以后你的法名叫做" + new_name + "。");
	command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_record", me->query("PKS") + me->query("MKS"));
	me->set("shen_record", me->query("shen"));
	me->set_temp("pending/apprentice", this_object());
	command("recruit " + me->query("id"));

	return 1;
}