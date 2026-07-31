// feiying.c 葵花飞影术

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( !target ) target = me;
        if(!me->is_fighting())
                return notify_fail("葵花飞影术只能在战斗中使用。\n");

        
        if( (int)me->query("neili") < 500  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("jing") < 200  ) 
                return notify_fail("你的精力不够。\n");
        if( (int)me->query_temp("feiying") ) 
                return notify_fail("你已经在运用葵花飞影术了。\n");
        if( (int)me->query_skill("pixie-jian", 1) < 120 )
                return notify_fail("你的辟邪剑法还没练成，无法使用葵花飞影术。\n");
        if( (int)me->query_dex() < 30  )
                return notify_fail("你的身法太低，不能使用葵花飞影术。\n");
       
	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("你的葵花飞影术不够娴熟。\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("你的葵花心法不够娴熟。\n");

        skill = me->query_skill("kuihua-feiying") / 3;
        skill = skill + me->query_skill("pixie-jian");
        skill = skill / 4;
        me->add("neili", -200);
//        me->add("jing", -150);
        me->receive_damage("qi", 50);

        message_vision(
        MAG "只见$N眼中青光一闪，凭空飞升离地尺余，身形飘浮不定，就如影子一般。\n" NOR, me);
        tell_object(me, MAG "你默运葵花飞影术，内劲外泄，将身体凭空抬了起来。\n" NOR);

        me->add_temp("apply/dodge", skill);
        me->set_temp("feiying", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feiying");
        tell_object(me, MAG "你一遍葵花飞影术已经使完，身法又恢复正常。\n" NOR);
}

