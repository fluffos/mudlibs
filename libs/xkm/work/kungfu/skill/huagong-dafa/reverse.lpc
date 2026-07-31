//write by bright
// reverse.c 
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me,object target)
{
        int skill;   
        if (target != me)
                return notify_fail("你只能自己逆转化功护体！\n");

        if (!(me->query_temp("hua")))
                return notify_fail("你并未运转化功护体,怎么逆转啊。\n");


        if (me->query("max_neili")<2000
                || me->query("neili") < me->query("max_neili")/10)
                return notify_fail("你的内力不够逆运化功护体！\n");

        
        message_vision(HIB"$N暗运内劲把布在全身的内力收回丹田。\n"NOR, me);
        skill = me->query_skill("huagong-dafa", 1)+me->query_skill("poison", 1);
        me->delete_temp("hua");
        me->add_temp("apply/parry",  -skill/3);                       
        me->add_temp("apply/dodge",  -skill/3);

        me->add("neili", -100);

        return 1;
}
