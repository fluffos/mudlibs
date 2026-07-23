#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define DUO "「" HIC "夺魂势" NOR "」"

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp,attack_time,i;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DUO "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        if (me->query_skill("force", 1) < 130)
                return notify_fail("你的内功火候不够，使不了" DUO "。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("你的化功大法火候不够.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴蜈蚣爪火候不够.\n");

        if (me->query_skill("chanhun-suo", 1) < 100)
                return notify_fail("你的缠魂索功力太浅，使不了" DUO "。\n");

        if (me->query("neili") < 220)
                return notify_fail("你的真气不够，无法使用" DUO "。\n");

        if (me->query_skill_mapped("whip") != "chanhun-suo")
                return notify_fail("你没有激发缠魂索法，使不了" DUO "。\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "诡异的一笑，手中" + weapon->name() +
              HIY "抖得笔直，劈向$n" HIY "手腕，可是待到中途却又停滞，转往$n"
              HIY "胸口挥去！\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (random(me->query("combat_exp"))+100000 > (int)target->query("combat_exp") / 2)
        {
                damage = ap + random(ap / 3);
                me->add("neili", -180);
                me->start_busy(2);
        target->receive_wound("qi", target->query("qi")/8);
        target->receive_damage("qi", target->query("qi")/7);
target->apply_condition("xx_poison",20);
target->apply_condition("x2_sandu",20);
target->apply_condition("sanpoison",20);
                msg += HIR "结果$n" HIR "一声惨叫，未能看破$N"
                                           HIR "的企图，被这一鞭硬击在胸口，鲜血飞"
                                           "溅，皮肉绽开！\n" NOR;


                message_combatd(msg, me, target);
                if (ap > 400) ap = 400;
                dp += target->query_skill("huagong-dafa", 1) * 2;
                if (! target->is_busy() &&
                    ap / 2 + random(ap) > dp)
                {
                        target->start_busy(2 + random(6));
                        message_vision(HIW "$N" HIW "一抖，手中的" + weapon->name() +
                                       HIW "“嗖“的串了出来，隐隐然缠向$n"
                                       HIW "。\n$n" HIW "大吃一惊，急忙退后，闪去这一招。\n" NOR,
                                       me, target);
                }
        } else
        {
                me->add("neili", -100);
                me->start_busy(2);
                msg += CYN "可是$p" CYN "飞身一跃而起，躲避开了"
                       CYN "$P" CYN "的攻击！\n" NOR;
                message_combatd(msg, me, target);
        }

attack_time=(int)me->query_skill("chanhun-suo", 1) /50;
        if (attack_time > 6)
                attack_time = 6;

        me->add("neili", -attack_time * 10);


	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N挥舞出满天鞭影，打出第"+(i+1)+"鞭！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}


        return 1;
}
