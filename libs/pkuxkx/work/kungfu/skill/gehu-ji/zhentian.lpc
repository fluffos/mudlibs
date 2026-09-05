// 雷霆震天
// bye jfeng
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    	string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
            return notify_fail("「雷霆震天」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || ((string)weapon->query("skill_type") != "axe"&&(string)weapon->query("skill_type") != "halberd"))
                        return notify_fail("你使用的武器不对。\n");
        if((int)me->query_str() < 40)
                return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
        if((int)me->query_skill("axe",1) < 120)
                return notify_fail("你的基本斧法的火候还不到家, 不能使用这一绝技 !\n");
		if((int)me->query_skill("halberd",1) < 120)
                return notify_fail("你的基本戟法的火候还不到家, 不能使用这一绝技 !\n");
        if((int)me->query_skill("gehu-ji",1) < 120)
                return notify_fail("你的格虎戟法的火候还不到家, 不能使用这一绝技 !\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力修为不够！\n");
        if( (int)me->query_temp("sum_power"))
                return notify_fail("你正在施展「雷霆震天」！\n");
    	msg = HIY "\n$N深深吸了口气，身形巍然卓立，暴喝一声使出格虎戟的绝技「雷霆震天」！\n" NOR;
        message_vision(msg, me);
	me->set_temp("sum_power", 1);
	remove_call_out("return_normal");
	call_out("return_normal", 10, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add("neili",-random(300)-150);
    	return 1;
}
void return_normal(object me)
{
	me->delete_temp("sum_power");
        message_vision("$N的震天神力渐渐平息了下来。\n", me);
}
