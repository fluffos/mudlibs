// buddhism-force (protect)
#include <ansi.h>
void remove_effect(object me, int amount);
int exert(object me, object target)
{
    int skill;
    if( target != me ) 
        return notify_fail("金刚不坏神功护体真气只能对自己使用。\n");
    if( (int)me->query("neili") < 1000  ) 
        return notify_fail("你的内力不够。\n");
    if( (int)me->query_temp("protect") ) 
        return notify_fail("你已经在运功中了。\n");
    skill = me->query_skill("buddhism-force",1);
        if (skill<90) return notify_fail("你的金刚不坏神功还不够娴熟。\n");
    me->receive_damage("qi", 0);
    message_vision( HIW "$N微一凝神，运起金刚不坏护体神功，全身衣衫一震。\n" NOR, me);
    me->add_temp("apply/armor_vs_force",skill); 
    me->set_temp("protect", 1);
     me->set_temp("zjb_bubai", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);
    if( me->is_fighting() ) me->start_busy(1);
    return 1;
}
void remove_effect(object me, int amount)
{
    if (!me)    return;
    me->add_temp("apply/armor_vs_force", - amount);
    me->delete_temp("protect");
    me->delete_temp("zjb_bubai");
    tell_object(me, BOLD"你的金刚不坏护体神功运行完毕，将内力收回丹田。\n"NOR);
}
void reset() { }
int clean_up() { return 1; }
