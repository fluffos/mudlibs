// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	object weapon;
	extra = me->query_skill("tmdao",1);
	if ( extra < 190) return notify_fail("你的天魔刀还不够纯熟！\n");
	dodskill = (string) me->query_skill_mapped("dodge");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天地人魔］只能对战斗中的对手使用。\n");

        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你手中没有装备刀类武器！\n");
        if( (int)me->query("neili")<500)
        return notify_fail("你现在内力太弱，不能使用！\n"NOR);


	weapon = me->query_temp("weapon");
	msg = HIY  "$N神气贯通，将天地人魔连环八式一气呵成！\n万魔初醒！" NOR;
	me->set_temp("action_flag", 1);
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
me->delete_temp("action_flag");
	me->add("neili", -350);
	me->start_busy(2);
	return 1;
}
