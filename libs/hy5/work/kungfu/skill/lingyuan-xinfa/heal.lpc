// heal.c
// Modified by Venus Oct.1997

#include <ansi.h>

int exert(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("战斗中运功疗伤？找死吗？\n");

    if ((int)me->query_skill("lingyuan-xinfa", 1) < 10)
   return notify_fail("你的灵元心法修为还不够。\n");
    if( (int)me->query("neili") < 50 )
   return notify_fail("你的真气不够。\n");

    if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 5 )
   return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

    write( HIY "你全身放松，坐下来运起灵元心法开始疗伤。\n" NOR);
    message("vision",
   HIY + me->name() + "坐下运功疗伤，头顶白雾缭绕，半响后吐出一口浊
气，气色已恢复正常。\n" NOR,
   environment(me), me);
    me->receive_curing("qi", 60 + (int)me->query_skill("force")/2 );
    me->receive_curing("jing", 40 + (int)me->query_skill("force")/2 );
    if( (int)me->query("qi") > (int)me->query("eff_qi") )
    me->set("qi", (int)me->query("eff_qi"));
    if( (int)me->query("jing")>(int)me->query("eff_jing") )
    me->set("jing", (int)me->query("eff_qi"));
    me->add("neili", -50);

    return 1;
}
