// energy.c 聚精会神

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIG "聚精会神" NOR; }

int perform(object me, string skill)
{
        int count;
        
          if(me->query("age")<18)
                      return notify_fail("你还未成年，不能使用特殊技能。\n");
          if (me->query_temp("special_skill/energy", 1))
	          return notify_fail("你已经尽力激发自己的精神了。\n");
		  if (me->query("qi") < 300)
				 return notify_fail("你的体力不支，无法发挥自己的精神力量。\n");
		  if (me->query("jingli")<200)
				 return notify_fail("你的精力不足，无法使用聚精会神。\n");  
		  if (me->query("neili")<200)
				 return notify_fail("你的内力不足，无法使用聚精会神。\n");  

          if(me->query_temp("init_max_jing"))
                count =me->query_temp("init_max_jing") * 3 /10;
     else 
        {
                me->set_temp("init_max_jing",me->query("max_jing"));
                count =me->query_temp("init_max_jing") * 3 /10;   
        }
    if (count>=6000) count = 6000; //最大6000
    	me->add_temp("apply/max_jing", count);
          me->set("max_jing",me->query_max_jing());
          me->set("eff_jing",me->query("eff_jing")+count);
          me->set("jing",me->query("jing")+count);
         if(me->query("jing")>me->query("max_jing")) me->set("jing",me->query("max_jing"));
       
        message_vision(WHT "$N" WHT "静心凝神，意守丹田，顿时觉得精神充沛。\n" NOR, me);
		me->receive_damage("qi", 100 + random(100));
		me->add("neili",-200);
		me->add("jingli",-200);
		me->set_temp("special_skill/energy", 1);
        me->set_temp("active_force_buffer/special.energy/name", HIG "聚精会神" NOR );                                  //buff名称
        me->set_temp("active_force_buffer/special.energy/effect1", "精神+"+count+"点");       //效果描述1
		if ((me->query("special_level/energy")>1)&&me->query("special_skill/intellect"))
		{
		  me->add_temp("special_skill/energy", 1);
          me->set_temp("active_force_buffer/special.energy/effect2", "全神贯注");       //效果描述1
		}
/*
        me->start_call_out((: call_other, __FILE__, "remove_effect", me,
                              count :), 360 + random(30));
*/
        return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("special_skill/energy");

        me->add_temp("apply/max_jing", -count);
        me->set("max_jing", me->query_max_jing());
              if(me->query("eff_jing")>count)                    
                       me->set("eff_jing",me->query("eff_jing")-count);
              else
                      me->set("eff_jing",10);
              if(me->query("jing")>count)
                      me->set("jing",me->query("jing")-count);
              else
                      me->set("jing",10); 
        me->delete_temp("active_force_buffer/special.energy");
        tell_object(me, "你渐渐的放送下来，感觉精神没有那么充沛了。\n");
}
