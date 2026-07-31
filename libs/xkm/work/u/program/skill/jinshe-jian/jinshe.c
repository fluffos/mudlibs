// jinshen.c perform 金蛇万道
// cck 13/6/97

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
	string msg;
        int damage;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「蛇影万道」只能在战斗中对对手使用。\n");

if( (int)me->query_skill("jinshe-jianfa", 1) < 90 )
		return notify_fail("你的金蛇剑法不够娴熟，不会使用「金蛇万道」。\n");

        if( (int)me->query_skill("sword", 1) < 90 )
		return notify_fail("你的基本功还没练好，不能使用「金蛇万道」。\n");
        if( (int)me->query_dex() < 30  )
                return notify_fail("你的身法太低，无法使出「金蛇万道 。\n");

         if( (int)me->query_str() < 30 )
		return notify_fail("你的膂力不够强，不能使用「金蛇万道」。\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("你现在内力太弱，不能使用「金蛇万道」。\n");

	msg = HIY "$N突然长啸一声，身随剑走，剑幻万道游蛇，诡异般袭向$n周身要害。\n" NOR;

	        
      if( random(me->query("combat_exp")*2) > (int)target->query("combat_exp")/2 )  
        {
    msg += HIY"\n$p被飘风骤雨般剑气笼罩难以躲避，金光一闪，金蛇剑刺入胸膛，" +
                "伤口刹时涌出鲜血。\n" NOR;
	damage = (int)me->query_skill("jinhse-jianfa", 1);
        damage = damage*2 + random(damage / 2);
	if (damage > target->query("neili") / 10)
	damage -= target->query("neili") / 15;
	target->receive_damage("qi", damage);
	target->receive_wound("qi", damage/2);
     if( damage < 300) msg += HIY"$n的胸前衣襟已经侵出了鲜血。\n"NOR;
       else if( damage < 500 ) msg += HIR"$n胸前现出了一个又长又深的伤口！\n"NOR;
      else msg += RED"竟然洞穿了$n的身体，$n手捂伤口，“哇”的一声吐出了一口鲜血。\n"NOR;
	message_vision(msg, me, target);
	} 
        else {
		msg += "可惜$n早已防备了$N的这招，向旁边一跃，躲开此招，但对剑势如此迅猛怪异也心下骇然。\n" NOR;
		message_vision(msg, me, target);
	}
	me->add("neili", -500);
	me->start_busy(3);
        target->start_busy(2);
	return 1;
}
