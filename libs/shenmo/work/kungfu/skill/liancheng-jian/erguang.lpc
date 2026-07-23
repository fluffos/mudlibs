// ci.c  刺肩式
// congw@CCTX

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「耳光式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	if( (int)me->query_skill("liancheng-jian", 1) < 70 )
		return notify_fail("你的连城剑法不够娴熟，不会使用。\n");
	                        
	if( (int)me->query_skill("force", 1) < 70 )
		return notify_fail("你的基本内功不够高。\n");
			
	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("你现在内力太弱，不能使用「耳光式」。\n");
			
	msg = HIY "只见$N手中兵器由右手快速交换到左手，右手以意想不到的方位挥向$n的脸颊。\n"NOR;



          if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
	{
          if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
        if( !target->is_busy() )
{
	target->start_busy( (int)me->query_skill("liancheng-jian") / 50 + 1);
}	
}
		damage = (int)me->query_skill("liancheng-jian", 1);
		damage = damage +  (int)me->query_skill("liancheng-jian", 1);
		damage = damage +  (int)me->query_skill("sword", 1);
		damage = damage+600;
		target->receive_damage("qi", damage);
		target->receive_damage("jing", 40);
		target->receive_wound("qi", damage/2);
		me->add("neili", -100);
		msg += CYN"$n只觉只觉得脸上一正火辣辣的生痛，已被$N响亮的打了一耳光！\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"可是$p身形一侧,躲过了$P的掌风。\n"NOR;
		me->add("neili", -100);
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
