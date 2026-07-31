void attempt_apprentice(object ob)
{
	object me;
	mapping my_fam, ob_fam;
	string title;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	title = ob->query("title");

        if ((int)ob->query("shen") <= (-1000))
{
                if ((my_fam) && (my_fam["family_name"] != "发梦二党") )
		{
			command("hmm");
			command("say 发梦二党乃正派人士的帮会，岂能容纳邪魔外道，你还不快滚出去！！！");
			return;
		}
		else
		{
			command("say 你身为发梦帮众却不主张正义，甘入魔道，这里容不下你！");
			command("kaichu "+ob->query("id"));
			return;
		}
	}
	if ( my_fam )
	{
		if ( my_fam["family_name"] == "发梦二党" )
		{
			if ( ob_fam["generation"] == my_fam["generation"] )
			{
				command("say 你我乃同辈弟子，切磋切磋倒是可以，拜师却是从何说起？");
				return;
			}
			if ( ob_fam["generation"] > my_fam["generation"] )
			{
				message_vision("$N一脸的诚惶诚恐道：究竟弟子犯了什么错，您要和弟子开这样的玩笑。\n", me);
				return;
			}
		}
	}
	command("say 好吧，" + RANK_D->query_respect(ob) +"既然拜我为师，还望努力练功，以期能为武林正义出一份力量。");
	command("recruit " + ob->query("id"));
	return;
}

