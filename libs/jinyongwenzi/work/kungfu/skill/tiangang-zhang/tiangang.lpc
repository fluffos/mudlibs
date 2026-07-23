// jingang-zhang

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      string *limbs;
	int count, damage = 0;
	int arg=(int)(me->query_skill("tiangang-zhang", 1) / 30);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「天罡」只能在战斗中对对手使用。\n");

	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能施展「天罡」。\n");

	if( (int)me->query_skill("tiangang-zhang", 1) < 150 )
		return notify_fail("你的天罡掌法不够娴熟，不会使用「天罡」。\n");

	if( (int)me->query_skill("xiantian-gong", 1) < 90 )
		return notify_fail("你的先天功等级不够，不能使用「天罡」。\n");

	if( (int)me->query_str() < 35 )
		return notify_fail("你的膂力不够强，不能使用「天罡」。\n");

	if( arg <= 1 )
		return notify_fail("至少要有两招才可组成「天罡」。\n");

	if( (int)me->query("neili", 1) < 1200 )
		return notify_fail("你现在内力太弱，不能使用「天罡」。\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("你现在的内力施展不了那么多招。\n");

//	if( (int)me->query_skill("tiangang-zhang", 1) < arg * 30 )
//		return notify_fail("你的天罡掌法还没有修练到那种境界！\n");

	message_vision(HIG"$N突然左掌向前一探，右掌倏地拍出，身随掌行，奔行愈速，双掌忽缓忽急拍出"+ chinese_number(arg) +"掌。\n\n"NOR,  
	              me, target);

	limbs = target->query("limbs");
	for(count = 0; count < arg; count++)
        {
	  message_vision(
		replace_string(
	  SKILL_D("tiangang-zhang")->query_action(me, me->query_temp("weapon"))["action"],
		"$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
     damage = damage+150+random(150);
        }    

	damage = (1 + me->query("jiali")/250) * damage / 2;
	if( arg*(random(me->query("combat_exp"))) > target->query("combat_exp") )
	{
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		COMBAT_D->report_status(target, 1);
		COMBAT_D->report_status(target, 0);
	}

   me->add("neili", -700 * arg);
     me->start_busy(15);

	return 1;
}
