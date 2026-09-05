#include <ansi.h>
inherit F_SSERVER;

int exert(object me, object target)
{       
        int skill;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("移魂大法只能对战斗中的对手使用。\n");
        if ((int)target->is_busy())
                return notify_fail("对方正忙着呢。\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 200)
                return notify_fail("你的九阴真功修为还不够。\n");
        if( (int)me->query_int() < 45 )
                return notify_fail("你的悟性不够。\n");
        if( (int)me->query("neili") < 2000 )
                return notify_fail("你的真气不够。\n");

        skill = me->query_skill("jiuyin-zhengong",1);
        me->add("neili", - 200);
        if (random(me->query_skill("force"))>target->query_skill("force")/3) {
                message_vision(HIW"$N脸上突然开始做出各样奇怪的表情。\n"NOR, me, target);
                message_vision(HIW"$n看了备取笑$N，却不知不觉的学起$N的表情。\n"NOR, me, target);
                message_vision(HIW"$N猛然做出向自己攻击的动作，$n立刻向自己发疯似的攻击起来，出手越来越重！\n"NOR, me, target);
                target->start_busy(5 + me->query_skill("jiuyin-zhengong", 1)/20);
                target->add_temp("apply/attack",skill);
                target->add_temp("apply/damage",skill);
                target->add_temp("apply/dodge",-skill);
                target->add_temp("apply/parry",-skill);
                target->add_temp("apply/defence",-skill);
                COMBAT_D->do_attack(target, target, target->query_temp("weapon"), 2);
                COMBAT_D->do_attack(target, target, target->query_temp("weapon"), 0);
                COMBAT_D->do_attack(target, target, target->query_temp("weapon"), 3);
                target->add_temp("apply/attack",-skill);
                target->add_temp("apply/damage",-skill);
                target->add_temp("apply/dodge",skill);
                target->add_temp("apply/parry",skill);
                target->add_temp("apply/defence",skill);
        } else {
                message_vision(HIW"$N脸上突然开始做出各样奇怪的表情。\n"NOR, me, target);
                message_vision(HIW"不管$N怎么变化表情，$n总是冷冷的无动于衷。\n"NOR, me, target); 
        }
        return 1;
}

