// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("yingzhua-gong");
       if( (int)me->query_skill("yingzhua-gong", 1) < 100 )
		return notify_fail("你的龙爪功不够娴熟!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「鹰爪功」只能空手使用。\n");		
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力不足！\n");     

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［鹰爪闪击］只能对战斗中的对手使用。\n");
//	me->add("force_factor",extra/3);
//	orforce = (int) me->query("force");
//	me->add("force",extra/3*100);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$N高高跳起使出独步天下的［鹰爪闪击］，身形加快！\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  "第一抓-抓身-！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "第二抓-抓头---！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "最后一抓-抓心------！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//	me->set("force_factor",0);
//	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);
	me->start_busy(2);
        me->add("neili", -50);

	return 1;
}
