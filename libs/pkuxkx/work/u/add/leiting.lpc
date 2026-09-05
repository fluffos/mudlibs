//leiting.c -雷霆降龙

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
    string msg;

    if( !target ) target = offensive_target(me);

    if( !me->query("leiting"))
        return notify_fail("你的外功中没有这种功能。\n");

    if( !target ||      !target->is_character() ||      !me->is_fighting(target) )
        return notify_fail("「雷霆降龙」只能对战斗中的对手使用。\n");

    if (me->query_skill("force",1)/2 + me->query_skill("huntian-qigong",1) < 135 )
        return notify_fail("你的内功等级不够，无法施展「雷霆降龙」。");

    if (me->query_skill("strike",1)/2 + me->query_skill("xianglong-zhang", 1) < 135 )
        return notify_fail("你的降龙十八掌等级不够，施展不出「雷霆降。\n");

    if (me->query("neili")<200||me->query("max_neili")<200)
        return notify_fail("你的内力不够，无法施展「雷霆降龙」。");
    if ( target->query("luding_monster"))
    return notify_fail(HIC"对方不吃这一招，看来要另想办法！\n"NOR);
    msg = HIC+"$N默运混天气功，施展出「" + HIW + "雷" + HIC + "霆" + HIR + "降龙」" 
        + HIC + "，全身急速转动起来，越来越快，就犹如一股旋风\n骤然间，已卷向正看得发呆的$n。\n"+NOR;
    me->start_busy(3);
//     if( random(200000+me->query("combat_exp")) > (int)target->query("combat_exp")) {
   if( random(me->query("combat_exp") * 0.65) > random((int)target->query("combat_exp"))) {
        msg += HIR + "$n只见一阵旋风影中陡然现出$N的双拳，根本来不及躲避，\n" + 
            "被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n" NOR;
        message_vision(msg, me, target);
        target->set_temp("last_damage_from", me);
        target->unconcious();
    } else {
        msg += HIG"可是$p还是躲过了$P的最后一击！！\n" NOR;
        message_vision(msg, me, target);
        me->set("neili",(me->query("neili")-200));
    }
    return 1;
}
