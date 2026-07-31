//perform ku,“枯”字大法
//14/02/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("kurong-changong", 1) < 180 )
                return notify_fail("你的枯荣禅功修为不够，无法使用「枯」字大法！\n");

      if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("其它内功有「枯」字大法吗？\n");

      if( (int)me->query_con() < 35 )
                return notify_fail("你的根骨太低，根本无法使用「枯」字大法！\n");
 
      if( (int)me->query("neili") < 600 )
                return notify_fail("你的内力太少了，无法使用出「枯」字大法！\n");   
    
      if( (int)me->query("max_neili") < 2000 )
                return notify_fail("你的内力修为这么差，还想使用「枯」字大法？\n");   
                                                                                
      if( me->query_temp("pf_ku")   )
                return notify_fail("你正在运用「枯」字大法！\n");
      if( me->query_temp("pf_rong")   )
                return notify_fail("你正在运用「荣」字大法！\n"); 
      message_vision(GRN"\n$N结珈而坐,双臂张开外划，缓缓收回于丹田，运起「枯」字大法，内力扩散全身，隐隐散着一股青气！\n\n" NOR, me);
   me->start_busy(2);
      me->set_temp("pf_ku",1); 
      me->add_temp("apply/armor", me->query_skill("kurong-changong", 1)/3); 
      me->add_temp("apply/dodge", me->query_skill("kurong-changong", 1)/3);
      me->add("neili", -600);    
   call_out("remove_effect", me->query_skill("kurong-changong", 1)/2+10, me);
      return 1;
}

void remove_effect(object me)
{
      if(me){
      me->delete_temp("pf_ku");
      me->add_temp("apply/armor", -me->query_skill("kurong-changong", 1)/3); 
      me->add_temp("apply/dodge", -me->query_skill("kurong-changong", 1)/3);
      message_vision(WHT"\n$N结珈而坐，长吐一口气，散去了凝聚全身内力。\n"NOR, me);    
      }
}
