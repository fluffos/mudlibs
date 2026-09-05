// sanjiao.c 三焦齐逆诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-shengong",1);

        if( !me->is_fighting() )
                return notify_fail("「三焦齐逆诀」只能在战斗中使用。\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("你的内力还不够高！\n");

        if( (int)me->query_skill("cuff") < 200 )
                return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！\n");

        if( (int)me->query_skill("qishang-quan", 1) < 200)
                return notify_fail("你七伤拳的修为不够，不能够体会三焦齐逆诀! \n");

        if( (int)me->query_skill("jiuyin-shengong", 1) < 200)
                return notify_fail(HIM "你的九阴神功修为不足，不能随便使用三焦齐逆诀! \n" NOR);

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("你没有激发七伤拳，无法运用三焦齐逆诀！\n");

        msg = HIY "$N凝神定气，企图使出七伤拳总诀中的「" HIR "三焦齐逆诀" HIY "」，将敌方招数反弹！\n"NOR;
//  结果发觉这招已经失传，不能使用，呵呵。\n"
//        message_combatd(msg, me, target);

	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp");
	if( dp < 1 )
		dp = 1;
	if( F_KUNGFU->hit_rate( ap, dp, 9, me, target) )
	{
		if(userp(me))
			me->add("neili",-100);

		msg += HIG "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");

		target->add("neili", -neili_wound);
		F_KUNGFU->hit_wound("qi", qi_wound, 0, me, target);
		target->add_busy(3);
                me->start_busy(1+random(2));
                me->receive_wound("qi",qi_wound/4, "七伤拳反噬");
	}
	else
	{
		msg += HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(1);
	}
	message_combatd(msg, me, target);
    COMBAT_D->report_status(target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
	return 1;
}
