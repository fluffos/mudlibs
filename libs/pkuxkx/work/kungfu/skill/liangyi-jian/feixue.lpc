// feixue.c 漫天飞雪 



#include <ansi.h>

#include <weapon.h>



inherit F_SSERVER;



int perform(object me, object target)

{

        int damage, attp, defp;

        object obj;

        string w_name;



        w_name = me->query("weapon/name");

        obj = me->query_temp("weapon");



        if( !target ) target = offensive_target(me);



        if( !target || !target->is_character() || !me->is_fighting(target) )

                return notify_fail("「漫天飞雪」只能对战斗中的对手使用。\n");



        if ((int)me->query_skill("liangyi-jian", 1) < 60)

   return notify_fail("你的正两仪剑法不够娴熟，无法使出两仪剑绝技之一的「漫天飞雪」。\n");



        if ((int)me->query_skill("xuantian-wuji", 1) < 70)

                return notify_fail("你的玄天无极功火侯太浅，无法使出「漫天飞雪」。\n"); 

//         if ((int)me->query_skill("throwing", 1) < 60)

//                return notify_fail("你的「基本暗器」火侯太浅，无法使出「漫天飞雪」。\n"); 

        if ((int)me->query("neili",1) < 300)

                return notify_fail("你的内力不够，无法使出两仪剑中「漫天飞雪」的绝技。\n"); 

        message_vision( HIW "$N大喝一声，聚气于剑，默运内力，只听“铮”的一声，天地为之一窒，但见银光点点，$N手中\n"

         + "长剑竟化为无数粹片，如漫天飞雪般向$n激射而出！\n"NOR, me, target );



        attp = me->query_skill("xuantian-wuji",1) + me->query_skill("liangyi-jian",1);

        defp = target->query_skill("dodge");



        if( random( attp ) > random( defp ) )

        {

                damage = me->query_skill("liangyi-jian",1) + (int)me->query_skill("xuantian-wuji", 1)*2;

                damage = damage - random( target->query_skill("dodge")/3 );



                if( objectp(obj)&&w_name!=obj->query("name") )

                {

                        target->receive_wound("jing", random( damage/2 ), me)*3;

                        target->receive_damage("qi", 20 + random(damage), me)*3;

                        target->receive_wound("qi", 20 + damage, me)*3;

                        COMBAT_D->report_status(target);

                        target->start_busy(3 + random(10));

                }

                else

                {

                        target->receive_wound("jing", random( damage/2 ), me);

                        target->receive_damage("qi", 20 + random(damage), me);

                        target->receive_wound("qi", 20 + damage, me);

                        COMBAT_D->report_status(target);

                        me->start_busy(3);

                        target->start_busy(3 + random(4));

                }

        }

        else {

                message_vision( HIY "$p不慌不忙地晃动身形，瞬时间躲过了剑雨。\n" NOR, me, target );

                me->start_busy(5);

        }



        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);



        me->add("neili", -150);



        if( objectp(obj) && w_name!=obj->query("name") )

        {

                me->set("weapon/make",0);

                destruct( obj );

                me->delete("weapon");

                me->save();

        }

        else destruct( obj );



        return 1;

}



