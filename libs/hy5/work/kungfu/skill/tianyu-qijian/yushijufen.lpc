#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	if( !target ) target = offensive_target(me);

if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「玉石俱焚」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("tianyu-qijian", 1) < 180 )
		return notify_fail("你的天羽奇剑不够娴熟，不会使用。\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 40 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 40 ))
		return notify_fail("你的本门内功不够娴熟。\n");

       if(!( me->query("eff_qi")<100||(int)(me->query("max_qi")/me->query("eff_qi"))>=2.5))
             return notify_fail("你还没受重伤，不要使用玉石俱焚。\n");

	if(((int)me->query_skill("bahuang-gong", 1) < 100 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 100 ))
		return notify_fail("你的本门内功实在太差，没法用「玉石俱焚」。\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你现在内力太弱，不能使用「玉石俱焚」。\n");
			
	msg = RED "$N跃出数丈，神色凝重，一招[玉石俱焚]想跟$n同归于尽！\n"NOR;
	
if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "结果$p被$P攻了个措手不及，昏死过去！\n" NOR;
if (target->query("qi") > 50000)
{
target->add("qi",-35000);
target->add("eff_qi",-35000);
}else target->unconcious();
if (random(10) == 1)
                {
		msg += "$P自己也由于用力过度，昏死过去！\n" NOR;
                me->unconcious();
                }
	} else {
		msg += "可是$p还是躲过了$P的最后一击！！\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
//        me->unconcious();
	return 1;
}
