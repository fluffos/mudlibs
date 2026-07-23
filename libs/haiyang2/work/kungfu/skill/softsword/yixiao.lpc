// mie.c  回风拂柳剑法「灭剑」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(RED"开什么玩笑，没装备剑就想使「剑神一笑」？\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「剑神一笑」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("softsword", 1) < 100)
                return notify_fail(WHT"你的回风拂柳剑法不够娴熟，还使不出「剑神一笑」。\n"NOR);
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        if (me->is_busy())
		return notify_fail("你正忙着呢。\n");
        if ((int)me->query("neili")<200)
        {
               return notify_fail(HIC"你现在内力不够，没能将「灭剑」使完！\n"NOR);
        }
	msg = HIR  "$N手中"+ weapon->name() +"的剑芒散发出若有若无的浅笑．．．" NOR;
	msg +=  HIW "剑光一闪，消失．．．．\n" NOR;
                me->start_busy(2);
                if (!target->is_busy())
                target->start_busy(random(2));
                damage = (int)me->query_skill("softsword", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                target->receive_damage("jing", damage/6);
                target->receive_wound("jing", damage/6);
            	  target->add("neli",-100);
                me->add("neili", -100);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        return 1;
}

