 // cimu.c  辟邪剑法「刺目」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「刺目」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("pixie-sword", 1) < 80 )
        return notify_fail("你辟邪剑法不够娴熟，使不出「刺目」。\n");
    if ((int)me->query("max_neili")<400)
        return notify_fail("你内力修为不足，无法运足内力。\n");
    if( (int)me->query_temp("pixie/cimu") ) 
                return notify_fail("你已经在运功中了。\n");
        if ((int)me->query("neili")<200)
    {
        return notify_fail("你现在内力不够，没能将「刺目」使完！\n");
    }
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
       msg = RED "$N左手两指并拢，手臂暴长，迅捷异常分刺$n双目，\n"NOR;
    else
       msg = RED "$N手中长剑一振，剑尖一点暴长，分刺$n左右双目，\n"NOR;
    if (random(me->query_skill("sword")) > target->query_skill("dodge")/2) 
       //random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        me->start_busy(1);
        damage = (int)me->query_skill("pixie-sword", 1) + (int)me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage, me);
        target->receive_wound("qi", damage/2, me);
        msg += WHT"$n只看到寒尖一点，双目一阵剧痛，眼前一黑，就什么也看不见
了，顿时长声痛极而呼！\n"NOR;
        message_combatd(msg, me, target);
        COMBAT_D->report_status(target);
       target->start_busy(me->query_skill("pixie-sword",1)/50+2);
 me->add("neili", -damage/5);
        me->set_temp("pixie/cimu", 1);
        target->set_temp("block_msg/all",1);
        call_out("cimu_end", (int) 2+random(6), me);
    } else
    {
        me->start_busy(2);
        msg += "$n情急智生，抬手也向$N右眼刺去，迫得$N回剑跃开。\n"NOR;
        message_combatd(msg, me, target);
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

void cimu_end(object me)
{	object target;
	target = offensive_target(me);
	if (!target) me->delete_temp("pixie/cimu");
	else {
        //target->enable_player();
        message_combatd("$N抹了抹流着"HIR"鲜血"NOR"，终于能看见了。\n", target);
        target->set_temp("block_msg/all", 0);
        me->delete_temp("pixie/cimu");
}
        return;
}

