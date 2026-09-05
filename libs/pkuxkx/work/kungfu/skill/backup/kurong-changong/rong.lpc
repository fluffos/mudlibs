//perform ku,“荣”字大法
//14/02/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("kurong-changong", 1) < 180 )
                return notify_fail("你的枯荣禅功修为不够，无法使用「荣」字大法！\n");

      if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("其它内功有「荣」字大法吗？\n");

      if( (int)me->query_str() < 25 )
                return notify_fail("你的臂力太低，根本无法使用「荣」字大法！\n");
 
      if( (int)me->query("neili") < 600 )
                return notify_fail("你的内力太少了，无法使用出「荣」字大法！\n");   
    
      if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为这么差，还想使用「荣」字大法？\n");   
                                                                                
      if( me->query_temp("pf_rong")   )
                return notify_fail("你正在运用「荣」字大法！\n"); 
      if( me->query_temp("pf_ku")   )
                return notify_fail("你正在运用「枯」字大法！\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");
                
      message_vision(HIR"\n$N深吸一口气，运起「荣」字大法,身体由缓到急,开始旋转起来，双手隐隐散发着光芒！\n\n" NOR, me);
   me->start_busy(2);
      me->set_temp("pf_rong",1); 
      me->set_temp("powerup",1);
      me->add_temp("apply/attack", me->query_skill("kurong-changong", 1)/3); 
      me->add_temp("apply/damage", me->query_skill("kurong-changong", 1)/3);
      me->add("neili", -600);    
      call_out("remove_effect", me->query_skill("kurong-changong", 1)/2+5, me);
      return 1;
}

void remove_effect(object me)
{
      if(me){
      me->delete_temp("pf_rong");
      me->add_temp("apply/attack", -me->query_skill("kurong-changong", 1)/3); 
      me->add_temp("apply/damage", -me->query_skill("kurong-changong", 1)/3);
      me->delete_temp("powerup");
      message_vision(WHT"\n$N结珈而坐，长吐一口气，散去了凝聚于双手的内力。\n"NOR, me);    
      }
}
