// wanli.c 晴空万里

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object  weapon;
	int     damage;
	string  msg;
        string  pmsg;
        string *limbs;
        string  limb;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("晴空万里只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("never-defeated", 1) < 120)
		return notify_fail("你的不败神功还不够娴熟，不能使用晴空万里。\n");
	                        
        if ((int)me->query("neili", 1) < 200)
		return notify_fail("你现在内力太弱，不能使用晴空万里。\n");
			
        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须手持兵刃才能施展晴空万里！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");


       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "怀抱" + weapon->name() + HIC "，一"
              "圈圈的划向$n" HIC "，将$p" HIC "卷在当中！\n" NOR;
	me->add("neili", -20);

        ap = me->query_skill("never-defeated", 1) * 3 / 2 +
             me->query_skill("unarmed", 1);
        dp = target->query_skill("parry") +
             target->query_skill("unarmed", 1);

        if (ap / 2 + random(ap * 2) > dp)
        {
		me->start_busy(2);
                me->add("neili", -180);

		target->start_busy(3);

		damage = ap + (int)me->query_skill("force");
                damage = damage + random(damage / 2);

if (me->query("zhuanfinal/1") ==1 && random(2)==0)
{
	if (userp(target))
	target->receive_wound("qi", target->query("qi")/8);
        if (!userp(target))
         target->receive_wound("qi", 500);
	msg +=RED"$N使用了斩仙决!!$n突然胸口一痛鲜血狂奔!\n"NOR;
}
else
if (me->query("zhuanfinal/2") ==1 && random(2)==0)
{
	if (userp(target))
	target->add("neili", -target->query("neili")/8);
        if (!userp(target))
         target->add("neili", -500);
	msg +=HIY"$N使用了破仙决!!$n突然内力消失!\n"NOR;
}
else
if (me->query("zhuanfinal/3") ==1 && random(2)==0)
{
	if (!target->is_busy())
	target->start_busy(4);
	msg +=HIY"$N使用了乱仙决!!$n突然手忙脚乱!\n"NOR;
}
                if (arrayp(limbs = target->query("limbs")))
                        limb = limbs[random(sizeof(limbs))];
                else
                        limb = "要害";
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n连忙腾挪躲闪，然而“扑哧”一声，" + weapon->name() +
		       HIR "正好击中$p" HIR "的" + limb + "，$p"
		       HIR "一声惨叫，连退数步。\n" NOR;
	} else 
	{
		me->start_busy(2);
		msg += CYN "可是$p" CYN "看破了$P"
                       CYN "的变化，见招拆招，没有受到任何伤害。\n"NOR;
	}

	message_vision(msg, me, target);

	return 1;
}
