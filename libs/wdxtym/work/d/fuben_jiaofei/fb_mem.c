inherit F_DBASE;

#include "include/fb_mem.h"
#include "finish_obj_map.h"

void heart(int open)
{
	int i;
	object me;
	object *team;
	object temp;
	
	me = this_object();
	team = me->query("team");
	if (me->query("fuben_end_sign") == 1)
	{
		if(delete_map(me))
		{
			destruct(me);
			return ;
		}
	}
	foreach(temp in team)
	{
    	if((!environment(temp)->query("is_fuben")) && !open)
    	{
    		if(delete_map(me))
    		{
    			for(i = 0; i < sizeof(team); i++)
    				tell_object(team[i], "检测到有人离开副本，副本已清除。\n");
    			destruct(me);
    			return ;
    		}
    	}
    }

	if (query("fuben_end") < time())
	{
		if(delete_map(me))
		{
			destruct(me);
			message("shout", "时间到，停止挑战。\n", team);
			return ;
		}
	}

	call_out("heart", 5);
}

int delete_map(object me)
{
	object temp, *room_arr;
	object *objs, obj;
	
	room_arr = me->query("room_obj");
	
	foreach(temp in room_arr)
	{
		if (!temp || !clonep(temp))	continue;
		if (!objectp(temp))	continue;
		if (!objs = all_inventory(temp) || !arrayp(objs))	continue;
		
		foreach (obj in objs)
		{
			if (!objectp(obj))	continue;
			if (userp(environment(obj))) continue;
			if (userp(obj))
			{
				//obj->move("/d/city/guangchang");
				obj->move("/d/city/ymzhengting");
				continue;
			}
		}
		destruct(temp);
	}
	
	return 1;
}

void fuben_finish(object who)
{
	remove_call_out("heart");
	call_out("fuben_end", 3, who);
}

void fuben_end(object who)
{
	int i, fuben_jiaofei, money_amount;
	object *team;
	object obj, money, suipian;
	
	team = who->query_team();
	
	if(this_object()->query("have_noplayer"))
	{
		message("shout", "击杀匪徒时队伍中存在不在匪徒房间的人，副本结束。\n", team);
	}
	else
	{
    	for(i = 0; i < sizeof(team); i++)
    	{
    		fuben_jiaofei = team[i]->query("fuben_jiaofei/count");
    		
    		if ((fuben_jiaofei/10) < ((fuben_jiaofei+1)/10))
        	{
        		suipian = new(__DIR__"obj/butian_suipian");
        		tell_object(team[i], "你完成了副本获得了" + suipian->name());
        		suipian->move(team[i]);
        		if (i == 0)
        		{
        			obj = new(finish_obj[random(sizeof(finish_obj))]);
        			tell_object(team[i], "队长十环额外奖励，你获得了" + obj->query("name") + "。\n");
        			obj->move(team[i]);
        		}
    		}
        	team[i]->add("fuben_jiaofei/count", 1);
        	team[i]->add("xiayi", 1);
        	tell_object(team[i], "你目前完成了" + (fuben_jiaofei + 1) + "次副本。\n");
        	if (i)
        		money_amount = 70;
        	else
        		money_amount = 90;
        	money = new("/clone/money/silver");
        	money->set_amount(money_amount);
        	tell_object(team[i], "你获得了" + money->short() + "\n");
        	money->move(team[i]);
    		if (fuben_jiaofei < 5)
    		{
        		if (i == 0)
        		{
        			team[i]->add("combat_exp", 10000);
        			team[i]->add("potential", 10000);
					team[i]->add("tufeijf", 1);
        			tell_object(team[i], "你获得了1点土匪点券（客栈使者领取） 10000点修为 10000点潜能。\n");
        		}
        		else
        		{
        			team[i]->add("combat_exp", 10000);
        			team[i]->add("potential", 10000);
					team[i]->add("tufeijf", 1);
        			tell_object(team[i], "你获得了1点土匪点券（客栈使者领取）1000修为和1000点潜能。\n");
        		}
        	}
        	else
        		tell_object(team[i], "你今日副本完成超过五次，无法再获得修为潜能。\n");
    	}
    }
    	
	this_object()->set("fuben_end_sign", 1);
	heart(0);
}