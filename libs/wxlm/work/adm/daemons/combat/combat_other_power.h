//新增特效一：封脉 限制敌方释放绝技
int ban_pfm(object me,int time)
{
	if( !me ) return 0;

	if (me->query_temp("ban_pfm/time"))
	{
		// 封脉时间是否大于或者等于现在的时间，如果是则增加时间，否则设定为现在的时间加上封脉时间
		if (me->query_temp("ban_pfm/time") >= time())
		{
			me->add_temp("ban_pfm/time",time);
		}
		else
		{
			me->set_temp("ban_pfm/time",time()+time);
		}

		//提示我被新增封脉时间多少秒
		tell_object(me,HIR"你的被封脉时间增加了"+time+"秒。\n"NOR);
	}

	return 1;
}

//新增特效二:封脉化解绝技
int unban_pfm(object me)
{
	if( !me ) return 0;

	if (me->query_temp("ban_pfm/time"))
	{
		//提示我被封脉时间多少秒
		tell_object(me,HIR"你的被封脉时间减少。\n"NOR);
		me->delete_temp("ban_pfm/time");
	}

	return 1;
}


//角力判定
//对比双方的后天膂力和内力，对比方式是：后天膂力 * 30 + 内力

/**
 * 角力判定函数
 * @param me 发起角力的对象
 * @param ob 被角力的对象
 * @return 1表示me胜利，0表示ob胜利
 */
int judge_power(object me, object ob)
{
	int my_power, ob_power, random_factor;
	
	// 基础力量计算
	my_power = me->query_str() * 30 + me->query("max_neili");
	ob_power = ob->query_str() * 30 + ob->query("max_neili");
	
	// 引入随机波动，范围为±15%
	random_factor = 85 + random(31); // 85%到115%之间的随机值
	my_power = my_power * random_factor / 100;
	
	random_factor = 85 + random(31);
	ob_power = ob_power * random_factor / 100;
	
	// 太极拳特殊加成
	if (me->query_skill("taiji-quan", 1) > ob->query_skill("force", 1))
	{
		if (random(2))
		{
			ob_power = ob_power - ob_power/10;
		}
	}
	
	// 力量相差在5%以内视为相等
	if (abs(my_power - ob_power) <= my_power / 20)
	{
		return random(2);
	}
	
	return (my_power > ob_power) ? 1 : 0;
}

//获取意境等级
int get_skill_aoyi_level(object me,string skill_name)
{
	int level = 0;

	if (level = me->query("skill_aoyi/" + skill_name))
	{
		level += me->query_temp("skill_aoyi_up");
	}
	
	// 如果意境是通用意境，则检查是否装配
	if (AOYI_D->is_general_aoyi(skill_name))
	{
		if (!me->query("aoyi_general/" + skill_name))
		{
			level = 0;
		}
	}

	return level;
	
}




