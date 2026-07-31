// duo.c 空手入白刃
 
#include <ansi.h>
 
inherit F_SSERVER;

string query_name() { return "夺兵式"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	string msg;
	object weapon, weapon2;
	int skill, ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「空手夺白刃」只能对战斗中的对手使用。\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手才能施展「空手夺白刃」。\n");

	if (! objectp(weapon2 = target->query_temp("weapon")))
	   return notify_fail("对方没有兵刃，你不用担心。\n");

	skill = me->query_skill("zhemei-shou", 1);

	if (skill < 100)
		return notify_fail("你的天山折梅手等级不够，不能「空手夺白刃」！\n");

	if (me->query_skill("force") < 200)
		return notify_fail("你内功火候不够，使不出「空手夺白刃」。\n");

	if (me->query("neili") < 100)
		return notify_fail("你的真气不够，无法空手入白刃！\n");
 
	if (me->query_skill_prepared("hand") != "zhemei-shou")
		return notify_fail("你没有准备使用折梅手，无法施展「折梅式」！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "凝神闭息，双手插入$n" HIC
	      "的破绽之处，试图夺下它的兵刃。"NOR"\n";
	message_combatd(msg, me, target);
 
	ap = me->query_skill("hand");
	dp = target->query_skill("parry") * 3 / 2;
	me->add("neili", -50);
	if (ap / 2 + random(ap) > dp)
	{
		me->add("neili", -50);
		msg = HIY "$n" HIY "顿时觉得眼前一花，手腕一麻，手"
		     "中兵刃脱手而出！"NOR"\n";
		weapon2->move(me, 1);
		me->start_busy(2);
	}
	else
	{
		msg = CYN "可是$p" CYN "的看破了$P" CYN
		      "的企图，立刻采取守势，使$P" CYN "没能夺下$p"
		      CYN "的兵刃。"NOR"\n";
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	return 1;
}
