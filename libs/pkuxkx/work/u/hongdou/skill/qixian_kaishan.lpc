//kaishan 七弦无形剑 － 六丁开山
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	int damage,jifa,jiben;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「六丁开山」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("id") != "gu qin")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("id") != "gu qin")
	        return notify_fail("你没拿琴，弹什么？\n");

        if( (int)me->query_skill("qixian-jian", 1) < 100 )
                return notify_fail("你的七弦无形剑不够娴熟，不会使用「六丁开山」。\n");
       if((int)me->query("neili") < 50)
              return notify_fail("你的内力不够呀!\n");
        msg = HIR "突然之间，$N在琴上连弹数声，乐音转急，琴音铮铮大响。\n";
	jifa = (int)target->query_skill("force");
	jiben = (int)target->query_skill("force",1);
        me->start_busy(1);
        if(jifa != (jiben/2)) 
	{
                msg += "琴音连响五下，$p不由自主的退了五步。接着又是一声大响，$p脸色雪白，显然是支持不住了。\n" NOR;
		
		damage = (int)target->query("max_qi");

                damage = damage/3;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -damage/10);

        } else {
 		me->start_busy(3);
                msg += "可是$p如同没事人一般，一点反应也没有，丝毫不起感应。\n" NOR;
        }
        message_vision(msg, me, target);
	return 1;
}





