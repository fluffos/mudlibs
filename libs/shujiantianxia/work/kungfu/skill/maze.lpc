// maze.c 奇门八卦迷阵

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, object target, int count, int skill);

int exert(object me, object target)
{
	string msg;
	int skill, ap, dp;
//<Added by mxzhao 2005/02/10>
	int count = 3;
//</Added by mxzhao 2005/02/10>

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target) )
		return notify_fail("布迷阵只能对战斗中的对手使用。\n");

	if(me->query_temp("thd/mazed")) 
		return notify_fail("你正在陷入别人布的迷阵中。\n");

	if(me->query("neili") < 600  ) 
		return notify_fail("你的内力不够。\n");

	if(me->query("jingli") < 400  )
		return notify_fail("你的精力不够。\n");

	if(me->query_skill("bihai-chaosheng", 1) < 120)
		return notify_fail("你的碧海潮生功等级不够。\n");

	if( me->query_skill_mapped("force") != "bihai-chaosheng")
		return notify_fail("你必须激发碧海潮生功。\n");

	if(me->query_skill("qimen-bagua", 1) < 120 )
		return notify_fail("你的奇门八卦等级不够。\n");

	if(me->query_temp("thd/maze")) 
		return notify_fail("你已经布了一个迷阵了。\n");

	skill = me->query_skill("qimen-bagua", 1);

	me->add("neili", -150);
	me->add("jingli",- 50);

	me->start_exert(2, "奇门迷魂阵");
	me->start_busy(random(2));

	if ( !me->is_perform())
		me->start_perform(2, "奇门迷魂阵");

	msg = HIY"\n$N突然跃起，左拍一掌，右挑一腿，将周围的石块、树枝移动了位置！";

	me->add_temp("apply/armor", skill/4);
	me->set_temp("thd/maze", skill/4);

	ap = me->query("combat_exp", 1);
	dp = target->query("combat_exp", 1);

	if( random( ap + dp ) > dp ) {
		msg += "$n陷入迷阵中，登时手足无措。\n"NOR;
		target->add_temp("apply/dexerity", -(skill/10));
		target->add_temp("apply/damage", -(skill/10));
		target->add_temp("apply/dodge", -(skill/10));
		target->set_temp("thd/mazed", 1);
		target->add_busy(3 + random(2));
		me->add("neili", -100);
		me->add("jingli",-100);
		me->set_temp("thd/maze_target", target);
//<Added by mxzhao 2005/02/10>
		count = skill/2;
//</Added by mxzhao 2005/02/10>
	}
	msg += "\n"NOR;
	message_vision(msg, me, target);
//<Modified by mxzhao 2005/02/10>
//	call_out("remove_effect", 1, me, target, skill / 2, skill);
	call_out("remove_effect", 1, me, target, count, skill);
//</Modified by mxzhao 2005/02/10>
	return 1;
}

void remove_effect(object me, object target, int count, int skill)
{
	if (objectp(me) && me->query_temp("thd/maze")){
		if (count-- > 0 && me->is_fighting(target)) {
			call_out("remove_effect", 1, me, target, count, skill);
			return;
		}
		me->add_temp("apply/armor", - (skill/4));
		me->delete_temp("thd/maze");
		if (!target || target->is_ghost(1)) return;
		me->delete_temp("thd/maze");
		me->delete_temp("thd/maze_target");
		if (target && me->is_fighting(target)) {
			tell_object(me, "你布的迷阵已经被" + target->name(1) + "破坏了。\n");
			if (userp(target) && living(target))
				tell_object(target, me->name(1) + "对你布的迷阵已经被你识破了。\n");
		}
		else {
			tell_object(me, "你布的迷阵已经失效了。\n");
		}
	}
	if (objectp(target) && target->query_temp("thd/mazed")){
		target->delete_temp("thd/mazed");
		target->add_temp("apply/dexerity", skill/10);
		target->add_temp("apply/dodge", skill/10);
		target->add_temp("apply/damage", skill/10);
	}
}

string exert_name(){ return HIY"迷阵"NOR; }

int help(object me)
{
        write(HIY"\n碧海潮生功之「迷阵」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 600 以上；
                当前精力 400 以上；
                碧海潮生功等级 120 以上；
                奇门八卦等级 120 以上；
                激发内功为碧海潮生功。

HELP
        );
        return 1;
}
