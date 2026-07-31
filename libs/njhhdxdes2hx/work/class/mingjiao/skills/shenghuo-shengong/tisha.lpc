// tisha.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("万里黄沙只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "双目难睁，无法攻击。ⅵ\n");
		
	if( (int)me->query_skill("shenghuo-shengong", 1) < 50 )
		return notify_fail("你的圣火神功不够娴熟，不会使用万里黄沙。\n");

	msg = CYN "$N身子半蹲，右腿贴地一扫，将地上的沙石扬起，企图迷住$n的眼睛。
\n";

	me->start_busy(1);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += "结果$p被$P迷住了双眼，双目不能视物。\n" NOR;
		target->start_busy( (int)me->query_skill("shenghuo-shengong") / 20 );
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}

