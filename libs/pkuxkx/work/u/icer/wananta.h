//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
#include <room.h>
inherit ROOM;
int lvl;
int do_qiao(string);
int give_reward(object me);
int do_look(string dir);

void init()
{	
	object me=this_player();
    object ob,room,tasknpc1;
	object *tasknpc;

    int target_num;
	lvl = query("room_lvl");
	room=this_object();
	

  if ( !userp(me) && me->query("id")!="fanbang wushi" && me->query("id") !="body guard" )
  {
      me->move("/d/luoyang/wananta");
	  return;
  }
  //到这里结束

  if(wizardp(me) && me->query("env/no_fanseng")) return;

  tasknpc1 = new("/d/luoyang/npc/hebiweng");
	if (lvl==1 && me->query("id") != "fanbang wushi" && me->query("id") != "body guard" )
	{
		 CHANNEL_D->do_channel(tasknpc1, "baowei", me->query("name")+"开始闯塔。\n");
	}
	if (lvl>1 && me->query("id") != "fanbang wushi" && me->query("id") != "body guard")
	{
		CHANNEL_D->do_channel(tasknpc1, "baowei", me->query("name")+"到达第"+chinese_number(lvl)+"层.\n");
	}
	//************************************ modified by icer
  //数据统计
  COMBAT_D->add("task_stat/wat/"+ lvl + "/times",1);
	//*****************************************************
	if (lvl<4)
	{
		target_num=1;
	}
	
	if (lvl==4)
	{
		if (random(lvl)==0)
		{

			target_num=1;
		}
		else
		{
			target_num = lvl-3+random(lvl-2);			
		}
		me->set_temp("wanansi/fscount",target_num);
	}
	
	if (lvl>4)
	{
		if (me->query_temp("wanansi/fscount")==1)
		{
			if (random(lvl-1)==0)
			{
				target_num=1;
			}
			else
			{
				target_num = lvl-3+random(lvl-2);
			}						
		}		
		else if(random(lvl)==0)
		{
			target_num=1;
		}
		else
		{
			target_num = lvl-3+random(lvl-2);
			me->set_temp("wanansi/fscount",target_num);
		}
	}
    
    if(!me->query_temp(sprintf("wanansi/%d",lvl)) && interactive(me))
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
		me->set_temp(sprintf("wanansi/%d",lvl),1);
		me->set_temp("wananta/lvl",lvl);
    }
   
        
	add_action("do_qiao","qiao");       //敲锣
	add_action("do_jiangli","jiangli");   
	add_action("do_look","look");
    set("real_dark",1);
    //测试期间假死
    set("no_die",1);
	set("no_sleep_room",1);
    set("least_msg",1);
    this_player()->listen_to_die(this_object());
}

//************************************ modified by icer
//任务统计数据查看函数，可以放在luzhangke或者其他npc代码，直接call查看，不应放在这里，需include <ansi.h>
//*****************************************************
void task_stat()
{
	int levels = 7;
	string result;
	int i;
	
	result = "自上次更新combatd之后，万安塔任务数据统计如下：\n" 
	for (i=1;i<=levels;i++)
	{
		result += HIW+"第" + chinese_number(i) + "层：\n" +NOR;
		result += "进入：" + COMBAT_D->query("task_stat/wat/"+i+"/times") + "人次\n";
		result += "死亡：" + COMBAT_D->query("task_stat/wat/"+i+"/penalty/times")+"人次\n";
		result += "惩罚经验：" + COMBAT_D->query("task_stat/wat/"+i+"/penalty/exp")+"，潜能：" + COMBAT_D->query("task_stat/wat/"+i+"/penalty/potential")+"，声望：" + COMBAT_D->query("task_stat/wat/"+i+"/penalty/reputy")+"\n";
		//以下统计尚未实现
		result += "奖励经验：" + COMBAT_D->query("task_stat/wat/"+i+"/reward/exp")+"，潜能：" + COMBAT_D->query("task_stat/wat/"+i+"/reward/potential")+"，声望：" + COMBAT_D->query("task_stat/wat/"+i+"/reward/reputy")+"\n";
	}
	write(result);
	return;
}

