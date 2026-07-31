//六脉神剑之少商剑气内伤
//By KinGSo 2007.1.4
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me,int duration)
{
	if(!environment(me)) return CND_CONTINUE;
	
	me->receive_wound("qi", random(1000));
	me->add("neili",- random(300));
	me->add_busy(2);
	me->set_temp("last_damage_from","少商剑气内伤发作");
	if( !living(me) ) message("vision",HIB+ me->name() + MAG"只觉方才受少商剑气所伤，五脏翻腾，痛苦地哼了一声。\n"NOR, environment(me), me);
	else 
		message_vision(MAG"$N只觉方才受少商剑气所伤，五脏翻腾，痛苦地哼了一声。\n"NOR,me);
	if(duration < 1) return 0;
	me->apply_condition("liumai_shaoshang_hurt",duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
        return "hurt";
}
	