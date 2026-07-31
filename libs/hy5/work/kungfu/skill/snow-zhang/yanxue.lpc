//yanxue.c  「烟雪春梅」
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「"+HIW"烟雪春梅"NOR+"」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("bingxue-xinfa", 1) < 100 )
   return notify_fail("你的冰雪心法火候不够，使不出「"+HIW"烟雪春梅"NOR+"」。\n");

    if( (int)me->query_skill("snow-zhang", 1) < 100 )
   return notify_fail("你的飞雪映梅掌不够熟练，不会使用「"+HIW"烟雪春梅"NOR+"」。\n");
     if( (int)me->query("neili") < 400 )
   return notify_fail("你的内力修为还不够高。\n");

    msg = HIW "
$N冰雪心法运转一周天，全身只觉一股寒气蒸腾欲出,清啸一声,\n"
"飞身而上,施展出「"+HIW"烟雪春梅」，双手一搓一放,一股凝人气血的\n"
"狂飙向$n铺天盖地席卷而去。\n"NOR;

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) { 
      me->start_busy(1+random(1));
   target->start_busy(random(1));

   damage = (int)me->query_skill("snow-zhang", 1)+(int)me->query_skill("bingxue-xinfa",1);

   damage = damage/2 + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
           target->apply_condition("ice_poison",50);
        target->apply_condition("xuantian_han",50);
        target->apply_condition("xuanming_poison",50);

   me->add("neili", -300);
   msg += HIC"
$n只见漫天青气席卷而来,躲无可躲,卒一接触,便被震的七窍流血,如断线风筝向后飘去。\n"NOR;
    } else
    {
       me->start_busy(2+random(1));
       msg += HIC"可是$p看破了$P的企图，轻轻地闪在了一边。\n"NOR;
    }
    message_combatd(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}


