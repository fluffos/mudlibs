// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	object weapon;
	extra = me->query_skill("huanhe-dao",1);
	if ( extra < 190) return notify_fail("你的［天地人魔连环八式］还不够纯熟！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天地人魔］只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-100);
	me->add_temp("apply/attack", 90);
me->add_temp("apply/damage", 1000);
	weapon = me->query_temp("weapon");
	msg = HIY  "$N神气贯通，将天地人魔连环八式一气呵成！\n万魔初醒！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "魔焰万丈！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "魔光乍现！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔独尊！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万刃天魔！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔回天！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔七现！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万魔归宗！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("shenzhao",random(10)+20);
	me->add_temp("apply/attack", -90);
me->add_temp("apply/damage", -1000);
	me->start_busy(2);
	return 1;
}
