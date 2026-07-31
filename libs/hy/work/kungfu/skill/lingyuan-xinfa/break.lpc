// break -「以柔破钢」
// made by deaner
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int exert(object me, object target)
{
    string msg;
    object target_w;
    
    if( !target )
    return notify_fail("格式：exert break [目标]\n");
    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
   return notify_fail("你只能对战斗中的对手使用「以柔破钢」。\n");

    if( target->is_busy() )
   return notify_fail(target->name() + "目前正在发愣，是进攻的好时机!\n");
    if( (int)me->query_skill("lingyuan-xinfa", 1) < 50 )
    return notify_fail("你的灵元心法火候不够，还不会使用「以柔破钢」。\n");

    msg = HIC "$N沉肩滑步，自丹田中升起一股阴柔之气顺着血脉经络传至双手劳宫穴， 
接着这股阴柔之气就激射而出，喷向$n手中的兵刃！\n";
    me->start_busy(2);

    if (target->query_temp("weapon") ||
   target->query_temp("secondary_weapon")) {
target_w = target->query_temp("weapon");

    if( random(me->query("combat_exp")) >
   (int)target->query("combat_exp")/3 ) {
    msg += HIW"结果$p手中的"+target_w->query("name")+"与这股阴柔之气一碰竟被
震了个粉碎！\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target_w->set("name", "震碎的" + target_w->query("name"));
    target_w->set("value", target_w->query("value")/10);
    target_w->set("weapon_prop", 0);
    target->reset_action();
    target->start_busy( (int)me->query_skill("lingyuan-xinfa") / 20 );
    } else {
    msg += "可是$p急急拆招，躲了开去，$P的计谋没有得逞。\n" NOR;
    }
    message_combatd(msg, me, target);
    return 1;
    }
    return notify_fail(target->name() + "目前是空手，没什么可以震碎的。\n");
}
