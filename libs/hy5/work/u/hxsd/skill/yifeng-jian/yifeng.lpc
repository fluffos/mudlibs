// yifeng.c  移风剑 [移风起栖云飞扬]

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
    string msg, string1;
    int count;
 
    if( !me->is_fighting() )
	    return notify_fail("「移风起栖云飞扬」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if((int)me->query_dex() < 30)
		return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");

//	if((int)me->query_skill("dodge") < 235)
//		return notify_fail("你的轻功修为不够, 不能使用移风起栖云飞扬！\n");
 
	if( (int)me->query_skill("yifeng-jian", 1) < 150 )
		return notify_fail("你的移风剑法不够娴熟。\n");

	if((int)me->query_skill("sword") < 235)
		return notify_fail("你的剑法修为不够， 目前不能使用移风起栖云飞扬! \n");

    if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够！\n");


    msg = HIM "$N使出移风剑法的绝技「移风起栖云飞扬」，顿时花瓣飞舞！\n" NOR;
    message_vision(msg, me);

//	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili", -550);
	me->start_busy(random(4));

    return 1;
}