// modify by gudu
// Modified by iszt@pkuxkx, 2007-04-14

inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/xx_poison");
        return 0;
    }

	if( !living(me) )
		message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	else
	{
		tell_object(me, HIB "忽然一阵刺骨的奇寒袭来，你中的"+cond_def["xx_poison"]["name"]+"发作了！\n" NOR );
		if(environment(me) && environment(me)->query("real_dark") != 1)
	    {
    		message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
    			environment(me), me);
		}
	}

    me->set_temp("death_cond_id", "xx_poison");
	F_POISON->poison_eff(me,"xx_poison",(["qi":({1,(random(duration/10+2)+1)*30}),"jing":({1,(random(duration/10+2)+1)*30}),]),1); 
	me->apply_condition("xx_poison", duration - 1);

	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
