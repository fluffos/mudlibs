// yulong 玉龙倒悬
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage;
        object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「玉龙倒悬」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
	        return notify_fail("你没拿剑，拿什么倒悬?!\n");

	if( (int)me->query_skill("pomo-jianfa", 1) <100 )
		return notify_fail("你的泼墨披麻剑法不够火候, 使不出玉龙倒悬\n");
	if((int)me->query("neili") < 50)
              return notify_fail("你的内力不够呀!\n");
	msg = CYN "$N左手捏个剑诀，右手" + weapon->query("name") + "攻将过来，向着$n当头砍落，势道凌厉\n";
        me->start_busy(1);
		if(F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 12, me, target))
//        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*2/3 )
        {
            msg += HIR "结果" + weapon->query("name") + "在$n身上划过长长的一道血痕。\n" NOR;

			damage = (int)me->query_skill("pomo-jianfa", 1);
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/2, me);
            me->add("neili", -(damage>>2));
			me->start_busy(1);

        } 
		else 
		{
		    me->start_busy(3);
			msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
     	}
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}


