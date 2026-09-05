//醉笑红尘
#include <ansi.h>
inherit F_SSERVER;
// by male/mudy

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
        string msg;
    int skill,limit;
    int damage;
    int coefficient;
if(me->query("zuiquanpf")!=3) return notify_fail("你不会这一招!\n");
            if( objectp(me->query_temp("weapon")) )
                 return notify_fail("使用醉笑红尘,必须空手!\n");
        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;

        if( !target ) target = offensive_target(me);
                        

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("醉笑红尘只能对战斗中的对手使用。\n");
       if( (int)me->query("max_neili")< 300 || (int)me->query("neili") < 300 )
                return notify_fail("你的内力不足，无法使用醉笑红尘。\n");

        if( !(int)me->query_condition("drunk"))
       {
            msg = HIC"\n$N故作醉态使出「醉笑红尘」,突然仰天一笑,双手突然变换手形,让$n感到变换莫测!\n\n"NOR;
              coefficient=1;
             }
     else
        {
            msg = HIC"\n$N拳借酒势,使出「醉笑红尘」,突然仰天一笑,双手突然变换手形,让$n感到变换莫测!\n\n"NOR;
              coefficient=2;
          }

        me->add("neili", - 300);
          skill=(int)me->query_skill("zui-quan", 1);
        message_vision(msg, me, target);
  if(F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 14-coefficient*5, me, target) )
  {
   message_vision(HIB"\n霎那间,$n已感到胸前已中了一下,只感觉到$N双手亦拳亦掌,十分怪异!\n\n"NOR,me,target);
     damage=skill*(100+me->query_condition("drunk")*50/ limit)/100;
   F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
   COMBAT_D->report_status(target);
 }
else
 {
    message_vision(MAG"\n$n一闪,躲开了$N的怪招!\n\n"NOR,me,target);
 me->start_busy(3);
 if (!target->is_busy()) target->start_busy(random(5));
return 1;
}
return 1;
}


