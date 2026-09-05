// chanchu_poison.c
// by star  98.12.4
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	if(me->query_temp("nopoison")) return 0;
    if( duration < 1 )
    {
        me->delete_temp("death_cond_origin/chanchu_poison");
        return 0;
    }

    me->set_temp("death_cond_id", "chanchu_poison");
	F_POISON->poison_eff(me,"chanchu_poison",(["qi":({1,15+random(50)}),"jing":({1,15+random(40)}),"busy":({4,random(3)}),]),1); 
	me->apply_condition("chanchu_poison", duration - 1);
	tell_object(me, HIG "你中的"+cond_def["chanchu_poison"]["name"]+"发作了！\n" NOR );

	return CND_CONTINUE;
}


string query_type(object me)
{
	return "poison";
}

