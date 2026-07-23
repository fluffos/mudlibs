//by congw
// qu.c perform laincheng-jian
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{      object weapon;
       object obj;
       string msg;
	int extra;
	extra = me->query_skill("liancheng-jian",1) / 23;
	extra += me->query_skill("liancheng-jian",1) /23;

    if( !target ) target = offensive_target(me);
if( !target || !target->is_character() || !me->is_fighting(target) )
return notify_fail("去剑势只能只能对战斗中的对手使用。\n");
	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("你现在内力太弱。\n");

if(me->query_skill("liancheng-jian")<30)
return notify_fail("你的连城剑法不够娴熟，不能施用「去」字决。\n");
if (!objectp(weapon = target->query_temp("weapon")))
return notify_fail("对手并没有使用武器。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
me->add("neili",-100);
msg =  HIW"$N清啸一声，抖直手中的兵刃，以连城剑法的「去」字决顺势搭上了$n的兵器！\n"NOR;
if( !target->is_killing(me) ) me->kill_ob(target);
me->start_busy(2);
if( random( (int)me->query("combat_exp",1))
> target->query("combat_exp") /3 )  {
msg +=HIY"只听得一阵金铁交鸣之声，结果$p的兵刃被$P手中的兵器一连一带，远远地飞了开去！\n" NOR;
obj=target->query_temp("weapon");
obj->move(environment(me));
message_vision(msg, me, target);
msg = HIR  "$N一得手，马上接着几剑，闪电般的击向$n！" NOR;
msg = HIW  "上一剑！" NOR;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIG  "下一剑！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY  "左一剑！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC  "右一剑！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);
//destruct(obj);
} else {
msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
me->start_busy(2);
message_vision(msg, me, target);
}
return 1;
}
