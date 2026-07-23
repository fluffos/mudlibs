#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( !living(me) ) return CND_CONTINUE;
    if (duration % 2 == 0)
	tell_room(environment(me), HIM + me->name()+"朝你诡异地一笑。\n" NOR,
		({ me }));
	if( duration < 1 ) {
		me->set_temp("last_damage_from", "剧毒发作");
		me->die();
		return 0;
	}
	me->apply_condition("sanxiao", duration - 1);
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
