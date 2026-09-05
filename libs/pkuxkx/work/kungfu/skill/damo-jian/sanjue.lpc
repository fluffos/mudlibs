//sanjue.c 达摩三绝剑

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    object weapon;
    mapping attack_val = ([
        "base" : ([ "weapon" : "sword", ]),//基本功夫类型
        "skill" : ([ "weapon" : "damo-jian", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「达摩三绝剑」只能对战斗中的对手使用。\n");

    if( (!objectp(weapon = me->query_temp("weapon")) 
         || (string)weapon->query("skill_type") != "sword") )
        return notify_fail("你必须使剑才能使「达摩三绝剑」。\n");

/*    if( me->query_skill_mapped("sword")!="damo-jian")
        return notify_fail("你必须使达摩剑才能施展「三绝剑」。\n"); */

    if( (int)me->query_dex() < 30)
    return notify_fail("你的身法不够，无法施展「达摩三绝剑」。\n"); 

    if( (int)me->query_skill("damo-jian", 1) + (int)me->query_skill("sword", 1)/2 < 135 )
    return notify_fail("你的剑法不够娴熟，不会使用「达摩三绝剑」。\n");

    if( (int)me->query_skill(me->query_skill_mapped("dodge"), 1) + (int)me->query_skill("dodge", 1)/2 < 135 )
    return notify_fail("你的轻功等级不够，无法使用「达摩三绝剑」。\n");

    if( (int)me->query_skill("hunyuan-yiqi", 1) < 60 )
    return notify_fail("你的混元一气功等级不够，不能使用「达摩三绝剑」。\n");

    if( (int)me->query("max_neili") < 300 || (int)me->query("neili") < 300 )
    return notify_fail("你的内力不足，无法使用「达摩三绝剑」。\n");

    me->add("neili", -300);
    me->start_busy(random(3) );

    msg = CYN "$N使出「达摩三绝剑」，闪电般攻向$n。\n" NOR;
    message_vision(msg, me, target);

    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);

    if( (int)target->query("qi") < 0 ) 
    return 1;

    if( objectp(me->query_temp("weapon")) ) 
    {
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
    }

    if( (int)target->query("qi") < 0 ) 
    return 1;

    if( objectp(me->query_temp("weapon")) ) 
    {
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL);
    }
    return 1;

}
