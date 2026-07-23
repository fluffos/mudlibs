#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int lvl;
        lvl = me->query_skill("xuanyin-jian", 1);
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用玄阴诀。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if( (int)me->query_skill("xuanyin-jian", 1) < 120 )
                return notify_fail("你的玄阴剑法不够娴熟，无法施展出玄阴诀。\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
                return notify_fail("你的九阴真功火候不够，无法施展出玄阴诀。\n");
        if ((int)me->query_skill("jiuyin-shenfa", 1) < 120)
                return notify_fail("你的九阴身法火候不够，无法施展出玄阴诀。\n");
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够，无法施展出玄阴诀。\n");
        if ( (int)me->query("neili") < 800)
                return notify_fail("你的真气不够，无法施展出玄阴诀。\n");
        message_vision(HIB"$N使出九阴「玄阴诀」，迅捷无比的攻向$n！\n"NOR,me, target);

        me->add("neili", -(300 +random(300)) );
        me->start_perform(2,"「玄阴诀」");

        message_vision(HIB"$N连出数剑，一剑比一剑凌利！\n"NOR,me);
	if (random(lvl) > target->query_skill("parry", 1) / 3) {
		message_vision(HIB"$N连连後退，防守尚有困难，更别说攻击了。\n"NOR,target);
	        target->start_busy(lvl / 50);
	        me->start_perform(7, "「玄阴诀」");
		me->add("neili", -300);
	}
        me->add_temp("apply/attack",lvl/2);
        me->add_temp("apply/dexerity",lvl/3);
        me->add_temp("apply/damage",lvl/2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	if (userp(target))
        me->start_busy(3);
        else me->start_busy(random(3) + 2);
        me->add_temp("apply/attack", -lvl/2);
        me->add_temp("apply/dexerity",-lvl/3);
        me->add_temp("apply/damage", -lvl/2);
        return 1;
}
