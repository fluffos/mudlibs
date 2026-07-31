// ss.c 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int exert(object me, object target)
{
    string msg;
    object weapon,ob;
    if( !target ) target = offensive_target(me);
    if( !target ) return notify_fail("你想点谁的穴位？\n");
    if( !target->is_character() || target->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");
    if((int)me->query_str() < 30)
        return notify_fail("你臂力不够,不能使用牵制！\n");
    if((int)me->query_skill("iceforce",1) < 150)
        return notify_fail("你的寒意心法修为不够,目前还不能使用牵制！\n");
    if((int)me->query("neili") < 800)
        return notify_fail("你内力现在不够, 不能使用牵制！\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
    msg = HIW "$N盯着$n的双眼，施展开九阴密技，$n只觉得$N的盯着自己的眼神冰冷异常！\n"NOR;
    if( me->query_skill("iceforce",1) > me->query_skill("unarmed",1)/2 ) 
    {
        target->start_busy(5);
        me->add("neili", -150);
        if (objectp(weapon = target->query_temp("weapon"))) { weapon->move(target);}
        if (objectp(ob = target->query_temp("armor/cloth"))) { ob->move(target);}
        if ( me->query_skill("iceforce",1)>80) {
          target->apply_condition("cuixin_poison", me->query_skill("iceforce",1)/10 + 1 +
          target->query_condition("cuixin_poison")); 
       } 
    } 
    else 
    {
        
     msg += HIR"可是$n以静制动，紧守门户，丝毫不受$N的影响,$N自己倒累的满头大汗！\n"NOR;
        me->start_busy(2);
    }
    message_vision(msg, me, target);
    return 1;
}