// lian.c 金面生莲

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

 
int perform(object me, object target)
{
	object weapon;
        string msg;
        int ap, dp;
        int damage;
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("「金面生莲」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "sword")
		return notify_fail("手中没有剑如何使用「金面生莲」！\n");

	if ((int)me->query("neili") < 250)
		return notify_fail("你的真气不够！\n");

	if ((int)me->query_skill("force") < 120)
		return notify_fail("你的内功火候不够！\n");

	if ((int)me->query_skill("miaojia-jian", 1) < 100)
		return notify_fail("你的苗家剑法还不到家，无法使用「金面生莲」！\n");

        if (me->query_skill_mapped("sword") != "miaojia-jian")
                return notify_fail("你没有激发苗家剑法，无法使用「金面生莲」！\n");

	msg = HIG "$N" HIG "手中的" + weapon->name() +
              HIG "一晃，突然化作万朵金莲，逼向$n" HIG "，眩人耳目！\n" NOR;

        ap = me->query_skill("sword",1);
        dp = target->query_skill("parry",1);
        
        if (ap / 2 + random(ap) > dp)
	{
		damage = me->query_skill("sword",1)*2;
		target->add("qi",-damage/2);
		target->add("eff_qi",-damage/2);
                me->add("neili", -150);
		msg +=                    HIR "$n" HIR "眼花缭乱，完全无法看清$N"
                                           HIR "的剑招，一个不慎，连披数剑，血溅五步！\n" NOR;
		me->start_busy(2);
	} else 
	{
		msg += HIC "可是$p" HIC "眼明手快，叮叮当当接连将$P"
                       HIC "的杀招接下，叹为观止！\n"NOR;
                me->add("neili", -100);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	return 1;
}
