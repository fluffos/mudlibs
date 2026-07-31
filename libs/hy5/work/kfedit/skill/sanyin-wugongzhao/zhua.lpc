// zhua.c 三阴毒爪

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define ZHUA "「" HIG "三阴毒爪" NOR "」"

string final(object me, object target);

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int damage;


	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail(ZHUA "只能对战斗中的对手使用。\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 180)
		return notify_fail("你的三阴蜈蚣爪不够娴熟，无法使用" ZHUA "。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 50)
		return notify_fail("你的本门内功不够娴熟，无法使用" ZHUA "。\n");


        if (me->query("neili") < 150)
                return notify_fail("你真气不足，无法施展" ZHUA "。\n");
 
        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "突然一声怪叫，蓦的面赤如血，随即手腕一抖，抓向$n"
              HIR "的要害。\n" NOR;

        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
	if (ap  + random(ap) > dp)
        {
                damage = me->query_skill("sanyin-wugongzhao",1)*2  + random(me->query_skill("claw",1));
        msg += HIR "$p" HIR "惊慌失措，连忙后退，然而没"
               "能避开，被$P" HIR "这一爪抓得鲜血淋漓！\n" NOR;
        if (target->query("qi") > damage)
        {
        target->add("qi",-damage);
        target->add("eff_qi",-damage);
        }
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
                me->start_busy(2);
	} else
        {
		msg += HIR "不过$p" HIR "看破了$P" HIR "的招式，"
                       "凝神招架，挡住了$P" HIR "的毒招。\n" NOR;
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}

