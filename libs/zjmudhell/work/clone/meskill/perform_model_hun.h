
#include <ansi.h>
#include <combat.h>

#define PFM "「" HIW "<绝招名>" NOR "」"

inherit F_SSERVER;

string *weapon_sk = ({
	"sword", "blade", "staff", "whip", "club", "hammer", "axe"
});

int perform(object me, object target)
{
	object weapon;
	string msg;
	int ap, dp;
	int count, damage;
	int attack_time;
	int attack, i;

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
	
	if (me->query("neili") < 500)
		return notify_fail("你现在的真气不够，难以施展" PFM "。\n");

	if (! living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "<PFM发招描述>" + "\n" + NOR;

	ap = me->query_skill("BASE_SKILL");
	dp = target->query_skill("parry");
	 
	if (ap / 2 + random(ap * 2) > dp)
	{
		damage = da_power(me, "BASE_SKILL") * 2;
		msg += COMBAT_D->do_damage(me, target, attack, damage, 100, HIM "<PFM打中描述>" + ""NOR"\n");
		me->add("neili", -200);
	     
		if (! target->is_busy())
			target->start_busy(2);
	} else
	{
		msg += NOR + CYN "<PFM失误描述>" + ""NOR"\n";
		me->add("neili", -100);
	}
		
	message_sort(msg, me, target);
    
	msg = HIW "$N" HIW "余势未尽，招式陡然变得凌厉无比，一转念间已然攻出数招。"NOR"\n";
	if (ap / 2 + random(ap * 2) > dp)
	{
		count = ap / 20;
		msg += HIR "$n" HIR "见$P" HIR "来势迅猛之极，一时不知该如"
		       "何作出抵挡，竟呆立当场。"NOR"\n";
	} else
	{
		msg += HIY "$n" HIY "见$p" HIY "来势迅猛之极，甚难防备，连"
		       "忙振作精神，小心抵挡。"NOR"\n";
		count = 0;
	}

	message_combatd(msg, me, target);
	
	attack_time = 3;
	attack_time += me->query("jieti/times") * 2;
	if (attack_time > 8)
		attack_time = 8;

	me->add("neili", -attack_time * 20);

	me->add_temp("apply/attack", count);
	me->add_temp("apply/damage", count);
		
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
			break;

		COMBAT_D->do_attack(me, target, (member_array("BASE_SKILL", weapon_sk) == -1 ? 0 : weapon), 0);
	}
	me->add_temp("apply/attack", -count);
	me->add_temp("apply/damage", -count);
	me->start_busy(3 + random(attack_time/ 3));			
	return 1;
}


