#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me)
{
        int skill;
        me=this_player();


        if( (int)me->query_skill("buddhism", 1) < 50 )
                return notify_fail("你的禅宗心法等级不够。\n");

        if( (int)me->query("neili") < 300 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("qi") < 300 )
                return notify_fail("你的气血不足。\n");
        if( (int)me->query("jing") < 300 )
                return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("anti_magic") ) 
                return notify_fail("你已经在运功中了。\n");
	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");
        skill = me->query_skill("buddhism");

        me->add("neili", -100);
if (me->query("qi") <= me->query("max_qi")*2)
        me->add("qi", 150+me->query_skill("buddhism",1)*3);
if (me->query("eff_qi") <= me->query("max_qi")*2)
        me->add("eff_qi", 150+me->query_skill("buddhism",1)*3);
if (me->query("jing") <= me->query("max_jing")*2)
        me->add("jing", 150+me->query_skill("buddhism",1)*3);
if (me->query("eff_jing") <= me->query("max_jing")*2)
        me->add("eff_jing", 150+me->query_skill("buddhism",1)*3);
        message_vision(
                HIC"$N微一凝神，背后幻出一朵白莲，五色毫光闪现。\n" NOR, me);

        me->set_temp("anti_magic", skill);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 8 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->delete_temp("anti_magic");
        tell_object(me, "你身后的白莲渐渐隐去了。\n");
        return;
}

