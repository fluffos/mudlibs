int player_escape(object killer, object ob)
{
	object iob;
	string msg;

	if (! objectp(ob))
		return 0;

	// 是玩家么？
	if (! playerp(ob))
		return 0;

	if ((int)ob->query("combat/which_day") == time() / 86400 &&
	    (int)ob->query("total_count") > 0)
		return 0;

	// 真的晕倒了，察看是否是被别人有意打晕的
	if (! killer) killer = ob->query_defeated_by();
	if (! killer || ! playerp(killer) ||
	    ! killer->is_want_kill(ob->query("id")))
		return 0;

	if (ob->query("combat_exp") >= 150000)
		return 0;

	switch (random(7))
	{
	case 0:
		msg = "突然只听幽幽一声长叹，一掌轻轻按来。$N大吃一惊，不及"
		      "多加思索，只是抬手一格。匆忙之间只怕对手过于厉害，难"
		      "以招架，急忙向后跃开。却见来人并不追击，只是一伸手拎"
		      "起$n，转身飘然而去，仙踪渺然。\n";
		break;

	case 1:
		msg = "$N将$n打翻在地，“哈哈”一声笑声尚未落下，只听有人冷"
		      "哼一声，忽然间掌风袭体，$N顿感呼吸不畅，几欲窒息，慌"
		      "忙中急忙退后，待得立稳脚跟，却见$n早已无影无踪。\n";
		break;

	case 2:
		msg = "一人忽然掠至，喝道：“岂有此理？我龙岛主最恨此欺善怕"
		      "恶之辈，休走！”说罢一掌击来，$N奋力招架，一招之下几"
		      "欲吐血！只见来人轻轻提起$n，冷笑两声，转身离去，$N惊"
		      "骇之下，竟然说不出一句话来。\n";
		break;

	case 3:
		msg = "突然一人喝道：“且慢！”只见一道黑影掠到，飞起一脚将"
		      "$N踢了个跟头，左手拎起$n，冷冷对$N道：“今日所幸尚未"
		      "伤人命，你作恶不甚，饶你去吧！”$N捂胸运气，不住喘息"
		      "，眼睁睁的看着来人去了。\n";
		break;

	case 4:
		msg = "$N跨前一步，忽然看到面前已多了两人，一胖一瘦，一喜一"
		      "怒，不由暗生疑窦。一人手中亮出一面铜牌，笑道：“这位" +
		      RANK_D->quert_respect(killer)+ "，这面罚恶铜牌你收下可"
		      "好？”$N听了大吃一惊，手只是一软，哪里还敢搭半句话？"
		      "那瘦子冷冷看了过来，目光如电，$N讪讪笑了两声，目送两"
		      "人带了$n逍遥而去。\n";

	case 5:
		msg = "恰在此时，正逢一老者路过，只见他微一颦眉，喝道：“兀"
		      "那" + RANK_D->query_rude(killer)+ "，伤人做甚？”$N大"
		      "怒道：“你是何人，如此嚣张？”老者大怒，一掌拍落，$N"
		      "向上只是一格，“噗噜”一下双腿陷入土中，足有半尺。老"
		      "者森然道：“我乃侠客岛木岛主是也，如有不服，恭候大驾"
		      "！”此时$N内息如狂，连句场面话也说不出来，只能眼看$n"
		      "被那木岛主带了离去。\n";
		break;

	default:
		msg = "忽听“哈哈”一阵长笑，一人道：“龙兄，想不到我们三十"
		      "年不履中土，这些武林高手却是越来越不长进了！”另一人"
		      "道：“正是，看来赏善罚恶，漫漫无期，终无尽头。”$N听"
		      "得大汗涔涔而下，环顾四方却无一人，转回头来，更是大吃"
		      "一惊！连$n也不见了。\n";
		break;
	}

	if ((environment(killer) == environment(ob)) &&
	    killer->is_fighting(ob))
	{
		msg = replace_string(msg, "$n", ob->name());
		message_sort(msg, killer);
	} else
	{
		msg = "正逢一老者路过，见了" + ob->name() + "晕倒在地，叹口"
		      "气，将他扶起带走了。\n";
		message("vision", msg, environment(ob));
	}


	// 将身上带的东西放下
	foreach (iob in all_inventory(ob))
//		if (! iob->query("money_id") && ! iob->query("owner_id") && ! iob->query("equipped"))
                if ( iob->query("id")=="shaolin wuji")
			iob->move(environment(ob));


	// 初始化玩家的状态
	ob->clear_condition();
	ob->remove_killer(killer);
	killer->remove_killer(ob);

	// 通缉伤人凶手
	if (! killer->query_condition("killer"))
	{
		msg = "听说官府发下海捕文书，缉拿伤人凶手" + killer->name(1) + "。";
		killer->apply_condition("killer", 900);
	} else
	{
		msg = "听说官府加紧捉拿累次伤人的暴徒" + killer->name(1) + "。";
		killer->apply_condition("killer", 900 + (int)killer->query_condition("killer"));
	}
	CHANNEL_D->do_channel(this_object(), "rumor", msg);

	ob->move("/d/xiakedao/shiroom24");
	ob->set("startroom", "/d/xiakedao/shiroom24");
	ob->revive();
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("qi", 0);
	ob->set("jing", 0);

	if (intp(ob->query_busy()))
		ob->start_busy(30);

	tell_object(ob, "你睁开眼来，看到两位老者正在静坐修炼。\n"
		    HIG "龙岛主告诉你：" + RANK_D->query_respect(ob) +
			"，你要想离岛不妨和我说一声。"NOR"\n");

	return 1;
}