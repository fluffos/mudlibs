// dashouyin dashou-yin perform
// by dubei

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

int perform(object me, object target)
{
      string msg, dodge_skill;                                
      int damage, jiali, attack, defense, p;
      object armor;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target) )
           return notify_fail("「大手印」只能在战斗中对对手使用。\n");        
      
      if( (int)me->query_skill("dashou-yin",1) < 120 )
           return notify_fail("你的大手印不够娴熟，不会使用密宗神功「大手印」！\n");
      
      if( (int)me->query_skill("hand",1) < 120 )
           return notify_fail("你的基本手法不够娴熟，不会使用密宗神功「大手印」！\n");

      if( (int)me->query_skill("longxiang",1) < 120 )
           return notify_fail("你的龙象般若功等级不够，不能使用「大手印」！\n");  
      
      if( (int)me->query_str() < 35 )
           return notify_fail("你的臂力不够强，不能使用「大手印」！\n");
      
      if( (int)me->query("max_neili") < 1000 )
           return notify_fail("你的内力太弱，不能使用「大手印」！\n");
      
      if( (int)me->query("neili") < 800 )
           return notify_fail("你的内力太少了，无法使用出「大手印」！\n");   
       
      if( (int)target->query_condition("dashouyin"))
           return notify_fail("对方早已身中「大手印」绝技了！\n");   
      
      if ( me->query_skill_mapped("hand") != "dashou-yin"
        || me->query_skill_mapped("parry") != "dashou-yin")
           return notify_fail("你现在无法使用「大手印」！\n");   
          
      if( objectp(me->query_temp("weapon")) )
           return notify_fail("你必须空手使用「大手印」！\n");                                                                              
      
       
      jiali = me->query("jiali")+1;
      attack = me->query("combat_exp")/1000;
      attack += me->query_skill("hand");
      attack += me->query("neili")/5;
      defense = target->query("combat_exp")/1000;
      defense += target->query_skill("dodge");
      defense += target->query("neili")/7;
      attack = (attack+random(attack+1))/2;
      
      damage = me->query_skill("dashou-yin", 1)/40 * jiali;
      if(damage > 1500) damage = 1500;
      
      message_vision(BLU"\n$N突然面色怪异，低声默念密宗真言，双臂骨节一阵爆响，猛然腾空而起，伸手向$n胸前按去，好一式密宗「大手印」！\n"NOR,me,target);
 
      if( attack > defense ) { 
      	 if( objectp(armor = target->query_temp("armor/cloth"))
      	    && armor->query("armor_prop/armor") < 1500
      	    && damage > 500){
                	message_vision(HIY"只见这斗大的手印正好印在$N的$n"HIY"上，越变越大，竟将它震得粉碎，裂成一块块掉在地上！\n"NOR, target, armor);
                        armor->unequip();
                        armor->move(environment(target));
                        armor->set("name", "破碎的" + armor->query("name"));    
                        armor->set("value", 0);
                        armor->set("armor_prop/armor", 0);
                        target->reset_action();
                        }
      	 tell_object(target, RED"你只觉得霍的胸口一阵剧痛，已经被拍中了前胸！\n"NOR);
      	 target->apply_condition("dashouyin", 1+(me->query_str()/8));
      	 target->receive_damage("qi", damage,  me); 
         target->receive_wound("qi", damage, me);
         p = (int)target->query("qi")*100/(int)target->query("max_qi");
         msg = damage_msg(damage, "内伤");
         msg += "( $n"+eff_status_msg(p)+" )\n";
         message_vision(msg, me, target);
         me->add("neili", -jiali);
      	}
      else {
      	 dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
         }
      me->add("neili", -200);
      me->start_busy(2);            
      return 1;
}

 
