// bo.c 阴阳十二重天

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
        int ap, dp;

	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
		return notify_fail("阴阳十二重天只能对战斗中的对手使用。\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("你必须空手使用！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");
           
	if (target->is_busy())
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
		
	if ((int)me->query_skill("yinyang-shiertian", 1) < 100)
		return notify_fail("你的阴阳十二重天不够深厚，不会使用。\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "掌力忽左忽右，形成一个个气旋，如波浪一般接连向$n"
              HIC "逼去！\n" NOR;

        ap = me->query_skill("yinyang-shiertian", 1) * 3 / 2 +
             me->query_skill("unarmed", 1);
        dp = target->query_skill("parry") +
             target->query_skill("unarmed", 1);

	if (ap / 2 + random(ap) > dp)
        {
if (me->query("zhuanfinal/4") ==1 && random(2)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$N使用了妙仙决!!$N全身的伤好了很多!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(2)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$N使用了动仙决!!$N突然动作又快了!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(2)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$N使用了银仙决!!$N突然内力恢复了!\n"NOR;
}
		msg += HIR "结果$p" HIR "被$P" HIR "逼得施展不开半点招式！\n" NOR;
		target->start_busy(ap / 50 + 3);
	} else
        {
		msg += CYN "可是$p" CYN "看破了$P" CYN "的掌势来路，"
                       "镇定自若，应对自如。\n" NOR;
		me->start_busy(1);
	}
	message_vision(msg, me, target);

	return 1;
}
