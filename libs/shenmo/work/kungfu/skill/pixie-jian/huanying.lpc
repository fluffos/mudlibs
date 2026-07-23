// huanying.c 幻影

#include <ansi.h>

inherit F_SSERVER;


int perform(object me)
{
        
       string msg;
        
       object weapon, weapon2, target;
       
       int skill, ap, dp, damage;



       me->clean_up_enemy();
       
       target = me->select_opponent();


        skill = me->query_skill("pixie-jian",1);

   
       if( !(me->is_fighting() ))
            
       return notify_fail("「幻影」只能对战斗中的对手使用。\n");

 
        if (!objectp(weapon = me->query_temp("weapon"))
        ||          (string)weapon->query("skill_type") != "sword")
          
        return notify_fail("你使用的武器不对。\n");

       
     if (!objectp(weapon2 = target->query_temp("weapon")))
                        return notify_fail("对方没有用兵器，你不需要用幻影。\n");

  
      if( skill < 100)
         
      return notify_fail("你的僻邪剑法等级不够, 不能使用「幻影」！\n");

           if( me->query("neili") < 200 )
    
         return notify_fail("你的内力不够，无法运用「幻影」！\n");

 
      if ((int)me->query_skill("kuihua-xinfa", 1) < 80 )
       
      return notify_fail(RED"你葵花心法火候不够，使不出「幻影」。\n"NOR);

        msg = HIC"$N人影连晃，衣袖微摆，向$n急冲而去\n"NOR;
              message_combatd(msg, me, target);

      
     damage = 10 + random(skill / 2)+600;
       
     ap = me->query_skill("sword") + skill;
       
      dp = target->query_skill("dodge")/2 ;
        
      if( dp < 1 )
          
      dp = 1;
    
      if( random(ap) > dp)
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = HIR"$n只觉双手一阵刺痛,大叫一声，手中";
            msg += weapon2->name();
            msg += "落地，一个筋斗翻了出去！\n" NOR;
            me->start_busy(1);
            target->receive_damage("qi", damage);
            target->start_busy(2);  
            me->add("neili",-50);
    if (random(me->query("combat_exp"))> target->query("combat_exp")/2)
   {
            weapon2->move(environment(me));
   }
}            

    else
        {
                  
            me->add("neili",-50);
            msg = MAG"$n以来不及抵挡，百忙中手中的";

      msg += weapon2->name(); 

      msg += "颤动，急刺$N的左目,$N只得向后跳开。\n"NOR;
            me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}
