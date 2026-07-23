#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

#define SUO "「" HIR "锁魂势" NOR "」"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;
        int lvl, p;
        int count;
	int i, attack_time;


        if (! target) target = offensive_target(me);

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("chanhun-suo",1) < 120)
                return notify_fail("你的缠魂索功力太浅，使不了。\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("你的化功大法火候不够.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("你的三阴蜈蚣爪火候不够.\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("你的内功火候不够，使不了" SUO "。\n");

        //if (target->is_busy())
        //        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if (me->query_skill_mapped("whip") != "chanhun-suo")
                return notify_fail("你没有激发缠魂索法，使不了" SUO "。\n");

        if (me->query("neili") < 350)
                return notify_fail("你内力不足，无法施展" SUO "。\n");

        if (! living(target))
               return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIR "$N" HIR "一声阴笑，使出缠魂索锁魂绝迹，挥舞出满天鞭影，将$n"
              HIR "全全笼罩！\n\n" NOR;

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3)
        {
                msg += HIY "结果$n" HIY "被这排山倒海般的攻击攻了个措手不及，陷如困境，完全无法脱身！\n" NOR;
        message_combatd(msg, me, target);

attack_time=(int)me->query_skill("chanhun-suo", 1) /40;
        if (attack_time > 9)
                attack_time = 9;
        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 300);
        me->add("neili", -attack_time * 30);


	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N挥舞出满天鞭影，打出第"+(i+1)+"鞭！\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -300);
                me->start_busy(2);
        } else
        {
                msg += CYN "可是$p" CYN "看破了$P" CYN "的企图，往后一纵，逃开了攻势。。\n" NOR;
                me->start_busy(3);
        message_combatd(msg, me, target);
        }
        
        return 1;
}
