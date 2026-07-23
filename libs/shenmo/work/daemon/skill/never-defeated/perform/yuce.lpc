// yuce.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, i;
        int n;
        int my_exp, ob_exp,damage;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail("御策诀只能在战斗中对对手使用。\n");


//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

        if ((skill = me->query_skill("never-defeated", 1)) < 100)
                return notify_fail("你的不败神功火候不够，不会施展御策诀。\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("你内力不够了。\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须手持兵刃才能施展！\n");
                
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        me->add("neili", -120);
        //weapon->add_amount(-1);

        msg = HIC "$N" HIC "手指一合一弹，只听呼啸破空声起，有若龙吟，一" +
             weapon->query("unit") + weapon->name() + HIC "如蛟龙般" +
             "打向$n" HIC "。\n" NOR;

        me->start_busy(3);
        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");
        if (random(my_exp) > ob_exp * 2 / 3)
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
                damage=target->query("qi")/2;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR + "只见那" + weapon->name() + HIR "去势恰如神光闪电！$n"
                       HIR + "不及闪避，被打了个正中，惨叫一"
                       "声，退了几步。\n" NOR;
               message_vision(msg, me, target);
        } else
        {

                msg += CYN "可是$p" CYN "急忙一闪，躲过了$P" HIG "发出的" +
                       weapon->name() + CYN "。\n" NOR;
                message_vision(msg, me, target);
        }

        me->reset_action();
        return 1;
}
