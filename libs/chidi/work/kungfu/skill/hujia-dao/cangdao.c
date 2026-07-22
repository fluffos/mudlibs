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
        return notify_fail("八面藏刀只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "blade")
            return notify_fail("你使用的武器不对。\n");
      
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        
    if( (int)me->query_skill("hujia-dao", 1) < 100 )
        return notify_fail("你的胡家刀法不够娴熟，不会使用「八面藏刀」字诀。\n");
        if( me->is_busy()) return notify_fail("你现在正忙着。\n");     
    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
    msg = HIW "$N使出胡家刀法缠字决之「八面藏刀」，连递数个虚招企图扰乱$n的攻势。\n";
     time = (int)me->query_skill("hujia-dao") / 25;
    if (time<3) time = 3;
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5 ) {
        msg += HIB " $p始终逃不出$P的攻击范围，被$P攻的分不了身！\n" NOR;
        target->start_busy(time);
    } else {
        if(time > 5) time = 5;
        me->start_busy(time/2);
        msg += HIC"可是$p看破了$P的企图，并没有上当。\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}

