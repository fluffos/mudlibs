// duo.c 空手入白刃

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
      string msg;
      object weapon, weapon2, target,wea;

      me->clean_up_enemy();
      target = me->select_opponent();

      if( (int)me->query_temp("duo") )
              return notify_fail("你已经在夺敌人的兵刃了。\n");

      if( !(me->is_fighting() ))
              return notify_fail("夺字诀只能对战斗中的对手使用。\n");
       if (!present("shenghuo ling",me))
        return notify_fail("没有圣火令，你无法夺取别人的兵器。\n");

      if (!objectp(weapon = target->query_temp("weapon")) && !objectp(weapon2 = target->query_temp("secondary_weapon")))
         return notify_fail("对方没有兵刃，你不用担心。\n");

      if( (int)me->query_skill("shenghuo-shengong",1) <100)
              return notify_fail("你的圣火神功不够纯熟,无法夺人兵器！\n");


     msg = CYN "$N用"+HIY"圣火令"+CYN"搭住$n的兵器，试图夺走$n的兵器。\n";           message_vision(msg, me,target);
//命中率C- 
     if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target) )

     {
         msg = HIW"$N使出圣火神功的夺字诀, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
	       if (objectp(weapon))
           weapon->move(environment(target));
         else
           weapon2->move(environment(target));
         me->start_busy(1);
     }
     else
     {
         msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
         me->start_busy(3-(int)me->query("mingjiaonewbiejobdone"));
     }
     message_vision(msg, me, target);

     return 1;
}
