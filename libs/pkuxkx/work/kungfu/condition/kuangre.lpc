//狂热病
//提高攻击力，加快食物和水的消耗速度

#include <login.h>
int update_condition(object me, int duration)
{
	object* ob;
	int i =0;
	int bonus = 0;
    return 0;
	if(!me->query_temp("kuangre/bonus"))
	{
		if(me->query_temp("apply/damage") > 0)
		{
			bonus = me->query_temp("apply/damage")/5;
		}
		else
		{
			bonus = random(50)+1;
		}

		me->add_temp("apply/damage",bonus);
		write("你感到身体一阵燥热，血液似乎想要冲破身体迸发出来，战斗的欲望也变得更加强烈。\n");
		me->set_temp("kuangre/bonus",bonus);
	}
	else
	{
		//消耗食物和水
		me->add("food",-me->query_temp("kuangre/bonus"));
		me->add("water",-me->query_temp("kuangre/bonus"));
		if(me->query("food") < 0) me->set("food",0);
		if(me->query("water") < 0) me->set("water",0);
	}

	if(random(1000) == 0)
	{
		tell_object(me,"你感到自己觉得舒服了一点，燥热慢慢褪去了。\n");
		me->add_temp("apply/damage",-me->query_temp("kuangre/bonus"));
		if(me->query_temp("apply/damage") < 0)
		{
			me->set_temp("apply/damage",0);
		}
		me->delete_temp("kuangre");
		return 0;
	}

	if(objectp(environment(me)) && environment(me)->query("no_sick_spread"))
	{
		return 1;
	}

	ob = all_inventory(environment(me));


	if(arrayp(ob))
	{
		for(i=0;i<sizeof(ob);i++)
		{
			if(random(5) != 0) continue;

			if(ob[i]->query_condition("kuangre") == 0)
			{
				if(random(ob[i]->query_temp("kuangre/infect_times")) > 3)
				{
					ob[i]->apply_condition("kuangre",1);
					ob[i]->delete_temp("kuangre/infect_times");
				}
				else
				{
					ob[i]->add_temp("kuangre/infect_times",1);
				}
			}
		}
	}
	return 1;
}
