//leiting.c  「雷霆一击」
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「雷霆一击」只能对战斗中的对手使用。\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("你必须空手使用「雷霆一击」！\n");

    if( (int)me->query_skill("huntian-qigong", 1) < 100 )
   return notify_fail("你的混天气功火候不够，使不出「雷霆一击」。\n");

    if( (int)me->query_skill("xianglong-zhang", 1) < 120 )
   return notify_fail("你的降龙十八掌不够熟练，不会使用「雷霆一击」。\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

    if( (int)me->query("neili") < 500 )
   return notify_fail("你的内力修为还不够高。\n");

    msg = HIB "
$N默运混天气功，施展出「雷霆一击」，全身急速转动起来，越来越快，就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) { 
      me->start_busy(3);

   damage = (int)me->query_skill("xianglong-zhang", 1)*3+(int)me->query_skill("huntian-qigong",1);

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/3);
   me->add("neili", -500);
   msg += "
$n只见一阵旋风影中陡然现出$N的双掌，根本来不及躲避，被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n"NOR;
message_combatd(msg, me, target);
COMBAT_D->report_status(target);

    } else
    {
      me->start_busy(3);
      me->add("neili", -300);
       msg += "可是$n看破了$N的企图，忽然向$N攻击。\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(me);
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

