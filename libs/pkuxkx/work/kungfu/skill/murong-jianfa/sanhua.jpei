// modified by snowman@SJ 05/12/2000

#include <ansi.h>
inherit F_SSERVER;
#include <combat_msg.h>

int perform(object me,object target)
{
        object weapon;
        string msg;
        int i = me->query_skill("douzhuan-xingyi",1) / 3;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) || !living(target)
        || environment(target)!=environment(me))
                return notify_fail("天女散花只能对战斗中的对手使用。\n");

        if(me->query_skill_mapped("force") != "shenyuan-gong")
                return notify_fail("你的内功不是神元功，无法使用天女散花！\n");
        if( me->query_skill("shenyuan-gong", 1) < 100 )
                return notify_fail("你的内功还未练成，不能使用天女散花！\n");
        if( me->query_skill("murong-jianfa", 1) < 100 )
                return notify_fail("你的剑法还未练成，不能使用天女散花！\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "murong-jianfa")
                return notify_fail("你手里没有剑，无法使用天女散花！\n");

        if(me->query_skill_mapped("parry") != "murong-jianfa")
                return notify_fail("你的招架功夫不对，无法使用天女散花！\n");
        if(me->query("max_neili") < 1000 )
                return notify_fail("你的内力修为不够，不能使用天女散花！\n");
        if(me->query("neili") < 800 )
                return notify_fail("你现在真气不足，不能使用天女散花！\n");
        if(me->query("jingli") < 500 )
                return notify_fail("你现在精力不足，不能使用天女散花！\n");
        if(me->query_temp("sanhua"))
                return notify_fail("你正在使用天女散花！\n");
        if(me->query_skill("sword", 1) < 100 )
                return notify_fail("你的基本剑法不够娴熟，不能在剑招中使用天女散花。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        msg = HIG "$N使出「天女散花」，点点剑光直飞$n全身各大要穴。\n"NOR;
        me->start_perform(4,"「天女散花」");
        if((random(me->query_skill("dodge",1)) + me->query_int()) >
        (target->query_skill("dodge",1) + target->query_int())/3) {
                msg = msg + MAG "结果$n被$N攻了个措手不及。\n" NOR;
                target->add_busy(random(i/10) + 2);
                me->add_temp("apply/attack", i);
                me->add_temp("apply/damage",  i);
                me->add_temp("apply/sword",  i);
                me->set_temp("sanhua", 1);
                call_out("next1", 1, me, target, i);
        }
        else
                msg = msg + MAG "可是$n看破了$N的企图，并没有上当。\n" NOR;

        message_vision(msg, me, target);
        return 1;
}

int next1(object me, object target, int i)
{
        string msg;
        int damage;
        object weapon;

        if (!me) return 0;

        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->add_temp("apply/attack", -i);
                me->add_temp("apply/damage",  -i);
                me->add_temp("apply/sword",  -i);
                me->delete_temp("sanhua");
                return 0;
        }

        msg = HIR "紧跟着$N剑锋一转，欺身近前，从不可思议的角度刺向$n的" + HIY"「命门穴」"HIR + "。\n"NOR;

        if((random(me->query("max_neili")) + me->query_skill("force",1)) >
            (target->query("max_neili") + target->query_skill("force",1))/3 ){
                msg = msg + CYN"$n只觉全身真气由「命门穴」狂泻而出。\n"NOR;
                damage = me->query_skill("murong-jianfa",1);
                damage += me->query_skill("sword",1);
                damage += random(damage);

                target->add("neili",-(500+random(150)));
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                msg += damage_msg(damage, "刺伤");
                msg = replace_string(msg, "$w", weapon->name());
                msg = replace_string(msg, "$l", "「命门穴」");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
                me->add("neili",-300);
                me->add("jingli",-100);
        } else {
                msg  =  msg + CYN"$n一个懒驴打滚，危急之中躲过致命一击。\n"NOR;
                message_vision(msg, me, target);
                me->add_busy(1+random(2));
        }

        call_out("next2", 1, me, target, i);

        return 1;
}

int next2(object me, object target, int i)
{
        string msg;
        int damage;
        object weapon;

        if( !me ) return 0;

        weapon = me->query_temp("weapon");
        if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
                me->add_temp("apply/attack", -i);
                me->add_temp("apply/damage",  -i);
                me->add_temp("apply/sword",  -i);
                me->delete_temp("sanhua");
                return 0;
        }

        msg = HIC "就在$n疲于防守之际，$N又风驰电掣地刺出第三剑。\n"NOR;

        if((random(me->query("combat_exp")) + me->query_str()) >
            (target->query("combat_exp") + target->query_str())/3 ){
                msg = msg + HIW "结果一剑正刺中$n的" + HIR"「檀中穴」"HIW + "。\n"NOR;
                damage = me->query_skill("murong-jianfa",1);
                damage += me->query_skill("sword",1);
                damage += random(damage);
                target->add_temp("apply/attack", -100);
                target->add_temp("apply/dodge", -100);
                target->add_temp("apply/parry", -100);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                msg += damage_msg(damage, "刺伤");
                msg = replace_string(msg, "$w", weapon->name());
                msg = replace_string(msg, "$l", "「檀中穴」");
                message_vision(msg, me, target);
                COMBAT_D->report_status(target, random(2));
                me->add("neili",-300);
                me->add("jingli",-150);
                call_out("back", 5 + random(me->query("jiali") / 20), target);
        } else {
                msg = msg + HIW "$n一个旱地拔葱，跃起数丈，堪堪避过。\n" NOR;
                message_vision(msg, me, target);
                me->add_busy(1 + random(2));
        }

        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage",  -i);
        me->add_temp("apply/sword",  -i);
        me->delete_temp("sanhua");
        return 1;
}

void back(object target)
{
        if (!target) return;
        target->add_temp("apply/attack", 100);
        target->add_temp("apply/dodge", 100);
        target->add_temp("apply/parry", 100);
}

