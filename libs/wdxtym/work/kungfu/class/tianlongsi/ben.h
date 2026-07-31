// ben.h for fight

int accept_touxi(object ob)
{
	object kr;

	if (is_killing(ob->query("id")))
		return 1;

	if (! objectp(kr = present("ku rong")))
		return 1;

	command("say 枯荣大师！这" + RANK_D->query_rude(ob) +
		"好无礼，竟然出手暗算！");
	kr->start_fight(ob);
    	return 1;
}

int accept_hit(object ob)
{
	object kr;

	if (is_killing(ob->query("id")))
		return 1;

	if (! objectp(kr = present("ku rong")))
		return 1;

	command("say 枯荣大师！这" + RANK_D->query_rude(ob) +
		"打上门来了！");
	kr->start_fight(ob);
    	return 1;
}

int accept_kill(object ob)
{
	object kr;

	if (is_killing(ob->query("id")))
		return 1;

	if (! objectp(kr = present("ku rong")))
		return 1;

	command("say 枯荣大师！这" + RANK_D->query_rude(ob) +
		"妄图行凶，强抢剑谱！");
	kr->start_fight(ob);
	return 1;
}

int accept_fight(object ob)
{
	command("say 善哉！善哉！施主何出此言？");
    	return 0;
}

int accept_ansuan(object ob)
{
	return notify_fail("那人气度庄严，你不敢贸然下手。\n");
}
