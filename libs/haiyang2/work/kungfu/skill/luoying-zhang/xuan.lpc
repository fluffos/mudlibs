// xuan.c  落英神掌「玄」字诀
// modified by Venus Oct.1997
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("神掌袭敌只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("luoying-zhang", 1) < 30 )
        return notify_fail("你的落英神掌不够娴熟，不会使用「玄」字诀。\n");

    if( (int)me->query_skill("bibo-shengong", 1) < 30 )
        return notify_fail("你的内功心法不够高，不能用来袭击敌人。\n");
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在内力不足！\n");     


    msg = HIG "$N默运落英心法，使出落英神掌「玄」字诀，从半空中撒出一片掌影逼向$n。\n"NOR;

    if (random(me->query("combat_exp")) > target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3)+2);

        damage = (int)me->query_skill("bibo-shengong", 1); 
        damage = damage*3 + random(damage);

        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage);
        me->add("neili", -100);

        if ( damage < 40 ) msg += HIY"结果$N受到$n的内力反震，虽然击中$N，自己却闷哼一声向后退了两步。\n"NOR;
        else if( damage < 80 ) msg += RED"结果$N被$n以内力反震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
        else msg += HIR"$n茫然不知所措，结果被$N一掌击中前胸，$n眼前一黑，被击飞出两丈许！！！\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(target);
    } else
    {
        me->start_busy(1);
        msg += HIG"可是$p看破了$P的企图，早就闪在了一边。\n"NOR;
	message_combatd(msg, me, target);
    }
    return 1;
}

