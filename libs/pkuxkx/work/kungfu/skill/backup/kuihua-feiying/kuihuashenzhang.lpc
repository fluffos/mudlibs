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
		return notify_fail("葵花神掌只能对战斗中的对手使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「葵花神掌」只能空手使用。\n");		

	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("你的葵花飞影术不够娴熟，不能用葵花神掌。\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("你的葵花心法不够娴熟，不能使用葵花神掌。\n");

	extra = me->query_skill("kuihua-feiying",1) / 20;
	extra += me->query_skill("kuihua-xinfa",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N运起［葵花心法］，同时使出［葵花神掌］死命的打向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "$N的人影变成了几个，．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = HIC "在$n的身旁出现一个人影，一掌向$n打了过去！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
me->add("neili", - 80 * i);
	me->start_busy(4);
	return 1;
}
