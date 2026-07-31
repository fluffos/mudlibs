// huadu.c 化毒
// by pishou

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me)
{
    int skill, i;

        if(!me->is_fighting())
               return notify_fail("聚毒护身只能在战斗中使用。\n"); 
        if ((int)me->query_skill("huagong-dafa", 1) < 150)
               return notify_fail("你的化功大法功火候太浅。\n");

        if ((int)me->query_skill("poison", 1) < 150)
               return notify_fail("你体内的毒素不够聚毒所需。\n");

        if( (int)me->query("neili") < 1500  ) 
                return notify_fail("你的内力不足于聚毒护身。n");
        if( (int)me->query_temp("hgdf/judu") ) 
                return notify_fail("你已运功聚毒护身了。\n");
        if( objectp(me->query_temp("weapon")))
                return notify_fail("聚毒护身前必须空出双掌来才行！\n");

        skill = me->query_skill("huagong-dafa", 1)/2;
        me->add("neili",  -400);
        me->add("jingli", -100);

        message_vision(BLU"$N潜运内功，双手相搓，将体内毒质慢慢逼出，化为一团青气，将$N笼罩在其中！\n" NOR, me);
        i = me->query_skill("poison", 1)/2;
        me->add_temp("apply/armor", i);       
        me->set_temp("hgdf/judu", i);
        me->start_call_out((: call_other, this_object(), "remove_effect", me:), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me)
{
	int i;
	if(!me || !me->query_temp("hgdf/judu")) return;
	i = me->query_temp("hgdf/judu");
    	me->add_temp("apply/armor", -i);           
    	me->delete_temp("hgdf/judu");
}
