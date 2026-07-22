void choose_ok(string arg, object me)
{
	int i,p;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh "+me->query("id"));
		command("say 只是如此羞涩，哪里有江湖儿女的洒脱。也罢，我将这旗上的名字擦去。");
		message_vision(HIY"\n$N走上前去，将锦旗上书写的名字擦去。\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 取消比武招亲choose_ok",me->query("name"),me->query("id")),me);
		return;
	}
	if(arg == "R" || arg == "r" ) 
	{
	   command("nod "+me->query("id"));
	   delete("bwzh/exp");
	   delete("bwzh/per");
	   delete("bwzh/age");
	   tell_object(me,HIW"\n原来设置全部消除，你可以重新设置：\n\n"NOR);
	   if(!query("bwzh/exp")) tell_object(me,WHT"  1、【经验】"NOR);
	   if(!query("bwzh/per")) tell_object(me,WHT"  2、【相貌】"NOR);
	   if(!query("bwzh/age")) tell_object(me,WHT"  3、【年龄】"NOR); 
	   tell_object(me,HIW"\n\n你可以选择数字，你也可以Q键取消。\n"NOR);
       input_to( (: choose_mode :), me );
	   return;
	}
	i=me->query("age")-query("bwzh/age");
	if(i<18) i=18;
	p=me->query("age")+query("bwzh/age");
	if(p>80) p=80;

	if(arg != "Y" && arg != "y" ) 
	{
		command("? "+me->query("id"));
		tell_object(me,HIW"\n你现在心目中的夫君的要求设置如下：\n\n"NOR);
		tell_object(me,HIR"  1、【经验】最低经验"+chinese_number(query("bwzh/exp"))+"兆。\n"NOR);
		tell_object(me,HIR"  2、【相貌】最低相貌"+chinese_number(query("bwzh/per"))+"。\n"NOR);
		tell_object(me,HIR"  3、【年龄】在"+chinese_number(i)+"岁和"+chinese_number(p)+"岁之间。\n"NOR); 
		tell_object(me,HIW"\n如果你同意，可以选择：\n"NOR);
		tell_object(me,WHT"（Y）同意 （R）重选 （Q）取消\n"NOR);
		input_to( (: choose_ok :), me );
		return;
	}
    log_file("quest/zhaoqin",sprintf("%-8s%-10s 招亲设置完毕choose_ok",me->query("name"),me->query("id")),me);

	over_time=time();//嘿嘿
	start_time=time();
	set("bwzh/host_player/name",me->query("name"));//美女信息
	set("bwzh/host_player/id",me->query("id"));
	set("bwzh/host_player/object",me);
	set("bwzh/winner_player/name",me->query("name"));//擂主是美女
	set("bwzh/winner_player/id",me->query("id"));
	set("bwzh/winner_player/object",me);
	set("station",2);//下一个状态
	me->set_temp("quest/bwzh/biwu_host",1);//擂主的标记
	me->set_temp("quest/bwzh/hoster",1);//发起人的标记，美女标记
	me->set_temp("quest/busy",1);//不能作任务
	me->set_temp("apply/short", ({me->name()+"("+me->query("id")+")"YEL" <比武招亲中（擂主）> "NOR}));	
	
	message_vision(HIR"\n$N在锦旗旁边注明几条要求，包括【经验】、【相貌】、【年龄】。\n"NOR,me);
	command("pat "+me->query("id"));
	command("addoil "+me->query("id"));

	command("chat* smile "+me->query("id"));
	CHANNEL_D->do_channel(this_object(),"chat",HIY+me->query("name")+"正在比武招亲，欢迎各路豪杰可踊跃报名。"NOR);
	command("chat* addoil");

	tell_object(me,HIW"\n你现在开始等待。注意第一届擂主是你本人。另外，你可以取消（cancel）招亲，\n也可以让穆念慈帮你多次发布消息（fabu xiaoxi）。\n"NOR);
	remove_call_out("biwu_over");
	remove_call_out("checking");
	call_out("checking",1);
	call_out("biwu_over",NEXT_TIME);
  	return;
}
