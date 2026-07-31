#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("「娇阳似火」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「娇阳似火」必须用剑才能施展。\n");

        if( (int)me->query_skill("lieyang-jian", 1) < 90 )
                return notify_fail("你的「烈阳剑法」不够娴熟，不会使用「娇阳似火」。\n");
        if( (int)me->query("neili") < 600  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("lieyang-jian");
        msg = BLINK HIY "$N清啸一声,使出「烈阳剑」中的绝技「娇阳似火」发魔般地向$n刺出三剑！\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();

        msg = HIR"●日●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●出●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●东●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●方●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●娇●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●阳●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●似●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●火●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

