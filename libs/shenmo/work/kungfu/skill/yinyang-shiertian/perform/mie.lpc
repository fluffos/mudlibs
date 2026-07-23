// mie.c 五阴焚灭

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	string msg;
        int ap, dp;
 
	if (! target) target = offensive_target(me);

	if (! target || ! me->is_fighting(target))
	        return notify_fail("五阴焚灭只能在战斗中对对手使用。\n");

	if (me->query_skill("yinyang-shiertian", 1) < 150)
		return notify_fail("你的阴阳十二重天还不够娴熟，不能使用五阴焚灭！\n");

	if (me->query("neili") < 300)
		return notify_fail("你的真气不够！\n");

       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("你必须空手使用！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

        msg = HIC "$N" HIC "暴喝一声，变掌为爪，迅捷无比的袭向$n！\n";

        ap = me->query_skill("yinyang-shiertian");
        dp = target->query("combat_exp") / 10000;
	me->add("neili", -60);
	me->start_busy(4);

	me->want_kill(target);
        if (dp >= 100)
        {
                msg += HIC "$n" HIC "知道来招不善，小心应对，没出一点差错。\n" NOR;
        } else
        if (random(ap) > dp)
        {
                msg += HIR "这一招完全超出了$n" HIR "的想象，被$N"
                       HIR "结结实实的抓中了气海穴，浑身真气登时涣散！\n" NOR;
                message_vision(msg, me, target);
                                if (target->query("qi") > 35000)
{
target->add("qi",-30000);
target->add("eff_qi",-30000);
}else target->unconcious();
                return 1;
        } else
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
                msg += HIM "$n" HIM "大吃一惊，连忙胡乱抵挡，居"
                      "然没有一点伤害，侥幸得脱！\n" NOR;
        }

        message_vision(msg, me, target);

	return 1;
}
