void biwu_over()
{
    biwu_stop(0);
	log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 比武时间到biwu_over"NOR,this_object()->query("name"),this_object()->query("id")),this_object());
	return;
}
int cancel(string arg)
{
	object me;
	me = this_player();
	if(!me->query_temp("quest/bwzh/can_marry")) return 0;
	if(!me->query_temp("quest/bwzh/hoster")) return 0;
	if(arg)	return 0;
	if(query("station")<2 ||query("station")>=6) return 0;
	log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 主动取消比赛biwu_over"NOR,me->query("name"),me->query("id")),me);
    biwu_stop(1);
	return 1;
}
void biwu_stop(int i)
//0 biwu_over 1 cancel
{
	object me,ob,winner_player,challenge_player,room;
	object *ob_list;
	int p;

	ob= this_object();
	remove_call_out("biwu_over");
	remove_call_out("checking");
	if(query("station")<2 && i==0)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 程序运行错误biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(query("station")>=6 && i==0)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 程序运行修正biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/host_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 丢失美女数据biwu_over"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/winner_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 丢失擂主数据biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if (!(room = find_object(query("leitai"))))
		room = load_object(query("leitai"));
	if(!room)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 缺少更新文件biwu_stop"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
    
	room->remove_call_out("start_biwu");//中止比赛
	ob_list = filter_array(children(BIWU_USER), (: clonep :));
	for(p=0; p<sizeof(ob_list); p++) 
	{
		log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 比武招亲中止biwu_stop"NOR,ob_list[p]->query("name"),ob_list[p]->query("id")),ob_list[p]);
		ob_list[p]->quit(ob_list[p]);
	}
	me=ob->query("bwzh/host_player/object");//美女
	if(me) 
	{
		me->delete_temp("apply/short");  
 		if(i) tell_object(me,HIR"招亲活动比武被强行中止！\n"NOR);
		else tell_object(me,HIR"时间到，招亲活动比武部分中止！\n"NOR);		
	}
	winner_player=ob->query("bwzh/winner_player/object");
	if(winner_player)
	{
 		if(i) tell_object(winner_player,HIR"招亲活动比武被强行中止！\n"NOR);
		else tell_object(winner_player,HIR"时间到，招亲活动比武部分中止！\n"NOR);
	}
	challenge_player=ob->query("bwzh/challenge_player/object");
	if(challenge_player)
	{
		if(i) tell_object(challenge_player,HIR"招亲活动比武被强行中止！\n"NOR);
		else tell_object(challenge_player,HIR"时间到，招亲活动比武部分中止！\n"NOR);
		challenge_player->delete_temp("quest/bwzh");
		challenge_player->delete_temp("quest/quest");
		challenge_player->delete_temp("apply/short");
	}
	
	over_time=time();
	set("station",0);

	if(!me || !me->query_temp("quest/bwzh/hoster"))
	{
		command("bite");
		command("say "+ob->query("bwzh/host_player/name")+"可能离开了。看来比赛只能中止了。");
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"因为"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")离开现场，比武招亲被迫取消！"NOR);
		command("chat* shrug");
		if(!me)
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 美女不在连线biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		else 
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 美女离开现场biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		init_over();
		return;
	}

	if(!winner_player || !winner_player->query_temp("quest/bwzh/biwu_host"))
	{
		command("chat* hmm");
		if(i)
			CHANNEL_D->do_channel(this_object(),"chat",HIY+""+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")的比武招亲活动被强行中止！"NOR);
		else
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"因为时间关系，"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")比武招亲活动中止！"NOR);
		if(winner_player)
		{
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"最终比武胜利者："+winner_player->query("name")+RANK_D->query_respect(winner_player)+"！"NOR);
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"但是，"+winner_player->query("name")+RANK_D->query_respect(winner_player)+"目前不在现场，招亲取消！"NOR);
		}
		if(winner_player) log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 擂主不在现场biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		else log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 缺少擂主信息biwu_stop"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		init_over();  
		command("say 时间到，看来现在游戏中无人对你有意了。");
		command("poor "+me->query("id"));
		return;
	}

	if(winner_player==me|| me->query_temp("quest/bwzh/biwu_host"))
	{
		if(!ob->query("bwzh/bwzh/fail_player") && !ob->query("bwzh/challenge_player"))
		{
			if(i) command("say 看来现在游戏中无人对你有意了。"); 
			else command("say 时间到，看来现在游戏中无人对你有意了。");
			command("poor "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 无挑战者失败biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		else if(!ob->query("bwzh/bwzh/fail_player") && ob->query("bwzh/challenge_player"))
		{
			if(i) command("say 只可惜挑战的人迟迟未敢上台。"); 
			else command("say 时间到，只可惜挑战的人迟迟未敢上台。");
			command("shrug "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 挑战者懦弱中biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		else if(ob->query("bwzh/bwzh/fail_player") && !ob->query("bwzh/challenge_player"))
		{
			if(i) command("say 看来寻找一个武功高强的有情郎还是很难的。"); 
			else command("say 时间到，看来寻找一个武功高强的有情郎还是很难的。");
			command("addoil "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 太厉害，失败biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		else
		{
			if(i) command("say 看来寻找一个武功高强的有情郎还是很难的。"); 
			else command("say 时间到，看来寻找一个武功高强的有情郎还是很难的。");
			command("addoil "+me->query("id"));
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 。。。。。。biwu_stop",ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		}
		if(i)
			CHANNEL_D->do_channel(this_object(),"chat",HIY+""+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")的比武招亲活动被强行中止！"NOR);
		else
			CHANNEL_D->do_channel(this_object(),"chat",HIY+"因为时间关系，"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")比武招亲活动中止！"NOR);
		command("chat* shrug");
		init_over();  
		return;
	}
	
	winner_player->delete_temp("apply/short");  
	message_vision(HIY"\n$n对着娇羞懵懂的$N作了个揖。\n"NOR,me,winner_player);
	message_vision(CYN"$n说道：「在下卤莽承让，对姑娘仰慕之情是真，并不敢倚强而逞，望姑娘勿要介意」\n\n"NOR,me,winner_player);
	command("pat "+me->query("id"));	
	command("pat "+getuid(winner_player));	
	command("say 时间到，目前应招者最优秀的当属"+winner_player->query("name")+RANK_D->query_respect(winner_player)+"。");
	if(i)
		CHANNEL_D->do_channel(this_object(),"chat",HIY+""+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")的比武招亲活动被强行中止！"NOR);
	else
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"因为时间关系，"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")比武招亲活动中止！"NOR);
	CHANNEL_D->do_channel(this_object(),"chat",HIY+"最终比武胜利者："+winner_player->query("name")+RANK_D->query_respect(winner_player)+"！"NOR);
	command("chat* addoil "+winner_player->query("id"));
	
	winner_player->set_temp("apply/short", ({winner_player->name()+"("+winner_player->query("id")+")"YEL" <成亲中> "NOR}));
	me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <成亲中> "NOR}));
	
	me->set_temp("quest/bwzh/over",1);
	winner_player->set_temp("quest/bwzh/over",1);
	
	remove_call_out("zhaoqin");
	call_out("zhaoqin",6,me,winner_player);
	set("station",6);
	over_time=time();
	return;    
}