//吐雾

#include <ansi.h>


inherit F_SSERVER;


int perform(object me, object target)
{
	
  int skill;
	string msg;
	object weapon;
	
 if( !target ) target = offensive_target(me);

	
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		
return notify_fail("吐雾只能在战斗中使用。\n");

  msg = HIR "$N大吼一声！\n" NOR;
    	message_combatd(
        HIW "只见$N"HIW"口一张，一团白色巨热的浓雾径直喷向$n!\n" NOR, me, target);
	
   if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_combatd(HIR "$n"HIW"一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR, me, target);
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
	       target->apply_condition("snake_poison",10 );
	       target->apply_condition("wugong_poison",10 );
	       target->apply_condition("chanchu_poison",10);
	       target->apply_condition("snake_poison",30 );
	       target->apply_condition("wugong_poison",30 );
	       target->apply_condition("zhizhu_poison",30 );
	       target->apply_condition("xiezi_poison",30 );
	       target->apply_condition("chanchu_poison",30);
    target->start_busy(6);           
}
else 
{
    if( (int)me->query("qi") > (int)me->query("eff_qi") ) me->set("qi", (int)me->query("eff_qi"));
      if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$n一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR;
            target->start_busy(3);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
            } else {
                msg += HIY"可是$p看破了$N的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
message_combatd(HIC "$n"HIC"身形一闪，跃出了浓雾的攻击范围！\n" NOR, me, target);
    me->start_busy(1); 	
}

        return 1;
  
 }