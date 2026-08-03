void choose_exp(string arg, object me)
{
	int exp;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh");
		command("say 只是如此羞涩，哪里有江湖儿女的洒脱。也罢，我将这旗上的名字擦去。");
		message_vision(HIY"\n$N走上前去，将锦旗上书写的名字擦去。\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 取消比武招亲choose_exp",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/exp")) 
	{
	   command("? "+me->query("id"));
	   choose_other(me,1);
	   return;
	}
	if(!sscanf(arg, "%d", exp))
	{
		command("say "HIC"请输入一个数字表示经验。");
		command("hammer "+me->query("id"));
		input_to( (: choose_exp :), me );
		return;
	}
	if(exp<1 || exp>99)
	{
		command("say "HIC"你输入的数值不符合要求（0<EXP<99）。");
		command("hmm "+me->query("id"));
		input_to( (: choose_exp :), me );
		return;
	}
	command("nod "+me->query("id"));
	set("bwzh/exp",exp);
	choose_other(me,1);
	return;
}
void choose_per(string arg, object me)
{
	int per;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh");
		command("say 只是如此羞涩，哪里有江湖儿女的洒脱。也罢，我将这旗上的名字擦去。");
		message_vision(HIY"\n$N走上前去，将锦旗上书写的名字擦去。\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 取消比武招亲choose_per",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/per")) 
	{
	   command("? "+me->query("id"));
	   choose_other(me,2);
	   return;
	}
	if(!sscanf(arg, "%d", per))
	{
		command("say 请输入一个数字表示相貌。");
		command("kick "+me->query("id"));
		input_to( (: choose_per :), me );
		return;
	}
	if(per<1 || per>50)
	{
		command("say "HIC"你输入的数值不符合要求（0<PER<50）。");
		input_to( (: choose_per :), me );
		return;
	}
	command("nod "+me->query("id"));
	set("bwzh/per",per);
	choose_other(me,2);
	return;
}
void choose_age(string arg, object me)
{
	int age;
	if( arg == "Q" || arg == "q" )    
	{
		command("sigh");
		command("say 只是如此羞涩，哪里有江湖儿女的洒脱。也罢，我将这旗上的名字擦去。");
		message_vision(HIY"\n$N走上前去，将锦旗上书写的名字擦去。\n"NOR,this_object());
		command("nod "+me->query("id"));
		init_over();
		log_file("quest/zhaoqin",sprintf("%-8s%-10s 取消比武招亲choose_age",me->query("name"),me->query("id")),me);
		return;
	}
	if(query("bwzh/age")) 
	{
	   command("? "+me->query("id"));
	   choose_other(me,3);
	   return;
	}
	if(!sscanf(arg, "%d", age))
	{
		command("claw "+me->query("id"));
		command("say "HIC"请输入一个数字表示年龄差。");
		input_to( (: choose_age :), me );
		return;
	}
	if(age<1 || age>me->query("age"))
	{
		command("say "HIC"你输入的数值不符合要求（0<AGE<"+me->query("age")+"）。");
		input_to( (: choose_age :), me );
		return;
	}
	command("nod "+me->query("id"));
	set("bwzh/age",age);

	choose_other(me,3);
	return;
}
void choose_other(object me,int x)
{
    int i,p;
	if(!me) return;
	i=me->query("age")-query("bwzh/age");
	if(i<18) i=18;
	p=me->query("age")+query("bwzh/age");
	if(p>80) p=80;
    
	if(x==1)
		tell_object(me,HIW"\n你已经设定【最低经验："+chinese_number(query("bwzh/exp"))+"兆】\n"NOR);
	else if(x==2)
		tell_object(me,HIW"\n你已经设定【最低相貌："+chinese_number(query("bwzh/per"))+"】\n"NOR);
	else 
		tell_object(me,HIW"\n你已经设定【年龄："+chinese_number(i)+"岁----"+chinese_number(p)+"岁】\n"NOR);

	if(query("bwzh/exp")
		&& query("bwzh/per")
		&& query("bwzh/age")) 
	{
		command("addoil "+me->query("id"));
		tell_object(me,HIW"\n你现在心目中的夫君的要求设置如下：\n\n"NOR);
		tell_object(me,HIR"  1、【经验】最低经验"+chinese_number(query("bwzh/exp"))+"兆。\n"NOR);
		tell_object(me,HIR"  2、【相貌】最低相貌"+chinese_number(query("bwzh/per"))+"。\n"NOR);
		tell_object(me,HIR"  3、【年龄】在"+chinese_number(i)+"岁和"+chinese_number(p)+"岁之间。\n"NOR); 
		tell_object(me,HIW"\n如果你同意，可以选择：\n"NOR);
		tell_object(me,WHT"（Y）同意 （R）重选 （Q）取消\n"NOR);
		input_to( (: choose_ok :), me );
		return;
	}
	tell_object(me,HIW"\n你可以选择设置其他要求：\n\n"NOR);
	if(!query("bwzh/exp")) tell_object(me,WHT"  1、【经验】"NOR);
	if(!query("bwzh/per")) tell_object(me,WHT"  2、【相貌】"NOR);
	if(!query("bwzh/age")) tell_object(me,WHT"  3、【年龄】"NOR); 
	tell_object(me,HIW"\n\n你可以选择数字，你也可以Q键取消。\n"NOR);
	input_to( (: choose_mode :), me );
	return;
}