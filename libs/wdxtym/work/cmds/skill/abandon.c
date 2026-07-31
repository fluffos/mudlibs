// abandon.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int skill_lvl, lvl;
    	int jingcost;
	string skill;
    	string name,ok;
	int lost,queren;
	mapping skills;

	if (! arg || arg == "")
		return notify_fail("你要放弃修为还是某一项技能？\n");

	if(sscanf(arg,"%s %d %d",skill,lvl,queren)==3)
	{
		if(lvl<1)
			return notify_fail("放弃单位至少需要1 。。。\n");
	}
	else if(sscanf(arg,"%s %d",skill,lvl)==2)
	{
		if(skill=="exp")
		{
			write(ZJOBLONG"你确定要放弃"+lvl+HIY"修为"NOR"吗？\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"确认:abandon "+arg+" 1\n");
			return 1;
		}
		else
		{
			write(ZJOBLONG"你确定要放弃"+lvl+"级"HIY+to_chinese(skill)+NOR"吗？\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"确认:abandon "+arg+" 1\n");
			return 1;
		}
	}
	else skill=arg;

    	if (me->is_fighting())
		return notify_fail("你正忙着打架呢，哪有时间做这种事？\n");

    	if (me->is_busy())
		return notify_fail("你正忙，没法静下心来。\n");

    	jingcost = me->query("int") + random(me->query("int"));
    	if (jingcost > me->query("jing"))
		return notify_fail("你无法集中精力。\n");

	if (skill == "exp")
	{
		if (me->query("combat_exp")>2000000 && me->query("zjvip/times")<1)
			return notify_fail("你目前的修为过高，无法忘记实战修为。\n");

		if (!queren)
			return notify_fail(INPUTTXT("请谨慎操作！"ZJBR"你想放弃多少的"HIY"修为"NOR"：","abandon exp"+" $txt#")+"\n");
		lost = me->query("combat_exp");
		if (lost < lvl)
			return notify_fail("你发现自己现在对武学简直就是一无所知。\n");

		if (10000000 < lvl)
			return notify_fail("一次最多只能忘掉10000000实战修为。\n");

		message("vision", me->name() + "坐下在凝神思索什么。\n",environment(me), me);
		tell_object(me, "你不再想拳脚兵器轻功内功，只是一门心思忘记武功。\n");
		me->start_busy(1);

		me->add("combat_exp", -lvl);
		switch (random(6))
		{
		case 0:
			tell_object(me, HIR "你又想起了很多温馨的往事，不由得沉浸其中。"NOR"\n");
			break;
		case 1:
			tell_object(me, HIR "你似乎又看到了遥远的童年，一时忘却了尘世间的烦恼。"NOR"\n");
			break;
		case 2:
			tell_object(me, HIR "你黯然一声长叹，只觉得自己为了武学荒废一生，实在无谓。"NOR"\n");
			break;
		case 3:
			tell_object(me, HIR "你心如止水，所有的武功都仿佛离自己远去了。"NOR"\n");
			break;
		case 4:
			tell_object(me, HIR "你抬头仰望天空，发现它明亮透析，说不出的娇媚，令你身心俱化。"NOR"\n");
			break;
		default:
			tell_object(me, HIR "你脑海中晃过当年无数刻苦修炼的日子，不由得暗自苦笑。"NOR"\n");
			break;
		}

		UPDATE_D->check_user(me);
		return 1;
	}

    	if (file_size(SKILL_D(skill)+".c")<0)
		return notify_fail("没有这项技能！\n");

    	name = to_chinese(skill);
    	if (name[0] < 160) name = "这项技能";
	if (!queren)
		return notify_fail(INPUTTXT("你想放弃多少级的"HIY+to_chinese(skill)+NOR"：","abandon "+skill+" $txt#")+"\n");

	if (!mapp(skills = me->query_skills())||undefinedp(skills[skill]))
		return notify_fail("你还不会这项技能！\n");

	skill_lvl = skills[skill];
	if (! skill_lvl)
	{
		me->delete_skill(skill);
		write("好了。\n");
		return 1;
	}


    	skill_lvl = skill_lvl - lvl;
    	if (skill_lvl < 1)
    	{
		me->delete_skill(skill);
		write("你集中精力不再想【" + name + "】，结果终于将它彻底忘记了。\n");
    	} else
    	{
		me->set_skill(skill, skill_lvl);
		write("你集中精力不再想【" + name + "】，结果有所效果。\n");
    	}
	return 1;
}

int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称> | exp

放弃你的实战修为或是某一项你所学过的技能，成功率和你的天赋有
关，只有能够休息的地方才能够静下心来忘记武功。如果你对这项技
能的修为比较高，一次不一定能够彻底的忘记。

有时候因为武功相克或者你不再打算在某项技能上再下功夫，就可以
使用这条指令放弃它。
TEXT );
	return 1;
}
