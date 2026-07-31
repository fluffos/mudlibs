#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
 
string query_name() { return "百花"ZJBR"错乱"; }

string query_txt()
{
	return "要求：百花错拳200级，拳脚、拳法、掌法、爪法、手法全部激发为百花错拳，百花错拳等级不能高于5种空手基本，内力大于1000"ZJBR
			"效果：分别对比自身5种空手激发等级和目标的招架激发等级，对目标打出最多5种单招伤害，"
			"每命中一下，自身 busy +1，内力 -100。";
}

int perform(object me, object target)
{
	string msg;
	int damage;
	int lvl;
	int n,ap,dp;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("百花错乱只能对战斗中的对手使用。\n");

	if (me->query_skill_prepared("unarmed") != "baihua-quan" &&
	    me->query_skill_prepared("cuff") != "baihua-quan" &&
	    me->query_skill_prepared("strike") != "baihua-quan" &&
	    me->query_skill_prepared("claw") != "baihua-quan" &&
	    me->query_skill_prepared("hand") != "baihua-quan")
		return notify_fail("你现在没有准备使用百花错拳，无法施展百花错乱！\n");
 
	if (me->query_temp("weapon"))
		return notify_fail("百花错乱须是空手才能施展。\n");

	if (me->query("neili") < 1000)
		return notify_fail("你的真气不够，无法施展百花错乱。\n");

	if ((lvl = me->query_skill("baihua-quan", 1)) < 200)
		return notify_fail("你的百花错拳还不够纯熟！\n");

    if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "只见$N使出百花错拳的精妙百花错乱，擒拿手中夹着鹰爪功，左手查拳，右手绵掌。攻\n"
		  "出去是八卦掌，收回时已是太极拳，诸家杂陈，毫无规律，只令$n眼花缭乱。"NOR"\n";

	n = 1;
	// 第一招
	ap = me->query_skill("unarmed");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += "\n" HIC "$N" HIC "深深吸了一口气，纵深一跃，双腿交错，踢向$n" HIC "。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "奋力抵挡，却哪里招架得住？被$P"
					   HIR "这一下踢中，狂喷一口鲜血！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "嘿的一声，硬声声将$P" CYN "这一脚架开，丝毫无损。"NOR"\n";
	}

	// 第二招
	ap = me->query_skill("strike");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += HIC "$N" HIC "随即一声冷笑，双手变掌虚虚实实，变幻莫测，排向$n！"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "大惑不解，一时难以勘透其中奥妙，连中几掌，身披数创！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "淡淡一笑，浑然不将$P" CYN "玄妙的招数放在眼中，随意将之架开。"NOR"\n";
	}

	// 第三招
	ap = me->query_skill("cuff");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += HIC "$N" HIC "又是一声暴喝，双手变拳一式精妙拳法向$n直捣而下！"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "运力抵挡，然而这一拳却从意想不到的角度实实在在的打中$n！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "一口气自丹田运了上来，$P"
		CYN "硬生生架住了这精妙的一拳。"NOR"\n";
	}

	// 第四招
	ap = me->query_skill("hand");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += "\n" HIC "$N" HIC "脚步一晃，忽然近上身来，身法奇快，双手忽然变化，竟然又一式手法，直指$n" HIC "要害。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "只是慢了一步，登时被$P"
					   HIR "这一击正中，登时闷哼一声！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "身法却是更快，只是一退，让$P" CYN "这一招堪勘不能奏效。"NOR"\n";
	}

	// 第五招
	ap = me->query_skill("claw");
	dp = target->query_skill("parry");
	damage = ap + random(ap/3);
	msg += "\n" HIC "$N" HIC "眼神一变，右手转而变爪，抓向$n胸口几处大穴。"NOR"\n";
	if (ap / 2 + random(ap) > dp)
	{
		n++;
		me->add("neili", -100);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 40,
					   HIR "$p" HIR "一时竟被$P这冰冷的眼神镇住，忙轮中胸口忽然一麻！"NOR"\n");
	} else
	{
		msg += CYN "$p" CYN "冷静非凡，不为所动，凝神抵挡，不漏半点破绽！"NOR"\n";
	}

	me->start_busy(n);
	me->add("neili", -100);
	message_combatd(msg, me, target);

	return 1;
}
