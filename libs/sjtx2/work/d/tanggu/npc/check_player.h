int check_player(object me,int i)
//检查女性(0)和男性(1)
{
	mapping mp;
	object ob=this_object();
    object *obj;
    int p;

	if(!me) return 1;
	if(me->query("gender")!="女性" && me->query("gender")!="男性" )
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say 目前无性人婚姻暂时未开放。");	
		command("hoho "+me->query("id"));	
		return 1;
	}
	switch (me->query("class")) {
		case "bonze":
		case "huanxi":
		case "lama":
		case "taoist":
			command("look "+me->query("id"));
			message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
			command("say "+me->query("name")+"是还俗以后再来谈婚论嫁吧。");	
			return 1;
	}
	if(me->query("gender")!="女性" && i==0)
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say "+me->query("name")+"是不是喝多了？连自己性别也忘记了？大老爷们也来比武招亲？");	
		command("laugh "+me->query("id"));	
		return 1;
	}
	if(me->query("gender")!="男性" && i)
	{
		command("pat "+me->query("id"));	
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say 目前书剑暂不开放同性恋功能。");	
		command("shrug "+me->query("id"));	
		return 1;
	}
	if(me->query("age") < 18)
	{
		command("shrug "+me->query("id"));	
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say "+me->query("name")+"那么小怎么行？等长大一点再想嫁人的事吧。");	
		command("pat "+me->query("id"));	
		return 1;
	}
	if(me->query("age") > 80)
	{
		command("shrug "+me->query("id"));	
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		if(i) command("say 让我怎么说呢......"+me->query("name")+"公公！");	
		else command("say 让我怎么说呢......"+me->query("name")+"婆婆！");	
		command("pat "+me->query("id"));	
		return 1;
	}
	if (me->query("marry"))
	{
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("? "+me->query("id"));	
		if(random(2)) command("say 这事情"+me->query("marry/name")+"("+capitalize(me->query("marry/id"))+")知道吗？" );	
		else command("say "+me->query("name")+"想红杏出墙么？难道忘记自己已经有配偶了啦。" );	
		command("sneer "+me->query("id"));	
		return 1;
	}
	if (me->query_temp("marry"))
	{
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("? "+me->query("id"));	
		command("say "+me->query("name")+"想红杏出墙么？难道忘记了自己已经订婚了啊？" );	
		command("sneer "+me->query("id"));	
		return 1;
	}

	if(me->query_condition("killer"))
	{
		command("look "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("shake "+me->query("id"));
		command("say 小心官府通缉！");
		return 1;
	}
	if(me->query_condition("job_busy"))
	{
		command("look "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say 刚做完"+me->query("job_name")+"任务，还是稍微休息一下吧！");
		return 1;
	}
	if( mapp(mp = me->query_conditions_by_type("poison")) && sizeof(mp)>0 )
	{
		command("poor "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say "+me->query("name")+"还是先治好自己的病再来比武招亲吧！");
		return 1;
	}  
	if( mapp(mp = me->query_conditions_by_type("killer")) && sizeof(mp)>0 )
	{
		command("hmm "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say "+me->query("name")+"还是先解决了自己的个人恩怨再来比武招亲吧！");
		return 1;
	} 
	if( mapp(mp = me->query_conditions_by_type("hurt")) && sizeof(mp)>0 )
	{
		command("sigh "+me->query("id"));
		message_vision(HIY"\n$n轻轻地将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say "+me->query("name")+"还是先治疗一下内伤再来比武招亲吧！");
		return 1;
	}  
	if(wizardp(me) && !me->query("env/marry_test")) 
	{
		message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
		command("say "+me->query("name")+"你老就别捣乱了，专心搞开发去吧！");
		return 1;
	}
	obj = deep_inventory(me);
	p = sizeof(obj);
	while (p--)
	{
		if (obj[p]->is_character() )
		{
			message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
			command("say "+me->query("name")+"，你这个"+obj[p]->query("name")+"是什么东东哦？");
			return 1;
		}
		if(obj[p]->query("unique"))
		{
			message_vision(HIY"\n$n一把将$N拦了下来，缓缓地摇摇了头。\n"NOR,me,ob);
			command("say "+me->query("name")+"，你这个"+obj[p]->query("name")+"可是宝物啊，别比武出现什么闪失就不好了！");
			return 1;
		}
	}
	return 0;
}
