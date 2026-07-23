#include <ansi.h>
#include <combat.h>

#define KONG "「" HIG "空空如也" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
        int ap, dp;

	int extra;
	int i,a;
	object weapon;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
                return notify_fail(KONG "只能对战斗中的对手使用。\n");

		
        if ((int)me->query_skill("kongming-quan", 1) < 150)
		return notify_fail("你的空明拳不够娴熟，难以施展" KONG "。\n");

        if (me->query_skill_mapped("unarmed") != "kongming-quan")
                return notify_fail("你没有激发空明拳，难以施展" KONG "。\n");


        if ((int)me->query("neili", 1) < 150)
		return notify_fail("你现在的真气太弱，难以施展" KONG "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = WHT "$N" WHT "使出空明拳「" HIG "空空如也" NOR + WHT "」，拳劲"
              "虚虚实实，变化莫测，让$n" WHT "一时难以捕捉。\n" NOR;
	me->add("neili", -80);

        ap = me->query_skill("unarmed");
        dp = target->query_skill("parry");
	if (ap  + random(ap) > dp)
	{
		me->start_busy(2);
		
		damage = (int)me->query_skill("force", 1);
                damage = damage + random(damage );
		target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "无法窥测$N" HIR "拳中奥"
                                           "秘，被这一拳击中要害，登时呕出一大口"
                                           "鲜血！\n" NOR;
	} else 
	{
		me->start_busy(2);
		msg += CYN "可是$p" CYN "识破了$P"
                       CYN "的拳招中的变化，精心应对，并没有吃亏。\n" NOR;
	}
	message_combatd(msg, me, target);
	extra = me->query_skill("kongming-quan",1) / 20;
	extra += me->query_skill("xiantian-qigong",1) /20;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIG "空明拳 ! 虚虚实实，变化莫测！．．．．\n" NOR;
        message_vision(msg, me, target);
a=extra/3;
if (a> 8) a=8;
	for(i=0;i<a;i++)
	{
	msg = HIW "$N一拳打出,虚虚实实，变化莫测！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	i = extra/4;
	me->add("neili", - 50 * i);
	me->start_busy(3);
	return 1;
}
