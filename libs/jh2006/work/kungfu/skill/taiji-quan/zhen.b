// zhen.c 太极拳「震」字诀
// snowman
#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
string *taiji_msg = ({"十字手","如封似闭","搬拦捶","野马分鬃","斜飞势","云手","马步靠","闪通臂"});

int perform(object me, object target)
{
        int damage, p,ap,dp;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
                return notify_fail("神功震敌只能对战斗中的对手使用。\n");

        if(!me->query_temp("taiji"))
                return notify_fail("太极拳讲究劲断意不断，你没有运用「太极」，又如何能使用「震」字诀？\n");
        if( (int)me->query("neili", 1) < 1000 )
                return notify_fail("你现在真气不够，强迫使用「震」字诀只会伤到你自己！\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");                   
          
        msg = CYN "\n突然，$N一招「"+taiji_msg[random(sizeof(taiji_msg))]+"」，双手左右连画，一个圆圈已将$n套住，太极拳的"RED"「震」"CYN"字诀随即使出！\n"NOR;

        ap = me->query("combat_exp")/1000 * me->query_skill("taiji-quan",1);
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1);
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        damage = me->query("combat_exp")/1000 * (int)me->query_skill("taiji-quan", 1)/100 * (int)me->query_skill("force", 1)/100;
        if(damage>3000) damage = 3000;
        if(damage<500) damage = 500;
        
        if(random(ap) > dp/3 )
        {
                if((int)me->query("neili")/2 < random((int)target->query("neili"))){
                       me->start_busy(2);
                       if(!target->is_busy()) target->start_busy(2); 
                       me->add("neili", -100);
                       target->add("qi", -damage/4);
                       target->add("neili", -damage/10);
                       msg += HIY"只听「啪」的一声，$p和$P两人内力相拼相碰，各自退了几步。\n"NOR;
                       p = (int)target->query("qi")*100/(int)target->query("max_qi");
                       msg += damage_msg(damage, "内伤");
                       msg += "( $n"+eff_status_msg(p)+" )\n";       

                       message_vision(msg, me, target);
                       return 1;
                       }
                me->start_busy(2);
                if(!target->is_busy()) target->start_busy(2+random(2));
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/5);
                if(target->query("neili") >= damage/3) target->add("neili", -(damage/3));
                else target->set("neili", 0);

                me->add("neili", -100);
                me->add("jingli", -50);

                if(damage > 2000)
                   msg += "$N恨他歹毒，「震」字诀使出时连绵不断，跟着喀喀喀几声，$p全身各处骨头也被一一绞断！\n";
                else                    
                   msg += "太极之意连绵不断，有如自去行空，一个圆圈未完，第二个圆圈已生，喀喇一响，$p一处骨头被绞断！\n";
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";       
       } 
        else{
                me->start_busy(2);
                me->add("jingli", -50);
                me->add("neili", -100);
                msg += HIY"$p一看不对，马上一阵急攻，$P登时手忙脚乱，再也来不及出招！\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}
