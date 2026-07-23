// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("胡家刀法刀刀相连只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("hujia-daofa", 1) < 50 )
		return notify_fail("你的胡家刀法不够娴熟，不能用刀刀相连。\n");

	if( (int)me->query("neili") < 400  ) 
		return notify_fail("你的内力不够。\n");

	me->delete_temp("lianhuan");
	extra = me->query_skill("hujia-daofa",1) / 35;
	extra += me->query_skill("hujia-daofa",1) /35;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N一咬牙，手上动作加快，同时使出［胡家刀法中］的刀刀相连，手中的"+ weapon->name() +" 一刀连着一刀，闪电般的击向$n！" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIR "在一片刀光中，一刀劈了过来\n" NOR;
        message_vision(msg, me, target);

	for(i=0;i<extra/5;i++)
	{
	msg = HIY "$N咬紧牙关，一刀又劈了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
        i = extra/5;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        me->add("neili", -50 * i);
	me->start_busy(3);
	return 1;
}

