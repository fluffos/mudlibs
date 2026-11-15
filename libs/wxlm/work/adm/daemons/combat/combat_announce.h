void announce(object ob, string event)
{

	if (!objectp(ob))
		return;
      
	switch (event)
	{
	case "kuilei":
		message_vision(NOR"$N施展神奇幻术，化作一道" HIW "流光" NOR "转瞬消逝于无形！\n", ob);
		
		break;

	case "dead":
		message_vision(NOR"$N" HIR "一口鲜血喷涌而出" NOR "，身形摇晃，" HIR "气绝身亡" NOR "，就此消殒！\n", ob);
		
		break;

	case "unconcious":
	tell_object(ob,json_encode((["code":"昏迷信息","info":"昏迷"])) + "\n");
	message_vision("\n"NOR"\n$N" HIW "状态不继" NOR "，" HIR "真气逆行" NOR "，一阵眩晕之下轰然倒地，昏死过去。\n", ob);
	player_escape(0,ob);
	break;

	case "revive":
		tell_object(ob,json_encode((["code":"昏迷信息","info":"清醒"])) + "\n");
		message_vision("$N缓缓运转" HIG "真气" NOR "，" HIY "神志渐复" NOR "，终于转醒过来。\n", ob);
		break;
	}
}

void clear_announce(object me)
{
	if (! objectp(me))
		return;

	me->delete_temp("has_announce");
}