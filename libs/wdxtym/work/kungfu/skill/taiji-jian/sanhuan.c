
#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "三环套月"; }
string *pfm_type() { return ({ "sword", }); }

int query_cd() { return 4; }

int perform(object me, object target)
{
	object weapon;
	int i;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("太极剑法「三环套月」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("taiji-jian", 1) < 300)
		return notify_fail("你的太极剑法不够娴熟，无法使出「三环套月」。\n");

	if (me->query("neili") < 1000)
		return notify_fail("你的真气不够，无法使出「三环套月」。\n");

	if (me->query_skill_mapped("sword") != "taiji-jian")
		return notify_fail("你没有激发太极剑法，无法使出「三环套月」。\n");
	//if (me->query_skill_mapped("parry") != "taiji-jian")
		//return notify_fail("你没有激发太极剑法为招架武功，无法使出「三环套月」。\n");

      if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	me->set_temp("tjj/sanhuan", 3);
	for (i = 0; i < 3; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}

	return 1;
}
