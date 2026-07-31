// tiao.c 
// liu 2002

/*
黄蓉心中气恼已消，也就不为已甚，笑上双颊，竹棒缩回，使起“挑”字诀，搭住钢杖向上甩出，将简长老疾奔的力道传到杖上，钢杖急飞上天。
被她轻轻一挑，竟尔把持不住，杖头直翻起来，砸向自己额角，急忙振腕收住，更是暗暗吃惊，
*/

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string *limb,msg;
        object weapon,weapon2;
        int exp1,exp2,skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
				return notify_fail("「挑」字诀只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        weapon2 = target->query_temp("weapon");
        exp1 = me->query("combat_exp")/1000;
        exp2 = target->query("combat_exp")/1000;
        skill = me->query_skill("stick");

        if( me->query_skill_mapped("force") != "huntian-qigong")
                return notify_fail("你所用的内功与打狗棒的气路相悖！\n");

        if( (int)me->query_skill("force") < 100 )
                return notify_fail("你的内功修为不够火候，使用不了「挑」字诀。\n");
                
        if( (int)me->query_skill("stick") < 100 )
                return notify_fail("你的打狗棒法不够娴熟，不会使用「挑」字诀。\n");

        if( !objectp(target->query_temp("weapon") ) )
                return notify_fail("对手没有兵器，无法使用「挑」字诀。\n");
        
        if( me->query("neili") <= skill*3 )
                return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= skill*2 )
                return notify_fail("你的精力不够！\n");


        msg = CYN "\n$N笑上双颊，"NOR+weapon->name()+CYN"缩回，使起“挑”字诀，搭住"NOR+weapon2->name()+CYN"向上甩出！\n"NOR;

                 me->start_busy(1+random(1));
        if( target->query_temp("tiao_hit"))
        {
                msg += CYN"可$p刚看$P的用过此招，冷哼一声，并没有上当。\n\n" NOR;
        }
        else if (target->query("jiali"))
        {
                msg += CYN"将$n疾奔的力道传到"NOR+weapon2->name()+CYN"之上，"NOR+weapon2->name()+CYN"急飞上天。\n\n" NOR;
                weapon2->move(environment(target));
        }
        else if (exp1 > random(exp2*8/5) )
        {
                limb = target->query("limbs");
                msg += CYN"$n被$N轻轻一挑，竟尔把持不住，"NOR+weapon2->name()+CYN"头直翻起来，砸向自己"+limb[random(sizeof(limb))]+"。\n\n" NOR;
                if (me->query_int()+me->query_skill("dodge")/10 > target->query_int()+target->query_skill("dodge")/10)
                {
                        msg += CYN"$n躲避不及，竟被自己的"NOR+weapon2->name()+CYN"所伤。\n\n" NOR;
                        target->receive_damage("qi", skill,  me);
                        target->receive_wound("qi", random(skill), me);
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(target);
                        me->start_busy(1+random(1));
                        return 1;
                }
                else
				{
                        msg += CYN"$n急忙振腕收住，虽已躲过，却是暗暗吃惊。\n\n" NOR;
                }
        }
        else {
                msg += CYN"$p看破了$P的意图，立刻不再施劲，将"+weapon2->name()+"带回。\n\n" NOR;
                target->set("jiali",0);
                target->set("jiajin",1);
                me->start_busy(1 + random(1));
        }
        message_vision(msg, me, target);
        me->add("neili", -100);
        me->add("jingli", -80);
        target->set_temp("tiao_hit",1);
        return 1;
}
