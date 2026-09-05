// wugong_poison.c
// by star  98.12.4
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
    if( me->query_temp("nopoison") || duration < 1 )
    {
        me->delete_temp("death_cond_origin/wugong_poison");
        return 0;
    }

    me->set_temp("death_cond_id", "wugong_poison");
	F_POISON->poison_eff(me,"wugong_poison",(["qi":({1,15+random(50)}),"jing":({0,15+random(45)}),"busy":({4,random(3)})]),1); 
	me->apply_condition("wugong_poison", duration - 1);
	tell_object(me, HIG "你中的"+cond_def["wugong_poison"]["name"]+"发作了！\n" NOR );

	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}

