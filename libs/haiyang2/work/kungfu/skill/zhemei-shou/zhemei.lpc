// zhemei.c
// /kungfu/skill/zhemei-shou/
// Program by ying

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() )
                return notify_fail("折梅展只能对对手使用。\n");
       if( environment(me)->query("no_fight") )
                       return notify_fail("这里不能攻击别人! \n");
        if( (int)me->query_skill("zhemei-shou", 1) < 80 )
                return notify_fail("你的折梅手不够娴熟，不会使用折梅展。\n");
	if( !(me->is_fighting() ))
		return notify_fail("折梅手只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 120 && (int)me->query_skill("bahuang-gong", 1)<120 )
                return notify_fail("你的本派内功不够娴熟，不会使用折梅展。\n");

        if( (int)me->query("neili", 1) < 350 || (int)me->query("max_neili",1)<200 )
                return notify_fail("你现在内力太弱，不能使用折梅展。\n");

        msg = HIC "$N手法突然加快，迅速扑向$n，抓住$n一只手臂，用力弯折。\n"NOR;

        if( !target->is_fighting(me) ) me->kill_ob(target);

        if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
        {
                me->start_busy(3);

                damage = (int)me->query_skill("zhemei-shou", 1) + (int)me->query_skill("force",1);

                damage = damage/2 + random(damage/2 + 30) ;

                target->receive_damage("qi", damage );
		target->receive_damage("qi", damage );
                target->start_busy(6);
                me->add("neili", -200);

                msg += HIR"结果$n的手臂被$N弯折得无法动弹，只觉一阵疼痛难忍。\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
                me->start_busy(2);
                msg += CYN"可是$p用力一震，震了开去。\n"NOR;
		message_combatd(msg, me, target);
		target->start_busy(1);
        }

        return 1;
}
