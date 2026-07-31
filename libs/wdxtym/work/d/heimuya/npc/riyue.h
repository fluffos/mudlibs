int permit_recruit(object ob)
{
	/*
	if (!wizardp(ob)) {
		command("say 对不起，管理大人没同意之前我不可以收徒！");
		return 0;
	}*/
	if ((int)ob->query("shen") > 100)
	{
		command("say " + RANK_D->query_respect(ob) +
			"我日月神教需要的是充满邪气的人士，我看你还是免了吧。");
		return 0;
	}
	
	if( ob->query("detach/日月神教") ||
	    ob->query("betrayer/日月神教") )
	{
		command("say 你当我日月神教是什么地方？想来就来，想走就走？！");
		return 0;
	}

	if( ob->query("betrayer/times") )
	{
		command("say 我日月神教虽为江湖人所不耻，却也不收不忠不信之徒。");
		return 0;
	}

	if( ob->query("family/family_name") &&
	    ob->query("family/family_name") != "日月神教" )
	{
		command("say 你已经有师傅了，是想混进我日月神教当奸细么？！");
		return 0;
	}

	return 1;
}
