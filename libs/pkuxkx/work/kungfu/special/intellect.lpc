// intellect.c 聪明睿智
//update by yhzzyahoo@2015.6.5
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return MAG "聪明睿智" NOR; }

int perform(object me, string skill)
{
	int count;
	int max_count,add_p;
	
	  if(me->query("age")<18)
		     return notify_fail("你还未成年，不能使用特殊技能。\n");
//      if ( time()- me->query_temp("no_intellect")<=240 )
//             return notify_fail("你刚刚使用过聪明睿智，精力还未平复。\n");
      if (me->query("qi") < 300)
             return notify_fail("你的体力不支，无法竭力使出自己的蛮力。\n");

	  if (me->query("jingli")<200)
             return notify_fail("你的精力不足，无法使用聪明睿智。\n");  
	  if (me->query("neili")<200)
             return notify_fail("你的内力不足，无法使用聪明睿智。\n");  

	  if (me->query("int")>40)
	  {
		  add_p=5;
	  }
	  else
	  {
		  add_p=0;
	  }
	if (me->query("special_level/intellect")>1)
	{
		max_count=10+add_p;
	}
	else
	{
        return notify_fail("这项技能等级一能够使你悟性更高，不需要运用。\n");
	}
	if (me->query_temp("special_skill/intellect", 1))
          return notify_fail("你已经尽力发挥了自己的所有智商了。\n");
    count = me->query_int() * max_count /100;	
    if (count>=80) count = 80; //最大80
    me->add_temp("apply/intelligence", count);
  	message_vision(WHT "$N" WHT "绞劲脑汁，将自己的智商发挥到了极限。\n" NOR, me);
    me->receive_damage("qi", 100 + random(100));
    me->add("neili",-200);
	me->add("jingli",-200);
    me->set_temp("special_skill/intellect", 1);
//    me->set_temp("no_intellect",time());
//    me->set_temp("active_force_buffer/special.intellect/last_time", time() + count * 3);       //持续时间
    me->set_temp("active_force_buffer/special.intellect/name", HIG "聪明睿智" NOR );                                  //buff名称
    me->set_temp("active_force_buffer/special.intellect/effect1", "悟性+"+count+"点");       //效果描述1   
    me->start_busy(1+random(2));
//    call_out("remove_effect", count * 3, me, count, count);
    return 1;
}

void remove_effect(object me, int count)
{
        me->delete_temp("special_skill/intellect", 1);
        me->add_temp("apply/intelligence", -count);
	    me->delete_temp("active_force_buffer/special.intellect");
		me->add("jingshen",-200);
        tell_object(me, "脑子一疼，你的思维一片混乱。\n");
}
