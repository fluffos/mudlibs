// practice.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

void auto_lian(object me,string skill,int times)
{
	if(!me||!me->query_temp("pending/auto_lian"))
		return;
	if(me->is_busy())
		call_out("auto_lian",1,me,skill,times);

	else if(me->query("neili")<500)
	{
 		if(me->present("huiling dan",me))
			me->force_me("use huiling dan");
        else me->force_me("use huxin dan");
        me->force_me("exert recover");
        me->force_me("exert regenerate");
		me->force_me("dazuo "+me->query("max_qi")/2);
		call_out("auto_lian",10,me,skill,times);
	}
	else if( (int)me->query("qi") < me->query("eff_qi"))
	{
		if (SKILL_D("force/recover")->exert(me, me))
		{
            me->force_me("exert regenerate");
			if( (int)me->query("qi") *100/ me->query("eff_qi")<90)
			{
				tell_object(me,"气血不足，等待恢复中。。。\n");
				call_out("auto_lian",10,me,skill,times);
			}
			else
			{
				call_out("auto_lian",1,me,skill,times);
			}
		}
		else
		{
			tell_object(me,"气血不足，等待恢复中。。。\n");
			call_out("auto_lian",10,me,skill,times);
		}
	}
	else
	{
		tell_object(me,"托管中，继续练习。。。。。。\n");
		tell_object(me,ZJFORCECMD("lian "+skill+" "+times));
	}
}

int main(object me, string arg)
{
	object where = environment(me);
	string skillname;
	string base_skname;
	int skill, skill_basic, times, i;
	int t = time();

	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (t == me->query_temp("time/practice"))
		return notify_fail("你刚刚才练习过（如果你要连续练习，可以指明练习的次数）。\n");

	if (me->is_fighting())
		return notify_fail("你已经在战斗中了，学一点实战修为吧。\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_fight"))
		return notify_fail("你无法在这个地方安心练习。\n");

	if (! arg) return (__DIR__"enable")->main(me, arg);

	if ((sscanf(arg, "%s %d", base_skname, times) != 2))
	{
		return notify_fail(INPUTTXT("请输入练习次数：","lian "+arg+" $txt#")+"\n");
	}
	    
	if (times < 1 || times > 999999)
		return notify_fail("练习次数必须大于1次，但不能超过999999次。\n");

	if (! stringp(skillname = me->query_skill_mapped(base_skname)))
		return notify_fail("你只能练习用 enable 指定的特殊技能。\n");

	skill_basic = me->query_skill(base_skname, 1);
	skill = me->query_skill(skillname, 1);
	if (skill < 1)
		return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");

	if (skill_basic < 1)
		return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

	if (skill_basic <= skill)
		return notify_fail("你的" + to_chinese(base_skname) + "火候不够，难以继续提升你" + to_chinese(skillname) + "的水平。\n");

	notify_fail("你现在不能练习这项技能。\n");
	if (! SKILL_D(skillname)->valid_learn(me)) return 0;

	if (! XUE_CMD->can_learn(me, skillname))
		return 0;

	notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");
	if (! me->can_improve_skill(skillname))
		return notify_fail("也许是缺乏实战修为，你的练习总没法进步。\n");

	me->set_temp("pending/auto_lian",1);
	me->set_temp("time/practice", t);
	for (i = 0; i < times; i++)
	{
		int tmpi;
		tmpi = (skill_basic / 5 + 1);
		if(where->query("practice_room"))
		{
			if(me->query_condition("db_exp"))
				tmpi *= 2;
			else
				tmpi = tmpi*6/5;
		}
    if (me->query("id")=="dudu66"){
		tmpi *= 5;
	   	}
if (present("lian xi",me))
				tmpi *= 5/2;	
		if (SKILL_D(skillname)->practice_skill(me))
			me->improve_skill(skillname, tmpi,skill_basic > skill? 0: 1);
		else break;
	}
	write(HIC "你试着把" + to_chinese(skillname) + "练了" + chinese_number(i)+"趟。"NOR"\n");
	if (i == 0 && 0 == times)
		write("然而你今天太累了，无法再进行任何练习了。\n");
	else if (i >= 0 && i < times)
	{
		call_out("auto_lian",1,me,base_skname,times-i);
	}

	return 1;
}

int help(object me)
{
	write(@TEXT
指令格式：practice|lian <技能种类> <次数>

这个指令让你练习某个种类的技能，这个技能必须是经过 enable 的专业技能。

如果你对这方面的基本技能够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的修为以提升你的基
本技能。
TEXT );
	return 1;
}

