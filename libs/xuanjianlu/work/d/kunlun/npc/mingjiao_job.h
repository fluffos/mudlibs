//Cracked by Kafei
// mingjiao job file
// modify by box 2003-12-10

#include <ansi.h>
#define BASE 100

string judge_jobmsg(object player,int flg)
{
	string s_msg,job_msg,job_flg;
	s_msg=player->query("mingjiao/job");
	
	switch (s_msg)
	{
		case "jin_caikuang":
			job_flg="采集铁矿";break;

		case "huo_zaoqiang":
			job_flg="打造火枪";break;

		case "mu_kanshu":
			job_flg="砍树";	break;
			
		case "shui_tiaoshui":
			job_flg="挑水"; break;
			
		case "tu_didao":
			job_flg="挖地道"; break;
			
		case "kill_npc_player":
			job_flg="铲除异己";break;
			
		case "yudi":
			job_flg="御敌";break;

//		default:
//			job_msg="这位"+RANK_D->query_respect(player)+"现在好象没有任务在身。";
//			return job_msg;
//			write("judge_jobmsg reached default! please report.\n");
	}
	
	if(flg)
		return job_flg;

	job_msg="这位"+RANK_D->query_respect(player)+"现在不是"+job_flg+"吗？等完成了再来领取其它任务吧。";
	return job_msg;
}

int cut_abandon_jl(string job_kind)
{
	int old_cc,cut_cc;
	old_cc=this_player()->query("mingjiao/credit");
	
	switch (job_kind)
	{
		case "采集铁矿":
			cut_cc=BASE+random(BASE*2)/2; break;
		case "打造火枪":
			cut_cc=BASE+random(BASE*3)/2; break;
		case "挑水":
			cut_cc=BASE+random(BASE*2)/2; break;
		case "挖地道":	
			cut_cc=BASE+random(BASE*3)/2; break;
		case "砍树":
			cut_cc=BASE+random(BASE*2)/2; break;
		case "铲除异己":
			cut_cc=2*BASE + random(BASE*2)/2; 
			this_player()->delete_temp("mjjob_over");
			break;			
		case "御敌":	
			cut_cc=4*BASE + random(BASE*3)/2;
			break;
	}

	if(cut_cc<old_cc)		
	{
		this_player()->add("mingjiao/credit",-cut_cc);
		tell_object(this_player(),RED"你的明教忠诚度下降了"+cut_cc+"点。\n"NOR);
	}
	else
	{
		tell_object(this_player(),HIB"你的明教忠诚度太低，不能再放弃"+job_kind+"的任务了。\n"NOR);
		return 0;
	}

	this_player()->delete("mingjiao/job");
	return 1;
}




string ask_abandon()
{
	object player, ob, npc, room;
	string job_flg, id, name;
	player=this_player();
        ob=present("tieyan ling", player);
        if(!objectp(ob))
                return "没有铁焰令，你完成任务，我也不知道该怎么奖赏你啊？\n";
	if(!player->query("mingjiao/job"))
		return "这位"+RANK_D->query_respect(player)+"现在好像没有任务在身。";

	job_flg=judge_jobmsg(player,1);

	switch (job_flg)
	{
		case "采集铁矿":
			id = "zhuang zheng"; name = "庄铮"; break;
		case "打造火枪":
			id = "xin ran"; name = "辛然"; break;
		case "挑水":
			id = "tang yang"; name = "唐洋"; break;
		case "挖地道":	
			id = "yan yuan"; name = "颜垣"; break;
		case "砍树":
			id = "wen cangsong"; name = "闻苍松"; break;
		case "铲除异己":
		case "御敌":
			id = "yang xiao"; name = "杨逍";break;
	}
	if(this_object()->query("id")==id && this_object()->query("name")==name)
	{
		if(cut_abandon_jl(job_flg))
		{
			if(job_flg=="御敌")
			{
                                ob->delete("mjjob_note");
                                
                                //防止放弃任务后还追杀玩家
                               	player->add_temp("yudijob",1);

				while(player->query("mingjiao/enemy")>0)
				{
					//清除没有杀掉的npc
					room=load_object(player->query("mingjiao/" + player->query("mingjiao/enemy"))+".lpc");
					if (objectp(room))
					{
						npc=present(player->query("mingjiao/npc"+player->query("mingjiao/enemy")), room);
						if(objectp(npc))
							npc->self_destruct();
					}	

					player->delete("mingjiao/" + player->query("mingjiao/enemy"));
					player->delete("mingjiao/npc"+ player->query("mingjiao/enemy"));
					player->add("mingjiao/enemy",-1);
				}
				player->delete("mingjiao/enemy");
				player->delete("mingjiao/killed");
				player->delete_temp("mjjob_over");
			}
			return "阁下连这种事情都办不好，将来如何光大我光明圣火教。";				
		}	
		else				
			return "阁下尽力完成这次任务吧。";
	}
	else
		return "既然这位"+RANK_D->query_respect(player)+"想放弃"+job_flg+"的任务，请去跟"+name+"旗主说一声。";

	return "ask_abandon() has error!";
}



