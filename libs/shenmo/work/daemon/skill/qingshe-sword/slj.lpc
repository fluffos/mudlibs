// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage,ap,dp;
	object weapon;
	extra = me->query_skill("qingshe-sword",1);
	if ( extra < 200) return notify_fail("你的[这门武功]还不够纯熟！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你现在内力太弱，不能使用绝招。\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［神龙剑］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
if (extra>=200) extra=200;

if (random(3)==0) target->start_busy(2);

me->add_temp("apply/damage", 1500);
me->add_temp("apply/attack", 100);

	msg =  HIW "$N大喝一声：神龙剑！\n"+HIR "龙形－－$N抡动手中$w，棍风呼啸，打向$n的$l！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC "凤形－－$N手中$w化做剑影重重，将$n团团围住！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

     msg =  HIW "虎形－－$N向前一纵，手中$w狂舞，向$n猛扑过去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = HIY "豹形－－$N欺身急进，手中$w头尾齐出，分打$n的两处要害！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = HIG "猿形－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = HIB "蛇形－－$N身影绕着$n连续晃动，手中$w连发，扫向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

   msg = GRN "鹰形－－$N身形纵起，手中$w自上而下，迅猛无比，砸向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);


me->add_temp("apply/damage", -1500);
me->add_temp("apply/attack", -100);
	     ap = me->query("combat_exp");
        dp = target->query("combat_exp");
 damage=extra*2+300;
 msg = HIW "一剑摧心－－ $N" HIW "一声暴喝，手中" + weapon->name() +
                      HIW "直劈而下，只听呼啸声大作，地上的尘土受内力所激纷纷飞扬而起。\n" NOR;
damage = extra * 2 + random(extra);

        if (random(ap) > dp/2)
        {
        target->receive_damage("qi", damage*2,me);
        target->receive_wound("qi", damage,me);

        msg += HIR "$n" HIR "只觉得$N" HIR "内力犹如"
                                           "排山倒海一般，怎能抵挡？“哇”的一下吐出一大口鲜血。\n" NOR;
                        }
else
	{
                msg += CYN "可是$n" CYN "内功深厚，奋力接下$N"
                       CYN "这一招，丝毫无损。\n" NOR;
}
message_combatd(msg, me, target);
	me->add("neili",-380);
	me->start_busy(3);
	return 1;
}
