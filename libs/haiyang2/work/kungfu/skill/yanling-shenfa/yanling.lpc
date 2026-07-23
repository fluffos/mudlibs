#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int improve);

int perform(object me, object target)
{
      string msg;                                   
      int improve;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("「灵动如燕」只能在战斗中使用。\n");
             
      
      if( (int)me->query_skill("yanling-shenfa",1) < 120 )
                return notify_fail("你的燕灵身法不够娴熟，不会使用「灵动如燕」！\n");

      if( (int)me->query_dex() < 20 )
                return notify_fail("你的身法太低，不能使用「灵动如燕」！\n");

      if (me->query_skill("shenyuan-gong", 1)<50)
                return notify_fail("你的本门内功火候未到，！\n");

      
      if( (int)me->query_skill("dodge",1) < 150 )
                return notify_fail("你的基本轻功太差，身体笨拙，不能使用「灵动如燕」！\n");
      
      if( (int)me->query("neili") < 400 )
      return notify_fail("你的内力太少了，无法使用出「灵动如燕」！\n");   
    
      if (me->query_skill_mapped("dodge") != "yanling-shenfa")
               return notify_fail("你现在激发的轻身数使用「灵动如燕」绝技。\n");                                                                                 
      if( me->query_temp("yanling")   )
      return notify_fail("你正在使用燕灵身法的特殊防御「灵动如燕」！\n");
       
     msg = HIG"$N突然深吸一口气，突然之间拔高数丈，升势刚尽，又是一个翻身，" +
               "身体又上升丈许，才有如一只灵动的燕子！\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->set_temp("yanling",1);  
      me->add("neili", -(350-(int)me->query_skill("yanling-shenfa",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("yanling-shenfa") * 2/3 );
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->delete_temp("yanling");
      tell_object(me, HIR"你散去丹田凝聚的内力，混身经脉真气流动，气定神闲，精神弈弈。\n"NOR);
      tell_room(environment(me), HIW + me->name()+"全身骨头一阵轻响，散去了混身的功力。\n" NOR,  ({ me }));
    
}
