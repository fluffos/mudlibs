inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 ) 
    {
        me->delete_temp("death_cond_origin/nx_zhua");
        return 0;
    }
    me->set_temp("death_cond_id", "nx_zhua");
	F_POISON->poison_eff(me,"nx_zhua",(["qi":({1,20+random(10)}),"jing":({1,20+random(10)}),]),1); 
    if (!me->is_busy()) me->start_busy(2+random(2));
    me->apply_condition("nx_zhua", duration - 1);
    if( (int)me->query("qi") < (int)me->query("max_qi")/4 ) message_vision("$N吐出一口淤血，看样子爪伤发作得很厉害。\n", me);
    else if( (int)me->query("qi") < (int)me->query("max_qi")/2 ) message_vision("$N觉得爪痕象要爆开来一样，全身抽搐不停。\n", me);
    else message_vision("$N觉得爪痕一阵巨痛，不由全身一阵抽搐。\n", me);

    return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

