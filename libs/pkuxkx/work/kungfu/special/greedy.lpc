// greedy.c 饕餮之力
// update by yhzzyahoo@2015.6.5

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "饕餮之力" NOR; }

int perform(object me, string skill)
{
	int count;
	int max_count,add_p;
	
	  if(me->query("age")<18)
		     return notify_fail("你还未成年，不能使用特殊技能。\n");
//      if ( time()- me->query_temp("no_greedy")<=150 )
//             return notify_fail("你刚刚使用过饕餮之力，精力还未平复。\n");
      if (me->query("qi") < 300)
             return notify_fail("你的体力不支，无法竭力使出自己的蛮力。\n");
	  if (me->query("jingli")<200)
             return notify_fail("你的精力不足，无法使用饕餮之力。\n");  
	  if (me->query("neili")<200)
             return notify_fail("你的内力不足，无法使用饕餮之力。\n");  

	  if (me->query("str")>40)
	  {
		  add_p=5;
	  }
	  else
	  {
		  add_p=0;
	  }
	if (me->query("special_level/greedy")>2)
	{
		max_count=15+add_p;
	}
	else
	{
		if (me->query("special_level/greedy")>1)
		{
			max_count=10+add_p;
		}
		else
		{
        return notify_fail("这项技能等级一能够使你恢复速度更快，不需要运用。\n");
		}
	}
	if (me->query_temp("special_skill/greedy", 1))
          return notify_fail("你已经尽力激发自己的蛮力了。\n");
    count = me->query_str() * max_count /100;	
    if (count>=100) count = 100; //最大100
    me->add_temp("apply/strength", count);
  	message_vision(WHT "$N" WHT "大叫一声，使出吃奶的力气，挤出了自身的一点点蛮力。\n" NOR, me);
    me->receive_damage("qi", 100 + random(100));
    me->add("neili",-200);
	me->add("jingli",-200);
    me->set_temp("special_skill/greedy", 1);
//    me->set_temp("no_greedy",time());
//    me->set_temp("active_force_buffer/special.greedy/last_time", time() + count * 3);       //持续时间
    me->set_temp("active_force_buffer/special.greedy/name", HIG "饕餮之力" NOR );                                  //buff名称
    me->set_temp("active_force_buffer/special.greedy/effect1", "臂力+"+count+"点");       //效果描述1   
    me->start_busy(1+random(2));
//    call_out("remove_effect", count * 3, me, count, count);
    return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("special_skill/greedy", 1);
        me->add_temp("apply/strength", -count);
	    me->delete_temp("active_force_buffer/special.greedy");
		me->add("jingshen",-200);
        tell_object(me, "劲力散去，浑身都软了下来。\n");
}

