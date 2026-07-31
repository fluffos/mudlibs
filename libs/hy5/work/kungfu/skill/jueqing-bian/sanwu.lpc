//Cracked by Kafei
// sanwu.c
// Xuanyuan 14/7/2001

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{
        int skill, amount;
        string weapon;

        if( !target ) target = offensive_target(me);



        if( !target || !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「三无三不手」只能对战斗中的对手使用。\n");

        if( me->query_temp("yield") )
                return notify_fail("你不出掌，如何使出「三无三不手」？\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        if( me->query_skill("jueqing-bian", 1) < 100 )
                return notify_fail("绝情鞭法不够娴熟，无法施展「三无三不手」！\n");

        if( (int)me->query("max_neili", 1) < 1000 )
                return notify_fail("你的内力修为不够，无力施展「三无三不手」！\n");

        if( me->query("neili") < 800 )
                return notify_fail("你现在的内力太弱，不够使用「三无三不手」！\n");

        if( (int)me->query("jing", 1) < 300 )
                return notify_fail("你现在的体力太弱，不够使用「三无三不手」\n");

        message_vision( HIR"\n$N一声冷笑，迅捷凌利的连攻三招，正是赤炼仙子的绝技「三无三不手」！\n"NOR, me);

        me->add("neili", -400);
        me->add("jing", -100);
        me->set_temp("sanwu", 1);

                skill = me->query_skill("whip");

                switch ( me->query_temp("sanwu") )
                {
                        case 1:         
                                amount = skill/20;
                                break;
                        case 2:
                                amount = skill/15;
                                break;
                        case 3:
                                amount = skill/10;
                                break;
                }

                me->add_temp("apply/attack", amount);
                me->add_temp("apply/damage", amount);

                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
		me->add_temp("sanwu", 1);
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
		me->add_temp("sanwu", 1);
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
		me->add_temp("sanwu", 1);
                me->add_temp("apply/attack", -amount);
                me->add_temp("apply/damage", -amount);


                if ( !me->query_temp("sanwu") || me->query_temp("sanwu") == 4 )
                        remove_effect(me);

		me->start_busy(2);
		return 1;
}

void remove_effect(object me)
{


        int amount = (int)(450 - me->query_skill("whip")) / 2;
        if ( amount < 15 ) amount = 15;

        if ( 1 )
                message_vision(RED"\n$N三鞭击出，三无三不发挥得淋漓尽致，端是毒辣至极。\n"NOR,me);

        // if 3 hit all missed, delete sanwu temp here.
        if ( me->query_temp("sanwu") )
                me->delete_temp("sanwu");

        // more hits, cost more neili, min 100, max 300.
        me->add("neili", -100 * 4);

        // more hits, longer busy time, longer to receive heal.
        me->start_busy(3);

}


