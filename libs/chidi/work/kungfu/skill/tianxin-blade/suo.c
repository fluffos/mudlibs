#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, weapon2, target;
    int skill, ap, dp, damage;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("blade-of-death",1); 
    if( !(me->is_fighting() ))
        return notify_fail("「死神锁」字决只能对战斗中的对手使用。\n");

    if (!objectp(weapon2 = target->query_temp("weapon")))
       return notify_fail("对方没有兵刃，你不用担心。\n");

    if (me->query_temp("perform"))
   message_vision(HIR"$N刀上散发出来的死起竟然化作一只似有似无的巨手，凌空抓向$n手中兵刃 一一「死神锁」\n");
 
    damage = 10 + random(skill / 2);
    ap = skill+me->query_skill("blade",1);
    dp = target->query_skill("unarmed",1);
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
        msg = "$n一惊，急忙向后退去，忽觉手中一轻";
        msg += weapon2->name();
        msg += "已脱手飞出。\n" NOR;
        target->receive_damage("qi", damage);
        target->start_busy(2);
        weapon2->move(environment(me));
        }
    else
    {
        if(userp(me))
            me->add("neili",-30);
        msg = "左躲右闪，连变数种身法，终於保住了兵器在手，不至空手死战。\n"NOR;
    }
      message_vision(msg, me, target);
    return 1;
}


