// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
notify_fail("你只能提升自己的耐力。\n");

        if( (int)me->query("force") < 100 )     return 
	notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("douhan") ) return 
	notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("jingxing");
	if(skill < 10) return notify_fail("你的混沌功太差了！\n");
        me->add("force", -100);
        message_vision(
                HIR 
"$N深深地吸了几口气，暗念〔斗寒诀〕，整个人似乎又精神了很多．．．\n" NOR, me);
        me->add_temp("apply/durability", skill/10);
        me->set_temp("douhan", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/durability", - amount);
        me->delete_temp("douhan");
        tell_object(me, "你的〔斗寒诀〕运行完毕，将内力收回丹田。\n");
}
 
