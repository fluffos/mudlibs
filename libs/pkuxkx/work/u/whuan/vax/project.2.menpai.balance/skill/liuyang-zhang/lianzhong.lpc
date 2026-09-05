// zhong.c 种生死符

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    object obj;
    string msg;
    int extra;
			 // dewolf 大弟子判定
    if( me->query("family/family_name")!="灵鹫宫" || !me->query("family/topone") )
        return notify_fail("只有本派大弟子才会种生死符呦！\n");
		
    extra = me->query_skill("liuyang-zhang",1);
    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() )
        return notify_fail("连种生死符只能种在对手身上。\n");
    if(((int)me->query_skill("bahuang-gong", 1) < 200 ) )
        return notify_fail("你的本门内功不够娴熟，不能连种生死符。\n");

    if( (int)me->query_skill("liuyang-zhang", 1) < 200 )
        return notify_fail("你的天山六阳掌不够娴熟，不能连种生死符。\n");

    if( (int)me->query_skill("throwing", 1) < 200 )
        return notify_fail("你的暗器功夫不够娴熟，不能种生死符。\n");

    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");

    if (me->query_skill_mapped("throwing") != "liuyang-zhang")
        return notify_fail("你现在的暗器功夫不是天山六阳掌,无法种生死符。\n");
    if (!objectp(obj=present("jiudai", me)))
        return notify_fail("你身上没有酒袋，不能化水为冰。\n");

    me->add_temp("apply/strength", extra/4);
    me->add_temp("apply/attack", extra);
    msg = BLU "$N化水为冰，凝于掌中，双指一弹，手上几道青光急速射向$n。\n";

    msg +=  HIW  "$N左指一弹，"HIG"第一道生死符"HIW"向$n左边打来！" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR, msg);

    msg = HIB  "$N右指一弹，"HIG"第二道生死符"HIB"向$n右边打来! " NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR, msg);
    msg = CYN  "$N凌空跃起,"HIG"第三道生死符"CYN"向$n上面打来!" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR, msg);

    me->add_temp("apply/strength", -extra/4);
    me->add_temp("apply/attack", -extra);

    me->add("neili", -200);
    if( random( (int)me->query_skill("liuyang-zhang")) > random(target->query_skill("dodge")/3 ) )
    {
        msg = HIG " 结果$p被$P攻了个正着！身上中了几道生死符\n" NOR;
        target->receive_damage("qi",(int)me->query_skill("bahuang-gong",1), me);
        target->receive_wound("qi",15 + random(50));
        target->receive_wound("jing", 10 + random(50));
        target->apply_condition("ss_poison", random(me->query_skill("liuyang-zhang",1)/10) + 2 +
                target->query_condition("ss_poison"));
        me->start_busy(2);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
    } else
    {
        msg = HIY"$N又是一道生死符打向$n，可是$p急忙闪在一旁，躲了开去。\n" NOR;
        me->start_busy(4);
        message_combatd(msg, me, target);
    }
    target->start_busy(1 + random(2));
    target->kill_ob(me);
    destruct(obj);
    return 1;
}
