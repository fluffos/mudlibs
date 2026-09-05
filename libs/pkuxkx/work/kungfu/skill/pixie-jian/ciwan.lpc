//tiao.c 打狗棒法挑字决 by advent 060729

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    object weapon, weapon2, wea;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「刺腕」只能对战斗中的对手使用。\n");

    if ( !objectp(wea = me->query_temp("weapon"))|| (string)wea->query("skill_type") != "sword" )
        return notify_fail("你没有拿剑，怎么刺腕啊？\n");

    if ( target->query_condition("cannt_eq") )
        return notify_fail("对方已经身中「刺腕」了！\n");

    if( (int)me->query_skill("pixie-jian",1) <150)
        return notify_fail("你的辟邪剑法还没学到家,无法「刺腕」！\n");

    msg = HIY"$N突然手中兵器一震，剑尖飞鹰扑兔般点向$n"+HIY"手腕要害。\n";
    message_vision(msg, me,target);

    //C-
    if( F_KUNGFU->hit_rate(me->query_dex(), (int)target->query_dex(), 9, me, target) )
    {
        msg = HIR"$n"HIY"只觉得手腕一麻，一阵无力地垂了下去，显然已经受伤！\n" NOR;
        //               target->kill_ob(me);
        if (objectp(weapon=target->query_temp("weapon")))
        {    
            weapon->move(environment(me));
        }

        if (objectp(weapon2 = target->query_temp("secondary_weapon")))
        {
            weapon2->move(environment(me));
        }

        me->start_busy(2);        
        //        message_vision(msg, me,target)
        target->apply_condition("cannt_eq",3+random((int)me->query_skill("pixie-jian",1)/100));
    }
    else 
    {
        me->start_busy(4);
        msg = CYN"$n"CYN"疾忙一侧手，恰恰避过了$N的出手一击！\n"NOR; 
    }

    message_vision(msg, me,target);
    me->add("neili",-50);
    return 1;
}

