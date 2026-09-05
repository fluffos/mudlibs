//瘟疫
//每次发作降低eff_qi
//同时可能传染给身边的人


#include <login.h>
int update_condition(object me, int duration)
{
	object* ob;
	int i =0;

    return 0;
	if(me->query_temp("wenyi/damage") <= 0)
	{
		me->add("eff_qi",-10);
		me->set_temp("wenyi/damage",10);
	}
	else
	{
		if(userp(me) && me->query("max_neili") > 1000)
		{
			me->add("eff_qi",-me->query_temp("wenyi/damage"));
		}
		else
		{
			me->add("eff_qi",-me->query_temp("wenyi/damage")/10);
		}
		me->add_temp("wenyi/damage",-(random(3)+1));
	}

	if(me->query("eff_qi") <= 0)
	{
		me->set("eff_qi",1);
		return 0;
	}

	ob = all_inventory(environment(me));

	if(arrayp(ob))
	{
		for(i=0;i<sizeof(ob);i++)
		{
			if(random(5) != 0) continue;

			if(ob[i]->query_condition("wenyi") == 0)
			{
				if(random(ob[i]->query_temp("wenyi/infect_times")) > 3)
				{
					ob[i]->apply_condition("wenyi",1);
					ob[i]->delete_temp("wenyi/infect_times");
				}
				else
				{
					ob[i]->add_temp("wenyi/infect_times",1);
				}
			}
		}
	}

	if(random(10) == 0)
	{
		message_vision("$N面色晦暗，目光无神，看起来病怏怏的。\n",me);
	}

	if(random(1000) == 0)
	{
		tell_object(me,"你感到自己觉得舒服了一点");
		return 0;
	}
	return 1;
}
