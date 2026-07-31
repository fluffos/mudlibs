void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

                if ((my_fam) && (my_fam["family_name"] != "发梦二党") )
	{
		command("say " + RANK_D->query_respect(ob) +"和我们发梦弟子向无来往，拜师去找戚恋霞师傅。\n");
		return;
	}
        if ( ((int)ob->query("shen") <= (-1000)) && (my_fam) )
	{
		command("say 你身为发梦弟子却不主张正义，甘入魔道,我不能要你！");
		command("kaichu "+ob->query("id"));
		return;
	}
        if (my_fam) {
	if ( ob_fam["generation"] == my_fam["generation"] )
	{
		command("say 你我乃同辈弟子，切磋切磋倒是可以，拜师却是从何说起？");
		return;
	}
      }
	if (ob->query("combat_exp")<50000)
	{
		command("say 学武应该扎扎实实，你功夫不够，拜我为师有害无益，还是算了吧。");
		return;
	}
	command("say 好吧，" + RANK_D->query_respect(ob) +"既然拜我为师，还望努力练功，以期能为武林正义出一份力量。");
	command("recruit " + ob->query("id"));
	return;
}


