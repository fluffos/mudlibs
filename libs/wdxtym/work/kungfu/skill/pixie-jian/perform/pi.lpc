// pi.c 群邪辟易

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return HIR"群邪辟易"NOR; }

int perform(object me, object target)
{
	string msg;
	object weapon;
	int i;
	int skill;
	int count;
	int isGhost;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("「群邪辟易」只能对战斗中的对手使用。\n");

	skill = me->query_skill("pixie-jian", 1);

	if (userp(me) && skill < 120)
		return notify_fail("你的辟邪剑法修为有限，现在不能使用「群邪辟易」！\n");

	if (me->query("neili") < 100)
		return notify_fail("你的真气不够，无法运用「群邪辟易」！\n");

	weapon = me->query_temp("weapon");

	if (weapon && weapon->query("skill_type") != "sword" &&
	    weapon->query("skill_type") != "pin")
		return notify_fail("你不能使用这种兵器施展「群邪辟易」！\n");

	if (userp(me) && ! weapon &&
	    sizeof(me->query_skill_prepare()) &&
	    me->query_skill_prepared("unarmed") != "pixie-jian")
		return notify_fail("你没有准备使用辟邪剑法，不能施展「群邪辟易」！\n");

    if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if (weapon)
	{
		msg = HIR "$N" HIR "身形忽然变快，蓦的冲向$n"
		      HIR "，手中的" + weapon->name() + HIR "指指点点，如同"
		      HIR "寒夜晨星一般，点点光芒刺向$p" HIR "。"NOR"\n";
	} else
	{
		msg = HIR "$N" HIR "忽然冲向$n" HIR "，身法快得"
		      HIR "不可思议，几近鬼魅，伸手就是数掌拍向$n" HIR "！"NOR"\n";
	}

	message_combatd(msg, me, target);
	count = skill / 8;
	isGhost = me->query("special_skill/ghost");

	if (isGhost && random(2))
		count *= 4;

	me->add_temp("apply/attack", count);

	for (i = 0; i < 7; i++)
	{
		if (! me->is_fighting(target))
			break;
		if ((random(3) == 0 || (isGhost && random(2))) && ! target->is_busy())
			target->start_busy(1);
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	if (me->query("special_skill/ghost") && random(2))
		me->start_busy(1 + random(4));
	else
		me->start_busy(1 + random(7));

	me->add_temp("apply/attack", -count);

	return 1;
}

