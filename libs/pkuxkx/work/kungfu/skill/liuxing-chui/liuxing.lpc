//liuxingZINE

#include <ansi.h>

inherit NPC;

int perform(object me, object target)
{
        string msg;
        object weapon;
		int h;
        if( !target ) 
		return notify_fail("你要攻击谁。\n");

		if( (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "hammer") )
                return notify_fail("你必须使锤才能使「流星赶月」。\n");

		if( me->query_skill_mapped("parry")!="liuxing-chui")
		return notify_fail("你必须使用童家流星锤法作为招架才能施展「流星赶月」。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「流星赶月」只能对战斗中的对手使用。\n");

		if( (int)me->query_dex() < 50)
		return notify_fail("你的身法不够，无法施展「流星赶月」。\n"); 

        if( (int)me->query_skill("liuxing-chui", 1) + (int)me->query_skill("hammer", 1)/2 < 250 )
                return notify_fail("你的锤法不够娴熟，不会使用「流星赶月」。\n");

        if( (int)me->query("max_neili") < 2500 || (int)me->query("neili") < 500 )
                return notify_fail("你的内力不足，无法使用「流星赶月」。\n");

		me->add("neili", -300);
        me->start_busy(random(3) );

        msg = RED "$N使出「流星赶月」，闪电般攻向$n。\n" NOR;
        message_vision(msg, me, target);
		h=(int)me->query_str();
		if (h<1)
		{
			h=1;
		}
		me->add_temp("apply/hammer", -h);//嘿嘿，先debuff的连招，限制威力
		COMBAT_D->do_attack(me, target, weapon);
		COMBAT_D->do_attack(me, target, weapon);
		COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->do_attack(me, target, weapon);
		COMBAT_D->do_attack(me, target, weapon);
		COMBAT_D->do_attack(me, target, weapon);
		me->add_temp("apply/hammer", h);
        return 1;

}
