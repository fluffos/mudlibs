// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);

void auto_tuna(object me, int exercise_cost)
{
	if(!me||!me->query_temp("pending/auto_tuna"))
		return;
	if(me->is_busy())
		call_out("auto_tuna",1,me,exercise_cost);
	else if( (int)me->query("jing") < exercise_cost )
	{
		if (SKILL_D("force/regenerate")->exert(me, me))
		{
			if( (int)me->query("jing") < exercise_cost)
			{
				tell_object(me,"精力不足，休息中。。。\n");
				call_out("auto_tuna",10,me,exercise_cost);
			}
			else
			{
				call_out("auto_tuna",1,me,exercise_cost);
			}
		}
		else
		{
			tell_object(me,"精力不足，休息中。。。\n");
			call_out("auto_tuna",10,me,exercise_cost);
		}
	}
	else
	{
		tell_object(me,"托管中，继续吐纳。。。。。。\n");
		tell_object(me,ZJFORCECMD("tuna "+exercise_cost));
	}
}

int main(object me, string arg)
{
	seteuid(getuid());
	
	if ((int)me->query("age") < 14)
		return notify_fail("你现在还年轻，以后再练吧！\n");

	if ((int)me->query_skill("force",1)<10)
		return notify_fail("你还是先学些呼吸吐呐的技巧！\n");

	if (environment(me)->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if (me->is_fighting())
		return notify_fail("战斗中吐纳，好象只有神仙才能做到。\n");

	if (!arg || !sscanf(arg, "%d", respirate_cost))
	{
		respirate_cost = me->query("max_jing") *2/5;
		if (respirate_cost < 10 ) respirate_cost = 10;
		me->set_temp("pending/auto_tuna",respirate_cost);
		tell_object(me,ZJEXIT"northwest:"RED"站起来"NOR":halt\n");
	}

	if (respirate_cost <= 0)
		return notify_fail("你不是神仙！\n");

	if ((int)me->query("jing") < respirate_cost)
		return notify_fail("你现在精不足，无法修行精力！\n");

	if ((int)me->query("qi") * 100 / (int)me->query("max_qi") < 70)
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");

	if( environment(me)->query("no_dazuo") )
		return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");

	write("你闭上眼睛开始打坐。\n");
	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	me->set_short_desc("正坐在地下吐纳炼精。");
	message_vision("$N盘膝坐下，开始吐纳炼精。\n", me);
	me->start_busy(bind((:call_other, __FILE__, "respirating" :), me),
		       bind((:call_other, __FILE__, "halt_respirate" :), me));
	return 1;
}

int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain = (int)me->query_skill("force") / 10;
	jingli_gain = 1 + jingli_gain / 2 + random(jingli_gain);

	if (respirate_cost > 0)
	{
		if (jingli_gain > respirate_cost)
			jingli_gain = respirate_cost;
	
		if (jingli_gain > me->query("jing"))
		{
			jingli_gain = me->query("jing");
			respirate_cost = 0;
			me->set_temp("respirate_cost", 0);
			me->set_short_desc(0);
		} else
		{
			me->set_temp("respirate_cost",
				     respirate_cost -= jingli_gain);
		}
	
		me->add("jingli", jingli_gain);
		me->add("jing", -jingli_gain);
	
		if (respirate_cost > 0)
			return 1;
	}

	me->set_temp("pending/respirate", 0);
	me->set_short_desc(0);
	respirate_cost = 0;
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
		call_out("auto_tuna",1,me,me->query_temp("pending/auto_tuna"));

	if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else
	{
		if ((int)me->query("max_jingli") > (int)me->query_current_jingli_limit())
		{
			write("你的精力修为似乎已经达到了瓶颈。\n");
			me->set("jingli", (int)me->query("max_jingli"));
			return 0;
		}
		else
		{
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("你的精力增加了！！\n");
			return 0;
		}
	}

}

int halt_respirate(object me)
{
	tell_object(me, "你将真气压回丹田，站了起来。\n");
	tell_room(environment(me), me->name() + "深吸一口气，站了起来。\n", me);
	respirate_cost = 0;
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
			me->set_short_desc(0);
	me->set_temp("pending/respirate", 0);
	me->set_short_desc(0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : respirate|tuna [<耗费「精」的量>]
 
当你的年龄大于24岁以后，可以通过打坐修行，利用「炼精化气，炼
气化神，炼神还虚」的方法将你的精转变成精力。注意：你不能在不
能战斗的地方吐纳。

See also: exercise
HELP
	);
	return 1;
}
