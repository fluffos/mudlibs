// jiao.c 巫月刀法「铰」字诀
// jacki于1997.7.25

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    object my_w,target_w;

    if( !target ) target = offensive_target(me);
    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
   return notify_fail("你只能对战斗中的对手使用「铰字诀」。\n");

    if( target->is_busy() )
   return notify_fail(target->name() + "目前正疲于招架，加紧攻击吧ⅵ\n");

    if( (int)me->query_skill("wuyue-blade", 1) < 50 )
   return notify_fail("你的巫月刀法不够娴熟，不能使用「铰」字诀。\n");
	
    msg = CYN "$N大喝一声，展开巫月刀法「铰」字诀，连递数个急招企图铰碎$n的兵刃。\n";
    me->start_busy(2);

    if (target->query_temp("weapon") ||
   target->query_temp("secondary_weapon")) {
	my_w = me->query_temp("weapon");
    target_w = target->query_temp("weapon");

    if( random(me->query("combat_exp")) >
   (int)target->query("combat_exp")/2 ) {
    if( target_w->weight() > 2 * random(my_w->weight()) ) {
   msg += "结果$p手中的$w被$P强力一铰，再也把握不住，立即脱手飞出！\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target->reset_action();
   me->start_busy(2);
}
   msg += "结果$p手中的兵刃被$P的强力一击铰了个粉碎！\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target_w->set("name", target_w->query("name") + "的碎片");
    target_w->set("value", 0);
    target_w->set("weapon_prop", 0);
    target->reset_action();
   me->start_busy(2);
    } else {
   msg += "可是$p通过巧妙的招架，并没有让$P的计谋得逞。\n" NOR;
   me->start_busy(2);
	 }
    message_combatd(msg, me, target);
    return 1;
    }
    return notify_fail(target->name() + "目前是空手，你想铰什么？\n");
}

