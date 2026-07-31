#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);


    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「天旋地转」只能对战斗中的对手使用。\n");


    if( (int)me->query_skill("cxwx-quan", 1) < 500 )
          return notify_fail("你的痴心妄想拳不够熟练，不会使用「天旋地转」。\n");


 if ( (string)me->query("family/family_name") != "痴心妄想门") 
       return notify_fail("「天旋地转」只有痴心之人人才能使用。\n");


    if( (int)me->query("max_neili") < 50000 )
           return notify_fail("你的内力修为还不够高。\n");

    if( (int)me->query("neili") < 800 )
           return notify_fail("你的内力不够了。\n");

    if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     

    msg = HIM "
$N左手虚晃，右手击中全身力量使出「天旋地转」绝拳，一股"HIC"碎心劲"HIM"震向$n！！\n"NOR;

if( random(me->query_skill("cxwx-quan",1)+me->query_skill("unarmed",1)) > target->query_skill("unarmed",1)) { 
      me->start_busy(1);
   target->start_busy(random(2));

damage = (int)me->query_skill("cxwx-quan", 1)*5+(int)me->query_skill("force",1)*2;

   damage = damage + random(damage);
if (damage<target->query("max_qi",1)/8 && me->query("max_neili",1) > target->query("max_neili",1)/2) damage = random (target->query("max_qi",1)/6);

if (damage>target->query("max_qi",1)/3) damage = random (target->query("max_qi",1)/4);
   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/2);
  me->add("neili", -damage/3);
   msg += HIR"$n连忙后退，连换数种身法，可惜还是让这一拳重重击在胸前！！\n"NOR;
                message_vision(msg, me, target);
      COMBAT_D->report_status(target);    
        return 1;

 } else
    {
       me->start_busy(1);
           me->add("neili",-200);        
       msg += HIY"$n施展出「卸」字决，手一翻已将$N拳劲化去。\n"NOR;
    }
    message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

