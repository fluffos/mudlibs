#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("tiexue-hammer",1);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hammer")
                return notify_fail("你用的武器不对！\n");
	if ( extra < 50) return notify_fail("你的铁雪锤法还不够纯熟！\n");
    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili", 1) < 400 )
	return notify_fail("你的内力还未练成，不能使用！\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［反转流星］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
if (random(2)==0) target->start_busy(3);
        me->add_temp("apply/attack", extra/2);    
        me->add_temp("apply/damage", extra*2);
	msg = HIY  "$N使出铁雪锤法中的［反转流星］，假意抽身急退，蓦地反身抖手一锤！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N紧跟一招，另一锤反身又是一锤！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N竟然还不回头，两臂一振，再来一锤！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra/2);    
        me->add_temp("apply/damage", -extra*2);

me->add("neili",-200);
	me->start_busy(2);
	return 1;
}
