void choose_mode(string arg, object me)
{
	int i,p;
	if( arg == "Q" || arg == "q" )    
	{
		command("shrug");
		command("say 只是如此羞涩，哪里有江湖儿女的洒脱。也罢，我将这旗上的名字擦去。");
		message_vision(HIY"\n$N走上前去，将锦旗上书写的名字擦去。\n"NOR,this_object());
		command("nod "+me->query("id"));
		me->delete_temp("quest/bwzh");
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 取消比武招亲choose_mode",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/exp")
		&& query("bwzh/per")
		&& query("bwzh/age")) 
	{
		i=me->query("age")-query("bwzh/age");
		if(i<18) i=18;
		p=me->query("age")+query("bwzh/age");
		if(p>80) p=80;
		command("addoil "+me->query("id"));
	   tell_object(me,HIW"你现在心目中的夫君的要求设置如下：\n\n"NOR);
	   tell_object(me,HIR"  1、【经验】最低经验"+chinese_number(query("bwzh/exp"))+"兆。\n"NOR);
	   tell_object(me,HIR"  2、【相貌】最低相貌"+chinese_number(query("bwzh/per"))+"。\n"NOR);
	   tell_object(me,HIR"  3、【年龄】在"+chinese_number(i)+"岁和"+chinese_number(p)+"岁之间。\n"NOR); 
	   tell_object(me,HIW"\n如果你同意，可以选择：\n"NOR);
	   tell_object(me,WHT"（Y）同意 （R）重选 （Q）取消\n"NOR);
	   input_to( (: choose_ok :), me );
	   return;
	}
	if(arg != "1"  && arg != "2" && arg != "3") 
	{
	   command("? "+me->query("id"));
	   tell_object(me,HIW"你可以在旁边注明你心目中的夫君的部分要求：\n\n"NOR);
	   if(!query("bwzh/exp")) tell_object(me,WHT"  1、【经验】"NOR);
	   if(!query("bwzh/per")) tell_object(me,WHT"  2、【相貌】"NOR);
	   if(!query("bwzh/age")) tell_object(me,WHT"  3、【年龄】"NOR); 
	   tell_object(me,HIW"\n\n你可以选择数字，你也可以Q键取消。\n"NOR);
	   input_to( (: choose_mode :), me );
	   return;
	}  
	if((arg == "1" && query("bwzh/exp"))
		|| (arg == "2" && query("bwzh/per"))
		|| (arg == "3" && query("bwzh/age"))) 
	{
	   command("say 这一项，你已经设置结束，你还需要设置其他几项。");
	   tell_object(me,"\n");
	   if(!query("bwzh/exp")) tell_object(me,WHT"  1、【经验】"NOR);
	   if(!query("bwzh/per")) tell_object(me,HIW"  2、【相貌】"NOR);
	   if(!query("bwzh/age")) tell_object(me,HIW"  3、【年龄】"NOR); 
	   tell_object(me,HIW"\n\n你可以选择数字，你也可以Q键取消。\n"NOR);
	   input_to( (: choose_mode :), me );
	   return;
	}  
 	if(arg=="1")
	{
		if(me->query("combat_exp")>=1000000 )
			command("say "HIC"你自己的经验现在大约"+chinese_number(me->query("combat_exp")/1000000)+"兆。");
		else command("say "HIC"你自己的经验现在还不到一兆。");
		command("say "HIC"你将输入的数值代表你要求你的夫君的最小经验值。");
		command("say "HIC"注意单位是M（1M=1000000），你也可以Q键取消。"NOR);
		input_to( (: choose_exp :), me );
	}
	else if(arg=="2")
	{
		command("say "HIC"你将输入的数值代表你要求你的夫君的最小相貌值。");
		command("say 一般来说相貌三十的，玉树临风，风流倜傥，堪称绝世美男！");
		command("say 相貌二十左右，属于五官端正，相貌平平。");
		command("say 而十四左右，就有点牛眼驴唇，面目狰狞。");
		if(me->query("per")>=10)
			command("say 你自己的相貌应该在"+chinese_number((me->query("per")/10)*10)+"以上。");
		else command("say 你自己的相貌确实一般哦，嘿嘿。");
		command("say "HIC"你自己酌情选择，你也可以Q键取消。"NOR);
		input_to( (: choose_per :), me );
	}
	else
	{
		command("say "HIC"你将输入的数值代表你要求你的夫君的年龄与你的年龄差。");
		command("say "HIC"比如你输入数值为二十，而你已经"+chinese_number(me->query("age"))+"岁。"NOR);
		command("say "HIC"同时注意，这里要求：年龄最低不得十八岁，最高不得八十岁。"NOR);
		i=me->query("age")-20;
		if(i<18) i=18;
		p=me->query("age")+20;
		if(p>80) p=80;
		command("say "HIC"所以，你实际要求你夫君年龄段："+chinese_number(i)+"岁到"+chinese_number(p)+"岁。"NOR);
		command("hehe");
		input_to( (: choose_age :), me );
	}
	return;
}
