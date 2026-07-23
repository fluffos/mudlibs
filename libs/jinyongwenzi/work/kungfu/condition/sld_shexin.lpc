#include <ansi.h>
#include <condition.h>
//modify By Ziqing Y2k
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{    
      	tell_object(me, HIC "你想起神龙邪教的种种诡异之处，一腔豪气再也提不起来。\n" NOR );
      	message_vision(HIC"$N突然一阵恐惧，瞬息之间仿佛老了几十岁。\n"NOR, me);
        
        me->set_temp("last_damage_from", "恐惧而");
        me->receive_wound("jing", random(me->query_skill("force"))/2 );
        me->receive_damage("jingli", random(me->query_skill("force")) );
        me->add_condition("sld_shexin",-1);
      	if( duration < 1 ) 
      		return 0;
      	return CND_CONTINUE;
}

string query_type(object me)
{
        return "hurt";
}

