void check_shou(object me);

void init()
{
	object me;
	me = this_player();

	call_out("check",1,me);
}

void attempt_apprentice(object ob)
{
	object me;
	me = this_object();

	command("say 阿弥陀佛，善哉！善哉！");

	if ((string)ob->query("gender") != "男性" )
	{
		command("say 这位施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}

	if (ob->query("family/family_name") != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本寺素无来往，不知此话从何谈起？");
		command("say 施主若要入我少林，还是先拜铜字辈弟子为师的好。");
		return;
	}

	if ( me->query("family/generation") >= ob->query("family/generation") )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	check_shou(ob);
	return;
}