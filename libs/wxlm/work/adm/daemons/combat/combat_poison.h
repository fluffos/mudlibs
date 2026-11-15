// me hit victim with poison in ob
void hit_with_poison(object me, object victim, object ob)
{
	mapping p, ap;
	string msg;
	string poison_type;

	if (! mapp(p = ob->query_temp("daub/poison")))
		return;

	if (! stringp(poison_type = ob->query_temp("daub/poison_type")))
		return;

	if (! p["remain"])
		return;

	// affect parameter
	ap = allocate_mapping(4);
	if (ob == me)
		ap["level"] = p["level"] * 9 / 10 + 1;
	else
		ap["level"] = p["level"] * 8 / 10 + 1;
		
	ap["id"]       = p["id"];
	ap["name"]     = p["name"];
	ap["duration"] = 1;

	if (p["remain"] > p["level"])
	{
		// decrase the remain poison
		p["remain"] -= p["level"];
	} else
	{
		// the poison has run out
		ob->delete_temp("daub");
	}

	msg = HIG "突然$n觉得受伤的地方有一些麻痒";
	if (p["id"] == victim->query("id"))
	{
		if (! victim->query_temp("has_announce/defense1"))
		{
			victim->set_temp("has_announce/defense1", 1);
			victim->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", victim :), victim), 15);
			msg += "。"NOR"\n" HIC "$n默一运功，冷笑两声：“好你个" +
			       RANK_D->query_rude(me) + "，居然在我面前卖弄" +
			       RANK_D->query_self_rude(victim) +
			       "毒药！真是假李鬼碰上真李逵了！”"NOR"\n";
		} else
			msg += "，不过$n并没有在意。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < victim->query_skill("poison", 1))
	{
		if (! victim->query_temp("has_announce/defense2"))
		{
			victim->set_temp("has_announce/defense2", 1);
			victim->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", victim :), victim), 15);
			msg += "。"NOR"\n" HIC "$n呼吸数次，嘿然冷笑道："
			       "“米粒之珠，也放光华？”"NOR"\n";
		} else
			msg += "，不过$n显然并没有把它放在心上。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < victim->query_skill("force") / 2)
	{
		if (! victim->query_temp("has_announce/defense3"))
		{
			victim->set_temp("has_announce/defense3", 1);
			victim->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", victim :), victim), 15);
			msg += "。"NOR"\n" HIC "$n深吸一口气，哈哈长笑道：“好家伙，居然" +
			       (ob == me ? "在身上淬毒" : "使用淬毒兵器") +
			       "，你这些下三滥的手段也敢到我面前卖弄？”"NOR"\n";
		} else
			msg += "，不过$n看起来似乎并无大碍。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	victim->affect_by(poison_type, ap);

	msg += "，大概是中毒了。"NOR"\n";
	if (p["level"] < victim->query_skill("force"))
	{
		msg += HIG "$n深深吸一了口气，面目凝重，手中的攻势陡然一紧。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	msg += HIR "$n闷哼一声，攻势顿缓，神情甚是痛苦。"NOR"\n";
	if (! victim->is_busy())
		victim->start_busy(1 + random(2));
	set_ahinfo(msg);
	return;
}

// me hit victim, but poison by victim in ob
void hit_poison(object me, object victim, object ob)
{
	mapping p, ap;
	string msg;
	string poison_type;

	if (! mapp(p = ob->query_temp("daub/poison")))
		return;

	if (! stringp(poison_type = ob->query_temp("daub/poison_type")))
		return;

	if (! p["remain"])
		return;

	if (me->query_temp("armor/hands"))
		return;

	// affect parameter
	ap = allocate_mapping(4);
	ap["level"]    = p["level"] * 7 / 10 + 1;
		
	ap["id"]       = p["id"];
	ap["name"]     = p["name"];
	ap["duration"] = 1;

	if (p["remain"] > p["level"])
	{
		// decrase the remain poison
		p["remain"] -= p["level"];
	} else
	{
		// the poison has run out
		ob->delete_temp("daub");
	}

	msg = HIG "突然$N觉得浑身有些麻痒";
	if (p["id"] == me->query("id"))
	{
		if (! me->query_temp("has_announce/defense1"))
		{
			me->set_temp("has_announce/defense1", 1);
			me->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", me :), me), 15);
			msg += "。"NOR"\n" HIC "$N默一运功，冷笑两声：“好你个" +
			       RANK_D->query_rude(victim) + "，居然在我面前卖弄" +
			       RANK_D->query_self_rude(victim) +
			       "的毒药！把你衣服上的毒药都还给我！”"NOR"\n";
		} else
			msg += "，不过$N并没有在意。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < me->query_skill("poison", 1))
	{
		if (! me->query_temp("has_announce/defense2"))
		{
			me->set_temp("has_announce/defense2", 1);
			me->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", me :), me), 15);
			msg += "。"NOR"\n" HIC "$N呼吸数次，嘿然冷笑道：“米粒之珠，也"
			       "放光华？你在衣衫上淬毒我就怕你了？”"NOR"\n";
		} else
			msg += "，不过$N显然并没有把它放在心上。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	if (p["level"] < me->query_skill("force") / 2)
	{
		if (! me->query_temp("has_announce/defense3"))
		{
			me->set_temp("has_announce/defense3", 1);
			me->start_call_out(bind((: call_other,
				__FILE__, "clear_announce", me :), me), 15);
			msg += "。"NOR"\n" HIC "$N深吸一口气，哈哈长笑道：“你居然在衣衫上"
			       "淬毒，这些下三滥的手段也敢到我面前卖弄？”"NOR"\n";
		} else
			msg += "，不过$N看起来似乎并无大碍。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	me->affect_by(poison_type, ap);

	msg += "，看来有些不妙。"NOR"\n";
	if (p["level"] < me->query_skill("force"))
	{
		msg += HIG "$N深深吸一了口气，面目凝重，手中的攻势陡然一紧。"NOR"\n";
		set_ahinfo(msg);
		return;
	}

	msg += HIR "$N脚步一个跄踉，攻势顿缓，神色难看之极。"NOR"\n";
	me->start_busy(1 + random(2));
	set_ahinfo(msg);
	return;
}