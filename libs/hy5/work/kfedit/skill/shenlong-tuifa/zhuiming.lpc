// zhuiming.c    神龙追命腿
// 98.9.18  by Aug    99.9.11 changed by aug

#include <ansi.h>

inherit F_SSERVER;

#define TICKTIME 5

void exam1(object me , object tartget );
int perform(object me, object target)
{
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character()|| !me->is_fighting(target) )
                return notify_fail("「神龙追命腿」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("shenlong-tuifa", 1) < 150 )
                return notify_fail("你的神龙腿法不够娴熟，不会使用「神龙追命腿」。\n");

        if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
                return notify_fail("你的神龙心法不够深厚，不会使用「神龙追命腿」。\n");

        if( (int)me->query("neili") < 1000)
                return notify_fail("你现在内力太弱，不能使用神龙追命腿。\n");

        if ( me->query_temp("weapon")) 
                return notify_fail("你拿着兵器无法使用神龙追命腿。\n");


        if ( (int)me->query_temp("zhuiming/time") > 0)
                return notify_fail("你正在使用神龙追命腿呢。\n");

        if( me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("你现在所使用的内功同神龙心法向抵触，不能使用「神龙追命腿」。\n");

//      me->start_busy(TICKTIME);
        me->add("neili" , -200);
        me->add("jing" , -80);
        me->set_temp("zhuiming/time",time());
        me->set_temp("zhuiming/target",target);
        me->set_temp("zhuiming/dodge",me->query_skill("dodge", 1)/5);
        me->set_temp("no_fight", 1);
        me->add_temp("apply/dodge",me->query_skill("dodge", 1)/5);
//        me->apply_condition("no_perform", 100);
        message_vision(HIY+"\n$N"+HIY+"陡然长啸一声，双腿飞快的移行换位，却不发一腿，似乎在积聚内力以使出绝技－－神龙追命腿！\n\n"NOR,me);
                
        call_out("exam1",TICKTIME,me,target);

        return 1;
}

void exam1(object me , object target )
{
        string str;     
        int  times;

        if (!me) return;
        times = time()- me->query_temp("zhuiming/time",1);
        if( me->query_skill_mapped("leg") != "shenlong-tuifa"
         || me->query_skill_prepared("leg") != "shenlong-tuifa"){
                me->add_temp("apply/dodge",-me->query_temp("zhuiming/dodge"));
//                me->clear_condition("no_perform");
                me->delete_temp("zhuiming");
                me->delete_temp("no_fight");
                me->start_perform(3,"「神龙追命腿」");
                tell_object(me,"你决定不用神龙腿法攻击，「神龙追命腿」也自动解除。\n");
                return;
        }
        if( target 
         && me->is_fighting(target)
         && (times < 38)
         && me->query_temp("zhuiming")){
                str = HIY+"\n$N"+HIY+"已经聚气"+CHINESE_D->chinese_number(times)+"秒钟，$N双腿快速的移动卷起一团团黄土，似乎在脚下聚集起一团";
                if( times < 10)  str +="小小的气团。"NOR;
                  else if( times < 20) str +="充满真气的气团。"NOR;
                      else if( times < 30) str +="正在不断变大的大气团！"NOR;
                         else str +="显示着逼人锋芒的巨大气团！"NOR;
                message_vision(str+"\n",me);
                message_vision(HIY+"\n$N"+HIR+"你飞快攻出二腿。\n"NOR,me);
me->add_temp("apply/attack",100);
me->add_temp("apply/damage",200);
		COMBAT_D->do_attack(me, target,0, 1); 
		COMBAT_D->do_attack(me, target,0, 1); 		
me->add_temp("apply/attack",-100);
me->add_temp("apply/damage",-200);
//              me->start_busy(TICKTIME);
                call_out("exam1",TICKTIME,me,target);
        }
        else {
                message_vision(HIY+"\n$N"+HIY+"慢慢收回聚集的内力。\n"NOR,me);
                me->add_temp("apply/dodge",-me->query_temp("zhuiming/dodge"));
//                me->clear_condition("no_perform");
                me->delete_temp("zhuiming");
                me->delete_temp("no_fight");
                me->start_perform(3,"「神龙追命腿」");
        }
}
