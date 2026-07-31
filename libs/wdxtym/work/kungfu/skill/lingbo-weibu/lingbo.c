// lingbo.c  洛神凌波

#include <ansi.h>

inherit F_SSERVER;

string query_name() { return "洛神"ZJBR"凌波"; }

int perform(object me, object target)
{
	string msg;
	int level,ap, dp,num;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("洛神凌波只有在战斗中才能使用。\n");

	if ((level = me->query_skill("lingbo-weibu", 1)) < 120)
		return notify_fail(HIY "你的凌波微步还不够熟练。"NOR"\n");

	if ((int)me->query("neili") < 400)
		return notify_fail(HIY "你现在真气不足。\n" HIY);

	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	if( me->query("gender") == "女性")
	       msg = HIW "$N" HIW "提起真气，依照先天伏羲六十"
		     "四卦，不理$n" HIW "如何出招，自顾自的将"
		     "凌波微\n步由头到尾迅速无比的走了一次。"
		     "$N" HIW "仿如洛神再生，微步凌波，$n" HIW
		     "却是一点\n皮毛也沾不上。$N" HIW "真个将"
		     "逍遥二字发挥得淋漓尽至。"NOR"\n";

	else   msg = HIC "$N" HIC "提起真气，依照先天伏羲六十"
		     "四卦，不理$n" HIC "如何出招，自顾自的将"
		     "凌波微\n步由头到尾迅速无比的走了一次。"
		     "只见$N" HIC "意态飘逸，影子乱飞，$n" HIC
		     "却是一点\n皮毛也沾不上。$N" HIC "真个将"
		     "逍遥二字发挥得淋漓尽至。"NOR"\n";
	ap = me->query_skill("lingbo-weibu", 1);
	dp = target->query_skill("dodge", 1);
num = ap/25  + 2;
if (num>25) num=25;	
if (me->query_skill("zuoyou-hubo", 1) > 300)
{
	if (ap *3/10 + random(ap) > dp)
	{
		msg += HIW "结果$p" HIW "被$P" HIW "围着转得头晕眼花！"NOR"\n";
		target->start_busy(num);
		me->add("neili", -100);
		me->start_busy(2);
	}
	else
	{
		msg += HIY "结果$p" HIY "只是勉强的逃了开去。"NOR"\n";
		me->add("neili", -30);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}else
{
	if (ap /2 + random(ap) > dp)
	{
		msg += HIW "结果$p" HIW "被$P" HIW "围着转得头晕眼花！"NOR"\n";
		target->start_busy(num);
		me->add("neili", -100);
		me->start_busy(2);
	}
	else
	{
		msg += HIY "结果$p" HIY "只是勉强的逃了开去。"NOR"\n";
		me->add("neili", -30);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
}	

	return 1;
}
