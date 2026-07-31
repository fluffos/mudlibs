#include <ansi.h>
#include <combat.h>

#define DIAN "「" HIR "神指点穴" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DIAN "只能对战斗中的对手使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(DIAN "只能空手施展。\n");

        if ((int)me->query_skill("yiyang-zhi", 1) < 120)
                return notify_fail("你一阳指诀不够娴熟，难以施展" DIAN "。\n");

        if ((int)me->query_skill("force") < 160)
                return notify_fail("你的内功火候不够，难以施展" DIAN "。\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("没有枯荣禅功作为准备，无法使出！\n"); 

        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("你的枯荣禅功太低。\n");
            
        if (me->query("max_neili") < 1800)
                return notify_fail("你的内力修为不足，难以施展" DIAN "。\n");

        if ((int)me->query("neili") < 200)
                return notify_fail("你现在的真气不够，难以施展" DIAN "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIR "$N" HIR "凝聚一阳指诀功力，陡然点出一指，变化多端，巧逼$n"
              HIR "诸处大穴。\n" NOR;

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");
	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "结果$p" HIR "被$P" HIR "逼得招"
                       "架不迭，一时无法反击！\n" NOR;
		target->start_busy((int)me->query_skill("finger") / 20 + 4);
	} else
        {
		msg += CYN "可是$p" CYN "看破了$P" CYN "的变化，"
                       "小心招架，挡住了$P" CYN "的进击。\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
