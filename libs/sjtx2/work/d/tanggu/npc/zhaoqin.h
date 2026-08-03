void zhaoqin(object me,object who)
{
	object ob=this_object();
	remove_call_out("zhaoqin");
	if(!me || !me->query_temp("quest/bwzh/over"))
	{
		if(!me) log_file("quest/zhaoqin",sprintf("%-8s%-10s 美女信息丢失zhaoqin",ob->query("name"),ob->query("id")),ob);
		else log_file("quest/zhaoqin",sprintf("%-8s%-10s 美女标记丢失zhaoqin",ob->query("name"),ob->query("id")),ob);
		init_over();
		return;	
	}
	if(!who || !who->query_temp("quest/bwzh/over")) 
	{
		if(!who) log_file("quest/zhaoqin",sprintf("%-8s%-10s 擂主信息丢失zhaoqin",ob->query("name"),ob->query("id")),ob);
		else log_file("quest/zhaoqin",sprintf("%-8s%-10s 擂主标记丢失zhaoqin",ob->query("name"),ob->query("id")),ob);
		init_over();
		return;	
	}

	if(environment(me)!=environment(ob))
	{
		command("chat* angry "+me->query("id"));	
        command("chat "+HIY+me->query("name")+"就算是不甚满意对方，怎能说走就走？终身大事，如此轻薄！"NOR);
		if(environment(who)==environment(ob))
			command("shrug "+getuid(who));	
		tell_object(who,"因为"+me->query("name")+"过早离开，招亲被迫中止！\n");
		tell_object(me,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。\n");
		me->add("combat_exp",-100000);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 损失十万经验zhaoqin",me->query("name"),me->query("id")),me);
		init_over();
		return;
	}
	if(environment(who)!=environment(ob))
	{
        command("chat "+HIY+who->query("name")+"既不愿娶她，干么下场比武？终身大事，如此轻薄！"NOR);
		command("chat* heng");
		command("chat* poor "+me->query("id"));	
		tell_object(who,"因为"+who->query("name")+"过早离开，招亲被迫中止！\n");

		tell_object(who,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。");
		who->add("combat_exp",-100000);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 损失十万经验zhaoqin",who->query("name"),who->query("id")),who);
		init_over();
		return;
	}
	command("smile "+getuid(ob));	
	command("smile "+me->query("id"));
	command("say 佳人配英雄，二位郎才女貌，天作之合，"+me->query("name")+"妹妹你还发什么呆啊，你比武都输了，可愿意嫁给"+who->query("name")+"么？");
	tell_object(who,HIY"你可以回答 answer y 或者 answer n 表示你同意或者拒绝这门婚事！\n"NOR);
	who->set_temp("quest/bwzh/marry_object",me);
	tell_object(me,HIY"你可以回答 answer y 或者 answer n 表示你同意或者拒绝这门婚事！\n"NOR);
	me->set_temp("quest/bwzh/marry_object",who);
	remove_call_out("answer_check");
	call_out("answer_check",10,me,who,0);
	return;
}
void answer_check(object me,object who,int i)
{
	object ob=this_object();
	int p;
	remove_call_out("answer_check");
	if(!me || !me->query_temp("quest/bwzh/over") || environment(me)!=environment(ob))
	{
        command("chat* hmm");
        command("chat "+HIY+"如何大家对待婚姻如此轻浮？就算是不甚满意对方，怎能说走就走？"NOR);
		if(me)
		{
			tell_object(me,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。\n");
			me->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 损失十万经验answer_check",me->query("name"),me->query("id")),me);
		}
		init_over();
		return;	
	}
	if(!who || !who->query_temp("quest/bwzh/over") || environment(who)!=environment(ob))
	{
        command("chat* hmm");
        command("chat "+HIY+"如何大家对待婚姻如此轻浮？就算是不甚满意对方，怎能说走就走？"NOR);
		if(who)
		{
			tell_object(who,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。\n");
			who->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 损失十万经验answer_check",who->query("name"),who->query("id")),who);
		}
		init_over();
		return;	
	}
	if(i>=9)
	{
		if(!who->query_temp("quest/bwzh/marry_yes"))
		{
			tell_object(who,HIY"这么长时间还没有决定。按取消算。\n"NOR);
			tell_object(who,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。\n");
			who->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 损失十万经验answer_check",who->query("name"),who->query("id")),who);
		}
		if(!me->query_temp("quest/bwzh/marry_yes"))
		{
			tell_object(me,HIY"这么长时间还没有决定。按取消算。\n"NOR);
			tell_object(me,"你因为在「比武招亲」中出尔反尔，而被扣除了十万点经验。\n");
			me->add("combat_exp",-100000);
			log_file("quest/zhaoqin",sprintf("%-8s%-10s 损失十万经验answer_check",me->query("name"),me->query("id")),me);
		}
        command("chat* hmm "+who->query("id"));
        command("chat* hmm "+me->query("id"));
        command("chat "+HIY+"如何大家对待婚姻如此轻浮？这等大事，竟然迟迟不做回应！"NOR);
		init_over();
		return;	
	}
	i=i+1;
	p=100-i*10;
	command("smile "+getuid(ob));	
	command("smile "+me->query("id"));
	tell_object(me,HIC"你还有"+chinese_number(p)+"秒决定。\n"NOR);
	tell_object(who,HIC"你还有"+chinese_number(p)+"秒决定。\n"NOR);
	call_out("answer_check",10,me,who,i);
	return;
}