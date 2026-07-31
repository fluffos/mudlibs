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
                return notify_fail("「大挪移」只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("qiankun-danuoyi", 1) < 50 )
                return notify_fail("你的乾坤大挪移不够娴熟，不会使用「大挪移」。\n");
        msg = CYN "$N使出乾坤大挪移「大挪移」，将$n的攻势反移了回去。\n";

        me->start_busy(1);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 )
	{
                msg += "结果$p的攻势被$P反移了回去。\n" NOR;
		
		damage = (int)me->query_skill("qiankun-danuoyi", 1);

                damage = damage + random(damage);

                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                me->add("force", -damage/10);

        } else {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
        }
        message_vision(msg, me, target);
	return 1;
}





