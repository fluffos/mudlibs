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
    int damage;
    object weapon;
    object room;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("你想对谁使用这一招啊?\n");

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
/*    if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword") */
        return notify_fail("在右手没拿剑的情况下似乎很难使出这一招。\n");

    if (!objectp(weapon = target->query_temp("weapon")))
        return notify_fail("好像你的对手并没有使用兵器！\n");

    if ((int)me->query_skill("fuliu-jian",1) < 100 )
        return notify_fail("你的回风拂柳剑水平还没到家呢！\n");

    msg = HIY "$N嫣然一笑，手中长剑拂过$n身前，$n只觉眼前一阵眩晕。\n";
    me->start_busy(2);
    //C-
    if ( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target) )
    {
         msg +=HIR"结果，$n睁开眼睛时，发现手中兵器不翼而飞！\n"NOR;
         weapon->unequip();
         weapon->move(environment(me));
         if (!me->is_busy()) me->start_busy(1);
    } 
    else 
    {
        msg += "可是$p很快便回过神来，并没有上当。\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}

