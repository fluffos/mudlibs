// taotian.c 烈火剑法


#include <combat.h>

inherit F_SSERVER;
string query_name() { return "烈焰"ZJBR"滔天"; }

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("「烈焰滔天」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("liehuo-jian", 1) < 70)
		return notify_fail("你的烈火剑法不够娴熟，不会使用「烈焰滔天」。\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功修为不够高。\n");

	if ((int)me->query("neili") < 300)
		return notify_fail("你现在真气不够，不能使用「烈焰滔天」。\n");

        if (me->query_skill_mapped("sword") != "liehuo-jian")
                return notify_fail("你现在没有激发烈火剑法，不能使用「烈焰滔天」。\n");

	msg = HIR "$N" HIR "口中暴喝一声：熊熊烈火，焚我残躯，生亦何欢，死亦何苦！\n\n"
              "刹那间浑身上下火光冲天，滚滚热浪带起强大的气流四处冲击！\n\n"
              "$N" HIR "冷笑下，腾身而起，人与" + weapon->name() + HIR "合而为一，直向$n" HIR "扑去，气势惊人！\n\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force") / 3 || !living(target))
	{
		damage = (int)me->query_skill("force") + (int)me->query_skill("sword");
        	damage = damage/2 + random(damage);
                me->add("neili", -200);
		me->receive_wound("qi",random(damage/5));
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 60,
                                           HIR "只见$N" HIR "浑身的火光将$n"
                                           HIR "团团围住，$n" HIR "的惨呼声"
                                           "令人毛骨悚然！\n" NOR);
		me->start_busy(2);
	} else
	{
		msg += HIC "可是$p" HIC "猛地向边上一跃，跳出了$P" HIC "的攻击范围。\n"NOR;
		me->add("neili", -100);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
