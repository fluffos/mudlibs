// jue.c 绝命针

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        object weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("pixie-jian", 1) < 140 )
                return notify_fail("你的辟邪剑法不够娴熟，不会使用绝命针。\n");

        if( (int)me->query_dex() < 35  )
                return notify_fail("你的身法太低，不能使用绝命针。\n");
 
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("你现在内力不足！\n");     
	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("你的葵花飞影术不够娴熟。\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("你的葵花心法不够娴熟。\n");
      
     if( (int)me->query("qi") > (int)me->query("max_qi") / 2 )
                return notify_fail("绝命针是救命招数，怎可以随便使用？！\n");    

      if (me->is_busy()) 
   {
    message_vision(MAG "$N将一声尖叫，身形飞了起来，如一朵红云将$N的身形掩没，竟然摆脱了攻击！\n" NOR, me);
me->start_busy(1);
}

  message_vision(RED"\n$N猛地纵起，向$n扑去，手指一弹，细针飞了出去，插向$n右目。\n\n"NOR, me, target);
  
   me->add("neili", -300);
      
if((me->query("combat_exp")) > (int)target->query("combat_exp")/3 &&
 me->query_dex() >random((int)target->query_dex())) {
        message_vision(HIR"\n$n猝不及防，大叫一声，右眼中针！\n"NOR, me, target);
        tell_object(target, HIY "你感觉细针正插在自己的瞳仁之中，如果这针直贯入脑，便有性命之忧！\n" NOR);
                me->start_busy(2);
                target->start_busy(2);
                me->add("neili", -300);
                damage = (int)target->query("max_qi");
                damage = damage/10;
                damage = damage*7;
                
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
//                me->query_temp("weapon")->move(target);
               }
         else 
              {
                target->start_busy(2);
//                me->query_temp("weapon")->move(environment(target));
                message_vision(HIY"\n可是$n看破了$N的企图，飞身闪了开去。\n"NOR, me, target);
                me->set("neili", 0);
              }

        return 1;
}

