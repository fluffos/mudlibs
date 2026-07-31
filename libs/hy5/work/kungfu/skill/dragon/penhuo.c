//喷火

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
		
return notify_fail("喷火只能在战斗中使用。\n");
msg = HIR "$N大吼一声！\n" NOR;
  
    	message_combatd(
        HIR "$N"HIR"深深吸了一口气，随即一声怒吼，一团火焰喷射而出！
 $n"HIR"一下之陷入的一片火海之中！\n" NOR, me, target);
   if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_combatd(HIR "$n"HIR"一声惨叫，看来伤得不轻！\n" NOR, me, target);
    target->add("eff_qi", -target->query("eff_qi")/20);           
    target->add("qi", -target->query("qi")/20);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
    me->start_busy(1); 	
}
else 
{
	
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$n一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR;
            target->start_busy(6);           
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
message_combatd(HIC "$n"HIC"不慌不忙，一个高跃。闪了出去！\n" NOR, me, target);
    me->start_busy(1); 	
}
        return 1;
  
 }