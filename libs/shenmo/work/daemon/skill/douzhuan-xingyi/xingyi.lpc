// xingyi.c 斗转星移perform星移斗转

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("星移斗转只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("douzhuan-xingyi", 1) < 120 )
                return notify_fail("你的星移斗转还未练成，不能使用！\n");

        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("你现在内力修为不够，不能使用星移斗转！\n");     
        if( (int)me->query("neili") < 600 )
                return notify_fail("你现在真气不足，不能使用星移斗转！\n");
        if( (int)me->query_skill("parry", 1) < 120 )
                return notify_fail("你的基本招架之法不够娴熟，不能使用星移斗转。\n");

        if (me->query_skill_mapped("parry") != "douzhuan-xingyi")
                return notify_fail("你现在无法使用星移斗转。\n");                                                                                 
                       
        msg = HIY "\n忽然天昏地暗，$N使出$n的绝招，袍袖中两股内家真气向$n扑去！\n"NOR;
        if(me->query("neili") < random(target->query("neili"))){
           me->start_busy(3);
           target->start_busy(3); 
           me->add("neili", -200);
           me->add("jing", -20);
           target->add("jingli", -50);
           target->add("neili", -200);
           msg += HIY"结果$p和$P两人内力一拼，双方都没占到丝毫好处！\n"NOR;
           message_vision(msg, me, target);
           return 1;
           }
        if( weapon = target->query_temp("weapon") ){
          if( random(me->query_str()) > target->query_str()/2 ) {
            me->start_busy(1);
            me->add("neili", -150);
            me->add("jing", -20);
     damage = (int)me->query_skill("shenyuan-gong", 1);
         damage = random(damage)+100;                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);   

            msg += HIR"\n$p只觉得全身受到内力震荡，钻心般巨痛，一口鲜血喷出，手中"
                +target->query_temp("weapon")->query("name")+HIR"坠地而出。\n"NOR;
            message_vision(msg, me, target);
                (target->query_temp("weapon"))->move(environment(target));
            } 
          else {
            me->start_busy(2);
            me->add("jing", -25);
            me->add("neili", -60);
            msg += "$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n";
            message_vision(msg, me, target);
            }        
         }
        else
        {
        if (random(me->query_skill("parry")) > target->query_skill("parry")/3)
            {
                me->start_busy(2);
                target->start_busy(random(3));
                
                me->add("jing", -50);
                damage = (int)me->query_skill("shenyuan-gong", 1);
				damage = (int)me->query_skill("douzhuan-xingyi", 1) +damage;
                damage = damage + random(damage);                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);   
				me->add("neili", -(damage/3));             
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                       
        } else 
           {
             me->start_busy(2);
             me->add("jing", -25);
             me->add("neili", -180);
             msg += CYN"\n$p怎么也想不到$N能够使出自己的成名绝技，危及之中双脚跋地而起，艰难的躲过这一招，脸色变的苍白。\n" NOR;
          }
        message_vision(msg, me, target);

        }
        return 1;
}
