// trans_condition.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (!me->query_temp("trans")) {
	me->clear_condition("trans_condition");
 	 return 0;
        }
        if (duration < 1) {
        message_vision(WHT"$N脸色通红，额头渗出一层汗珠。\n", me);
        tell_object(me, BLU"你感到全身似乎有丝丝热气冒出，传功的功力消耗完了。\n"NOR);
        me->delete_temp("trans");
        me->add_temp("apply/strength", -me->query_temp("trans_1"));
        me->add_temp("apply/attack", -me->query_temp("trans_2")); 
        me->delete_temp("trans_1");
        me->delete_temp("trans_2");
        me->clear_condition("trans_condition");
         return 0;
        }
        me->apply_condition("trans_condition", duration - 1);
        return 1;
}
