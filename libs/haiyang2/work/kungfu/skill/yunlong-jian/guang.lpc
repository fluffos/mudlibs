#include <ansi.h>
#include <combat.h>

#define XIAN "「" HIY "神光再现" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int level;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIAN "只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" XIAN "。\n");

        if (target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        level = me->query_skill("yunlong-jian", 1);



	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("你的云龙神功不够高。\n");
	if( (int)me->query_skill("yunlong-jian", 1) < 150 )
		return notify_fail("你的云龙剑法还不够纯熟！\n");
        if (me->query_skill_mapped("sword") != "yunlong-jian")
                return notify_fail("你没有激发云龙剑法，难以施展。\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不足，难以施展" XIAN "。\n");

        if (me->query("neili") < 150)
                return notify_fail("你现在的真气不够，难以施展" XIAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");


	msg = HIG "\n$N" HIG "长啸一声，使出破阳冷光剑绝招「" HIY "神光再"
              "现" HIG "」，\n手中" + weapon->name() + HIG "光芒瀑涨，刺眼"
              "眩目，犹如神光降世，刹那间只觉得天地为之失辉，光芒已盖"
              "向$n\n" HIG "。" NOR;
        message_vision(msg, me, target);

        me->add("neili", -120);
        if (level / 2 + random(level) > target->query_skill("dodge", 1))
        {
		msg = HIR "$n" HIR "被耀眼的光芒所惑，心中惊"
                      "疑不定，一时间不知如何应对！\n" NOR; 
                target->start_busy(level / 50 + 3);
                me->start_busy(1);
	} else
        {
		msg = CYN "可是$n" CYN "看破了$N"
                      CYN "的企图，一丝不乱，应对自若。\n" NOR;
                me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}