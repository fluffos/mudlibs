#include <ansi.h> 
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) return notify_fail("你只能用枯木神功提升自己的战斗力。\n");
    if( (int)me->query("neili") < 100)
        return notify_fail("你的内力不够!");
    if( (int)me->query_temp("kurong") ) return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("kumu-shengong",1);
    if (skill<60) return notify_fail("你的枯木神功还不够娴熟。\n");
    me->add("neili", -100);
    me->receive_damage("qi", 0);
    message_vision(
        BOLD "$N微一凝神，运起枯木神功，脸色忽然青黄变幻不定。\n" NOR, me);
    me->add_temp("apply/attack", skill*2/3);
    me->add_temp("apply/dodge", skill/3);
    me->set_temp("kurong", skill);
    me->add("bellicosity",skill);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/500);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}
void remove_effect(object me, int amount)
{
   if (!me) return;
   if ( (int)me->query_temp("kurong") ) {
    me->add_temp("apply/attack", - amount*2);
    me->add_temp("apply/dodge", - amount);
    me->delete_temp("kurong");
    tell_object(me, BOLD"你的枯木神功运行完毕，将内力收回丹田。\n"NOR);}
}
int clean_up()
{
    return 1;
}
void reset()
{
}

