// ruying 七星聚会
// campsun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「七星聚会」只能在战斗中对对手使用。\n");

      if( objectp(me->query_temp("weapon")) )
      return notify_fail("你必须空手使用「金刚伏魔」！\n");
      
      if( (int)me->query_skill("jingang-quan",1) < 200 )
      return notify_fail("你的大金刚拳不够娴熟，不会使用「金刚伏魔」！\n");
      
      if( (int)me->query_skill("yijinjing",1) < 230 )
      return notify_fail("你的易筋经等级不够，不能使用「金刚伏魔」！\n");  
      
      if(me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("你没有运用易筋经内功，无法使用「金刚伏魔」进行攻击。\n"); 

if( (int)me->query_skill("buddhism", 1) < 180 )
                return notify_fail("你的禅宗心法等级不够，不能使用「七星聚会」。\n");
        
if( (int)me->query_str() < 28 )
                return notify_fail("你的臂力不够强，不能使用「七星聚会」。\n");

      

        if( (int)me->query("neili") < 1200 )
                return notify_fail("你现在内力太弱，不能使用「七星聚会」。\n");

        msg = HIR "$N双拳连环，瞬息间连出七拳，分击$n全身，正是大金刚拳绝技「七星聚会」。\n" NOR;

        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
              msg = HIR "$N一拳既出，身形一转，闪至$n左侧，双拳并举，同时打到。\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              
              msg= HIR "$N双拳势若暴风骤雨，连击$n肩、臂、胸、背各个部位，快得难以形容。\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);     

        me->add("neili", -400);

        me->start_busy(2+random(2));

        return 1;
}
