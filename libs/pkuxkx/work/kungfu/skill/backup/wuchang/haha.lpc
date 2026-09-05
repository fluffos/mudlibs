
#include <ansi.h>


inherit F_SSERVER;
int perform(object me, object target)
{if( !objectp(target) )
                return notify_fail("定谁？\n");
        message_vision(
    HIR "$N微笑不语，伸手按住了$n的命门！ \n\n"NOR,me, target);
target->set("qi",target->query("qi")/2);
        message_vision(
    HIR "$n发现自己的内力顺着$N指间狂泻,不禁大骇！, \n\n"NOR,me, target);
target->set("neili",-1000);








                target->start_busy(900);



        return 1;
}
int exert(object me, object target)
{if( !objectp(target) )
                return notify_fail("定谁？\n");
        message_vision(
    HIR "$N微笑不语，伸手按住了$n的命门！ \n\n"NOR,me, target);
target->set("qi",target->query("qi")/2);
        message_vision(
    HIR "$n发现自己的内力顺着$N指间狂泻,不禁大骇！, \n\n"NOR,me, target);
target->set("neili",-1000);








                target->start_busy(900);



        return 1;


        
}


