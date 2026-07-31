#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
      int damage, damage2;
        string msg;
        object weapon;

if ( (string)me->query("family/family_name") != "云龙门") 
      return notify_fail("只有天地会成员才能使用该PFM。\n");


        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("耶，你的剑在哪里？？\n"NOR);
      if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「云龙三现」只能对战斗中的对手使用。\n");
      if ((int)me->query_skill("yunlong-jian", 1) < 60 )
        return notify_fail("你的回云龙剑不够娴熟，还使不出「云龙三现」。\n"NOR);
      if ((int)me->query_skill("yunlong-shengong", 1) < 60 )
        return notify_fail("你的云龙神功火候不够，「云龙三现」不成招式。\n"NOR);
      if ((int)me->query("max_neili")<400)
        return notify_fail("你的内力修为不足，无法运足「云龙三现」的内力。\n"NOR);
      if ((int)me->query("neili")<200)
        {
        return notify_fail("你现在内力不够，没能将「云龙三现」使完！\n"NOR);
        }
   msg = HIY"只见$N手中剑光幻作一条金龙,腾空而起,倏的罩向$n,\n$n只觉一股大力铺天盖地般压来,登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！\n"NOR;

   if (random(me->query_skill("force"))>target->query_skill("force")/2)
        {
                me->start_busy(2);
                target->start_busy(random(3));
damage = (int)me->query_skill("yunlong-jian", 1)*5+(int)me->query_skill("force",1)*2;
   damage = damage + random(damage);
if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);
if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);

damage2 = (int)me->query_skill("yunlong-jian", 1)*5+(int)me->query_skill("force",1)*2;
damage2 = damage2 + random(damage2);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);

      msg += HIC"$n还没来得及看清楚$N的剑路就被剑气卷住，狠狠的捱了一招「云龙三现」！！\n"NOR;
  me->add("neili", -damage/3);
        } else
        {
            me->start_busy(random(3));
      msg += HIC"$n心下大急，竟然连蹦带跳向后退去，这才躲过$N一手杀着！\n"NOR;

                me->add("neili", -200);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        if(userp(target)) target->fight_ob(me);
        else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}

