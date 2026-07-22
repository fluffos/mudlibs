#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg,limb;
	object weapon;
	mapping action;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「七星汇聚」只能对战斗中的对手使用。\n");

        weapon=me->query_temp("weapon");
	if (weapon)
		return notify_fail("[七星汇聚]只能在空手时候使用。\n");
		
	if( (int)me->query_skill("tiangang-zhi", 1) < 70 )
		return notify_fail("你的天罡指不够娴熟，不会使用[七星汇聚]。\n");
	                        			
      if( (int)me->query("neili") < 300 )
		return notify_fail("你现在内力太弱，不能使用「七星汇聚」。\n");
			
	msg = CYN "$N身形横飞,右手由拳而指,向$n连点七下。\n"NOR;

	if (random(me->query_skill("unarmed")+me->query_skill("dodge")) > 
	(target->query_skill("unarmed")+target->query_skill("dodge") )/2)
	{
		target->start_busy(1);		
		damage = (int)me->query_skill("unarmed");
		action = me->query("actions");
		limb="左眼";
              damage=damage/3;
		
		msg += HIR"$n招架不迭,脚下连退七步,忍不住喉头一甜,吐出一口鲜血.\n"NOR;
		message_vision(msg,me,target);
		COMBAT_D->do_attack_now(me,target,weapon,2,action,limb,damage);
              me->start_busy(2);
		return 1;
	} else 
	{
		msg += CYN"可是$n猛地向边上一跃,跳出了$N的攻击范围。\n"NOR;
               me->add("neili", -50);
		me->start_busy(2);
	}
message_vision(msg,me,target);

	if(userp(target)) target->fight_ob(me);
	return 1;
}
