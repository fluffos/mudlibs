//左右互搏
//write by hacky

#include <ansi.h>

inherit NPC;

void remove_effect(object me, int amount);

int perform(object me, object target)
{ int skill; int i;
        string msg;
        object weapon;
        if(!me->query("suxin"))
                return notify_fail("你所使用的外功中没有这项功能");                        
        if( !target ) 
		return notify_fail("你要攻击谁。\n");

        if(me->query("hubo")!=1)
              return notify_fail("你不会左右互搏，无法使出玉女素心剑法。\n");
        
	if( me->query_skill("yunu-jianfa",1)<120)
		return notify_fail("你的「玉女剑法」等级不够，无法使用「玉女素心剑法」。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「玉女素心剑法」只能对战斗中的对手使用。\n");
        
	if( (int)me->query("neili") < 300)
		return notify_fail("你的内力不够，无法施展「玉女素心剑法」。\n"); 
        if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
          if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword")
                 return notify_fail("你手中无剑，如何使得「玉女素心」？\n");
	if( (int)me->query_temp("yunv") ) 
		return notify_fail("你已经发动了玉女素心！\n");
	me->set_temp("yunv", 1);
        me->add("neili", -200);

 skill=(int)me->query_skill("yunu-jianfa",1);
   me->add_temp("apply/attack", skill/4);
me->add_temp("apply/damage", skill/5);
me->start_busy(3);
 me->start_call_out(__FILE__, "remove_effect", 10, me, skill);
 msg = RED "$N使出「玉女素心剑法」,同时默念左右互搏，向$n一阵猛刺。\n" NOR;
 message_vision(msg, me, target);
for(i=1;(i<=(me->query_skill("yunu-jianfa",1)-90)/30)&&(i<=3);i++)
{
msg = HIW "$N右手出剑......\n" NOR;
        message_vision(msg, me, target);
COMBAT_D->do_attack(me, target, weapon);

        
msg = HIW "$N左手出剑......\n" NOR;
 message_vision(msg, me, target);
COMBAT_D->do_attack(me, target, weapon);
  //    if( (int)target->query("qi") < 0 ) 
  //            return 1;

   //   COMBAT_D->do_attack(me, target, query_temp("weapon"));
   //   if( (int)target->query("qi") < 0 ) 
   //           return 1;
}
        
}
void remove_effect(object me, int amount)
{
         me->add_temp("apply/attack", - amount/4);
     me->add_temp("apply/damage", - amount/5);
message_vision(CYN "$N的素心剑法已使用一遍，攻势崭缓周围的人也都松了一口气。\n"NOR,me);
	me->delete_temp("yunv");
}


