void greeting(object ob)
{

          if (!ob || !objectp(ob)) return;
          if (environment(ob) != environment(this_object())) return;
	if ((ob->query("riyue_drug")) && ((string)ob->query("family/family_name") != "日月神教"))
	{
		command("say " + RANK_D->query_respect(ob) + "既已加入圣教，服了本教圣药，怎么竟敢判教？");
		command("follow " + ob->query("id"));
		command("kill " + ob->query("id"));
		return;
	}

	if ((string)ob->query("family/family_name") == "日月神教")
		if (((string)ob->query("family/master_name") == "东方不败")
			|| ((string)ob->query("family/master_name") == "任我行"))
		{
			command("bow");
			command("say 圣教主千秋万载，一统江湖！");
			command("say " + "您老圣明英武，定会将圣教主的武功发扬光大。");
			return;
		}
		else
		{
			command("say 圣教主千秋万载，一统江湖！");
			return;
		}
	if ((int)ob->query("shen") > 10000)
	{
		command("heng " + ob->query("id"));
		command("say " + "老子最看不惯的就是所谓正道的侠客侠女，你有本事就跟我比划比划！");
	}
}

string ask_df()
{
	object ob;
	ob = this_player();

	if ((string)ob->query("family/family_name") != "日月神教")
	{
		return "我们圣教主文成武德，仁义英明，中兴圣教，泽被苍生，武功天下第一！\n";
	}
	if ((string)ob->query("family/master_name") == "东方不败")
	{
		command("bow");
		return "圣教主他老人家可好？属下每见教主金面一次，便觉精神
大振，做事特别有劲，全身发热，似乎功力修为陡增十年。\n";
	}
	if ((string)ob->query("family/master_id") == "ren woxing")
	{
		return "那是我教前教主，胆大包天，竟敢谋反作乱，最终被任教主所平。\n";
	}
	return "圣教主文成武德，仁义英明，中兴圣教，泽被苍生。\n";
}

string ask_ren()
{
	object ob;
	ob = this_player();

	if ((string)ob->query("family/family_name") != "日月神教")
	{
		return "那是我教前教主，几年前突然失踪，由东方教主继任。\n";
	}
	if ((string)ob->query("family/master_id") == "dongfang bubai")
	{
		command("bow");
		return "杨总管吩咐了，谁也不许提这个名字。\n";
	}
	if ((string)ob->query("family/master_id") == "ren woxing")
	{
		command("bow");
		return "圣教主他老人家可好？属下每见教主金面一次，便觉精神
大振，做事特别有劲，全身发热，似乎功力修为陡增十年。\n";
	}
	return "杨总管吩咐了，谁也不许提这个名字。\n";
}
