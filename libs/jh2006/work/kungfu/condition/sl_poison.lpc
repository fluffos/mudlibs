// sl_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if(!living(me))
                return 0;
       me->receive_wound("qi", 100);
	me->receive_damage("qi", 100);
me->receive_damage("jingli",100);
me->receive_wound("jing",100);
	me->set_temp("last_damage_from", "神龙毒发作");
	me->apply_condition("sl_poison", duration - 1);
	if (living(me))
		message_vision(BLU "$N两眼发直，身子瑟瑟抖了起来！\n" NOR, me);
	else
       {
		message_vision(BLU "$N痛苦地呻咛了一声！\n" NOR, me);
              return 0;
             }
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
        return "poison";
}
