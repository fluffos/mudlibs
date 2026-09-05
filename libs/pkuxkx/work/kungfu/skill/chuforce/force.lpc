// force.c

inherit SKILL;

int exert(object me, object target)
{
        int damage;
       	string msg;

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("你必须空手才能运用内力反震。\n");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("神功震敌只能对战斗中的对手使用。\n");
		    
		    if ( me->is_busy() )
		      return notify_fail("你正忙着！\n");

        damage = (int)me->query_skill("force") - (int)target->query_skill("force") / 2;
        if( damage > 0 )
        {
                if( F_KUNGFU->hit_rate( me->query_skill("force"), target->query_skill("force"), 6, me, target) )
                {
                        F_KUNGFU->hit_wound("qi", damage * 2, damage, me, target);
                        if( damage < 100 ) msg = "$n受到$N的内力反震闷哼一声。\n";
                        else if( damage >= 100 && damage < 200 ) msg = "$n被$N以内力反震「嘿」地一声退了两步。\n";
                        else if( damage >= 200 && damage < 500 ) msg = "$n被$N以内力一震胸囗有如受到一记重锤，连退了五六步。\n";
                        else msg =  "$n被$N的内力一震，眼前一黑身子向後飞出丈许\n\n";
                        message_vision(msg, me, target);
                        COMBAT_D->report_status(target);
                }
                else
                {
                        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
                        if( damage < 100 ) msg = "受到$n的内力反震闷哼一声。\n";
                        else if( damage >= 100 && damage < 200 ) msg = "被$n以内力反震「嘿」地一声退了两步。\n";
                        else if( damage >= 200 && damage < 500 ) msg = "被$n以内力一震胸囗有如受到一记重锤，连退了五六步。\n";
                        else msg =  "被$n的内力一震，眼前一黑身子向後飞出丈许\n\n";
                        message_vision("结果$N一击失败，" + msg, me, target);
                        COMBAT_D->report_status(target);
                }

        }
        else
        {
        	       damage = - damage;
        	       F_KUNGFU->hit_wound("qi", damage, damage/2, target, me);
                 if( damage < 100 ) msg = "受到$n的内力反震闷哼一声。\n";
                 else if( damage >= 100 && damage < 200 ) msg = "被$n以内力反震「嘿」地一声退了两步。\n";
                 else if( damage >= 200 && damage < 500 ) msg = "被$n以内力一震胸囗有如受到一记重锤，连退了五六步。\n";
                 else msg =  "被$n的内力一震，眼前一黑身子向後飞出丈许\n\n";
                 message_vision("结果$N一击失败，" + msg, me, target);
                 COMBAT_D->report_status(target);
        }

        me->add("neili", - 100);
        me->start_busy(2);

        return 1;

}
