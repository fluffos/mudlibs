// feixue.c 漫天飞雪 



#include <ansi.h>
#include <combat.h>
#include <weapon.h>



inherit F_SSERVER;



int perform(object me, object target)

{
        string msg;
        int damage, attp, defp;

        object obj;

        string w_name;


    object weapon;
        w_name = me->query("weapon/name");

        obj = me->query_temp("weapon");
        


        if( !target ) target = offensive_target(me);


    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("开什么玩笑，没装备剑就想使「漫天飞雪」？\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )

                return notify_fail("「漫天飞雪」只能对战斗中的对手使用。\n");


   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");

        if ((int)me->query_skill("liangyi-jian", 1) < 60)

   return notify_fail("你的正两仪剑法不够娴熟，无法使出两仪剑绝技之一的「漫天飞雪」。\n");



        if ((int)me->query_skill("xuantian-wuji", 1) < 70)

                return notify_fail("你的玄天无极功火侯太浅，无法使出「漫天飞雪」。\n"); 

//         if ((int)me->query_skill("throwing", 1) < 60)

//                return notify_fail("你的「基本暗器」火侯太浅，无法使出「漫天飞雪」。\n"); 

        if ((int)me->query("neili",1) < 500)

                return notify_fail("你的内力不够，无法使出两仪剑中「漫天飞雪」的绝技。\n"); 
    if( (int)me->query_skill("art", 1) > 80 )
    {
    msg = HIC"$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n看到剑光偏右，疾侧身左转，但只这一刹，剑光刹时袭向左首！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"$n看到剑光偏上，疾侧身下转，但只这一刹，剑光刹时袭向下身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n看到剑光偏下，疾侧身上转，但只这一刹，剑光刹时袭向上身！"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
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


                        target->receive_damage("qi", 220 + random(damage))*3;

                        target->receive_wound("qi", 220 + damage)*3;



                        target->start_busy(2 + random(8));

                }

                else

                {


                        target->receive_damage("qi", 220 + random(damage));

                        target->receive_wound("qi", 220 + damage);



                        me->start_busy(3);

                        target->start_busy(3 + random(4));

                }

        }

        else {

                message_vision( HIY "$p不慌不忙地晃动身形，瞬时间躲过了剑雨。\n" NOR, me, target );

                me->start_busy(4);

        }



//        if( !target->is_killing(me) ) target->kill_ob(me);



        me->add("neili", -300);



if (random(2)==0) me->start_busy(3);


        return 1;

}



