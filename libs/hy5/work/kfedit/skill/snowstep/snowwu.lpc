#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("只有在站斗中才能使用！\n");


       if((int)me->query_skill("bingxue-xinfa",1) < 100)
                return notify_fail(HIY "你的冰雪心法修为不够。\n" NOR);

         if((int)me->query_skill("snowstep",1) < 100)
                return notify_fail(HIY "你的梅雪飘香不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
    
        if (me->query_skill_mapped("dodge") != "snowstep")
                return notify_fail("你现在激发的轻身不是「雪舞」绝技。\n");                                                                                 
      if( me->query_temp("piao")   )
      return notify_fail("你正在使用雪舞！\n");
       
     msg = HIW"$N如柳絮般轻轻飘起。四面八方都是$N的影子,如同满天雪舞！\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      if (improve > 100) improve =100;
      me->add_temp("apply/dodge", improve);
      me->add_temp("apply/defense", improve);
      me->set_temp("piao",1);  
      me->add("neili", -150);    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("snowstep") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/defense",- improve);
      me->delete_temp("piao");
      tell_object(me, HIW"你散去丹田凝聚的内力，身形又正常下来。\n"NOR);
      tell_room(environment(me), HIW + me->name()+"动作越来越慢，散去了混身的功力。\n" NOR,  ({ me }));
    
}
