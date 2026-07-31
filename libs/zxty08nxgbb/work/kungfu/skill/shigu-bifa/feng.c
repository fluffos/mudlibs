#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
      
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正手忙脚乱，快快进攻吧。ⅵ\n");
        
    if( (int)me->query_skill("shigu-bifa", 1) < 80 )
        return notify_fail("你的石鼓打穴笔法不够娴熟，不会使用神笔封穴。\n");
     if(me->query_skill_mapped("sword") != "shigu-bifa")
             return notify_fail("你的石鼓笔法没激发在剑法上吧? \n");

        if( me->is_busy()) return notify_fail("你现在正忙着。\n");     
    msg = HIY "$N使出石鼓打穴笔法「神笔封穴」，专打$n的各处要穴。\n";
    time = (int)me->query_skill("shigu-bifa") / 30;
    if (time<3) time = 3;
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        msg += HIC " 结果$p被$P点中了穴道！\n" NOR;
                          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                          COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        target->start_busy(time);
    } else {
        if(time > 5) time = 5;
        me->start_busy(time/2);
        msg += "可是$p看破了$P的企图，敏捷的躲开了。\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}

