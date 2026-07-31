// huanying.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
      int skill;
    if( !target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
      return notify_fail("你使用的武器不对。\n");

      if( !target || !me->is_fighting(target) )
      return notify_fail("「幻影」只能在战斗中对对手使用。\n");

    if ((int)me->query_skill("hujia-daofa", 1) < 100 )
        return notify_fail("你的胡家刀法等级不够，不能呼唤鬼魂！\n");    
    if ((int)me->query_skill("blade", 1) < 100 )
        return notify_fail("你的基本刀法极不够娴熟，不能呼唤出你的幻影！\n");    
    if ((int)me->query("neili") < 300 )
        return notify_fail("你现在真气太弱，不能呼唤幻影！\n");
    me->add("neili", -100);        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
    message_vision(HIY"$N前后游走，身形闪动，手中钢刀越使越快，幻起无数刀光化出数个身形。
$n被此胡家刀法之「无形幻影」所迷惑，手足无措，不知哪个$N是真，哪个是假。\n"NOR, me, target);
    target->start_busy(6);
    skill = me->query_skill("hujia-daofa", 1)/3;
    return 1;
        } else {
   message_vision(HIR"可是$n看破了$N的企图，镇定逾恒，全神应对自如。\n" NOR,me,target);
           me->start_busy(2);
    return 1;
        }

}

