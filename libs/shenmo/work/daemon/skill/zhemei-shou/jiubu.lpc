// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// jiubu.c 九部式

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
        int ap, dp;

        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }
	if (! target || ! me->is_fighting(target))
		return notify_fail("「九部式」只能对战斗中的对手使用。\n");

//        if (userp(me) && ! me->query("can_perform/zhemei-shou/jiubu"))
//                return notify_fail("你还没有领悟到这个绝招精华，无法施展「九部式」。\n");
                
	if ((int)me->query_skill("zhemei-shou", 1) < 120)
		return notify_fail("你的折梅手法不够娴熟，不会使用「九部式」。\n");
	                        
	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功修为不够高，难以运用「九部式」。\n");
			
	if ((int)me->query("neili") < 100)
		return notify_fail("你现在真气不够，不能使用「九部式」。\n");

        if (me->query_skill_mapped("hand") != "zhemei-shou")
                return notify_fail("你没有激发天山折梅手，不能使用「九部式」。\n");

	msg = HIC "$N" HIC "双手虚虚实实的抓向$n"
              HIC "的要害，身法缥缈，手式奇特，令人难以捉摸。\n" NOR;

        ap = me->query_skill("hand") + me->query("str") * 20;
        dp = target->query_skill("dodge") + target->query("dex") * 20;
             
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("hand");
		me->add("neili", -100);
  target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg += HIR "$p" HIR "一个闪避不及，结果被$P"
                                           HIR "抓了个正中，浑身内息不由得一滞，气血翻涌。\n" NOR;

		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "身手敏捷，巧妙的躲过了$P"
                       HIC "的攻击！\n"NOR;
		me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	return 1;
}
