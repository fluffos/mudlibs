// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［乱泼风］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	 extra = me->query_skill("lansha-shou",1)/10;
   if ( extra < 5) return notify_fail("你的［蓝砂手］还不够纯熟！\n");
    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
	        if (extra> 200) extra=200;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N双掌血红，五指绽开，无数道掌风破空而出，隐隐带着雷声迅疾无比地击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "$N猛一个翻身，迅捷无比地向$n踢出飞天一腿！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = HIR "$N使出鹰爪功中的［十指擒龙］，双手宛若布下天罗地网，招招扣向$n的关节要害！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   msg = HIR"$N身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n身边，袖中伸出纤纤素手，五根手指疾抓$n$l。\n"NOR ;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   msg = HIR"$N一招得手，更不稍停，反掌间五根手指已向$n的头顶插了下去。\n"NOR;
   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili",-80);
	me->start_busy(2);
	return 1;
}
