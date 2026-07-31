// 连环镖

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
		return notify_fail("「连环镖」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "throwing")
			return notify_fail("你使用的武器不对。\n");


	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("你的碧云心法不够高。\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力太弱。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	msg = HIY "$N左右手各抓二枚暗器，似乎分左右射向$n，。" NOR;
	message_vision(msg, me);

	msg = HIB "看镖           左上    "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIR "看镖           左下   "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIG "看镖           右上   "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
	msg = HIC "看镖           右下   "NOR;
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0,msg);
        target->apply_condition("tmpili_poison",60);
	me->add("neili", -150);
      me->start_busy(2);

	return 1;
}
