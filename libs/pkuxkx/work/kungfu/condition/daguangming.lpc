// daguangming xinfa

#include <ansi.h>

int update_condition(object me, int duration)
{
        int max_qi,max_jing,refresh_qi, last_time;
        if (!me->query_temp("daguangming"))
        {
            return 0;
        }
	    if (duration < 1) 
        {
            max_qi=(int)me->query_temp("daguangming/qi");
            max_jing=(int)me->query_temp("daguangming/jing");
            me->add_temp("apply/max_jing", -max_jing);
            me->add_temp("apply/max_qi", -max_qi);
            
            if (me->query("eff_qi")>max_qi)//仍然处于加气状态
            {
                me->add("eff_qi",-max_qi);
            }
            if (me->query("qi")>max_qi)
            {
                me->add("qi",-max_qi);
            }
            me->set("max_qi",me->query_max_qi());//不处于加气状态不回复
            if (me->query("eff_jing")>max_jing)
            {
                me->add("eff_jing",-max_jing);
            }
            if (me->query("jing")>max_jing)
            {
                me->add("jing",-max_jing);
            }
            me->set("max_jing",me->query_max_jing());
            me->delete_temp("daguangming/apply");
            tell_object(me, CYN+"你的大光明心法运转一圈，渐渐恢复平静。\n"NOR);
            me->delete_temp("active_force_buffer/kuihua-shengong.guangming");
            me->delete_temp("active_force_buffer/riyue-shengong.guangming");
            me->delete_temp("active_force_buffer/xixing-dafa.guangming");
		        return 0;
	    }
		if ((int)me->query("qi")<(int)me->query("eff_qi"))
		{
			refresh_qi=(int)me->query_skill("daguangming-xinfa",1)/5;
			if ((int)me->query("eff_qi")-(int)me->query("qi")>refresh_qi)
			{
				me->add("qi",refresh_qi);
			}
			else
			{
				me->set("qi",(int)me->query("eff_qi"));
			}
			message_vision("大光明心法在$N体内运转不息，气息又恢复了些许。\n",me);
		}
		
		last_time=me->query_temp("active_force_buffer/kuihua-shengong.guangming/last_time");
		if ( last_time )
		{ 
			if ( last_time-time()<duration*10-5 )
			  me->add_temp("active_force_buffer/kuihua-shengong.guangming/last_time",10);
	    else if ( last_time-time()>duration*10+5 )
        me->add_temp("active_force_buffer/kuihua-shengong.guangming/last_time",-10);
      
      tell_object(me, sprintf("%d, %d\n",last_time-time(), duration));
    }

    last_time=me->query_temp("active_force_buffer/riyue-shengong.guangming/last_time");
		if ( last_time )
		{ 
			if ( last_time-time()<duration*10-5 )
			  me->add_temp("active_force_buffer/riyue-shengong.guangming/last_time",10);
	    else if ( last_time-time()>duration*10+5 )
        me->add_temp("active_force_buffer/riyue-shengong.guangming/last_time",-10);
      
      tell_object(me, sprintf("%d, %d\n",last_time-time(), duration));
    }

    last_time=me->query_temp("active_force_buffer/xixing-dafa.guangming/last_time");
		if ( last_time )
		{ 
			if ( last_time-time()<duration*10-5 )
			  me->add_temp("active_force_buffer/xixing-dafa.guangming/last_time",10);
	    else if ( last_time-time()>duration*10+5 )
        me->add_temp("active_force_buffer/xixing-dafa.guangming/last_time",-10);
      
      tell_object(me, sprintf("%d, %d\n",last_time-time(), duration));
    }
			
    me->apply_condition("daguangming", duration - 1);
	  return 1;
}
