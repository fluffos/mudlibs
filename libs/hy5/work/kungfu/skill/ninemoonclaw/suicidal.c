
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
int j,j2;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「唯我独尊」只能对战斗中的对手使用。\n");


	msg = RED "$N双目尽赤，祭出九阴白骨爪最后一式「唯我独尊」，";
j=(int) me->query("max_qi")/2;
j2=(int) me->query("max_jing")/2;
if (j >5000) j=5000;
if (j2>3000) j2=3000;

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->receive_damage("qi",j,me);
		target->receive_wound("jing",j2,me );
	} else {
		msg += "可是$p还是躲过了$P的最后一击！！\n" NOR;
	}
	message_vision(msg, me, target);
        me->unconcious();
	return 1;
}
