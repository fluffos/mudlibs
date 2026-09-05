//handu.c -冰魄寒毒
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
         object weapon;
          if (me->query_skill_mapped("force") != "huagong-dafa"
|| me->query_skill("force",1)/2 + me->query_skill("huagong-dafa",1) < 150 )
                return notify_fail("你的内功还没到家，无法施展「冰魄寒毒」。");
     if (me->query_skill("staff",1)/2 + me->query_skill("tianshan-zhang",1) <150 )
          return notify_fail("你的天山杖法等级不够，无法施展「冰魄寒毒」。");
        if((string)weapon->query("id")!="bingpo zhang" )
          return notify_fail("你必须使用冰魄杖才能施展「冰魄寒毒」。");
      if (me->query("neili")<400||me->query("max_neili")<500)
          return notify_fail("你的内力不够，无法施展「冰魄寒毒」。");
        msg = CYN"$P突然诡秘一笑，手中" NOR + BLU"冰魄杖"NOR+CYN"向$p横扫而来。"NOR;
 target->kill_ob(me);
        me->start_busy(random(2));
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
{
                msg += CYN"$p突然打了个寒战，明显感到一股寒流已经侵入体内！\n" NOR;
                message_vision(msg, me, target);
               target->start_busy(me->query_skill("tianshan-zhang",1)/40);
               target->apply_condition("xx_poison",me->query_skill("huagong-dafa",1)/10+target->query_condition("xx_poison"));
          target->set("eff_qi",target->query("eff_qi")-me->query_skill("huagong-dafa",1)*2);
              target->set("qi",target->query("eff_qi")-me->query_skill("huagong-dafa,1")*3);
                me->set("neili",(int)me->query("neili")-400);
        } else {
                msg += CYN"$p下意识地跳到一旁，但还是被吓出了一身冷汗。\n" NOR;
                message_vision(msg, me, target);
      me->set("neili",(int)me->query("neili")-300);
      }
        return 1;
}
