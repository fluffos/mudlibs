// chan.c 

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
    int busytime;
    object weapon;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || ( string)weapon->query("skill_type") != "whip" )
/*        if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "whip") */
        return notify_fail("你必须右手用鞭子才能施展鞭法绝技。\n");

    if( target->is_busy() ) return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

    if( (int)me->query("neili") < 400  ) return notify_fail("你的内力不够。\n");

    busytime=(int)me->query_skill("shenlong-bian")/20 + (int)me->query_skill("shenlong-xinfa")/20;
    if (!userp(me) && busytime>20) busytime=20;

    msg = CYN "$N使出神龙鞭法「缠绕」诀，连挥数鞭企图把$n的全身缠绕起来。\n";

    me->start_busy(2);
//命中率级别C+
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 7, me, target) ) 
    {
        msg += "结果$p被$P攻了个措手不及！\n" NOR;
        F_KUNGFU->hit_busy( "body", busytime, target ); 
    } 
    else
    {
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR; 
        me->start_busy(1+random(3));        
    }
    me->add("neili", -100);
    message_vision(msg, me, target);

    return 1;
}

