// dongqu.c 大江东去

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "大江"ZJBR"东去"; }
string *pfm_type() { return ({ "sword", }); }

int perform(object me, object target)
{
	object weapon;
	int damage;
	int ap, dp, pp;
	string msg;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("大江东去只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("xuantie-jian", 1) < 100)
		return notify_fail("你的玄铁剑法不够娴熟，不能使用大江东去。\n");

	if ((int)me->query_skill("force") < 150)
		return notify_fail("你的内功火候不够，不能使用大江东去。\n");

	if ((int)me->query("neili") < 300 )
		return notify_fail("你现在内力太弱，不能使用大江东去。\n");

	if (me->query_skill_mapped("sword") != "xuantie-jian")
		return notify_fail("你没有激发玄铁剑法，不能施展大江东去。\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "一声猛喝，一股气劲从身后澎湃迸发，手中" +
	      weapon->name() + HIW "凌空挥卷而出，疾如电闪，势若"
	      "雷霆，剑光幻作万道长虹一齐贯向$n" HIW "！"NOR"\n";

	me->start_busy(3);
	ap = me->query_skill("sword") + me->query_str() * 5;
	pp = target->query_skill("force") + target->query_str() * 5;
	dp = target->query_skill("force") + target->query_dex() * 5;
	if (me->query("character") == "光明磊落")
		ap += ap / 10;
	if (ap / 2 + random(ap) < pp)
	{
		msg += CYN "然而$p" CYN "内功当真深厚，奋力接下此剑，竟然不落半点下风。"NOR"\n";
		me->add("neili", -100);
	} else
	if (ap / 2 + random(ap) < dp)
	{
		msg += CYN "$p" CYN "见$P" CYN "此剑势不可挡，急忙提气跃开。"NOR"\n";
	} else
	{
		damage = (ap + random(ap/2));
		me->add("neili", -200);
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 90,
					   HIR "$p" HIR "不及闪避，只得奋力招架，却被$P" HIR
					   "这一剑震的飞起，口中鲜血狂吐不止！"NOR"\n");
	}

	message_combatd(msg, me, target);
	
	if (me->query_skill("taishang-wangqing", 1) > 49 ) 
	{
        msg=HIB"骤然间，$N"HIB"手中" + weapon->name() + HIB "发出一阵轰鸣，带着隆隆的风雷之声，挟雷霆万均之势，一式「"HIR"力荡群魔"HIB"」，" + weapon->name() + HIB "朝$n"HIB"当头直压下去！\n";

	if (ap / 2 + random(ap) > dp)
	{
		damage = (ap + random(ap / 2))*(me->query_skill("taishang-wangqing", 1)+100)/100;
		msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 35,
                                          HIR "$n无力招架，登时被$N这记重招压得气血翻腾，禁不住「哇」地吐出一口鲜血！"NOR"\n");

		me->add("neili", -300);
		message_combatd(msg, me, target);

		return 1;
	}

                msg += HIW"$p连忙全力一挡，「砰」地一声巨响，$P这记重招居然被$p接了下来！\n" NOR;
	message_combatd(msg, me, target);
	}

	return 1;
}
