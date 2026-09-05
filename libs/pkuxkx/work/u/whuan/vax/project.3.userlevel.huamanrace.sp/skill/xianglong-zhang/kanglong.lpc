//leiting.c  「亢龙有悔」
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
   int damage;
   string msg;

   if( !target ) target = offensive_target(me);

/*
       if( !wizardp(me) )
               return notify_fail("你不是萧峰，不会使用「亢龙有悔」！\n");
*/

   if( !target || !target->is_character() || !me->is_fighting(target) )
  return notify_fail("「"HIC"亢龙有悔"NOR"」只能对战斗中的对手使用。\n");
  
	 // dewolf 大弟子判定
    if( me->query("id") != DADIZI_D->query_name("gaibang")  )
        return notify_fail("只有本派大弟子才有权使用亢龙有悔对敌！\n");
	 
   if( (int)me->query_skill("huntian-qigong", 1) < 180 )
  return notify_fail("你的混天气功火候不够，使不出「"HIC"亢龙有悔"NOR"」。\n");

   if( (int)me->query_skill("xianglong-zhang", 1) < 180 )
  return notify_fail("你的降龙十八掌不够熟练，不会使用「"HIC"亢龙有悔"NOR"」。\n");
   if( (int)me->query("neili") < 500 )
  return notify_fail("你的内力修为还不够高。\n");

    msg = MAG "
 $N默运混天气功，施展出降龙十八掌的绝招「"HIC"亢龙有悔"MAG"」，双掌在空中划了半个圆圈，缓缓的推向$n。
这招看似无力，却含着无穷的劲力，只见天空中电闪雷鸣，天昏地暗。\n"NOR;

me->add("neili", -500);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2) { 
      me->start_busy(3);
   target->start_busy(random(3));

   damage = (int)me->query_skill("xianglong-zhang", 1)*2+(int)me->query_skill("huntian-qigong",1);

   damage = damage + random(damage);
   msg += HIR"
$n伸手接下$N的这一招，不料这招中竟含者数重后劲，一遇阻力立刻发出。\n"NOR;
message_vision(msg, me, target);
target->receive_damage("qi", damage/2);

message_vision(HIW"\n$n感到一股无形的劲力扑面而来，逼的人喘不过气来！\n"NOR, me,target);
COMBAT_D->report_status(target);
target->receive_wound("qi", damage/4);

target->receive_damage("qi", damage/3);
target->receive_wound("qi",damage/6);
message_vision(HIC"\n第二道劲力随即压至，$n不由自主的向后连退三步方才挡住！\n"NOR, me,target);

COMBAT_D->report_status(target);
target->receive_damage("qi", damage/4);

target->receive_wound("qi",damage/8);
message_vision(HIM"\n$n全身气血翻腾，尚未恢复，第三股劲力如海潮般地扑来！\n"NOR, me,target);
COMBAT_D->report_status(target);
//me->start_perform(7,"「"HIC"亢龙有悔"NOR"」");
// ?? does upper line make any effect ?
    } else
     {
        me->start_busy(4+random(2));
        msg += HIC"可是$p看破了$P的企图，闪在了一边，但还是被掌风扫中了。\n"NOR;
         message_vision(msg, me, target);

     }
    return 1;
}
