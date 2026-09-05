// hua.c 化骨绵掌

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    object weapon;
    string msg;

    if( environment(me)->query("no_fight") )
        return notify_fail("这里不能攻击别人! \n");

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() )
        return notify_fail("辣手化骨只能对对手使用。\n");

    if( (int)me->query_skill("shenlong-xinfa", 1) < 50 )
        return notify_fail("你的神龙心法不够娴熟，不能化骨。\n");

    if( (int)me->query_skill("huagu-mianzhang", 1) < 40 )
        return notify_fail("你的化骨绵掌不够娴熟，不能化骨。\n");

    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你的内力不够，不能化骨。\n");

    me->add("neili", -100);

    msg = MAG "$N掌出如风轻轻落在$n肩头上。\n"NOR;

    me->start_busy(1);
//命中率级别B-
    if( F_KUNGFU->hit_rate( (int)me->query_skill("strike", "huagu-mianzhang"), (int)target->query_skill("dodge"), 6, me, target) &&
        !target->query_temp("active_debuff/huagu-mianzhang.hua") )
    {
        msg += MAG "结果只听扑的一声，$p被$P一掌拍中！\n" NOR;
        msg += MAG "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。\n" NOR;
        target->add_temp("apply/attack", -(int)me->query_skill("strike", "huagu-mianzhang")/40);
        target->add_temp("apply/dodge", -(int)me->query_skill("strike", "huagu-mianzhang")/40);
        target->add_temp("apply/defense", -(int)me->query_skill("strike", "huagu-mianzhang")/40);
        target->set_temp("active_debuff/huagu-mianzhang.hua/name", "化骨");                      //buff名称
        target->set_temp("active_debuff/huagu-mianzhang.hua/effect1", "攻击命中-"+(me->query_skill("strike", "huagu-mianzhang")/40)+"级");     //效果描述1
        target->set_temp("active_debuff/huagu-mianzhang.hua/effect2", "轻功技能-"+(me->query_skill("strike", "huagu-mianzhang")/40)+"级");     //效果描述2
        target->set_temp("active_debuff/huagu-mianzhang.hua/effect3", "防御躲闪-"+(me->query_skill("strike", "huagu-mianzhang")/40)+"级");     //效果描述3
    }
    else
    {
        msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
        me->start_busy(3);
    }
    message_combatd(msg, me, target);
    if( !target->is_fighting(me) ) target->fight_ob(me);
    return 1;
}

