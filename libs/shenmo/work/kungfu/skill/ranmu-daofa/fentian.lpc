// fentian.c 举火焚天
// by hunthu

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
void remove_effect(object me);
void check_fight(object me, object target, int j); 

int perform(object me, int amount)
{
        string msg;
        object weapon, target;
        int skill, damage,p;
        weapon = me->query_temp("weapon");  
        skill= me->query_skill("ranmu-daofa",1);

        if( !target ) target = offensive_target(me);

        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("「举火焚天」只能对战斗中的对手使用。\n");        

        if (!weapon || weapon->query("skill_type") != "blade"
                        || me->query_skill_mapped("blade") != "ranmu-daofa")
                return notify_fail("你现在无法使出「举火焚天」之技！\n");

        if((int)me->query_skill("ranmu-daofa", 1) < 160 )
                return notify_fail("你的燃木刀法火候不够，无法「举火焚天」。\n");

        if((int)me->query_skill("blade", 1) < 150 )
                return notify_fail("你的基本刀法还不够娴熟，使不出「举火焚天」绝技。\n");

        if( (int)me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("你的易筋经修为不够，使不出「举火焚天」绝技。\n");

        if ((int)me->query_skill("strike",1) < 120)
                return notify_fail("你的掌法修为太差，无法使出「举火焚天」绝技。\n");

        if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("没有易筋经作为根基，是无法使出「举火焚天」绝技的！\n"); 

        if (me->query_temp("fumo"))
                return notify_fail("你现在正在使用「金刚伏魔」神功。\n"); 

        if (me->query_temp("ranmu"))
                return notify_fail("你现在正在使用「天火焚心」绝技。\n"); 

        if (me->query_temp("fentian"))
                return notify_fail("你正在使用「举火焚天」绝技！");

        if (me->query("max_neili") < 1500)
                return notify_fail("你的内力修为不够。\n");

        if (me->query("neili") < 500)
                return notify_fail("你的内力不够。\n");

        if (me->query("jing") < 200)
                return notify_fail("你的精力不够。\n");

        me->set_temp("fentian",1);
        me->start_busy(2);
        me->add("neili", -800);
        me->add("jing", -100);        
        msg =HIR"\n$N猛然一声大喝，手中的"+weapon->name()+HIR"如一道流星腾空而起，一阵筚拨之声，洒下漫天火焰，\n"+
                "刀头指处，一股烈焰熊熊而出。$N聚气于双掌，在间不容发之际，往空虚劈九九八十一掌。\n"NOR;

        if(random(me->query("combat_exp",1)) > target->query("combat_exp",1)/2
         &&((me->query_skill("blade",1))+ me->query_skill("strike",1))/2 > random(target->query_skill("dodge",1))){
          skill= me->query_skill("ranmu-daofa",1)+me->query_skill("blade",1)+me->query_skill("buddhism",1);
          damage= skill*2;
          msg += HIR"\n$n见火焰扑面卷来，不免大惊失色，但躲闪无及，被熊熊大火围在当中。\n"NOR;
          damage = damage+random(damage/2);
          if (damage > 3000) damage = 3000;
          target->receive_damage("qi", damage*4);
          target->receive_wound("qi", damage*3);
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
          me->start_call_out((: call_other, __FILE__, "remove_effect", me :), random(5));
          me->start_busy(2+random(2));
          me->start_call_out((: call_other, __FILE__, "check_fight", me, target :), 1);
          message_vision(msg, me, target);
          return 1;
        }
        if(random(me->query("combat_exp",1)) > (target->query("combat_exp",1)/3)){
          message_vision(HIR"\n$n虽早有防备，但乍见火光耀眼也不禁大吃一惊，急忙跃开规避，也已大是狼狈。\n"NOR,me,target);
          target->start_busy(3+random(2));
          me->start_call_out((: call_other, __FILE__, "remove_effect", me :), random(5));
          me->start_call_out((: call_other, __FILE__, "check_fight", me, target :), 1);
          return 1;
        }
        msg += HIR"\n$n成竹在胸，长袖拂出，一股疾风扑出，漫天火光顿时凝聚成一个火柱，倒卷向$N。\n"NOR;
        damage = skill*5;
        me->receive_damage("qi", damage*3);
        me->receive_wound("qi", damage*3);
        p = (int)me->query("qi")*100/(int)me->query("max_qi");
        msg += "( $N"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
        me->delete_temp("fentian");
        return 1;
}

void remove_effect(object me)
{
        if ( (int)me->query_temp("fentian") ) {
                me->delete_temp("fentian");
                tell_object(me, HIC"火光渐渐暗淡终于消失无踪了。\n"NOR);}
}

void check_fight(object me, object target, int j)
{
        object weapon;      
        if (!target) {remove_effect(me); return;}
        if( !present(target->query("id"), environment(me)) 
           || me->query_skill_mapped("blade") != "ranmu-daofa"
           || !weapon
           || weapon->query("skill_type") != "blade"
           || !me->is_fighting() 
           || !living(target) 
           || !target->is_fighting()
           || target->is_ghost() 
           || me->is_ghost() 
           || !living(me))
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, j :), 0);
        else call_out("check_fight", 1, me, target, j);
}

