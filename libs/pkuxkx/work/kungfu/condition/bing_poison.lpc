inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	int damage;
    if (me->query_condition("bing_poison")>=(1+me->query_skill("poison",1)/20))
    {
        me->apply_condition("bing_poison", duration - 1 - me->query_skill("poison",1)/20);
    }
    else
    {
        me->delete_temp("death_cond_origin/bing_poison");
        return 0;
    }

    tell_object(me, HIB "突然你感觉四肢麻麻的似乎不大灵便！\n" NOR );
    tell_room(environment(me), HIB + me->name()+"突然全身一颤，两张手掌心已全成黑色，黑气更顺着手臂向上攀升！\n" NOR, ({ me }));     
    me->set_temp("death_cond_id", "bing_poison");
	if (userp(me)) damage=20;
	else damage=40;
	F_POISON->poison_eff(me,"bing_poison",(["qi":({1,25}),"jing":({1,damage}),]),1); 
    if(!me->is_busy()) me->start_busy(2);

    return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

int query_irregular_times()
{
	return 2;
}