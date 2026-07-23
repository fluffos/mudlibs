// fumo.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
           object target;
      string msg;                                   
      int i,z;
           i = (int)me->query_str();
           z = (int)me->query_skill("jiuyin-zhengong",1)/5+(int)me->query_skill("dafumo-quan",1)/4;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("「伏魔」只能在战斗中对对手使用。\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("你必须空手使用「伏魔」！\n");
      
      if( (int)me->query_skill("jiuyin-zhengong",1) < 100 )
      return notify_fail("你的九阴真功不够娴熟，不能使用「伏魔」！\n");  
      
      if( (int)me->query_skill("dafumo-quan",1) < 180 )
      return notify_fail("你的大伏魔拳不够娴熟，不会使用「伏魔」！\n");
      
      if(me->query_skill_mapped("force") != "jiuyin-zhengong")
                return notify_fail("你没有运用九阴真功，无法使用「伏魔」进行攻击。\n"); 

      if (me->query_skill_prepared("unarmed") != "dafumo-quan"
      || me->query_skill_mapped("unarmed") != "dafumo-quan")
                return notify_fail("你现在无法使用「伏魔」进行攻击。\n");                                                                                 

      if( (int)me->query_str() < 25 )
      return notify_fail("你的臂力不够强，不能使用「伏魔」！\n");
      
      if( (int)me->query("neili") < 1300 )
      return notify_fail("你的内力太弱，不能使用「伏魔」！\n");
      
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大伏魔拳的特殊攻击「伏魔」！\n");
       
      msg = HIW"$N突然全身骨骼作响，口中默念「伏魔」,运起九阴真功，全身好象有使不完的力量一样！\n" NOR;
      
      message_vision(msg, me, target); 
      if ((int)me->query_skill("jiuyin-zhengong", 1) > 300) i = i * 2;
      if (i> 200) i=200;
      me->add_temp("apply/strength", i);
      me->set_temp("fumo",1);  
      me->add("neili", - 1000);
      me->add("jing", - 250);  
if (!me->is_busy()) me->start_busy(2);
      call_out("check_fight", 1, me, i, z);
      
      return 1;
}
void remove_effect(object me, int i)
{
//    i = (int)me->query_str() * 2;
    if(me->query_temp("fumo")){
    me->add_temp("apply/strength", -i);
    me->delete_temp("fumo");
    tell_object(me,HIY"你的「伏魔」运功完毕，你的脸色好看多了。\n"NOR);
     }
//    else tell_object(me, "。\n" NOR);
}
void check_fight(object me, int i, int z)
{
  

    if (!me) return;
    if (me->query_temp("weapon")
       || me->query_temp("secondary_weapon")
       || me->query_skill_mapped("unarmed"!="dafumo-quan"))
    {
        remove_effect(me, i);
        return;
    }
    if (z < 1 || !me->is_fighting()) {
        remove_effect(me, i);
        return;
    }
    call_out("check_fight", 1, me, i, z-1);
}
