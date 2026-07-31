// soul_sense.c 灵识神通
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;

int conjure(object me, object target)
{
    int skill;

    if( me->query_temp("apply/astral_vision") )
   return notify_fail("你已经施展过灵识了。\n");

    if( (int)me->query("jingli") < 30 )
   return notify_fail("你的精力不够。\n");

    skill = me->query_skill("magic");

    me->add("jingli", - 30);
    me->receive_damage("jing", 5);

    message_vision(
   HIC "$N微一凝神，施展「灵识」之术。\n" NOR, me);
    tell_room(environment(me),HIY+ me->query("name")+"双手合为剑指在眼前慢慢
拉开，双眼竟变为金黄色，仿佛能洞穿一切！\n"NOR);
    me->add_temp("apply/astral_vision", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill);
    if( me->is_fighting() ) me->start_busy(1);

    return 1;
}

void remove_effect(object me)
{
    me->add_temp("apply/astral_vision", -1);
    tell_object(me, HIC"你的灵识失效了。\n"NOR);
}

