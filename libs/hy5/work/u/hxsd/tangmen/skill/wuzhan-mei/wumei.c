// wumei.c  五梅吐蕊

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
 if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「五梅吐蕊」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「五梅吐蕊」施展时必须拿着一把剑！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("sword") < 100 ||
	    me->query_skill_mapped("sword") != "wuzhan-mei")
		return notify_fail("你的五展梅还不到家，无法使用五梅如蕊！\n");

	msg = HIY "$N使出五展梅绝技「五梅吐蕊」，身法陡然加快！只见剑影如漫天梅瓣，急泄而下。" NOR;
	message_vision(msg, me);

	msg = HIB "蓝梅                                          蓝梅"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIR "              红梅                红梅"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIW+BLINK "		        白梅"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIG "              绿梅                绿梅"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIC "青梅				    	       青梅"NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);

	me->add("neili", -250);
      me->start_busy(3);

	return 1;
}
