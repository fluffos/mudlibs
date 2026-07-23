//改编自snowman的sanhuan
//改编者:caiji
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i = me->query_skill("zhuihun-gou", 1)/5;
        int j = me->query("jiali")/4 + 10;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「神形俱灭」只能对战斗中的对手使用。\n");
        if(me->query_temp("zhuihun/lpf"))
        return notify_fail("你正在使用「乱披风」。\n");
        if( (int)me->query_skill("zhuihun-gou", 1) < 100 )
                return notify_fail("你的追魂钩功力太浅，别做梦了。\n");

        if( (int)me->query_skill("hook", 1) < 100 )
                return notify_fail("你的基本钩法功力太浅，别做梦了。\n");

        if( (int)me->query_skill("huagong-dafa", 1) < 100 )
                return notify_fail("你的内功功力太浅，别做梦了。\n");
                
        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力太浅，别做梦了。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够，别做梦了。\n");
        if (me->query_skill_mapped("force") != "huagong-dafa")
                return notify_fail("你用什么为内功基础来使「神形俱灭」?\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "hook"
            || me->query_skill_mapped("hook") != "zhuihun-gou")
                return notify_fail("你使得了「神形俱灭」么?\n");
                 
        me->add("neili", -150);
        me->add("jingli", -100);
        me->set_temp("zhuihun/jumie", 4); 
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", j);
        message_vision(GRN "\n$N大喝一声「绝命」，第一招使出.....\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        if(me->is_fighting(target)){
        message_vision(YEL "\n$N反手一钩，紧跟着发出第二招「落魄」！\n"NOR,me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        }
        if(me->is_fighting(target)&&(int)me->query_skill("zhuihun-gou", 1) >= 140){
        message_vision(RED "\n$N凌空一劈，第三式「夺魂」随后而至，令$n"RED"措手不及！\n"NOR,me,target);
        me->add("neili", -50);        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);        
        }
        if(me->is_fighting(target)&&random(me->query("combat_exp"))>target->query("combat_exp")/2
        &&(int)me->query_skill("zhuihun-gou", 1) >= 180){
        message_vision(MAG "\n$N身行晃动，最后一式「屠灵」劲道凌厉非常！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
        me->add("neili", -80);
        }
        me->add_temp("apply/attack", -i);
        me->add_temp("apply/damage", -j);   
        me->start_busy(1);
        me->delete_temp("zhuihun/jumie"); 
        me->start_perform(4, "「神形俱灭」");
        return 1;
}
