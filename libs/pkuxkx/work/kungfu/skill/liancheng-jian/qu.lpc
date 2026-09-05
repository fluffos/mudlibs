//by congw
// qu.c perform laincheng-jian
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{      object weapon;
       object obj;
       string msg;
    if( !target ) target = offensive_target(me);
if( !target || !target->is_character() )
return notify_fail("去剑势只能对对手使用。\n");

if(me->query_skill("liancheng-jian")<30)
return notify_fail("你的连城剑法不够娴熟，不能施用「去」字决。\n");
if (!objectp(weapon = target->query_temp("weapon")))
return notify_fail("对手并没有使用武器。\n");

msg =  "$N清啸一声，抖直手中的兵刃，以连城剑法的「去」字决顺势搭上了$n的兵器！\n";
me->start_busy(1);
if( random( (int)me->query("combat_exp",1))
> random(target->query("combat_exp") /3 ) ) {
msg +=HIY"只听得一阵金铁交鸣之声，结果$p的兵刃被$P手中的兵器一连一带，远远地飞了开去！\n" NOR;
obj=target->query_temp("weapon");
obj->move(environment(me));
//destruct(obj);
target->start_busy(1 + random(2));
} else {
msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
me->start_busy(2);
}
message_vision(msg, me, target);
return 1;
}
