//sandu.c -散毒
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
//        if( !me->query("leiting"))
//                return notify_fail("你的外功中没有这种功能。\n");
/*        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「散毒」只能对战斗中的对手使用。\n"); */
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能施展「散毒」！\n");
          if (me->query_skill_mapped("force") != "huagong-dafa"
|| me->query_skill("force",1)/2 + me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("你的内功等级不够，无法施展「散毒」。");
     if (me->query_skill("strike",1)/2 + me->query_skill("xingxiu-duzhang",1) <120 )
          return notify_fail("你的星宿毒掌等级不够，无法散毒\n");
      if (me->query("neili")<300||me->query("max_neili")<300)
                return notify_fail("你的内力不够，无法散毒。");
        msg = BLU "$N积聚全身剧毒奋力击向$n。";
 target->kill_ob(me);
        me->start_busy(2);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp"))
{
                msg += "结果$p被$P一击命中，$P的剧毒散至$p的全身！\n" NOR;
                message_vision(msg, me, target);
               target->start_busy(1);
               target->apply_condition("xx_poison",
              10+target->query_condition("xx_poison"));
          target->set("eff_jing",target->query("eff_jing")-target->query("max_jing")/2);
              target->set("jing",target->query("eff_jing"));
              target->set("eff_qi",target->query("eff_qi")-target->query("max_qi")/2);
                target->set("qi",target->query("eff_qi"));
                me->set("neili",(int)me->query("neili")-300);
        } else {
                msg += "可是$p还是躲过了$P的致命一击！！\n" NOR;
                message_vision(msg, me, target);
      me->set("neili",(int)me->query("neili")-300);
      }
        return 1;
}
