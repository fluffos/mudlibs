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
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火候太浅。\n");

if((int)me->query_skill("liehuo-jian",1) < 50)
		return notify_fail("你的剑法修为不够, 不能使用「混然一剑」！\n");if((int)me->query("neili") < 200 )
	if((int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你没有装备武器。\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［混然一剑］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("liehuo-jian",1)/2;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", (extra*2));
        me->add_temp("apply/strength", extra);
	msg = HIR "$N错步上前，手中"+ weapon->name() +HIR"的一式［混然一剑］，剑芒若有若无地向$n挥去！"NOR;
       	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -(extra*2));
        me->add_temp("apply/strength", -extra);
        me->start_busy(1);
	return 1;
}
