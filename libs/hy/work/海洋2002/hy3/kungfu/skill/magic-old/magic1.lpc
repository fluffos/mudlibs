// mie.c  火炎球

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「火炎球」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("magic-old", 1) < 50)
                return notify_fail(WHT"你的古代魔法不够娴熟，还使不出「火炎球」。\n"NOR);
        if ((int)me->query("neili")<50)
        {
               return notify_fail(HIC"你现在内力(法力)不够，没能将「火炎球」使完！\n"NOR);
        }
        msg = RED "$N"RED"口中轻轻吟唱起了咒文.手中渐渐聚起了一团火球.火球渐大.\n"NOR;
        msg += RED"$N"RED"扬起了手,不知不觉中已对准了$n，$n看到漫天火光，抽身后跃，只这一刹，\n"NOR;
        msg += RED"$N"RED"大叫一声  火炎球!!  ,手中的火炎直向$n飞去，快捷无伦.！\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/3|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
//                me->start_busy(1);
                target->start_busy(random(3));
                damage = (int)me->query_skill("magic-old", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/5);
                target->receive_wound("qi", damage);
            	  target->add("neli",-100);
        msg += HIR"$n"HIR"根本没法躲避，一个巨大火球,端端正\n"NOR;
        msg += HIR"正打在$n"HIR"的身上！$n"HIR"全身都烧了起来!!\n"NOR;
                me->add("neili", -10);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
                me->start_busy(1);
        msg += HIY"可是$p"HIY"轻轻一笑，侧身右转.\n"NOR;
        msg += HIY"火球在$p"HIY"身侧划过，毫发无伤。\n"NOR;
                me->add("neili", -50);
		message_combatd(msg, me, target);
        }
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
