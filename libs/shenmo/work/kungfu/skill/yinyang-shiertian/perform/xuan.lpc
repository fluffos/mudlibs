// yong.c 玄黄连环掌

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int count;
        int lvl;
        int i;
 
        if (! target)
        {
	        me->clean_up_enemy();
	        target = me->select_opponent();
        }

	if (! target || ! me->is_fighting(target))
		return notify_fail("玄黄连环掌只能对战斗中的对手使用。\n");
 
	if (me->query("neili") < 200)
		return notify_fail("你的真气不够，无法施展玄黄连环掌！\n");

	if ((lvl = me->query_skill("yinyang-shiertian", 1)) < 150)
		return notify_fail("你的阴阳十二重天火候不够，无法施展玄黄连环掌！\n");

        if (me->query_skill_mapped("strike") != "yinyang-shiertian")
                return notify_fail("你没有激发阴阳十二重天为掌法，无法施展玄黄连环掌！\n");



       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("你必须空手使用！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");


	msg = HIC "$N" HIC "轻轻划了个圈子，身形忽然变快，合数招为一击攻向$n"
              HIC "！\n" NOR;
        i = 5;
        if (lvl / 2 + random(lvl) > (int)target->query_skill("force") * 2 / 3)
        {
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
                msg += HIY "内力激荡之下，$n" HIY "登时觉得呼吸"
                       "不畅，浑身有如重压，万分难受，只见$N"
                       HIY "一掌接一掌的攻到，有如海浪。\n" NOR;
                count = me->query_skill("yinyang-shiertian", 1) / 5;
                i += random(5);
        } else
        {
                msg += CYN "$n" CYN "见来掌奇快，只好振作精神勉力抵挡。\n" NOR;
                count = 0;
        }

	message_vision(msg, me, target);
	me->add("neili", -i * 20);
        me->add_temp("apply/attack", 80);
        while (i--)
        {
                if (! me->is_fighting(target))
                        break;
                if (i > 4 && ! target->is_busy())
                        target->start_busy(1);
        	COMBAT_D->do_attack(me, target, 0, 0);
        }

        me->add_temp("apply/attack", -80);
	me->start_busy(3);
	return 1;
}
