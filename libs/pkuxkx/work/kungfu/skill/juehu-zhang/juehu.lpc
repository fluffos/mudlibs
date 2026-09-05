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
                return notify_fail("「绝户」神功只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("juehu-zhang", 1) < 100 )
                return notify_fail("你的虎爪绝户手不够娴熟，不会使用「绝户」神功\n");

        if( (int)me->query_skill("bixue-xinfa", 1) < 100 )
                return notify_fail("你的内功等级不够高，不能用「绝户」神功伤敌。\n");

        if( (int)me->query("shen") > 1000 )
                return notify_fail("你是正人君子，怎么能用这么阴毒的招式。\n");

//        if(me->query("juehu_nouse"))
//                 return notify_fail("你内息无法运至赤阳二穴，不能使出「绝户」招式。\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力太弱，不能使出「绝户」招式。\n");


        msg = BLU "$N默运神功，脸色白得吓人，突然使出虎爪绝户掌的最后一击「绝户」，企图当场把$n废于掌下。\n"NOR;

        pfm_time  = busy_time - (me->query("juehu-zhang",1) + me->query("bixue-xinfa",1) ) * (1 + busy_time)/(200 * busy_time);
        if (pfm_time < 0) pfm_time = 0;
        pfm_time1 = busy_time1+(int)(me->query("juehu-zhang",1)+me->query("bixue-xinfa",1))*(1+busy_time)/(200*busy_time);
//C-
        if ( F_KUNGFU->hit_rate(me->query_skill("force"), target->query_skill("force"), 9, me, target) )
        {
                me->start_busy(pfm_time);
                if ( F_KUNGFU->hit_rate(100, 100, 9, me, target) )
                	F_KUNGFU->hit_busy( "fenjin", pfm_time1, target );

                damage = (int)me->query_skill("juehu-zhang", 1);
                damage = damage + 2 * random(damage);

                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                F_KUNGFU->hit_wound("jing", damage/2, damage/3, me, target);

                me->add("neili", - damage / 5);
                msg += RED"结果$N一击命中，$n只感到下体一阵刺痛，体内精元不断外泄，顿时觉的四肢无力，两腿不停颤抖。\n"NOR;
        } else
        {
                l_temp=200-(int)me->query_skill("bixue-xinfa", 1)/10;
                if (l_temp < 0) l_temp = 0;
                me->add("neili", -l_temp);
                me->start_busy(busy_time);
                msg += CYN"可是$p看破了$P的狠毒企图，向旁跳开数步，躲开了$P的凌厉一击！\n"NOR;
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        if (damage > 300 )
         {
          me->add("shen", - damage);

          if (target->query("gender")== "男性")
          {
             message_vision(HIW"$N突然觉的丹田内的精元已流失迨尽，心里一阵难过，知道自己有一段时间不能行欢做乐了!\n"NOR,target);
           } else
           {if (target->query("gender")== "女性")
               message_vision(HIW"$N被$n一击命中，不禁既羞又怒，$n居然对一女流之辈也用此阴毒招数！\n"NOR,target,me);
            else
               message_vision(HIW"$N虽然击中$n的要害，但感觉受力甚轻，似乎已无要害可言!\n"NOR,me,target);
           }
          target->kill_ob(me);
         }
        return 1;
}
