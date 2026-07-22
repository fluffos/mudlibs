#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
                    tell_object(me, HIY "你的蛤蟆神功终于复原！\n" NOR);
                    me->clear_condition("hama_po");
                 }else
         {       me->add_temp("apply/attack", -random(10));
                 me->add_temp("apply/dodge", -random(10));
                 me->add_temp("apply/parry", -random(10));
         }  
        if (!duration) return 0;
        me->apply_condition("hama_po", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "powerup";
}
