#include <ansi.h>
#include <localtime.h>
int exer()
{
    if (!living(this_object()))
    return 1;
    command("exert recover");
	command("exert powerup");
	return 1;
}

int gene(object ob)
{
	object robber=this_object();
	mapping skills;
	int i,adjust_lv,lv,exp,point;
	if (!ob||!ob->is_mazei())
	{
		return 1;
	}
	lv=ob->query("level");
	robber->set("belong",ob);
	skills=robber->query_skills();
	adjust_lv=random(lv*40/50+5);
	exp=(lv*40)*(lv*40)/9*(lv*40);
	exp=exp/10*9+random(exp/5);
	lv=lv*40-adjust_lv;
	point=lv*10;
	if (lv>200)
	{
		point=point+random(point);
	}
	if (lv>500)
	{
		point=point+random(point);
	}
	for (i=0;i<sizeof(skills);i++)
	{
		skills[keys(skills)[i]] = lv;
	}
	robber->set("combat_exp",exp);
	point=point/2+random(point/2);
	robber->set("qi", point);
    robber->set("eff_qi",point);
    robber->set("max_qi",point);
	point=point/2+random(point/2);
    robber->set("max_neili", point);
    robber->set("neili", point);
	point=point/2+random(point/2);
    robber->set("max_jingli", point);
    robber->set("jingli", point);
	point=point/2+random(point/2);
    robber->set("max_jing", point);
    robber->set("eff_jing",point);
    robber->set("jing", point);
	robber->set("title",HIR"马贼"NOR);
	return 1;
}
int check_status()
{
	object ob=this_object();
	object lord=ob->query("belong");
	if (!lord)
	{
		destruct(ob);
	}
	return 1;
}
void init()
{
    add_action("do_none", "steal");
    add_action("do_none", "attack");
    add_action("do_none", "beg");
    set("random_npc",1);
}

int weigh(object user,int exp,int point)
{
	float index,base_exp;
    int result;
	point=point/6;
    base_exp=100000000.0;
    index=1-exp/base_exp;
    result=to_int(point*index);
	result=REWARD_D->check_robot(user,point);
	if (result<=0)
    {
        result=1;
    }
    return result;
}
int weigh_money(object user,int point)
{
	point=REWARD_D->check_robot(user,point);
	return point;
}
int reward(object user,object robber,int damage,int flag)
{
	object *teamers,manager,lord,record=load_object("/d/menggu/zeiwo");
	int point,exp=user->query("combat_exp");
	mixed tm=localtime(time());
    string current=sprintf("%d-%d-%d-%d", tm[5], tm[4]+1, tm[3],tm[2]+1);
	string today=sprintf("%d-%d-%d", tm[5], tm[4]+1, tm[3]);
	if (user->query("statistic/menggu_mazei/gain_current")!=current)
	{
		user->set("statistic/menggu_mazei/gain_current",current);
		user->set("statistic/menggu_mazei/gain_current_point",0);
	}
	if (user->query("statistic/menggu_mazei/gain_today")!=today)
	{
		user->set("statistic/menggu_mazei/gain_today",today);
		user->set("statistic/menggu_mazei/gain_today_point",0);
	}
	if (current=user->query("statistic/menggu_mazei/gain_current")&&user->query("statistic/menggu_mazei/gain_current_point")>250000)
	{
		tell_object(user,BLINK+HIW+"这个时段你杀马贼造杀孽太重，有违天和，收收手吧。\n"+NOR);
		return 1;
	}
	if (today=user->query("statistic/menggu_mazei/gain_today")&&user->query("statistic/menggu_mazei/gain_today_point")>2000000)
	{
		tell_object(user,BLINK+HIW+"今日你杀马贼造杀孽太重，有违天和，收收手吧。\n"+NOR);
		return 1;
	}
	record->restore();
	if (damage==0&&flag==0)//死
	{
		if (robber->query("combat_exp")>exp/3*2)
		{
			point=weigh(user,exp,robber->query("max_qi")/4);
			robber->add("lost_points",point);
			if (robber->query("lost_points")<20000)
			{
				record->add("reward_for_exp/"+user->query("id")+"/points",point);
				user->add("statistic/menggu_mazei/gain_exp/"+robber->query("id"),point);
			}
		}
		else
		{
			point=weigh_money(user,robber->query("max_qi")/4);
			robber->add("lost_points",point);
			if (robber->query("lost_points")<20000)
			{
				record->add("reward_for_others/"+user->query("id")+"/points",point);
				user->add("statistic/menggu_mazei/gain_money/"+robber->query("id"),point);
			}
		}
		user->add("statistic/menggu_mazei/robber_kills",1);
	}
	else
	{
		if (robber->query("combat_exp")>exp/3*2)
		{
			point=weigh(user,exp,damage);
			robber->add("lost_points",point);
			if (robber->query("lost_points")<20000)
			{
				record->add("reward_for_exp/"+user->query("id")+"/points",point);
				user->add("statistic/menggu_mazei/gain_exp/"+robber->query("id"),point);
			}
		}
		else
		{
			point=weigh_money(user,damage);
			robber->add("lost_points",point);
			if (robber->query("lost_points")<20000)
			{
				record->add("reward_for_others/"+user->query("id")+"/points",point);
				user->add("statistic/menggu_mazei/gain_money/"+robber->query("id"),point);
			}
		}
	}
	record->save();
	user->add("statistic/menggu_mazei/gain_current_point",point);
	user->add("statistic/menggu_mazei/gain_today_point",point);
	return 1;
}
void die()
{
    object killer,lord,ob=this_object(),manager,*teamers;
    if(userp(killer = get_damage_origin_object()))
    {
        reward(killer,ob,0,0);
    }
    lord=query("belong");
	if (lord)
	lord->add("members",-1);
	teamers=lord->query("teamers");
	teamers-=({ob});
	lord->set("teamers",teamers);
	message_vision("$N死了。\n",ob);
	if (lord->query("members")==0)
	{
		message_vision(HIG"整队的马贼溃灭了。\n"NOR,lord);
		destruct(lord);
		manager=load_object("/d/menggu/xiboliya");
		manager->replenish_robber();
	}
    destruct(ob);
	return ;
}

varargs int receive_damage(string type, int damage, mixed who)
{
	int ret=0;
	object killer;

	ret=::receive_damage(type, damage, who);
    killer=get_damage_origin_object();

	if(objectp(killer) && userp(killer)) reward(killer, this_object(), damage, 1);

	return ret;
}


void unconcious() 
{
    object ob=this_object();
    object killer=ob->get_damage_origin_object();
    int damage=(int)ob->query("max_qi")/5;
    if(random(4) == 1 && ob->query("qi") > (ob->query("max_qi")/100)*50 && ob->query("eff_qi") > (ob->query("max_qi")/100)*50 && ob->query("jing") > (ob->query("max_jing")/100)*50 && ob->query("eff_jing") > (ob->query("max_jing")/100)*50)
	{
		ob->receive_damage("qi", damage, killer);
		ob->receive_wound("qi", damage/2, killer);
		return;
	}
	else
	{
		call_out("die",1);
		return;
	}
}

int do_none()
{
    return 1;
}
