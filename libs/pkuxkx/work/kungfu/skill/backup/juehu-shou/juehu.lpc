// juehu.c 三阴绝户手「绝户」perform
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,l_temp;
        string msg;

        int busy_time,busy_time1,pfm_time,pfm_time1;
        busy_time=3;   //perform的忙时间基数
        busy_time1=2;  //成功对手的忙时间基数
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("神功伤敌只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「绝户」神功！\n");  
                
        if( (int)me->query_skill("juehu-shou", 1) < 100 )
                return notify_fail("你的虎爪绝户手不够娴熟，不会使用「绝户」神功\n");

        if( (int)me->query_skill("yinyun-ziqi", 1) < 100 )
                return notify_fail("你的氤氲紫气不够高，不能用「绝户」神功伤敌。\n");

        if( (int)me->query("shen") < -1000 )
                return notify_fail("你邪气太重，无法使出「绝户」招式。\n");
       
        if(me->query("juehu_nouse"))
                 return notify_fail("你内息无法运至赤阳二穴，不能使出「绝户」招式。\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力太弱，不能使出「绝户」招式。\n");

        if( (int)me->query_condition("juehu_busy"))
                 return notify_fail("你元气大伤，现在没有能力使出「绝户」招式。\n");

                        
        msg = BLU "$N默运神功，脸色白得吓人，突然使出虎爪绝户手的最后一击「绝户」，企图当场把$n废于掌下。\n"NOR;

        pfm_time=(int)busy_time-(me->query("juehu-shou",1)+me->query("yinyun-ziqi",1))*(1+busy_time)/200*busy_time;
        pfm_time1=busy_time1+(int)(me->query("juehu-shou",1)+me->query("yinyun-ziqi",1))*(1+busy_time)/200*busy_time;
        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                me->start_busy(pfm_time);
                target->start_busy(random(pfm_time1));
                
                damage = (int)me->query_skill("juehu-shou", 1);
                
                damage = damage + random(damage)/2;
                
                target->receive_damage("qi", damage, me);

                target->receive_wound("qi", damage/2, me);
                target->receive_damage("jing", damage/2, me);
                target->receive_wound("jing", damage/3, me);
                me->add("neili", -damage/6);
                msg += RED"结果$N一击命中，$n只感到下体一阵刺痛，体内精元不断外泄，顿时觉的四肢无力，两腿不停颤抖。\n"NOR;
                
        } else 
        {
                me->start_busy(random(pfm_time));
                l_temp=80-(int)me->query_skill("yinyun-ziqi", 1)/10;
                me->add("neili", -l_temp);
                msg += CYN"可是$p看破了$P的狠毒企图，向旁跳开数步，躲开了$P的凌厉一击！\n"NOR;
        }
        message_vision(msg, me, target);
        if (damage>200 )
         {
          me->add("shen", -damage);
          target->apply_condition("juehu_hurt",(int)(500*target->query("age")));
          me->apply_condition("juehu_busy",(int)(100*me->query("age")));
          me->add("max_neili", - (20 + random(20)));
          if (target->query("gender")== "男性")
          {
             target->set("gender","无性");
             target->set("genderbak","男性");
             message_vision(HIW"$N突然觉的丹田内的精元已流失迨尽，心里一阵难过，知道自己有一段时间不能行欢做乐了!\n"NOR,target);
           } else
           {if (target->query("gender")== "女性")
               message_vision(HIW"$N被$n一击命中，，不禁既羞又怒，见$n竟对一女流之辈也用此阴毒招数！\n"NOR,target,me);
            else
               message_vision(HIW"$N虽然击中$n的要害，但感觉受力甚轻，似乎已无要害可言!\n"NOR,me,target);
           }
          target->kill_ob(me);
         }
        return 1;
}
