// mie.c  火炎球

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        
        if (!target ||  me==target )
                return notify_fail("「火炎球」只能对战斗中的对手使用。\n");

        if ((int)me->query_condition("boss-ai"))
                return notify_fail(WHT"现在不能使用。\n"NOR);


        msg = RED "$N"RED"口中轻轻吟唱起了咒文.手中渐渐聚起了一团火球.火球渐大.\n"NOR;
        msg += RED"$N"RED"扬起了手,不知不觉中已对准了$n，$n看到漫天火光，抽身后跃，只这一刹，\n"NOR;
        msg += RED"$N"RED"大叫一声  火炎球!!  ,手中的火炎直向$n飞去，快捷无伦.！\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("boss-ai", 1)*10;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
        msg += HIR"$n"HIR"根本没法躲避，一个巨大火球,端端正\n"NOR;
        msg += HIR"正打在$n"HIR"的身上！$n"HIR"全身都烧了起来!!\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
		message_vision(msg, me, target);
        }
me->apply_condition("boss-ai",1);

        return 1;
}
