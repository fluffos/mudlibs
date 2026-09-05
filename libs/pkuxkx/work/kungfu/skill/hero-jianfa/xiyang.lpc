#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target )
		target = offensive_target(me);

	if( !target
		|| !target->is_character()
		|| !me->is_fighting(target) )
		return notify_fail("夕阳残照只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须使剑才能使用「夕阳残照」！\n");
	if (me->query("neili") < 200)
		return notify_fail("你的内力不够！\n");
    if (time() - me->query_temp("hero-jianfa/last") < 5)
    {
        return notify_fail("你刚刚使用过英雄剑法的绝技，气息尚未调顺。\n");
    }
    me->set_temp("hero-jianfa/last",time());
	weapon = me->query_temp("weapon");
	extra = me->query_skill("hero-jianfa",1) / 5;
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N使出英雄剑法中的必杀着［夕阳残照］，手中的"+ weapon->name() +"舞出一片红光,$n顿时什么也看不见！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR, msg);
	msg = HIR "$w吐着红光，刺向$n的$l\n"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR, msg);
	target->add_busy(random(3)+1);
	msg = HIR "$N剑光一闪，只剩下一片惨淡的血红弥漫在黄昏的天地间.....\n"NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili",-200);
	me->add_busy(1);
	return 1;
}