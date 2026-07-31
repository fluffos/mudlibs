// qimai.c 伤字诀

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "伤字诀"; }
string *pfm_type() { return ({ "cuff", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp;
	int count;
	int damage,i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「伤字诀」只能在战斗中对对手使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「伤字诀」只能空手使用。\n");
		
	if (me->query("max_neili") < 1000)
		return notify_fail("你的内力修为还不够，无法施展「伤字诀」。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你的真气不够！\n");

	ap = me->query_skill("cuff") + me->query("con") * 6;
	dp = target->query_skill("force") + target->query("con") * 6;

	if ((int)me->query("qi") < ap*2)
		return notify_fail("伤字诀未伤敌先伤己，你的体力现在不足以施展伤字诀了！\n");

	if ((int)me->query_skill("qishang-quan", 1) < 180)
		return notify_fail("你的七伤拳火候不够，无法使用「伤字诀」！\n");

	if ((int)me->query_skill("force",1) < 180)
		return notify_fail("你的内功修为不够，无法使用「伤字诀」！\n");

	if (me->query_skill_prepared("cuff") != "qishang-quan")
		return notify_fail("你现在没有准备使用七伤拳，无法使用「伤字诀」！\n");

	if (! living(target))
	    return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "怒喝一声，施出绝招「" HIW "伤字诀" HIY "」，双拳迅猛无比的袭向$n" HIY "。\n" NOR;

	me->start_busy(2);
	if (ap / 2 + random(ap) > dp)
	{
		me->add("qi", -ap);   
		damage = ap + random(ap / 2);
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                   HIR "只见$P" HIR "这一拳把$p" HIR
                   "打飞了出去，重重的摔在地上，吐血不止！\n" NOR);
	} else
	{
		msg += HIG "可是$p" HIG "看破了$P" HIG "的企图，没有受到迷惑，闪在了一边。"NOR"\n";
	}
	message_combatd(msg, me, target);

	return 1;
}
