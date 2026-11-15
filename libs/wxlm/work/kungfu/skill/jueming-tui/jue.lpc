// jue 绝命一踢
 

#include <combat.h>
 
inherit F_SSERVER;
 
string query_name() { return "绝命"ZJBR"一踢"; }
string *pfm_type() { return ({ "unarmed", }); }

int perform(object me, object target)
{
	string msg;
	int ap, dp, pp;
	int damage;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「绝命一踢」只能对战斗中的对手使用。\n");
 
	if (objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用这一绝技。\n");

	if (me->query_skill("jueming-tui", 1) < 80)
		return notify_fail("你的「绝命腿」还不够娴熟，不能使用「绝命一踢」！\n");

	if (me->query_str() < 35)
		return notify_fail("你的膂力不够，小心踢断了腿！\n");

	if (me->query("neili") < 200)
		return notify_fail("你的内力不够，不能使用「绝命一踢」！\n");

	if (me->query_skill_mapped("unarmed") != "jueming-tui")
		return notify_fail("你没有激发绝命腿法，不能使用「绝命一踢」！\n");
 
       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	switch (random(3))
	{
	case 0:
		msg = HIC "$N" HIC "一声冷哼，侧身飞踢，右腿横扫$n"
		      HIC "，当真是势不可当！"NOR"\n";
		break;

	case 1:
		msg = HIC "$N" HIC "大喝一声，飞腿踢出，只踹向$n"
		      HIC "腰际。"NOR"\n";
		break;

	default:
		msg = HIC "$N" HIC "双腿连环踢出，挟带风声嚯嚯作响，"
		      "以千钧之势扫向" HIC "$n！"NOR"\n";
		break;
	}
 
	ap = me->query_skill("unarmed") + me->query("str") * 10;
	dp = target->query_skill("dodge") + target->query("dex") * 10;
	pp = target->query_skill("parry") + target->query("str") * 10;
	
	me->start_busy(2);
	me->add("neili", -50);
	if (ap * 7 / 10 + random(ap) < pp)
	{
		msg += HIG "$n" HIG "身子一晃，硬是架住了$N" HIG "这一击。"NOR"\n";
	} else
	if (ap * 7 / 10 + random(ap) < dp)
	{
		msg += HIG "只见$n" HIG "不慌不忙，轻轻一闪，躲过了$N" HIG "这一击！"NOR"\n";
	} else
	{
		me->add("neili", -70);
		damage = ap / 3 + random(ap / 3);
		msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 66,
					   HIR "$n" HIR "连忙格挡，只觉得力道大得出奇，哪里抵"
					   "挡得住！直被踢得飞起数尺之高！"NOR"\n");
	}

	message_combatd(msg, me, target);
	return 1;
}
