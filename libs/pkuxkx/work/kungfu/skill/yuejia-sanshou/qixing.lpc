// qixing jue
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
                return notify_fail("「七星诀」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("yuejia-sanshou", 1) < 100 )
                return notify_fail("你的岳家散手不够娴熟，不会使用「七星诀」！\n");

        if( (int)me->query_skill("bixue-xinfa", 1) < 100 )
                return notify_fail("你的内功等级不够高，不能用「七星诀」伤敌。\n");

        /*if( (int)me->query("shen") > 1000 )
                return notify_fail("你是正人君子，怎么能用这么阴毒的招式。\n");
*/
//        if(me->query("juehu_nouse"))
//                 return notify_fail("你内息无法运至赤阳二穴，不能使出「绝户」招式。\n");

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力太弱，不能使出「七星诀」招式。\n");


        msg = HIW "$N"+HIW+"默默将全身劲力提至双手，突然使出岳家散手的精华「七星诀」，轰然攻向$n"+HIW+"。\n"NOR;

        pfm_time  = busy_time - (me->query("yuejia-sanshou",1) + me->query("bixue-xinfa",1) ) * (1 + busy_time)/(200 * busy_time);
        if (pfm_time < 0) pfm_time = 0;
        pfm_time1 = busy_time1+(int)(me->query("yuejia-sanshou",1)+me->query("bixue-xinfa",1))*(1+busy_time)/(200*busy_time);
//C-
        if ( F_KUNGFU->hit_rate(me->query_skill("force"), target->query_skill("force"), 8, me, target) )
        {
                me->start_busy(pfm_time);
                if ( F_KUNGFU->hit_rate(100, 100, 8, me, target) )
                	F_KUNGFU->hit_busy( "fenjin", pfm_time1, target );

                damage = (int)me->query_skill("yuejia-sanshou", 1);
                damage = damage + 2 * random(damage);

                F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                F_KUNGFU->hit_wound("jing", damage/2, damage/3, me, target);

                me->add("neili", - damage / 5);
                msg += RED"结果$N一击命中，$n被$N双手蕴含的巨力震得内息全乱。\n"NOR;
        } else
        {
                l_temp=200-(int)me->query_skill("bixue-xinfa", 1)/10;
                if (l_temp < 0) l_temp = 0;
                me->add("neili", -l_temp);
                me->start_busy(busy_time);
                msg += CYN"可是$p看破了$P的企图，向旁跳开数步，躲开了$P的凌厉一击！\n"NOR;
        }
        message_vision(msg, me, target);
        if (damage > 300 )
         {
          me->add("shen", - damage);
          target->kill_ob(me);
         }
        return 1;
}
