//双打
//write by lysh

#include <ansi.h>

inherit F_SSERVER;
inherit NPC;

int perform(object me, object target)
{
        string msg;
        object weapon;
                        
        if( !target ) 
		return notify_fail("你要攻击谁。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你必须使剑才能使「双打」。\n");

	if( me->query_skill_mapped("sword")!="pixie-jian")
		return notify_fail("你必须使辟邪剑才能施展「双打」。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「双打」只能对战斗中的对手使用。\n");
        
	if( (int)me->query("neili") < 50)
		return notify_fail("你的内力不够，无法施展「双打」。\n"); 

        if( (int)me->query_skill("damo-jian", 1) < 60 )
                return notify_fail("你的剑法不够娴熟，不会使用「双打」。\n");
        me->add("neili", -50);

        msg = CYN "$N使出「双打」，闪电般功向$n。\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("qi") < 0 ) 
                return 1;

        COMBAT_D->do_attack(me, target, query_temp("weapon"));
        if( (int)target->query("qi") < 0 ) 
                return 1;

        
}