//当有玩家在此死亡时调用
int die_notify(object victim)
{
    object* obs;
	string system_msg;
	object tasknpc;
	
	//********************************** modified by icer
	int re,qn,exp;
	//***************************************************
	
	tasknpc = new("/d/luoyang/npc/luzhangke");
    if(userp(victim))
    {

		//********************************** modified by icer
		if (query("room_lvl")>1 && query("room_lvl")<6)
		{
			re = victim->query_temp("wanansi/reward_re2");
			qn = victim->query_temp("wanansi/reward_qn2");
			exp = victim->query_temp("wanansi/reward_exp2");
		} else if (query("room_lvl")>5)
		{
			re = victim->query_temp("wanansi/reward_re2")/5*2;
			qn = victim->query_temp("wanansi/reward_qn2")/5*2;
			exp = victim->query_temp("wanansi/reward_exp2")/5*2;
		}
			victim->add("repute", 0-re);
			victim->add("potential",0-qn);
			victim->add("combat_exp", 0-exp);
			system_msg = victim->query("name")+"在万安塔任务中损失";
			system_msg += victim->query_temp("wanansi/reward_re2")+"点江湖声望、";
			system_msg += victim->query_temp("wanansi/reward_qn2")+"点潜能，";
			system_msg += victim->query_temp("wanansi/reward_exp2")+"点经验";
			system_msg += "。";  	
			CHANNEL_D->do_channel(tasknpc, "sys", system_msg);
		  //数据统计
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/reputy",re);
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/potential",qn);
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/exp",exp);
	  	COMBAT_D->add("task_stat/wat/"+ query("room_lvl") + "/penalty/times",1);
		
		//***************************************************
		
		

        victim->delete_temp("wanansi");
        victim->set_temp("death_msg","在万安塔第"+chinese_number(lvl)+"层力战而");        
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
		jiangli_msg += chinese_number(me->query_temp("wanansi/reward_re"))+"点江湖声望";
		jiangli_msg += chinese_number(me->query_temp("wanansi/reward_qn"))+"点潜能、";
		jiangli_msg += chinese_number(me->query_temp("wanansi/reward_exp"))+"点经验";
		if (lvl>3)
		{
			jiangli_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级功夫";
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
	int i;
    object *ob;
	object me=this_player();
    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if( ob[i]->query("id") == "fanbang wushi" && ob[i]->query("uni_target") == me)
            return notify_fail("战斗还没完呢，瞎敲什么！！\n\n");
    }

	if (arg && arg == "luo")
	{		
		this_player()->move("/d/luoyang/wananta");
		this_player()->remove_listen_to_die(this_object());
		me->add("wananta/start",-(lvl-1)*120);        //每过一层，冷却时间减少两分钟
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
	object box;
	
	
	string system_msg = me->query("name")+"在万安塔任务中获得奖励";
	string channel_msg = me->query("name")+"在万安塔任务中闯过"+sprintf("%d",query("room_lvl"))+"关，被奖励";

	box=new("/d/wananta/npc/obj/box");

	if (me->query_temp("wananta/lvl")>3)
	{
		box->move(me);
		write(CYN"鹿杖客说道：阁下武艺不凡，我家郡主特赠厚礼，请笑纳！\n"NOR);
		write(CYN"鹿杖客给你一个宝盒。\n"NOR);
	}
    if(!objectp(me)) return 1;	
	
	tasknpc = new("/d/luoyang/npc/luzhangke");
	write(HIW"你被奖励了：\n");
	
	write("\t"+chinese_number(me->query_temp("wanansi/reward_re"))+"点江湖声望。\n");
	system_msg += me->query_temp("wanansi/reward_re")+"点江湖声望、";
	channel_msg += chinese_number(me->query_temp("wanansi/reward_re"))+"点江湖声望、";
	
	me->add("repute", me->query_temp("wanansi/reward_re"));

	
	write("\t"+chinese_number(me->query_temp("wanansi/reward_qn"))+"点潜能；\n");
	system_msg += me->query_temp("wanansi/reward_qn")+"点潜能，";
	channel_msg += chinese_number(me->query_temp("wanansi/reward_qn"))+"点潜能、";
	
	me->add("potential", me->query_temp("wanansi/reward_qn"));

	

	write("\t"+chinese_number(me->query_temp("wanansi/reward_exp"))+"点经验；\n");
	system_msg += me->query_temp("wanansi/reward_exp")+"点经验";
	channel_msg += chinese_number(me->query_temp("wanansi/reward_exp"))+"点经验";
	
	me->add("combat_exp", me->query_temp("wanansi/reward_exp"));

	if (lvl==4 && random(20)>18)
	{
		write(HIC"你的「"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"))+"」进步了！\n"NOR);
		system_msg += "，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+me->query_temp("wanansi/reward_skill");
		channel_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"));
		me->set_skill(me->query_temp("wanansi/reward_skill"), me->query_skill(me->query_temp("wanansi/reward_skill"), 1)+me->query_temp("wanansi/reward_count"));
	
	}

	if (lvl==5 && random(15)>13)
	{
		write(HIC"你的「"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"))+"」进步了！\n"NOR);
		system_msg += "，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+me->query_temp("wanansi/reward_skill");
		channel_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"));
		me->set_skill(me->query_temp("wanansi/reward_skill"), me->query_skill(me->query_temp("wanansi/reward_skill"), 1)+me->query_temp("wanansi/reward_count"));
	
	}

	if (lvl > 5 )
	{
		write(HIC"你的「"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"))+"」进步了！\n"NOR);
		system_msg += "，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+me->query_temp("wanansi/reward_skill");
		channel_msg +="，"+chinese_number(me->query_temp("wanansi/reward_count"))+"级"+CHINESE_D->chinese(me->query_temp("wanansi/reward_skill"));
		me->set_skill(me->query_temp("wanansi/reward_skill"), me->query_skill(me->query_temp("wanansi/reward_skill"), 1)+me->query_temp("wanansi/reward_count"));
	
	}
	
	
	channel_msg += "！\n";
	
	CHANNEL_D->do_channel(tasknpc, "chat", channel_msg);

	system_msg += "。";
    	
	CHANNEL_D->do_channel(tasknpc, "sys", system_msg);
	
	destruct(tasknpc);
	
	me->delete_temp("wanansi");
	
//	write("测试阶段，奖励没有实际加给你。谢谢！\n");
	
	return 1;
}

int valid_leave(object me, string dir)
{
    int i;
    object *ob;

	if(!userp(me)) return notify_fail("恪守职守，不得乱走！\n");

    ob = all_inventory( environment( me ));
    for(i=0; i<sizeof(ob); i++) 
    {
        if(!ob[i]->is_character() && !ob[i]->query_temp("seeme"))
        {
            destruct(ob[i]);
            continue;
        }
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
		write("两层间并无空隙，你无法看到上面一层的情况。\n");
		return 1;
	}
	return 0;
}
