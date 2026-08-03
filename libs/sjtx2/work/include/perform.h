// perform.c
// Create by athoi@sj

// 检查使用perform所需要的必要条件
int perform_check(object me)
{
	int num;
	string *skill, *gift, *other;

	// 检查武功
	skill = keys(requirement["skill"]);
	num = sizeof(skill);
	while (num--)
		if (me->query_skill(skill[num], 1) < requirement["skill"][skill[num]])
			return notify_fail("你的" + to_chinese(skill[num]) + "等级不够，还不能使用「" + perform_name() + "」\n");
	// 检查属性
	gift = keys(requirement["gift"]);
	num = sizeof(gift);
	while (num--)
		if (me->query_gift(gift[num], "postnatal") < requirement["gift"][gift[num]])
			return notify_fail("你的" + to_chinese(gift[num]) + "不够，还不能使用「" + perform_name() + "」\n");
	// 检查最大内力，精力等需要query()返回的东西
	other = keys(requirement["other"]);
	num = sizeof(other);
	while (num--)
		if (me->query(other[num]) < requirement["other"][other[num]])
		{
			if (is_chinese(to_chinese(other[num])))
				return notify_fail("你的" + to_chinese(other[num]) + "不够，还不能使用「" + perform_name() + "」\n");
			else
				return notify_fail("你尚有条件未能达到，请阅读帮助文件。\n");
		}

	return 1;
}
// 取得施用perform的skill的英文名称
string skill_name()
{
	string skill, *name;

	skill = file_name(this_object());
	name = explode(skill, "/");

	return name[2];
}
// 检查使用perform所需要的临时条件
// type 0代表空手武功 1代表兵器武功
// flag 0代表战斗中才能使用 1代表不需要战斗中
varargs int perform_temp_check(object me, object target, int type, string skill_type, int flag)
{
	object weapon;
	int num;
	string *query, *query_temp;

	if ( me->is_busy() && skill_name() != "tenglong-bifa" && perform_name() != HIG"神龙摆尾"NOR )
		return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

	if ( me->is_lost() && perform_name() != HIG"神龙摆尾"NOR )
		return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

	if(!flag && (!target || !me->is_fighting(target)))
		return notify_fail("「" + perform_name() + "」只能对战斗中的对手使用。\n");

	query = keys(requirement_temp["query"]);
	num = sizeof(query);
	while (num--)
		if (me->query(query[num]) < requirement_temp["query"][query[num]])
			return notify_fail("你的" + to_chinese(query[num]) + "不够，无法施展「" + perform_name() + "」\n");

	query_temp = keys(requirement_temp["query_temp"]);
	num = sizeof(query_temp);
	while (num--)
		if (me->query_temp(query_temp[num]) == requirement_temp["query_temp"][query_temp[num]])
			return notify_fail("你正在使用「" + to_chinese(query_temp[num]) + "」。\n");

        if (type == 1)
        {
        	if (!objectp(weapon = me->query_temp("weapon")))
        		return notify_fail("你没有使用武器，如何施展「" + perform_name() + "」？\n");
                if (weapon->query("skill_type") != skill_type)
        		return notify_fail("你使用的武器不对，难以施展「" + perform_name() + "」。\n");
	}

        if (!type && me->query_temp("weapon"))
        	return notify_fail("你拿着武器怎么能使用「" + perform_name() + "」？\n");

       	if (skill_type != "dodge")
       	{
        	if (me->query_skill_mapped(skill_type) != skill_name()
         	 || (!type && me->query_skill_prepared(skill_type) != skill_name()))
        		return notify_fail("你使用的外功不对，无法使用「" + perform_name() + "」！\n");
        	if (me->query_skill_mapped("parry") != skill_name()
        	 && me->query_skill_mapped("parry") != "douzhuan-xingyi"
        	 && me->query_skill_mapped("parry") != "qiankun-danuoyi"
        	 && !SKILL_D(me->query_skill_mapped("parry"))->valid_combine(skill_name()))
        	 	return notify_fail("你使用的招架不对，无法使用「" + perform_name() + "」！\n");
	}
	else
	{
		if (me->query_skill_mapped(skill_type) != skill_name())
			return notify_fail("你使用的轻功不对，无法使用「" + perform_name() + "」！\n");
	}

	return 1;
}
// 检查呼叫call_out的perform是否可以继续持续
// flag 0代表需要战斗中才能持续 1代表不需要
int checking(object me, object target, object weapon, string skill_type, int flag)
{
	if (!me
	|| !target
	|| !living(me)
	|| me->is_ghost()
	|| target->is_ghost()
	|| !present(target, environment(me))
	|| me->query_skill_mapped(skill_type) != skill_name()
	|| me->query_skill_mapped("parry") != skill_name())
		return 1;
	if (flag)
	{
		if (!weapon
		&& (me->query_temp("weapon")
	           || me->query_temp("secondary_weapon")
	           || me->query_skill_prepared(skill_type) != skill_name()))
	        	return 1;
	        if (weapon && (me->query_temp("weapon") != weapon))
	        	return 1;
	}
	else if (target == me)
	{
		if (!weapon
		&& (!me->is_fighting()
	           || me->query_temp("weapon")
	           || me->query_temp("secondary_weapon")
	           || me->query_skill_prepared(skill_type) != skill_name()))
	        	return 1;
	        if (weapon
	        && (!me->is_fighting() || me->query_temp("weapon") != weapon))
	        	return 1;
	}
	else
	{
		if (!weapon
		&& (!me->is_fighting(target)
	           || me->query_temp("weapon")
	           || me->query_temp("secondary_weapon")
	           || me->query_skill_prepared(skill_type) != skill_name()))
	        	return 1;
	        if (weapon
	        && (!me->is_fighting(target) || me->query_temp("weapon") != weapon))
	        	return 1;
	}
	return 0;
}
// 躲闪的描述
string dodge_msg(object target)
{
	string dodge_skill;

	dodge_skill = target->query_skill_mapped("dodge");
        if( !dodge_skill )
              	dodge_skill = "dodge";
        return SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
}
// 当前受伤状态的描述
varargs string status_msg(object ob, int effective)
{
	int jing_ratio, qi_ratio;

	if ( effective )
	{
		jing_ratio = ob->query("eff_jing") * 100 / ob->query("max_jing");
		qi_ratio = ob->query("eff_qi") * 100 / ob->query("max_qi");

		return jing_ratio > qi_ratio
		? "( $n" + COMBAT_D->eff_status_msg(qi_ratio) + " )\n"
		: "( $n" + COMBAT_D->eff_status_msg(jing_ratio) + " )\n";
	}
	else
	{
		jing_ratio = ob->query("jing") * 100 / ob->query("max_jing");
		qi_ratio = ob->query("qi") * 100 / ob->query("max_qi");

		return jing_ratio > qi_ratio
		? "( $n" + COMBAT_D->status_msg(qi_ratio) + " )\n"
		: "( $n" + COMBAT_D->status_msg(jing_ratio) + " )\n";
	}
}
// help function
int help(object me)
{
	int num;
	string *skill, *gift, *other;

	write("\n" + to_chinese(skill_name()) + "之" + perform_name() + "：\n");
	write("\n" + perform_help());

	write("\n要求：\n");
	skill = keys(requirement["skill"]);
	num = sizeof(skill);
	while (num--)
		write("\t" + to_chinese(skill[num]) + "：" + requirement["skill"][skill[num]] + "\n");
	gift = keys(requirement["gift"]);
	num = sizeof(gift);
	while (num--)
		write("\t" + to_chinese(gift[num]) + "：" + requirement["gift"][gift[num]] + "\n");
	other = keys(requirement["other"]);
	num = sizeof(other);
	while (num--)
		write("\t" + to_chinese(other[num]) + "：" + requirement["other"][other[num]] + "\n");

	return 1;
}

mapping get_requirement()
{
	return requirement;
}

mapping get_requirement_temp()
{
	return requirement_temp;
}