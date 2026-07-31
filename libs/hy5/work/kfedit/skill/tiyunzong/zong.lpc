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
      return notify_fail("「梯云纵」只能在战斗中使用。\n");
             
      
      if( (int)me->query_skill("tiyunzong",1) < 120 )
                return notify_fail("你的梯云纵不够娴熟，不会使用「梯云纵」！\n");
      
      if( (int)me->query_skill("taiji-shengong",1) < 120 )
                return notify_fail("你的气功等级不够，不能使用「梯云纵」！\n");  
      if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你的内功不对，不能使用「梯云纵」。\n");
      if( (int)me->query_dex() < 20 )
                return notify_fail("你的身法太低，不能使用「梯云纵」！\n");
      
      if( (int)me->query_skill("dodge",1) < 120 )
                return notify_fail("你的基本轻功太差，身体笨拙，不能使用「梯云纵」！\n");
      
      if( (int)me->query("neili") < 400 )
      return notify_fail("你的内力太少了，无法使用出「梯云纵」！\n");   
    
        if (me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("你现在激发的轻身数使用「梯云纵」绝技。\n");                                                                                 
      if( me->query_temp("zong")   )
      return notify_fail("你正在使用梯云纵的特殊防御「梯云纵」！\n");
       
     msg = HIW"$N突然深吸一口气，一抬腿猛的拔高数丈，升势刚尽，双腿连续踢出，" +
               "身体又上升丈许，才有如大鸟般盘旋落下！\n" NOR;
      
      message_vision(msg, me, target); 
      improve = (int)me->query_dex() * 2;
      me->add_temp("apply/dodge", improve);
      me->set_temp("zong",1);  
      me->add("neili", -(350-(int)me->query_skill("tiyunzong",1)/10));    
            
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), me->query_skill("tiyunzong") * 2/3 );
//    me->start_perform(me->query_skill("tiyunzong")/3, "「梯云纵」");
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dodge", - improve);
      me->delete_temp("zong");
      tell_object(me, HIR"你散去丹田凝聚的内力，混身经脉真气流动，气定神闲，精神弈弈。\n"NOR);
      tell_room(environment(me), HIW + me->name()+"全身骨头一阵轻响，散去了混身的功力。\n" NOR,  ({ me }));
    
}
