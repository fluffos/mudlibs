// Modified by iszt@pkuxkx, 2007-04-14

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/xxx_poison");
        return 0;
    }

	if( !living(me) )
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	else
	{
		tell_object(me, HIB "突然你打了个寒战，你中的"+cond_def["xxx_poison"]["name"]+"发作了！\n" NOR );
		message("vision", me->name() + "突然打了个寒战，好像要站不住的样子。\n",
			environment(me), me);
	}
    me->set_temp("death_cond_id", "xxx_poison");
	F_POISON->poison_eff(me,"xxx_poison",(["qi":({1,(random(duration/10+2)+1)*20}),"jing":({1,(random(duration/10+2)+1)*20}),]),1); 
	me->apply_condition("xxx_poison", duration - 1);

	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

