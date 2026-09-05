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
		return notify_fail("铁掌降龙只能对战斗中的对手使用。\n");
	 
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用！\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「铁掌降龙」只能空手使用。\n");		

	if( (int)me->query_skill("tiezhang-zhangfa", 1) < 50 )
		return notify_fail("你的铁掌掌法不够娴熟，不能用铁掌降龙。\n");

	if( (int)me->query_skill("guiyuan-tunafa", 1) < 60 )
		return notify_fail("你的归元吐纳法不够娴熟，不能使用铁掌降龙。\n");

	extra = me->query_skill("tiezhang-zhangfa",1) / 20;
	extra += me->query_skill("guiyuan-tunafa",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
	msg = HIR  "$N运起［归元吐纳法］，同时使出［铁掌降龙］一阵一阵的掌力，如潮水般的击向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "第一层掌力，．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = HIC "$N身形突转，一掌又打了过来！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
i = extra/4;
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);
me->add("neili", - 80 * i);
	return 1;
}
