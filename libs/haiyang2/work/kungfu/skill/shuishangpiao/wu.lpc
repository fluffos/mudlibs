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


        if((int)me->query_skill("guiyuan-tunafa",1) < 100)
                return notify_fail(HIY "你的归元吐纳法修为不够。\n" NOR);

         if((int)me->query_skill("shuishangpiao",1) < 100)
                return notify_fail(HIY "你的水上漂不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);
    
        if (me->query_skill_mapped("dodge") != "shuishangpiao")
                return notify_fail("你现在激发的轻身不是「水上漂」绝技。\n");                                                                                 
      if( me->query_temp("piao")   )
      return notify_fail("你正在使用水上漂的特殊防御「水上漂」！\n");
       
     msg = HIW"$N突然深吸一口气，身体忽然柔若无骨，左右摇摆" +
               "一招「鲤鱼倒穿波」，反窜出丈余！\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->add_temp("apply/defense", improve);
      me->set_temp("piao",1);  
      me->add("neili", -(350-(int)me->query_skill("shuishangpiao",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("shuishangpiao") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->add_temp("apply/defense", - improve);
      me->delete_temp("piao");
      tell_object(me, HIC"你散去丹田凝聚的内力，混身经脉真气流动，气定神闲，精神弈弈。\n"NOR);
      tell_room(environment(me), HIG + me->name()+"全身骨头一阵轻响，散去了混身的功力。\n" NOR,  ({ me }));
    
}
