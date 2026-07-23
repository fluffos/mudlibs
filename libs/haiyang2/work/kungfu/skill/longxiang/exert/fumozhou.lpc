// /kungfu/skill/longxiang
// by dubei

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me)
{
    if(me && me->query_temp("mz_lx")){
      me->add_temp("apply/strength", -me->query_skill("longxiang", 1)/6);
      me->add_temp("apply/dexerity", -me->query_skill("longxiang", 1)/6);
      me->delete_temp("mz_lx");
      tell_object(me,HIR"你的「降妖伏魔咒」运功完毕，感到内劲渐渐消退。\n"NOR);
      }
}
void check_fight(object me)
{
    if (!me) return;

    if (me->query_skill_mapped("force"!="longxiang") ||
        !me->is_fighting() || me->query("neili") < 100
        || me->query_temp("weapon")) {
        	remove_call_out("remove_effect"); 
                remove_effect(me);
                }
    else call_out("check_fight", 1, me);
}

int exert(object me)
{

      int i, z;

      if( (int)me->query_skill("longxiang",1) < 120 )
          return notify_fail("需要有第六层以上的龙象般若功，才能运用「降妖伏魔咒」！\n"); 
      if( (int)me->query_skill("lamaism",1) < 120 )
          return notify_fail("你的密宗心法不够，无法运用「降妖伏魔咒」！\n");      
      if( !me->is_fighting() )
          return notify_fail("「降妖伏魔咒」只能在战斗中对对手使用。\n");
      if (me->query_temp("weapon"))
           return notify_fail("「降妖伏魔咒」拿着武器是使不出来的！\n");
      if( (int)me->query("neili") < 800 || (int)me->query("max_neili")<1200  ) 
                return notify_fail("你的内力不够。\n");
      if( (int)me->query_temp("mz_lx") ) 
                return notify_fail("你已经在运功中了。\n");
      if(me->query_temp("honglian"))        
                return notify_fail("你正在使用「红莲火」。\n");  
      if(me->query_temp("combat_yield"))
           return notify_fail("哦。。。你现在正打不还手呢。\n");

      i = me->query_skill("longxiang", 1)/6;
      z = me->query_skill("lamaism")/3;
      me->add("neili", -500);

      message_vision(HIR "\n$N徒然凌空跃起，双臂向上伸展，口中喃喃念起「降妖伏魔咒」，内力汹涌而至，一层一层的加强！\n\n" NOR, me);
      me->add_temp("apply/strength", i);
      me->add_temp("apply/dexerity", i);
      me->set_temp("mz_lx", 1);
      check_fight(me);
      call_out("remove_effect", z, me);
      me->start_busy(1); 
      return 1;
}

