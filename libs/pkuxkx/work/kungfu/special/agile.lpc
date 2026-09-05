// agile.c 身轻如燕

#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "身轻如燕" NOR; }

int perform(object me, string skill)
{
	int count;
	int max_count,add_p;
	int c_time;
	
	  if(me->query("age")<18)
		     return notify_fail("你还未成年，不能使用特殊技能。\n");
//      if ( time()- me->query_temp("no_agile")<=150 )
//             return notify_fail("你刚刚使用过身轻如燕，精力还未平复。\n");
      if (me->query("qi") < 300)
                return notify_fail("你的体力不支，无法竭力提升自己的速度。\n");
	  if (me->query("jingli")<200)
             return notify_fail("你的精力不足，无法使用身轻如燕。\n");  
	  if (me->query("neili")<200)
             return notify_fail("你的内力不足，无法使用身轻如燕。\n");  

	  if (me->query("dex")>40)
	  {
		  add_p=5;
	  }
	  else
	  {
		  add_p=0;
	  }
	  max_count=0;
	/*if (me->query("special_level/agile")>2)
	{
		if (me->query("special_skill/chainless") && me->query("special_skill/ironskin"))
		{
			max_count=15+add_p;
		}
		else
		{
			if (me->query("special_skill/chainless"))
			{
				max_count=10+add_p;
			}
		}
	}
	else
	{
		if ((me->query("special_level/agile")>1)&&(me->query("special_skill/chainless")))
		{
			max_count=10+add_p;
		}
	}*/
	if (me->query("special_level/agile")>2)
	{
		max_count=15+add_p;
	}
	else
	{
		if ((me->query("special_level/agile")>1)&&(me->query("special_skill/chainless")))
		{
			max_count=5+add_p;
		}
	}

	if (me->query_temp("special_skill/agile"))
         return notify_fail("你已经竭力提升你自己的速度了。\n");
    message_vision(HIC "$N默默提气，顿时感觉自己身轻如燕。\n" NOR, me);
    count=(int)me->query_skill("dodge",1)*3/10;
	c_time=(int)count/2;
    me->receive_damage("qi", 100 + random(100));
    me->add("neili",-200);
	me->add("jingli",-200);
//    me->set_temp("no_agile",time());
    me->add_temp("apply/dodge", count);
    me->add_temp("apply/kf_anti_hr", count/450+1);    //基本轻功小于1500级1级特殊技能命中防御效果，否则2级特殊技能命中防御效果
    me->set_temp("special_skill/agile", 1+max_count);
//	me->set_temp("active_force_buffer/special.agile/last_time", time() + c_time);       //持续时间
	me->set_temp("active_force_buffer/special.agile/name", HIC "身轻如燕" NOR );                                  //buff名称
    me->set_temp("active_force_buffer/special.agile/effect1", "对方特殊技能命中-"+(count/450+1)+"级");       //效果描述1   
    me->set_temp("active_force_buffer/special.agile/effect2", "轻功技能+"+count+"级");       //效果描述2
    me->set_temp("active_force_buffer/special.agile/effect3", "对方一招晕命中-"+max_count+"%");       //效果描述3
    me->start_busy(1+random(2));
//    call_out("remove_effect", c_time, me, count, max_count);
    return 1;
}

void remove_effect(object me, int count,int max_count)
{
        me->delete_temp("special_skill/agile");
        me->add_temp("apply/dodge", -count);
		me->add_temp("apply/kf_anti_hr", -(count/450+1));
	    me->delete_temp("active_force_buffer/special.agile");
		me->add("jingshen",-200);
        tell_object(me, "一口气散去，身子都沉了许多。\n");
}
