// gaibang.h for fight and get 青竹令

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if (obj->query("id") != "qingzhu ling")
	{
		command("say 啥玩艺？自个留着吧！");
		return 0;
	}

	if (! ob_fam || ob_fam["family_name"] != "丐帮")
	{
		command("say 你哪里来的青竹令？");
		return 0;
	}

	if (ob->query("combat_exp") < 1000)
	{
		command("say 奇了怪了，你这种水平梁长老怎么会给你有青竹令？");
		return 0;
	}

	if (ob->query_temp("have_cloth") && present("po bu", ob))
	{
		command("say 你不是已经有破布么?");
		return 0;
	}

	if (((ob->query("beggarlvl") == 0) &&
	     (ob->query("combat_exp") <= 1000)) ||
	    ((ob->query("beggarlvl") == 1) &&
	     (ob->query("combat_exp") <= 2000)) ||
	    ((ob->query("beggarlvl") == 2) &&
	     (ob->query("combat_exp") <= 5000)) ||
	    ((ob->query("beggarlvl") == 3) &&
	     (ob->query("combat_exp") <= 8000)) ||
	    ((ob->query("beggarlvl") == 4) &&
	     (ob->query("combat_exp") <= 10000)) ||
	    ((ob->query("beggarlvl") == 5) &&
	     (ob->query("combat_exp") <= 30000)) ||
	    ((ob->query("beggarlvl") == 6) &&
	     (ob->query("combat_exp") <= 100000)) ||
	    ((ob->query("beggarlvl") >= 7) &&
	     (ob->query("combat_exp") <= 300000)))
	{
	     command("say 就你那点脓水？我看就算了吧。\n");
	     return 0;
	}

	if (((ob->query("beggarlvl") == 0) &&
	     (me->query("title") == "丐帮一袋弟子")) ||
	    ((ob->query("beggarlvl") == 1) &&
	     (me->query("title") == "丐帮二袋弟子")) ||
	    ((ob->query("beggarlvl") == 2) &&
	     (me->query("title") == "丐帮三袋弟子")) ||
	    ((ob->query("beggarlvl") == 3) &&
	     (me->query("title") == "丐帮四袋弟子")) ||
	    ((ob->query("beggarlvl") == 4) &&
	     (me->query("title") == "丐帮五袋弟子")) ||
	    ((ob->query("beggarlvl") == 5) &&
	     (me->query("title") == "丐帮六袋弟子")) ||
	    ((ob->query("beggarlvl") == 6) &&
	     (me->query("title") == "丐帮七袋弟子")) ||
	    ((ob->query("beggarlvl") == 7) &&
	     (me->query("title") == "丐帮八袋弟子")) ||
	    ((ob->query("beggarlvl") == 8) &&
	     (me->query("title") == "丐帮九袋长老")))
	{
		if (! ob->query_temp("have_cloth"))
		{
			ob->set_temp("fight_ok", me->query("id"));
			command("say 好，既然已有青竹令，那就看你的运气了。\n");
			destruct(obj);
			return 1;
		}
	}

	command("smile");
	command("say 升袋当然只升不降。跳升也是不行的。\n");
	command("say 这东西给你还是自己留着吧。\n");
	return 0;
}

int accept_fight(object ob)
{
	if (query_competitor() == ob)
		return 1;

	if (ob->is_fightint())
		return notify_fail("人家正在比武呢，你这么出手不太妥当吧！\n");

	if (ob->query("family/family_name") != query("family/family_name"))
	{
		command("say 免...我可没兴趣和你动手。");
		return 0;
	}

	if (ob->query_temp("fight_ok") != query("id"))
	{
		command("say 你向梁长老要了青竹令再来找我。");
		return 0;
	}

	ob->delete_temp("fight_ok");
	command("say 好！就让我试一试你的身手，看看你究竟有啥水平？");
	competition_with(ob);
	return 1;
}

void lost()
{
	object ob;
	object obj;

	ob = query_competitor();
	command("say 大爷今天心情好，算你运气。拿这块破布找简长老去！");
	message_vision("$N交给$n一块破布。\n", this_object(), ob);
	ob->set_temp("newtitle", query("title"));
	ob->set_temp("have_cloth",1);
	obj = new(__DIR__"obj/po-bu");
	obj->move(ob, 1);
	::lost();
}

void win()
{
	object ob;

	ob = query_competitor();
	if (! objectp(ob))
	{
		command("heihei");
		return;
	}
	command("say 就你这个" + RANK_D->query_rude(ob) +
		"也想升袋？也不看看自家长了几根毛！");
	::win();
}

int permit_recruit(object ob)
{
	if (ob->query("detach/丐帮") || ob->query("betrayer/丐帮"))
	{
		command("say 哈哈！想吃回头草？没门！");
		return 0;
	}

	if (ob->query("betrayer/times"))
	{
		command("say 我们丐帮虽然是叫花子，但是堂堂正正行路，不"
			"会收判师之徒的！");
		return 0;
	}

	if (ob->query("family/family_name") &&
	    ob->query("family/family_name") != "丐帮")
	{
		command("say 嘿！你既然已经有了名师指点，还来我们丐帮干什么？");
		return 0;
	}

	return 1;
}
