// jiang.c 神龙天降
// smallbear 11/2/2002

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg,force;
        int damage,sk1,sk2,exp1,exp2,skill,dp,ap;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「神龙天降」只能在战斗中使用。\n");


        skill = (int)me->query_skill("qingshe-sword",1);
        
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if( skill < 100 )
                return notify_fail("你的神龙剑法不够娴熟，不会使用「神龙天降」。\n");
                                
        if(  (int)me->query_skill("shenlong-xinfa", 1)<100) 
                return notify_fail("你的内功火候不够，无法发挥剑法威力。\n");
                        
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你现在内力太弱，不能使用绝招。\n");

        if (  me->query_skill_mapped("force") != "shenlong-xinfa") 
                 return notify_fail("你没有运用神龙教系列内功！\n");

/*        sk1 = (int)me->query_skill("sword");
        if(target->query_skill_mapped("parry")==target->query_attack_skill())
                sk2 = ((int)target->query_skill("parry")+(int)target->query_skill("dodge"))/2;
        else
                sk2 = ((int)target->query_skill("parry",1)+(int)target->query_skill("dodge"))/2;
        exp1 = (int)me->query("combat_exp");
        exp2 = (int)target->query("combat_exp"); */

        ap = me->query_skill("qingshe-sword",1) + me->query_skill("sword",1) + me->query_skill("force",1);
        dp = target->query_skill("dodge",1) + target->query_skill("parry",1) + target->query_skill("force",1);

        msg = CYN "$N后跃一步，手捏剑决，口中念念有词，突然大喝一声「神龙天降」！！\n"NOR;

        if (ap / 2 + random(ap) > dp || !living(target))
        {
                if(skill<350)
                target->start_busy(1 + random(2));
        else
                target->start_busy(1 + random(3));
                damage = (int)me->query_skill("qingshe-sword", 1);
                damage = damage +  skill;
                damage = damage +  (int)me->query_skill("sword", 1);

        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage,me);
        target->receive_damage("jing", damage/3,me);
        target->receive_wound("jing", damage/2,me);
        me->add("neili", -damage);
        msg += HIY"$N的剑法顿时变得诡异十分，幻出朵朵剑花，犹如数条金龙，迅速向$n飞去！\n"
                "$n试图避开剑招，可全身僵硬不能动弹，疑惑中已经身中数剑，精神愈加恍惚起来！\n"NOR;
        me->start_busy(3);
        }
        else
        {
        msg += CYN"$n顿感身体被制，情知不妙，立刻摄守神元，终于突破对方控制。\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        if(!userp(target)&& !target->is_killing(me->query("id")) ) target->kill_ob(me);
        return 1;
}


