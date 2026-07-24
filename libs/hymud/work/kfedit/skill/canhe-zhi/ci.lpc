// ci.c canhe-zhi perform 刺字诀
// by leontt 1/5/2000
// modified by darken to reduce busy time

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
          return notify_fail("「刺字诀」只能在战斗中对对手使用。\n");
             
      if( objectp(me->query_temp("weapon")) )
          return notify_fail("你必须空手使用「刺字诀」！\n");
          
      if( target->is_busy() )
          return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
      
      if( (int)me->query_skill("canhe-zhi",1) < 100 )
          return notify_fail("你的参合指不够娴熟，不会使用「刺字诀」！\n");

      if( (int)me->query_skill("shenyuan-gong",1) < 100 )
          return notify_fail("你的神元功等级不够，不能使用「刺字诀」！\n");  
      
      if( (int)me->query_str() < 30 )
          return notify_fail("你的臂力不够强，不能使用「刺字诀」！\n");
      
      if( (int)me->query("max_neili") < 1000 )
          return notify_fail("你的内力太弱，不能使用「刺字诀」！\n");
      
      if( (int)me->query("neili") < 300 )
          return notify_fail("你的内力太少了，无法使用出「刺字诀」！\n");   
                                                                                 
      if (me->query_skill_prepared("finger") != "canhe-zhi"
       || me->query_skill_mapped("finger") != "canhe-zhi")
          return notify_fail("你现在无法使用「刺字诀」进行攻击。\n");                                                                                 
      
      if( me->query_temp("ci"))
          return notify_fail("你正在使用参合指的特殊攻击「刺字诀」！\n");
       
      msg = HIC"$N突然一掌拍在自己的丹田上激荡全身的内力形成一股「"HIR"剑气"HIC"」，从右手拇指激射而出，刺向$n的肩部。\n" NOR;
      message_vision(msg, me, target);   
//      me->start_perform(4,"「刺字诀」");                                                                
      if(random(me->query("combat_exp"))>target->query("combat_exp")/4){
    
        msg = RED"$n的肩关节一酸，双臂立时失去知觉，动弹不得。\n"NOR;
      
        message_vision(msg, me, target); 
      
        improve = (int)me->query("dex");
        me->add_temp("apply/dexerity", improve);
        me->set_temp("ci",1);  
        me->add("neili", - 300);    
        target->start_busy(random((me->query_skill("douzhuan-xingyi",1)+me->query_skill("canhe-zhi",1))/60)+2);      
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :),
        me->query_skill("finger")/20+2);
      }
      else {
        msg = HIM"$n早已看出了$N的企图，纵身一跃，敏捷地躲过了$N的这一招！\n"NOR;          
        message_vision(msg, me, target);                                        
        me->start_busy(random(2)+1);                          
        me->add("neili", - 50);
      }
      return 1;
}

void remove_effect(object me, int improve)
{
      me->add_temp("apply/dexerity", - improve);
      me->delete_temp("ci");
//    tell_object(me, HIR"你「刺字诀」用完, 运气一周脸色好了许多。\n"NOR);
}
