// guangming.c 光明

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count, i;
	int skill;
 
    if( !me->is_fighting() )
	    return notify_fail("「烈火焚躯」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你没有装备武器。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("你的九阳神功火候太浅。\n");

	if((int)me->query_skill("liehuo-jian",1) < 100)
		return notify_fail("你的剑法修为不够, 不能使用「烈火焚躯」！\n");
 
	if((int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	me->clean_up_enemy();
	ob = me->select_opponent();

	skill = me->query_skill("liehuo-jian", 1);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/strength", skill/3);
	weapon = me->query_temp("weapon");
   message_vision(HIW "$N大喝一声：「" + HIR "焚我残躯，熊熊圣火" + HIW"」，真气所至，顿时四周狂风大作，$n身子不觉一震。\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
   message_vision(HIC "$N口中长吟到：“"HIR"焚我残躯，熊熊圣火。生亦何欢，死亦何苦"HIC"？”\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
   message_vision(HIC "$N口中长吟到：“"HIR"为善除恶，唯光明故。喜乐悲愁，皆归尘土"HIC"。”\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
   message_vision(HIC "$N口中长吟到：“"HIR"怜我世人，忧患实多！怜我世人，忧患实多"HIC"！”\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill/3);
	me->add_temp("apply/strength", -skill/3);
	me->add("neili", -250);
	me->start_busy(2);
 	return 1;
}