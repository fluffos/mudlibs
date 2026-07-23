// wudui.c 无双无对

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int improve);
int perform(object me, object target, int improve)
{
      object weapon;
      weapon = me->query_temp("weapon");

      improve =(int)me->query_skill("huashan-sword", 1) / 5;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("无双无对只能在战斗中对对手使用。\n");

//      if( (string)me->query("gender") != "女性" )
//      return notify_fail("只有女弟子才能用出无双无对。\n");	

      if (!weapon || weapon->query("skill_type") != "sword"
       || me->query_skill_mapped("sword") != "huashan-sword")
      return notify_fail("你手里没有剑，无法使用无双无对！\n");             

      if( (int)me->query_skill("huashan-sword",1) < 100 )
      return notify_fail("你的华山剑法不够娴熟，不能使用无双无对！\n");
      
      if( (int)me->query_skill("sword",1) < 100 )
      return notify_fail("你的基本剑法等级不够，不能使用无双无对！\n");  

      if( (int)me->query_skill("zixia-shengong", 1) < 60 )
      return notify_fail("你的紫霞神功等级不够，不能使用无双无对！\n");
      if (me->query_skill_mapped("force") != "zixia-shengong")
                return notify_fail("你所使用的内功不对。\n");
      if( (int)me->query("max_neili") < 800 )
      return notify_fail("你的内力太弱，不能使用无双无对！\n");
	if( (int)me->query_temp("leidong") ) 
		return notify_fail("你已经在运雷动九天中了。\n");

      
      if( (int)me->query("neili") < 500 )
      return notify_fail("你的内力太少了，无法使用出无双无对！\n");   

      if( me->query_temp("wudui") )
      return notify_fail("你正在使用无双无对。\n");
                                                                                 
      message_vision(HIC"\n$N突然使出华山绝技，一式“无双无对，宁式一剑”，只见$N挺剑
直出，剑式如虹，嗤嗤之声大作，凌厉绝伦，剑力已将$n全身笼罩。\n"NOR, me,target);
      me->start_busy(2);
      me->add_temp("apply/strength", improve);
      me->add_temp("apply/attack", improve);
      me->add_temp("apply/dodge", improve);
      me->set_temp("wudui", 1);
      me->add("neili", -200);
      me->add("jing", -50);
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), improve );
      return 1;
}

void remove_effect(object me, object target)
{
      int improve;
      improve =(int)me->query_skill("huashan-sword", 1) / 5;
      me->add_temp("apply/strength", - improve);
      me->add_temp("apply/attack", - improve);
      me->add_temp("apply/dodge", -improve);
      me->delete_temp("wudui");
}
	