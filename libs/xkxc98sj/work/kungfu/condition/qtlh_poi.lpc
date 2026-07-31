// qingtuoluohua.c 青陀罗花毒
// cck 17/6/97

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) )
	{
		message("vision", me->name() + "痛苦地呻吟了一声。\n", environment(me), me);
	}

	else
	{
		tell_object(me, HIB "突然你眼前变得模糊起来，你中的青陀罗花毒发作了！\n" NOR );
		message("vision", me->name() + "突然眼皮下垂，瞳孔放大，口唇青紫，走路不稳，言语也变得含糊不清起来。\n",
				environment(me), me);
	}

		me->receive_damage("qi", 35);
		me->receive_wound("jing", 20);
		me->set_temp("last_damage_from", "药毒发作");
		me->apply_condition("qtlh_poi", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
