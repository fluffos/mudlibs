void init()
{
	object me;
	me = this_player();

	call_out("check",1,me);
}

void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	me = this_player();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	command("say 阿弥陀佛，善哉！善哉！");

	if( (string)ob->query("gender") != "男性" )
	{
		command("say 这位施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}

	if (my_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本寺素无来往，不知此话从何谈起？");
		command("say 施主若要入我少林，还是先拜铜字辈弟子为师的好。");
		return;
	}

	if ( ob_fam["generation"] > my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

	if (!me->query("bai_tie") && ob_fam["generation"] < my_fam["generation"])
	{
		command("say " + me->query("name") + "，少林寺寺规，未得你师傅允许，我不能收你为徒，你回去吧。");
		return;
	}

	command("say " + me->query("name") + "，你师傅" + my_fam["master_name"] + "向我推荐过你。");
	command("consider");
	tell_object(me,"\n");
	call_out("check_shou",1,me);
	return;
}