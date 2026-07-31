#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int lev;
	if( duration < 1 ) return 0;

	lev = (int)me->query("emerald_poison");
        if (!lev) lev =1;
	if (lev < 1 || lev > 8) return 0;

        message_vision(HIR"$N身体一阵颤抖，痛苦地哼了一声。混身经脉疼痛欲裂,扭结成怪异的肉筋.\n"NOR, this_player());
//	message_vision(me->name() + "身体一阵颤抖，痛苦地哼了一声。\n", environment(me), me);
if ((int)me->query("qi") > 300 && 
(int)me->query("jing") > 100)
{
	me->receive_wound("qi", lev * 10 + random(lev * 100));
	me->receive_wound("jing", lev * 10 + random(lev * 20));
}
	me->start_busy(random(lev));
	me->apply_condition("emerald_poison", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
