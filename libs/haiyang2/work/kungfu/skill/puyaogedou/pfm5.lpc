// sui.c 加气血

#include <ansi.h>
void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("加气血只能在战斗中使用。\n");

	if( (int)me->query_skill("puyaogedou", 1) < 40 )
		return notify_fail("你不会使用加气血。\n");
        if( me->query("up1") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");
        if( me->query("pfm5") < 1 )
                return notify_fail("你现在不能使用此pfm.\n");
	skill = me->query_skill("puyaogedou");
	msg = HIG "$N大叫几声，激发全身潜力,伤口好像变好了一些。\n"NOR;
	message_combatd(msg, me, target);

    if( (int)me->query("qi") > (int)me->query("eff_qi") ) me->set("qi", (int)me->query("eff_qi"));
    me->receive_curing("qi", 100 + (int)me->query_skill("puyaogedou") );
    me->add("qi", 100 + (int)me->query_skill("puyaogedou")/2 );
me->add("eff_qi", 100 + (int)me->query_skill("puyaogedou")/2 );
if (me->query("up1")==2)
{
    me->receive_curing("qi", 100 + (int)me->query_skill("puyaogedou") );
    me->add("qi", 100 + (int)me->query_skill("puyaogedou") );
me->add("eff_qi", 100 + (int)me->query_skill("puyaogedou") );    
}
       if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$n一下啥也看不清了,只得采取守式，不敢妄动！\n" NOR;
            target->start_busy(3);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
            } else {
                msg += HIY"可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}
