// mie.c  痴心长情剑「万念俱灰」

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "万念"ZJBR"俱灰"; }

int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int ap, dp;
	
       if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	
	if (! target || ! me->is_fighting(target))
		return notify_fail("「万念俱灰」只能对战斗中的对手使用。\n");

        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("非蜀山不能用「万念俱灰」！\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("没装备剑怎么使用「万念俱灰」？\n");

	if ((int)me->query_skill("canxin-jian", 1) < 60 )
		return notify_fail("你的残心剑不够娴熟，还使不出「万念俱灰」。\n");

	if (me->query_skill_mapped("sword") != "canxin-jian")
		return notify_fail("你没有残心剑，不能使用「万念俱灰」。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够，难以施展「万念俱灰」。\n");

	if ((int)me->query("neili") < 200)
	       return notify_fail("你现在真气不够，难以施展「万念俱灰」。"NOR"\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐\n"
	      "渐逼近$n" HIC "，$p" HIC "看到漫天剑光，抽身后跃，只这一刹，漫天剑\n"
	      "影化为一剑直刺$n" HIC "前胸，快捷无伦，只有一剑！"NOR"\n";

	ap = me->query_skill("force") + me->query_skill("sword") + me->query_skill("sword-cognize");
	dp = target->query_skill("force") + target->query_skill("parry");
	if (ap * 4 / 5 + random(ap) > dp)
	{
		me->start_busy(2);
		damage = (int)me->query_skill("sword");
		damage +=damage + random(damage)*10;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 70,
					   HIR "$n" HIR "全然无法躲避，" + weapon->name() +
					   HIR "端端正正扎进在$n" HIR "胸口，登时鲜血飞溅！"NOR"\n");
		me->add("neili", -150);
	} else
	{
		me->start_busy(3);
		msg += YEL "可是$p" YEL "轻轻一笑，侧身右转，伸"
		       "出两指，正弹在$P" YEL "的剑上，" + weapon->name() +
		       YEL "在$p" YEL "身侧划过，有惊无险。"NOR"\n";
		me->add("neili", -60);
	}
	message_combatd(msg, me, target);
	return 1;
}
