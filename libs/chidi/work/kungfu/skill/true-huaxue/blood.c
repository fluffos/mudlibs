#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

      	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("化血只能对战斗中的对手使用。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "现在已经神志不清了！\n");
		
	if( (int)me->query_skill("true-huaxue", 1) < 400 )
		return notify_fail("你的真*化血神针不够娴熟，不会使用「化血」。\n");

	msg = HIR "只见$N化作一片血海向$n卷去。\n";

	 if (me->query("special_skill/gongfusoul") == 1 )
 {
       me->start_busy(random(2));
        }
        else
       {
        me->start_busy(1);
        }  
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 ) {
        msg += HIR " $p被血海一卷，顿时手足无措。\n" NOR;
		target->start_busy( (int)me->query_skill("true-huaxue") / 20 );
	} else {
		msg += HIY "$p轻蔑的看了$P一眼，并没有上当。\n" NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
