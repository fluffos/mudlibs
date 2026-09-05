// snake_poison.c
// Modified by iszt@pkuxkx, 2007-04-14

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/snake_poison");
        return 0;
    }

    me->set_temp("death_cond_id", "snake_poison");
	F_POISON->poison_eff(me,"snake_poison",(["qi":({0,(random(duration/10+2)+1)*10}),"jing":({1,(random(duration/10+2)+1)*10}),]),1); 
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "你中的"+cond_def["snake_poison"]["name"]+"发作了！\n" NOR );
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}