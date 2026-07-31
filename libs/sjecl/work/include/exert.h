int exert_check(object me)
{
	int num;
	string *skill, *gift, *other;
	
	skill = keys(requirement["skill"]);
	num = sizeof(skill);
	while (num--)
		if (me->query_skill(skill[num], 1) < requirement["skill"][skill[num]])
			return notify_fail("你的" + to_chinese(skill[num]) + "等级不够，还不能使用「" + exert_name() + "」\n");
	
	gift = keys(requirement["gift"]);
	num = sizeof(gift);
	while (num--)
		if (me->query_gift(gift[num], "postnatal") < requirement["gift"][gift[num]])
			return notify_fail("你的" + to_chinese(gift[num]) + "不够，还不能使用「" + exert_name() + "」\n");
			
	other = keys(requirement["other"]);
	num = sizeof(other);
	while (num--)
		if (me->query(other[num]) < requirement["other"][other[num]])
		{
			if (is_chinese(to_chinese(other[num])))
				return notify_fail("你的" + to_chinese(other[num]) + "不够，还不能使用「" + exert_name() + "」\n");
			else
				return notify_fail("你尚有条件未能达到，请阅读帮助文件。\n");
		}
	
	return 1;
}

string skill_name()
{
	string skill, *name;
	
	skill = file_name(this_object());
	name = explode(skill, "/");
	
	return name[2];
}

//int skill = this_player()->query_skill(skill_name());

varargs int exert_temp_check(object me, object target, int type, int flag)
{
	int num;
	string *query, *query_temp;

	if(!flag)
	{
		if (!type && (!target || !me->is_fighting()))
			return notify_fail("「" + exert_name() + "」只能在战斗中使用。\n");
        	if (type && (!target || !me->is_fighting(target)))
        		return notify_fail("「" + exert_name() + "」只能对战斗中的对手使用。\n");
        }
        
	query = keys(requirement_temp["query"]);
	num = sizeof(query);
	while (num--)
		if (me->query(query[num]) < requirement_temp["query"][query[num]])
			return notify_fail("你的" + to_chinese(query[num]) + "不够，无法施展「" + exert_name() + "」\n");
	
	query_temp = keys(requirement_temp["query_temp"]);
	num = sizeof(query_temp);
	while (num--)
		if (me->query_temp(query_temp[num]) == requirement_temp["query_temp"][query_temp[num]])
			return notify_fail("你正在使用「" + to_chinese(query_temp[num]) + "」。\n");

        return 1;
}

int checking(object me, object target, int flag) 
{
	if (!me
	|| !target
	|| !living(me)
	|| me->is_ghost()
	|| target->is_ghost()
	|| me->query_skill_mapped("force") != skill_name())
		return 1;
	
	if (flag)
		return 0;
	if (target == me)
	{
		if (me->is_fighting())
	        	return 0;
	        else
	        	return 1;
	}
	else if (!me->is_fighting(target))
	       	return 1;
	return 0;
}
// help function
int help(object me)
{
	int num;
	string *skill, *gift, *other;
	
	write("\n" + to_chinese(skill_name()) + "之" + exert_name() + "：\n");
	write("\n" + exert_help());
	
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
