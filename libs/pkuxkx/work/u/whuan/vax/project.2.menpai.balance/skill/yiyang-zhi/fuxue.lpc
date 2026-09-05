//fuxue.c

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
	int busytime;

    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

    if( me->query_skill("finger") < 100 )
        return notify_fail("一阳指拂穴需要有效指法 100 级。\n");
    if( me->query("neili") < 100 )
        return notify_fail("一阳指拂穴需要内力 100 以上。\n");

    msg = CYN "$N使出一阳指拂穴绝技，右手食指突然点向$n要穴。\n";
    me->add("neili", -100);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
    {
        //设置 last_damage_from
        target->set_temp("last_damage_from", me);
        msg += "结果$p被$P一击点中。\n" NOR;
		busytime = 2+ ceil(pow((int)me->query_skill("yiyang-zhi"),0.5));
        target->start_busy(busytime);
    }
    else
    {
        me->start_busy(2+random(4));
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
    }
    message_vision(msg, me, target);
    // 最后再叫杀，使得信息显示更合理
    if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    if( !me->is_fight(target) ) me->fight_ob(target);

    return 1;
}
