// lu.c 戮仙决
 
#include <ansi.h>
#include <combat.h>
 
inherit F_SSERVER;
#include <balance.h>
 
int perform(object me, object target)
{
	string msg;
	int ap, dp;
        int damage;

        if (! target)
        {
        	me->clean_up_enemy();
        	target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("戮仙决只能对战斗中的对手使用。\n");
 
	if (me->query_skill("bluesea-force", 1) < 120)
		return notify_fail("你的南海玄功还不够娴熟，不能使用戮仙决！\n");

        if (me->query("neili") < 200)
                return notify_fail("你的内力不够，不能使用戮仙决！\n");
 
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "嘿然冷笑，拍出一掌，吞吞吐吐，变化莫测，攻向$n"
              HIC "！\n" NOR;
 
        ap = ap_power(me, "force") + me->query("con") * 20;
        dp = dp_power(target, "parry") + target->query("con") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap + random(ap) < dp)
        {
		msg += HIG "然而$n" HIG "看破了$N" HIG
                       "的掌势，不慌不忙的躲过了这一击！\n" NOR;
        } else
	{
		me->add("neili",-75);
                damage = da_power(me, "force");
                msg += COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 60,
                                           HIR "$n" HIR "不明所以，运功抵挡，只觉得$P的掌力怪"
                                           "异之极，直渗入至奇经八脉，登时受了内伤！\n" NOR);
	}

	message_combatd(msg, me, target);
	return 1;
}
