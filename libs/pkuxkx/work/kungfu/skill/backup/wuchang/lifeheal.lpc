#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
       target->set("jing",target->query("max_jing"));

      
        target->set("qi",target->query("max_qi"));
        target->set("eff_jing",target->query("max_jing"));
        target->set("eff_qi",target->query("max_qi"));
        target->add("neili", 100);
        message_vision(
                HIR "$N将手掌贴到$n的胸口，将内力输入$n体内....\n\n"NOR,me, target );
       tell_object(target, HIR "你觉得冥冥中好像有人帮你渡过难关，丹田之气渐渐充盈！\n" NOR);
      
        return 1;
}
int exert(object me, object target)
{
       target->set("jing",target->query("max_jing"));

      
        target->set("qi",target->query("max_qi"));
        target->set("eff_jing",target->query("max_jing"));
        target->set("eff_qi",target->query("max_qi"));
        target->add("neili", 500);
        message_vision(
                HIR "$N将手掌贴到$n的胸口，将内力输入$n体内....\n\n"NOR,me, target );
       tell_object(target, HIR "你觉得冥冥中好像有人帮你渡过难关，丹田之气渐渐充盈！\n" NOR);
      
        return 1;
}
