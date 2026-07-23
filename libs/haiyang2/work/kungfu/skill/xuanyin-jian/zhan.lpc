#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
        object weapon;
        lvl = me->query_skill("xuanyin-jian", 1)/2;
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用斩字诀。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if( (int)me->query_skill("xuanyin-jian", 1) < 200 )
                return notify_fail("你的玄阴剑法不够娴熟，无法施展出斩字诀。\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 150)
                return notify_fail("你的九阴真功火候不够，无法施展出斩字诀。\n");
        if ((int)me->query_skill("jiuyin-shenfa", 1) < 200)
                return notify_fail("你的九阴身法火候不够，无法施展出斩字诀。\n");
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出斩字诀。\n");
        if ( (int)me->query("neili") < 900)
                return notify_fail("你的真气不够，无法施展出斩字诀。\n");
        message_vision(HIB"$N使出九阴「斩字诀」，剑光一瞬间攻向$n！\n"NOR,me, target);

        me->add("neili", -(500 +random(400)) );

        me->add_temp("apply/attack",lvl);
        me->add_temp("apply/dexerity",lvl/2);
        me->add_temp("apply/damage",lvl);
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
        message_vision(HIB"结果$N一招得手，$n的手腕居然被斩了下来！\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        target->apply_condition("broken_arm",180); }
        me->start_busy(random(3) + 2);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl);
        me->add_temp("apply/dexerity",-lvl/2);
}        
else {       
        if(random(me->query("combat_exp")) > target->query("combat_exp")/3	) {
        message_vision(HIB"结果$N一招得手，$n的手腕居然被斩了下来！\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
        target->apply_condition("broken_arm",180); }
        me->start_busy(random(3) + 2);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl);
        me->add_temp("apply/dexerity",-lvl/2);
}
        return 1;
}
