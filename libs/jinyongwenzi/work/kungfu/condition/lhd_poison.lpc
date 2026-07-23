#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if(!living(me)) {
      		message("vision", me->name() + "全身变黑，散发出一阵焦糊味。\n", environment(me), me);
   	}
	else {
      	tell_object(me, HIR "忽然被炸伤的地方传来一阵巨痛！\n" NOR );
      	tell_room(environment(me), HIR "一阵焦糊的味道从"+ me->name()+"身上传了出来，"+ me->name()+"被疼呻吟不止。\n" NOR,
                ({ me })); 
	}	
      	me->receive_damage("qi", 2000);
      	me->set_temp("last_damage_from", "被霹雳雷火弹炸");
      	if(userp(me))
        	me->receive_wound("jing", 2000);
      	else me->receive_wound("jing", 3000);
	me->add_busy(2);
      		me->apply_condition("lhd_poison", duration - 1);
   	if( duration < 1 ) return 0;
   	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
