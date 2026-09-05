//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
#include <room.h>
inherit ROOM;
int lvl;
int do_qiao(string arg);
int do_jiangli();
int do_look(string dir);

int give_reward(object me);


void init()
{	
	object me=this_player();
    object ob,room;
	object *tasknpc;

    int target_num;
	lvl = query("room_lvl");
	room=this_object();
	
	//主要是这个，帮我看看


  if (!userp(me) && me->query("id")!="fanbang wushi" )
  {
	  me->move(__DIR__"wananta");
	  return;
  }
  //到这里结束
	

	if (lvl<4)
	{
		target_num=1;
	}
	if (lvl>3)
	{
		target_num = 1+random(lvl-3);
	}
	
    
    if(!me->query_temp(sprintf("wananta/%d",lvl)) && interactive(me))
    {
    	for (int a=0;a< target_num;a++ )
    	{    	    
    		ob = new(__DIR__"npc/fanseng");
   		    ob->set_temp("seeme",me->query("id"));
    		ob->set("job_level", lvl);
    		ob->do_copy(me);
    		ob->move(this_object());
    		ob->kill_ob(me);
    		me->kill_ob(ob);
    	}
    }
   
        
	add_action("do_qiao","qiao");       //敲锣
	add_action("do_jiangli","jiangli");   
	add_action("do_look","look");
    set("real_dark",1);
    //测试期间假死
    set("no_die",1);
    set("least_msg",1);
    this_player()->listen_to_die(this_object());
}

//当有玩家在此死亡时调用
int die_notify(object victim)
{
    object* obs;
    if(userp(victim))
    {
        victim->delete_temp("wananta");
        victim->set_temp("death_msg","万安塔力战而");        
        obs = all_inventory( environment( victim ));
        for(int i=0; i<sizeof(obs); i++) 
        {
            if( obs[i]->query("id") == "fanbang wushi" && obs[i]->query("uni_target") == victim)
            {
                destruct(obs[i]);
            }
        }        
    }     
    return 1;
}

int do_jiangli()
{
	object me=this_player();
	string jiangli_msg;
	

	
	if (!this_player()->is_fighting())
	{
		jiangli_msg="你现在可以获得奖励：";
		jiangli_msg += chinese_number(me->query_temp("wananta/reward_re"))+"点江湖声望";
		jiangli_msg += chinese_number(me->query_temp("wananta/reward_qn"))+"点潜能、";
		jiangli_msg += chinese_number(me->query_temp("wananta/reward_exp"))+"点经验";
		if (lvl>3)
		{
			jiangli_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"));
		}
		
		
		jiangli_msg += "！\n";
		write(jiangli_msg);
		return 1;
	}

	write("能活下来再说吧。。。\n");
	return 1;
}

int do_qiao(string arg)
{
	if (this_player()->is_fighting())
	{
		write("战斗还没完呢，瞎敲什么！！\n");
		return 1;
	}
	if (arg && arg == "luo")
	{		
		this_player()->move(__DIR__"wananta");
		this_player()->remove_listen_to_die(this_object());
		call_out("give_reward",1,this_player());
		return 1;
	} 
	return notify_fail("敲什么敲？\n");
}



int give_reward(object me)
{
    string msg;
	int reward, i, cost_time;
	object tasknpc;

	string system_msg = me->query("name")+"在万安塔任务中获得奖励";
	string channel_msg = me->query("name")+"在万安塔任务中闯过"+sprintf("%d",query("room_lvl"))+"关，被奖励";

    if(!objectp(me)) return 1;	
	
	tasknpc = new(__DIR__"npc/luzhangke");
	write(HIW"你被奖励了：\n");
	
	write("\t"+chinese_number(me->query_temp("wananta/reward_re"))+"点江湖声望。\n");
	system_msg += me->query_temp("wananta/reward_re")+"点江湖声望";
	channel_msg += chinese_number(me->query_temp("wananta/reward_re"))+"点江湖声望";
	
	//me->add("repute", me->query_temp("wananta/reward_re"));

	
	write("\t"+chinese_number(me->query_temp("wananta/reward_qn"))+"点潜能；\n");
	system_msg += me->query_temp("wananta/reward_qn")+"点潜能，";
	channel_msg += chinese_number(me->query_temp("wananta/reward_qn"))+"点潜能、";
	
	//me->add("potential", me->query_temp("wananta/reward_qn"));

	

	write("\t"+chinese_number(me->query_temp("wananta/reward_exp"))+"点经验；\n");
	system_msg += me->query_temp("wananta/reward_exp")+"点经验";
	channel_msg += chinese_number(me->query_temp("wananta/reward_exp"))+"点经验";
	
	//me->add("combat_exp", me->query_temp("wananta/reward_exp"));

	if (lvl>3)
	{
		write(HIC"你的「"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"))+"」进步了！\n"NOR);
		system_msg += "，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+me->query_temp("wanansi/reward_skill");
		channel_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"));
	//me->set_skill(me->query_temp("wanansi/reward_skill"), me->query_skill(me->query_temp("wanansi/reward_skill"), 1)+me->query_temp("wanansi/reward_count"));
	
	}
	
	
	channel_msg += "！\n";
	CHANNEL_D->do_channel(tasknpc, "chat", channel_msg);

		
	
	channel_msg += "！\n";
	
	CHANNEL_D->do_channel(tasknpc, "chat", channel_msg);

	system_msg += "。";
    	
	CHANNEL_D->do_channel(tasknpc, "sys_misc", system_msg);
	
	destruct(tasknpc);
	
	me->delete_temp("wananta");
	
	write("测试阶段，奖励没有实际加给你。谢谢！\n");
	
	return 1;
}

int valid_leave(object me, string dir)
{
    int i;
    object *ob;

    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( ob[i]->query("id") == "fanbang wushi" && ob[i]->query("uni_target") == me)
            return notify_fail("武士漠然挡住了你：生死未判，就想走么？\n");
    }
    me->remove_listen_to_die(this_object());
    return ::valid_leave(me, dir);
}

int do_look(string dir)
{
	if(dir == "up")
	{
		write("塔内光线不甚明亮，你运足了目力也看不清楼上的情况。\n");
		return 1;
	}
	return 0;
}