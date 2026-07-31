// by darken@SJ

inherit F_SSERVER;
#include <ansi.h>
#include <combat.h>

string perform_name(){ return HBBLU"黑 砂 掌"NOR; }
int perform(object me, object target)
{
	string msg;
	int ap, dp;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 ||  !target->is_character()
	 ||  !me->is_fighting(target) )
		return notify_fail("「黑砂掌」只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 150 )
		return notify_fail("你的归元吐纳法修为未到，无法使出黑砂掌。\n");

	if( (int)me->query_skill("shuishangpiao", 1) < 150 )
		return notify_fail("你的水上漂修为未到，无法使出黑砂掌。\n");

	if( me->query_skill_mapped("parry") != "tiezhang-zhangfa" 
	|| me->query_skill_prepared("strike") != "tiezhang-zhangfa")
		return notify_fail("你现在无法使用「黑砂掌」！\n");

	if( me->query_temp("weapon") && !me->query_temp("tzzf") )
		return notify_fail("你手持武器，如何使用「黑砂掌」？\n");

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 150 )
		return notify_fail("你的铁掌修为未到，无法使出黑砂掌。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你现在内力太弱，不能出黑砂掌。\n");

	if( target->query_condition("no_force") )
		return notify_fail(target->name(1)+"已经被你击中了，不需要再使用黑砂掌。\n");
                

	msg = HBBLU"\n$N双手一错，一上一下向$n的胸口及丹田击到！\n"NOR;

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);

	if ( me->query_skill("tiezhang-zhangfa", 1) > 350 )
		ap += random(ap/3);

	if ( target->is_busy())
		dp -= dp/3;

	if (random(ap + dp ) > dp ) {
		msg += HIR"结果$N双双击中，$n真气一窒，内息再也无法自由运转！\n"NOR;
		target->add_condition("no_force", 4);
		me->add("neili",- 200);
		me->add("jingli",- 100);
	}
	else {
		msg += HIR"$n勉强躲开，气息粗重。\n"NOR;
		me->add("neili",-100 );
		me->add("jingli",- 50);
	}
	me->start_busy(random(2));
	me->start_perform(2, "黑砂掌");
	message_vision(msg, me, target);
	return 1;
}

int help(object me)
{
        write(HBBLU"\n铁掌掌法之「黑砂掌」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                归元吐呐法等级 150 以上；
                水上漂等级 150 以上；
                铁掌掌法等级 150 以上；
                激发掌法为铁掌掌法；
                且备铁掌掌法。

HELP
        );
        return 1;
}
