// juemi.c 天地绝灭
 
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
		return notify_fail("天地绝灭只能对战斗中的对手使用。\n");
 
	if (me->query_skill("never-defeated", 1) < 120)
		return notify_fail("你的不败神功还不够娴熟，不能使用天地绝灭！\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须手持兵刃才能施展天地绝灭！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

        if (me->query("neili") < 200)
                return notify_fail("你的内力不够，不能使用天地绝灭！\n");
 
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "随便走了几步，忽然一荡手中的" + weapon->name() +
              HIC "，迅捷无比的扫向$n" HIC "，变化复杂之极，不可思议！\n" NOR;
 
	ap = me->query_skill("never-defeated", 1) * 3 / 2 + me->query("int") * 20 +
             me->query_skill("never-defeated", 1);
	dp = target->query_skill("dodge") + target->query("dex") * 20;

        me->start_busy(2);
        me->add("neili", -50);
        if (ap / 2 + random(ap) < dp)
        {
		msg += HIG "只见$n" HIG "并不慌张，只是轻轻一闪，就躲过了$N"
	               HIG "这一击！\n"NOR;
        } else
	{
		me->add("neili",-70);
                damage = ap + random(ap / 3);
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
                
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "连忙格挡，可是这一招实在是鬼神莫"
                                           "测，哪里琢磨得透？登时中了$P" HIR "的重创！\n" NOR;
	}

	message_vision(msg, me, target);
	return 1;
}
