// zuijiu.c 醉酒

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{                                  
      int drunk, limit, i, lvl;
      	string msg;
        int extra;
      object weapon;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target))
                return notify_fail("「八仙醉打」只能在战斗中对对手使用。\n");

      if (!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "club"
        || me->query_skill_mapped("club") != "weituo-chu")
                return notify_fail("你现在无法使用「八仙醉打」。\n");
                
            
      if( (int)me->query_skill("weituo-chu",1) < 100 )
                return notify_fail("你的醉棍不够娴熟，不会使用「八仙醉打」！\n");
      
      if( me->query_skill_mapped("force") != "yijinjing" )
                return notify_fail("你现在所使的内功无法使出「八仙醉打」。\n");

      if( (int)me->query_skill("yijinjing",1) < 100 )
                return notify_fail("你的易筋经等级不够，不能使用「八仙醉打」！\n");  
       
      if( (int)me->query_str() < 25 )
                return notify_fail("你的臂力不够强，不能使用「八仙醉打」！\n");
      
      if( (int)me->query("max_neili") < 1300 )
                return notify_fail("你的内力太弱，不能使用「八仙醉打」！\n");
            
      	limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;
      	lvl = (int)me->query_skill("weituo-chu", 1);

      	lvl /= 30;
      	lvl--;
      	if(lvl > 12) lvl = 12;  
      	if(lvl < 1) return notify_fail("你的等级太低，无法使用出「八仙醉打」！\n");

      	if( (int)me->query("neili") < 100*lvl )
                return notify_fail("你的内力太少了，无法使用出「八仙醉打」！\n");
          
      	message_vision(HIY"\n$N突然一个醉嗝，顿时借着酒劲猛打，醉棍威力大增！\n"NOR,me);
if (random(2)==0) target->start_busy(2);
      	for(i=0; i < lvl; i++){
      	   	if(!me->is_killing(target) 
      	   	&& !target->is_killing(me)
      	   	&& !target->is_fighting(me))
      	   	break;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIR  "$N突然一个醉嗝，不知从何处打出第"+(i+1)+"棍！\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
      	}
           	me->add("neili", -400);
      		me->add("jing", 20);

      	me->start_busy(3);
        return 1;
}
