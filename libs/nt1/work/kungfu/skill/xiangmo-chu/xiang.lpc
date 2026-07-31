// xiang.c 降魔

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int i;
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("「降魔」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须拿着杵才能施展「降魔」！\n");

	if ((int)me->query("neili") < 80)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 100)
		return notify_fail("你的内功火候不够！\n");

	if ((int)me->query_skill("xiangmo-chu", 1) < 80)
		return notify_fail("你的降魔杵法还不到家，无法使用绝技「降魔」！\n");

	msg = HIY "$N" HIY "一声断喝，宝相庄严，气度万千，手中的" + weapon->name() + 
              HIY "劈头朝$n" HIY "砸下！\n" NOR;
	message_combatd(msg, me, target);
	me->add("neili", -80);

        for (i = 0; i < 4; i++)
        {
                if (! me->is_fighting(target))
                        break;
        	COMBAT_D->do_attack(me, target, weapon, 0);
        }

	me->start_busy(1 + random(4));
	return 1;
}
