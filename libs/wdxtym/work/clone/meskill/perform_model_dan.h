
#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "<绝招名>" NOR "」"

inherit F_SSERVER;
#include <balance.h>

string *weapon_sk = ({
	"sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int damage;
	int attack;

	if (! me->query("can_perform/" + "SKILL" + "/" + "E_NAME"))
		return notify_fail("你还没有受到高手指点，还不会运用" PFM "。\n");

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail(PFM "只能对战斗中的对手使用。\n");

	if (member_array("BASE_SKILL", weapon_sk) != -1)
	{
		attack = WEAPON_ATTACK;
		if (! objectp(weapon = me->query_temp("weapon"))
		   || (string)weapon->query("skill_type") != "BASE_SKILL")
			return notify_fail("你所使用的武器不对，难以施展" PFM "。\n");
	} else
	{
		attack = UNARMED_ATTACK;
		if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
			return notify_fail(PFM "只能空手使用。\n");	     
	}
	
	if ((int)me->query_skill("SKILL", 1) < 400)
		return notify_fail("你" + to_chinese("SKILL") + "不够娴熟，难以施展" PFM "。\n");

	if (member_array("BASE_SKILL", weapon_sk) == -1)
	{
		if (me->query_skill_prepared("BASE_SKILL") != "SKILL")
			return notify_fail("你没有准备" + to_chinese("SKILL") + "，难以施展" PFM "。\n");
	}
	
	if (me->query("neili") < 300)
		return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "<PFM发招描述>" + "\n" + NOR;

	ap = me->query_skill("BASE_SKILL");
	dp = target->query_skill("parry");
	 
	if (ap * 2 / 3 + random(ap * 2) > dp)
	{
		damage = da_power(me, "BASE_SKILL") * 3;
		msg += COMBAT_D->do_damage(me, target, attack, damage, 100, HIM "<PFM打中描述>" + ""NOR"\n");
		me->add("neili", -200);
		me->start_busy(1);
		if (! target->is_busy())
			target->start_busy(2);
	} else
	{
		msg += NOR + CYN "<PFM失误描述>" + ""NOR"\n";
		me->add("neili", -100);
		me->start_busy(2);
	}
		
	message_sort(msg, me, target);
	return 1;
}


