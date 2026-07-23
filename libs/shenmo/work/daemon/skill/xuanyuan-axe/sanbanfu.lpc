// tie@fengyun1
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
        extra = me->query_skill("xuanyuan-axe",1);
        if ( extra < 30) return notify_fail("你的轩辕斧法还不够纯熟！\n");
        	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［三板斧］只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("你使用的武器不对。\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");

	weapon = me->query_temp("weapon");
    extra=extra/3;
if (extra> 200) extra=200;    
	me->add_temp("apply/attack",extra);
	msg = HIY  "$N使出悟彻波风斧法中的［三板斧］，一招连环三斧，手中的"+ weapon->name()+  "劈山般向$n砍出第一斧！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第二斧！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "第三斧！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
	me->add("neili",-50);
	me->start_busy(2);
	return 1;
}
