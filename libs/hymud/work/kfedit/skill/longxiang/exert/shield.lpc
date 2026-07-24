// shield.c 护体神功

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
	int i = (int)me->query_skill("longxiang", 1);
	int t = i/40;

        if( target != me ) 
                return notify_fail("你只能用龙象般若功来运护体神功。\n");

        if( (int)me->query("neili") < 100  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("longxiang") ) 
                return notify_fail("你已经在运功中了。\n");

        if( (int)me->query_temp("shielded") ) 
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你正在用别的功法。\n");

        if( (int)me->query_skill("longxiang", 1) < 20)
                return notify_fail("你的龙象般若功火侯不够！\n");

        skill = me->query_skill("longxiang");
        me->add("neili", -100);

	message_vision(
	HIR"$N口中默念大明六字真言，手结摩利支天愤怒印，运起"+t+"龙"+t+"象之力！\n" +
	HIW"$N脚下砂石下陷，遽然出现了一个大坑！\n"
	NOR, me);
        message_vision(
        MAG "$N长吸一口气，运起护体神功，身上衣衫缓缓涨起，一股真流遍流全身。\n" NOR, me);

        me->add_temp("apply/armor",  skill/2);
        me->add_temp("apply/defense",  skill/2);
        me->set_temp("shielded", 1);
        me->set_temp("longxiang", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/3);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        int skill;
        skill = me->query_skill("longxiang");
        me->add_temp("apply/armor",  -skill/2);
        me->add_temp("apply/defense",  -skill/2);
        me->delete_temp("shielded");
        me->delete_temp("longxiang");
        tell_object(me, "你的护体神功运行完毕，将内力收回丹田。\n");
}
