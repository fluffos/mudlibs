// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        extra = me->query_skill("liumang-quan",1);
	if ( extra < 100) return notify_fail("你的流氓神拳还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［落日］只能对战斗中的对手使用。\n");
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用！\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("这个武功只能空手使用。\n");		
extra=extra/3;
if (extra> 200) extra=200;
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");
	if (random(3)==0) target->start_busy(3);
	msg = HIR  "$N仰天发出一声长笑，使出落日神拳中的［落日］，\n" NOR;
	msg += HIR   "就似灿烂无比的夕阳，顿时间天地亦为之变色！\n" NOR;
	          message_vision(msg,me,target);
        msg = HIC "\n   长 \n" NOR;
	  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "\n            河\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "\n                    落\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "\n                            日\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                    圆\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
	  me->add_temp("apply/damage",-extra*2);
	  me->start_busy(2);

	return 1;
}
