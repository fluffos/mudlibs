// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// rou.c 柔字诀

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
	int damage;
	string msg;
        int ap, dp;

        if (userp(me) && ! me->query("can_perform/lingshe-quan/rou")) 
                return notify_fail("你还没有受过高人指点，无法施展「柔字诀」。\n");  
        
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("「柔字诀」只能对战斗中的对手使用。\n");

	if (objectp(me->query_temp("weapon")))
		return notify_fail("你要施展拳法不能使用武器。\n");
		
	if ((int)me->query_skill("lingshe-quan", 1) < 120)
		return notify_fail("你的灵蛇拳法不够娴熟，现在还无法使用「柔字诀」。\n");
	                        
	if ((int)me->query("neili") < 200)
		return notify_fail("你现在真气不够，无法运用「柔字诀」。\n");
			
	msg = HIG "$N" HIG "一拳打出，半途中手臂忽然不可思议的转了个圈子，打向$n"
              HIG "，令$p" HIG "防不胜防。\n"NOR;

        ap = ap_power(me, "cuff"); 
        dp = dp_power(target, "dodge"); 

	if (ap / 2 + random(ap) > dp)
	{
		target->start_busy(1);
		damage = da_power(me, "cuff");

		me->add("neili", -100);
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 50,
                                           HIR "只见$n" HIR "大吃一惊，仓皇之下不及闪躲，被$N"
                                           HIR "一拳打了个正中，闷哼一声，连退数步！\n" NOR);
		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "见机的快，连忙施展身法，避开了拳。\n" NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
