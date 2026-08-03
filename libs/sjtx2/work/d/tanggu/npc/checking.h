void checking()//检查美女和擂主是否在场
{ 
	object me,ob,winner_player,challenge_player,room;
	object *ob_list;
	int i;

	ob= this_object();
	remove_call_out("checking");
	if(query("station")<2)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 程序运行错误checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/host_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 丢失美女数据checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(!ob->query("bwzh/winner_player"))
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 丢失擂主数据checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if (!(room = find_object(query("leitai"))))
		room = load_object(query("leitai"));
	if(!room)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 缺少更新文件checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}
	if(query("station")>=6)
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s 程序运行修正checking"NOR,ob->query("name"),ob->query("id")),ob);
		return;
	}

	me=ob->query("bwzh/host_player/object");//美女

	if(!me ||!me->query_temp("quest/bwzh/hoster"))//缺少美女
	{
		command("bite");
		command("say "+ob->query("bwzh/host_player/name")+"可能离开了。看来比赛只能中止了。");
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"因为"+ob->query("bwzh/host_player/name")+"("+capitalize(ob->query("bwzh/host_player/id"))+")离开现场，比武招亲被迫取消！"NOR);
		command("chat* shrug");
		if(!me) log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 美女不在连线checking"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
		else log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 美女离开现场checking"NOR,ob->query("bwzh/host_player/name"),ob->query("bwzh/host_player/id")),ob);
        
		ob_list = filter_array(children(BIWU_USER), (: clonep :));
		for(i=0; i<sizeof(ob_list); i++) 
		{
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 比武招亲中止checking"NOR,ob_list[i]->query("name"),ob_list[i]->query("id")),ob_list[i]);
			ob_list[i]->quit(ob_list[i]);
		}

		if(winner_player=ob->query("bwzh/winner_player/object"))
		{
			tell_object(winner_player,HIR""+ob->query("bwzh/host_player/name")+"竟然离开现场！招亲中止！\n"NOR);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 退出比武招亲checking",winner_player->query("name"),winner_player->query("id")),winner_player);
		}

		if(challenge_player=ob->query("bwzh/challenge_player/object"))
		{
			tell_object(challenge_player,HIR""+ob->query("bwzh/host_player/name")+"竟然离开现场！招亲中止！\n"NOR);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 退出比武招亲checking",challenge_player->query("name"),challenge_player->query("id")),challenge_player);
		}

		if(me)
		{
			tell_object(me,HIR"你因为在「比武招亲」中无故离开现场，而被扣除了十万点经验！\n"NOR);
			log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 损失十万经验checking"NOR,me->query("name"),me->query("id")),me);
			me->add("combat_exp",-100000);
		}
		init_over();
		return;
	}

	winner_player=ob->query("bwzh/winner_player/object");

	if(!winner_player || !winner_player->query_temp("quest/bwzh/biwu_host"))
	{
		command("smash");
		command("say "+ob->query("bwzh/winner_player/name")+"怎么离开这里了？看来擂主需要更换了。");
		CHANNEL_D->do_channel(this_object(),"chat",HIY+"因为"+ob->query("bwzh/winner_player/name")+"("+capitalize(ob->query("bwzh/winner_player/id"))+")的缺席，擂主资格取消！"+me->query("name")+"重新担任擂主！"NOR);
		command("chat* addoil "+me->query("id"));
		if(!winner_player) log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 离线擂主换人checking"NOR,ob->query("bwzh/winner_player/name"),ob->query("bwzh/winner_player/id")),ob);
		else log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 不在擂主换人checking"NOR,ob->query("bwzh/winner_player/name"),ob->query("bwzh/winner_player/id")),ob);
		
		ob_list = filter_array(children(BIWU_USER), (: clonep :));
		for(i=0; i<sizeof(ob_list); i++) 
		{
			tell_object(ob_list[i],HIR"擂主正在变化中。。。。。。！比赛暂时中止！\n"NOR);
			log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s 比武招亲中止checking"NOR,ob_list[i]->query("name"),ob_list[i]->query("id")),ob_list[i]);
			ob_list[i]->quit(ob_list[i]);
		}
        
		if(challenge_player=ob->query("bwzh/challenge_player/object"))
		{
			challenge_player->delete_temp("quest/bwzh");
			challenge_player->delete_temp("quest/busy");
			challenge_player->delete_temp("apply/short");  
			tell_object(challenge_player,HIR"通知："+ob->query("bwzh/winner_player/name")+"不再担任擂主，"+me->query("name")+"重新担任擂主！比赛继续！\n"NOR);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 通知更换擂主checking",challenge_player->query("name"),challenge_player->query("id")),challenge_player);
		}
		
		tell_object(me,HIR"通知："+ob->query("bwzh/winner_player/name")+"不再担任擂主，你重新担任擂主！比赛继续！\n"NOR);

		if(winner_player)
		{
			winner_player->delete_temp("quest/bwzh");
			winner_player->delete_temp("quest/busy");
			winner_player->delete_temp("apply/short");  
			tell_object(winner_player,HIR"你因为在「比武招亲」中无故离开，而被扣除了十万点经验！\n"NOR);
			log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 损失十万经验checking"NOR,winner_player->query("name"),winner_player->query("id")),winner_player);
			winner_player->add("combat_exp",-100000);
		}

		ob->set("bwzh/winner_player/name",me->query("name"));//更换擂主
		ob->set("bwzh/winner_player/id",me->query("id"));
		ob->set("bwzh/winner_player/object",me);

		me->set_temp("quest/bwzh/biwu_host",1);//擂主标志
		me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <比武招亲中（擂主）> "NOR}));
		ob->set("station",3);
		log_file("quest/zhaoqin",sprintf(HIY"%-8s%-10s 重新变成擂主checking"NOR,me->query("name"),me->query("id")),me);
	}
    call_out("checking",1);
}