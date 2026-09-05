// health.c 气息悠长
//update by yhzzyahoo @2015.6.5
//效果从30%加到45%
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIG "气息悠长" NOR; }

int perform(object me, string skill)
{
	int count;
	int max_count;
	
	  if(me->query("age")<18)
		      return notify_fail("你还未成年，不能使用特殊技能。\n");
	  if (me->query_temp("special_skill/health", 1))
          return notify_fail("你已经尽力激发自己的体力了。\n");
 	  if(me->query_temp("init_max_qi"))
        	count =me->query_temp("init_max_qi") * 9 /20;
     else 
       	{
       		me->set_temp("init_max_qi",me->query("max_qi"));
       		count =me->query_temp("init_max_qi") * 9 /20;	
       	}
	if (me->query("special_level/health")>2)
	{
		max_count=15000;
	}
	else
	{
		if (me->query("special_level/health")>1)
		{
			max_count=10000;
		}
		else
		{
			max_count=6000;
		}
	}

    if (count>=max_count) count = max_count; //最大15000
    me->add_temp("apply/max_qi", count);
    me->set("max_qi", me->query_max_qi() );
	  me->set("eff_qi",me->query("eff_qi")+count);
	  me->set("qi",me->query("qi")+count);
       
    if(me->query("qi")>me->query("max_qi")) 
		me->set("qi",me->query("max_qi"));
   	message_vision(WHT "$N" WHT "凝神聚气，将周身连同丹田内的气息一同运转，顿时感觉气息充足。\n" NOR, me);
    me->receive_damage("qi", 40 + random(40));
    me->set_temp("special_skill/health", 1);
    me->set_temp("active_force_buffer/special.health/name", HIG "气息悠长" NOR );                                  //buff名称
    me->set_temp("active_force_buffer/special.health/effect1", "气血+"+count+"点");       //效果描述1       
    return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("special_skill/health", 1);
        
        me->add_temp("apply/max_qi", -count);
        me->set("max_qi", me->query_max_qi());
	      if(me->query("eff_qi")>count)                    
		       me->set("eff_qi",me->query("eff_qi")-count);
	      else
		      me->set("eff_qi",10);
	      if(me->query("qi")>count)
		      me->set("qi",me->query("qi")-count);
	      else
		      me->set("qi",10);	
		    me->delete_temp("active_force_buffer/special.health");
        tell_object(me, "丹田中的气息渐渐的散去了。\n");
}

