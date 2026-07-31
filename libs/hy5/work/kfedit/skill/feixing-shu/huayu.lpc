// huayu.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int amount, i;
        string msg;
        object weapon, *ob;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("满天花雨只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
	     || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("feixing-shu", 1) < 150 )
                return notify_fail("你的飞星术不够娴熟，不会使用满天花雨。\n");
        if( (int)me->query_skill("huagong-dafa", 1) < 150 )
                return notify_fail("你的化功大法不够娴熟，不能使用满天花雨。\n");
	 if( (int)me->query_skill("throwing",1) <150 )
		  return notify_fail("你的暗器投掷不够娴熟，不能使用满天花雨。\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你内力不够了。\n");
weapon = me->query_temp("weapon");

        msg=HIR"只听一股劲风从$N的右侧发出，$N手中的"+weapon->name()+HIR"如烟雨般向$n笼罩过去！\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);

        me->start_busy(3);
	weapon->unequip();
        destruct(weapon);
        me->reset_action();
	me->add("neili",-300);
        return 1;
}

