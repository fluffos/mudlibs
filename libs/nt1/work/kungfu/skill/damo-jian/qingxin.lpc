// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// qingxin.c 「清心剑」

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	object weapon;
	string msg;
        int ap, dp;
        int ainc, dinc;

        if (userp(me) && ! me->query("can_perform/damo-jian/qingxin"))
                return notify_fail("你还没有受过高人指点，无法施展「清心剑」。\n");

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("「清心剑」只能对战斗中的对手使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_skill("damo-jian", 1) < 200)
		return notify_fail("你的达摩剑法不够娴熟，不会使用「清心剑」。\n");

        if (me->query("neili") < 300)
                return notify_fail("你现在真气不够，无法使用「清心剑」。\n");

        if (me->query_skill_mapped("sword") != "damo-jian")
                return notify_fail("你没有激发达摩剑法，无法使用「清心剑」。\n");

        if (target->query_temp("damo_qingxin"))
                return notify_fail("对方刚刚才中过达摩清心剑，你不必再用一次了。\n");

	msg = HIM "$N" HIM "将" + weapon->name() + "轻轻一抖，一股"
              "剑气悄然而出，分作数路攻向$n" HIM "！\n" NOR;

        me->add("neili", -200);
        
        ap = ap_power(me, "sword");
        dp = dp_power(target, "force");
        
        if (! target->query_temp("powerup"))
        {
 		msg += CYN "可是$p" CYN "看来似乎并没有运用真气提升" CYN
                       "战力，$P" CYN "这一招没有起到任何作用。\n" NOR;
		me->start_busy(1);
        } else
	if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "结果$p" HIR "觉得浑身一麻，手足软"
                       "软的竟然使不出一点力道！\n" NOR;
                ainc = target->query_temp("apply/attack");
                dinc = target->query_temp("apply/defense");
		target->add_temp("apply/attack", -ainc);
		target->add_temp("apply/defense", -dinc);
                target->set_temp("damo_qingxin", 1);
                me->start_call_out((: call_other, __FILE__, "remove_effect",  
                target, ainc, dinc:), ap / 5); 
	} else
        {
		msg += CYN "可是$p" CYN "内力深厚，使得$P" CYN
                       "这一招没有起到任何作用。\n" NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}

void remove_effect(object me, int ainc, int dinc)
{
        if (me->query_temp("damo_qingxin"))
        {
                me->delete_temp("damo_qingxin");
        	me->add_temp("apply/attack", ainc);
        	me->add_temp("apply/defense", dinc);
        	tell_object(me, "你觉得力气恢复了一些。\n");
        }
}
