#include <ansi.h>

int update_condition(object me, int duration)
{

if (me->query("eff_qi") > 100)
	me->receive_wound("qi", me->query("eff_qi")/8);
if (me->query("qi") > 100)
	me->receive_damage("qi", me->query("qi")/8);
if (me->query("eff_jing") > 100)
	me->receive_wound("jing", me->query("eff_jing")/8);
if (me->query("jing") > 100)
	me->receive_damage("jing", me->query("jing")/8);


    me->start_busy(2);
        me->apply_condition("feidian_poison", duration - 1);
        message_vision(RED"$N感到全身发热，呼吸困难，又咳嗽了几声。\n"NOR, me);
        tell_object(me, RED "你的非典型性肺炎发作了!\n" NOR );

        if( duration < 1 ) return 0;
        return 1;
}


