// wuqin.c 无情无义

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
string msg;
	if( !me->is_fighting() )
		return notify_fail("「无情无义」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("blade") < 50 ||
	    me->query_skill_mapped("blade") != "liujue-dao")
		return notify_fail("你的「六绝刀法」还不到家，无法使用「无情无义」！\n");

	if( (int)me->query_skill("liujue-dao", 1) < 150 )
		return notify_fail("你的「六绝刀法」还不到家，无法使用「无情无义」！\n");

	msg = HIY "$N使出「无情无义」，身法突地变得异常灵动飘忽！\n" NOR;
	message_vision(msg, me);

//	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

	me->add("neili", -100);
	me->start_busy(random(2)+1);

	return 1;
}
