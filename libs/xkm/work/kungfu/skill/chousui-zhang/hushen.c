//by pro
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        string weapon;
        int skill, amount, ap, dp, dmg;

         if( !target ) target = offensive_target(me);

        if( !wizardp(me) )
                return notify_fail("目前此功能暂不开放！\n");


         if( !target
         ||      !target->is_character()
         ||      !me->is_fighting(target) )
                 return notify_fail("火焰护体只能对战斗中的对手使用。\n");

         if( objectp(me->query_temp("weapon")) )
                 return notify_fail("只能空手撩动火焰。\n");

         if( me->query("neili",1) < 3000 )
                 return notify_fail("没有足够的内力无法催动火焰！\n");

         if( me->query_skill("feixing-shu",1) < 150 )
                 return notify_fail("你的飞星术等级不够！\n");

         if( me->query_skill("chousui-zhang",1) < 120 )
                 return notify_fail("你的抽髓掌等级不够！\n");

         if( me->query_skill_mapped("force") != "huagong-dafa" )
                    return notify_fail("你没有用化功大法用不出这么狠毒的招式！\n");

        if (!present("huo yan", environment(me)))
                 return notify_fail("你要撩动空气？！\n");

         if( me->query_temp("hushen",1) )
                 return notify_fail("你真在催动火焰护体！\n");


        message_vision(HIR "\n$N一口真气喷向火焰，火焰似是熄灭，却又腾空而起，\n只见$N不知用的什么邪术，撩动的火焰竟围绕$N快速的流动！\n\n" NOR, me, target);
             me->start_busy(1+random(2));
        ap = me->query_skill("force") + me->query("combat_exp",1)/1000;
        dp = target->query_skill("force") + target->query("combat_exp",1)/1000;

       skill = me->query_skill("feixing-shu",1);

         me->set_temp("apply/parry", skill*3/2);

        me->add("neili", -skill*2 );
        me->add("jingli", -skill );
        me->add("jing", -skill/2 );

        me->set_temp("hushen", skill/10);

        remove_call_out("huoyan_hit");
                 call_out("huoyan_hit",1,me,target);

        remove_call_out("checking");
        call_out("checking", 1, me);

        return 1;
}


int huoyan_hit(object me, object target){
        int skill, ap, dp;
        ap = me->query_skill("force") + me->query("combat_exp",1)/1000;
        dp = target->query_skill("force") + target->query("combat_exp",1)/1000;
        skill = me->query_skill("feixing-shu",1);
        if (present("huo yan", environment(me)) && me->is_fighting() && me->query_temp("hushen",1) > 0 ){
            if(random(ap) > dp*4/5 )
            {
       message_vision(HIR "\n$n抢攻$N上盘，$N身体后仰，同时交替踢出双腿，撩动的火焰烧向$n！\n\n" NOR, me, target);
         me->add("neili", -skill/2);
         target->add("qi", -skill);
         target->add("eff_qi", -random(skill)/2);
         }
            if(random(ap) > dp*10 )
            {
       message_vision(HIR "\n$N大喝：“天火焚身”，原本围绕$N的火焰随掌风罩向$n！\n\n" NOR, me, target);
               if(random(15) > 5) {
       message_vision(HIR "\n毕竟$n实战经验太少，被火焰烧成一堆焦炭！\n\n" NOR, me, target);
            target->die();
            me->add("neili",-skill/2);
                   }
             else
                 {
       message_vision(HIR "\n$n躲闪不及，被烧的遍体鳞伤！\n\n" NOR, me, target);
            me->add("neili",-skill/2);
            target->add("qi",-500);
                 }
           }
          call_out("huoyan_hit", 1, me, target);
        return 1;
     }
}
void checking(object me)
{
        if (!present("huo yan", environment(me)))
        {
         message_vision(HIY"$N眼看火堆熄灭，长叹一声散开内息，双手下垂而立。\n"NOR,me);
                me->delete_temp("hushen");
               me->set_temp("apply/parry", 0);
                return ;
         }
         if( me->query("neili",1) < 1000 )
        {
          message_vision(HIY"$N惊觉内力不续，缓缓散开内息，双手下垂而立。\n"NOR,me);
                me->delete_temp("hushen");
               me->set_temp("apply/parry", 0);
                return ;
         }
         if( me->query_skill_mapped("force") != "huagong-dafa" || me->query_temp("hushen") <= 0 || !me->query_temp("hushen"))
        {
          message_vision(HIY"$N将内力收回丹田，火焰的跳动也恢复了正常。\n"NOR,me);
                me->delete_temp("hushen");
                me->set_temp("apply/parry", 0);
                return ;
         }

        if( !me->is_fighting() )
        {
          message_vision(HIY"$N袖袍一拂，后退一步负手而立。\n"NOR,me);
                me->delete_temp("hushen");
                me->set_temp("apply/parry", 0);
                return ;
         }

         me->add_temp("hushen", -1);
         call_out("checking", 1, me);
         call_out("huoyan_hit", 1, me);

         return;
}