void reward_dest(object me, object ob, string job_flg)
{
	int old_cc,add_cc,max_pot,old_pot,add_exp,add_pot;
	object tool, room, npc;
	old_cc=me->query("mingjiao/credit");
	old_pot=me->query("potential");

	switch(job_flg)
	{
		case "采集铁矿":
		        tool=present("tie chui",me );
			if (tool) destruct(tool);
			destruct(ob);
			add_cc=BASE+random(BASE*2)/2;
			add_exp=BASE+random(add_cc);
			add_pot=40+random(add_exp/4);
			break;
		case "打造火枪":
			destruct(ob);
			add_cc=BASE+random(BASE*3)/2;
			add_exp=BASE+random(add_cc);
			add_pot=40+random(add_exp/4);
			break;
		case "挑水":
			destruct(ob);	
			add_cc=BASE+random(BASE*3)/2;
			add_exp=BASE+random(add_cc);
			add_pot=40+random(add_exp/4);			
			break;
		case "挖地道":
			add_cc=BASE+random(BASE*3)/2;
			add_exp=BASE+random(add_cc);
			add_pot=40+random(add_exp/4);			
			break;
		case "砍树":
			destruct(ob);
			add_cc=BASE+random(BASE*3)/2;
			add_exp=BASE+random(add_cc);
			add_pot=40+random(add_exp/4);			
			break;
		case "铲除异己":
			if(!objectp(tool = present("tieyan ling", me)) )
				return;
			//notify_fail("这位"+RANK_D->query_respect(me)+"没有我教信物铁焰令，我如何记录奖赏过失？\n");
			
			add_cc=3*BASE+random(BASE*3)/2;
			add_exp=tool->query_temp("add_exp");
			tool->delete_temp("add_exp");
			tool->delete("mjjob_note");
			add_pot=100+random(add_exp/4);
		case "御敌":
			if(!objectp(tool = present("tieyan ling", me)) )
				return;
				
                        //防止放弃任务后还追杀玩家
                        me->add_temp("yudijob",1);
                        
			while(me->query("mingjiao/enemy")>0)
			{
				//清除没有杀掉的npc
				if(tool->query("mjjob_note/" + me->query("mingjiao/npc" + me->query("mingjiao/enemy")) + "/bonus")==0)
				{
					room=load_object(me->query("mingjiao/" + me->query("mingjiao/enemy"))+".lpc");
					if (objectp(room))
					{
						npc=present(me->query("mingjiao/npc"+me->query("mingjiao/enemy")), room);
						if(objectp(npc))
							npc->self_destruct();
					}
				}		
				
				me->delete("mingjiao/" + me->query("mingjiao/enemy"));
				me->delete("mingjiao/npc" + me->query("mingjiao/enemy"));
				me->add("mingjiao/enemy",-1);
			}
			
			tool->delete("mjjob_note");
			
			add_exp=tool->query_temp("add_exp");
			tool->delete_temp("add_exp");
			
                        if(add_exp<=1000)
                        	add_exp=1000+random(100);
                        	
			add_cc=add_exp/2+random(BASE*3)/2;
			add_pot=BASE+random(add_exp/4);
			me->delete("mingjiao/killed");
			me->delete("mingjiao/enemy");
			me->delete_temp("mjjob_over");
	}			

	me->delete("mingjiao/job");

	me->add("mingjiao/credit",add_cc);
	me->add("combat_exp",add_exp);
	me->add("potential",add_pot);
	if (me->query("potential") > (max_pot = me->query("max_potential")) )
		me->set("potential",max_pot);
	tell_object(me,HIG"恭喜！你的明教忠诚度上升了"+add_cc+"点。\n"NOR);
	tell_object(me,HIG"你的经验上升了"+add_exp+"点。\n"NOR);
	tell_object(me,HIG"你的潜能上升了"+(me->query("potential")-old_pot)+"点。\n"NOR);
}
