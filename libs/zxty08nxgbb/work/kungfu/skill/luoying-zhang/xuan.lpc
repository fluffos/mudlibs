// xuan.c  落英神剑掌「玄」字诀
// by victori
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("神掌袭敌只能对战斗中的对手使用。\n");
    if( (int)me->query_skill("luoying-zhang", 1) < 200 )
        return notify_fail("你的落英神剑掌不够娴熟，不会使用「玄」字诀。\n");
    if( (int)me->query_skill("bibo-shengong", 1) < 150 )
        return notify_fail("你的碧波神功不够高，不能用来袭击敌人。\n");
    msg = HIG "$N默运碧波神功，使出落英神掌「玄」字诀，从半空中撒出一片掌影逼向$n。\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = (int)me->query_skill("bibo-shengong", 1);
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/3);
        me->add("neili", -damage/5);
        if ( damage < 40 ) msg += HIY"结果$N受到$n的内力反震，虽然击中$N，自己却闷哼一声向后退了两步。\n"NOR;
        else if( damage < 80 ) msg += RED"结果$N被$n以内力反震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
        else msg += HIR"$n茫然不知所措，结果被$N一掌击中前胸，$n眼前一黑，被击飞出两丈许！！！\n"NOR;
    } else
    {
        me->start_busy(1);
        msg += HIG"可是$p看破了$P的企图，早就闪在了一边。\n"NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
