int yingzhao(string arg)
{
	object me,ob,winner_player,host_player,room;
	me = this_player();
	ob = this_object();
	if(!me->query_temp("quest/bwzh/can_yingzhao")) return 0;
	if(arg)	return 0;
	if(query("station")!=5 && query("station")!=2 )
	{
		message_vision(HIY"\n$N故意摆了个造型，潇洒一笑，拨开人群，喝道：「我来应招」，腾身跃上了擂台。\n\n"NOR,me);
		command("? "+me->query("id"));
		message_vision(HIY"$n将$N拦了下来，惊奇地看着你：「你这是干什么啊？」。\n"NOR,me,ob);
		if(!query("station"))
			command("whisper "+me->query("id")+" "+HIR"目前没有人在比武招亲。你可以（Look qi）获得相关信息。"NOR);	
		else if(query("station")==1)
			command("whisper "+me->query("id")+" "+HIR""+query("bwzh/host_player/name")+"正在设置招亲要求。你稍候再应招。"NOR);	
		else if(query("station")==6)
			command("whisper "+me->query("id")+" "+HIR"比武已经结束。");
		else command("whisper "+me->query("id")+" "+HIR"已经有人正在比武应招，你稍微再应招。"NOR);
		return 1;
	}
	message_vision(HIY"\n$N上下打量那招亲的女子两眼，微微一笑，拨开人群，喝道：「我来应招」，腾身跃上了擂台。\n\n"NOR,me);
    if(check_player(me,1)) return 1;

	winner_player=ob->query("bwzh/winner_player/object");  
	host_player=ob->query("bwzh/host_player/object");   

	if(!winner_player||!host_player || environment(winner_player)!=environment(ob)||environment(host_player)!=environment(ob))
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("whisper "+me->query("id")+" "+HIR"目前比武还未开始，你稍后再来应招。"NOR);	
		command("shrug "+me->query("id"));	
		if(!winner_player||!host_player) 
			log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 缺少数据信息yingzhao"NOR,me->query("name"),me->query("id")),me);
		else log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 擂主美女不在yingzhao"NOR,me->query("name"),me->query("id")),me);
		return 1;
	}
	if((ob->query("bwzh/per")>me->query("per"))
		||(ob->query("bwzh/exp")>me->query("combat_exp"))
		||((host_player->query("age")-ob->query("bwzh/age"))>me->query("age"))
		||((host_player->query("age")+ob->query("bwzh/age"))<me->query("age")))
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		if(ob->query("bwzh/per")>me->query("per"))
			command("whisper "+me->query("id")+" "+HIR"你相貌平平，不符合要求。"NOR);	
		else if(ob->query("bwzh/exp")>me->query("combat_exp"))
			command("whisper "+me->query("id")+" "+HIR"你经验太低，不符合要求。"NOR);
		else if((host_player->query("age")-ob->query("bwzh/age"))>me->query("age"))
			command("whisper "+me->query("id")+" "+HIR"你年龄太低，不符合要求。"NOR);
		else command("whisper "+me->query("id")+" "+HIR"你年龄太大，不符合要求。"NOR);
		command("shrug "+me->query("id"));	
		return 1;
	}
	if(winner_player==me)
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("whisper "+me->query("id")+" "+HIR"你现在是擂主哦。"NOR);	
		command("shrug "+me->query("id"));	
		return 1;
	}

	command("addoil "+me->query("id"));
	ob->set("bwzh/challenge_player/id",me->query("id"));
	ob->set("bwzh/challenge_player/name",me->query("name"));
	ob->set("bwzh/challenge_player/object",me);

	me->set_temp("quest/bwzh/biwu_challenge",1);//挑战者的标记
	me->set_temp("quest/busy",1);//不能作任务

	log_file("quest/zhaoqin",sprintf("%-8s%-10s 开始比武应招yingzhao",me->query("name"),me->query("id")),me);

	if (!(room = find_object(query("leitai"))))
		room = load_object(query("leitai"));
    
	if( !room ) 
	{
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 缺少擂台文件yingzhao",me->query("name"),me->query("id")),me);
		init_over();
        return notify_fail("比武擂台没有准备好，请通知巫师。\n");  
	}
	if(ob->query("bwzh/winner_player/id")==ob->query("bwzh/host_player/id"))
		set("station",3);
	else set("station",4);

	winner_player->set_temp("quest/bwzh/leitai",1);
	me->set_temp("quest/bwzh/leitai",1);
	
	host_player->set_temp("apply/short", ({host_player->name()+"("+host_player->query("id")+")"YEL" <比武招亲中> "NOR}));
	winner_player->set_temp("apply/short", ({winner_player->name()+"("+winner_player->query("id")+")"YEL" <比武招亲中（擂主）> "NOR}));
	me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <比武招亲中（挑战者）> "NOR}));
    
	room->load_user(winner_player);//擂主进入
	room->load_user(me);//挑战者进入
	
	remove_call_out("checking");
	call_out("checking",1);
	return 1;
}