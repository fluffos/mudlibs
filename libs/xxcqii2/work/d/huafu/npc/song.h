int ask_rank()
{
      object me;
	mapping myfam,myparty;

	me=this_player();
	myfam=(mapping)me->query("family");
	myparty=(mapping)me->query("party");

	if ( (!myfam || myfam["family_name"]!="发梦二党" ) && ( !myparty || myparty["party_name"]!=HIG "发梦二党" NOR ))
	{
		command("say 你与本党并无瓜葛，此话从何谈起？\n");
		return 1;
	}

        if ( myfam && myfam["family_name"]=="发梦二党" )
	{
		command("say 你乃本党嫡系弟子，不需要计较职位的高低。\n");
		return 1;
	}
	if ( myparty["tasks"]<100 )
	{
		command("say 你对本党贡献还不够，不能让你担当要职。\n");
		return 1;
	}
        else if ( (myparty["tasks"]>100) && (myparty["tasks"]<200) && (myparty["rank"]!=HIM "护院" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升护院要职!\n");
		myparty["rank"]=HIM"护院"NOR;
		myparty["level"]=2;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>200) && (myparty["tasks"]<500) && (myparty["rank"]!=HIC "管事" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升管事要职!\n");
		myparty["rank"]=HIC "管事" NOR;
		myparty["level"]=3;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>500) && (myparty["tasks"]<800) && (myparty["rank"]!=RED "教头" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升教头要职!\n");
		myparty["rank"]=RED "教头" NOR;
		myparty["level"]=4;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>800) && (myparty["tasks"]<1000) && (myparty["rank"]!=HIR "总教头" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升总教头要职!\n");
		myparty["rank"]=HIR "总教头" NOR;
		myparty["level"]=5;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1000) && (myparty["tasks"]<1200) && (myparty["rank"]!=YEL "护法" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升护法要职!\n");
		myparty["rank"]=YEL "护法" NOR;
		myparty["level"]=6;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1200) && (myparty["tasks"]<1500) && (myparty["rank"]!=HIY "总护法" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升总护法要职!\n");
		myparty["rank"]=HIY "总护法" NOR;
		myparty["level"]=7;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1500) && (myparty["tasks"]<1800) && (myparty["rank"]!=HIG "长老" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升长老要职!\n");
		myparty["rank"]=HIG "长老" NOR;
		myparty["level"]=8;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>1800) && (myparty["tasks"]<2000) && (myparty["rank"]!=CYN "天王" NOR) )
	{
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升天王要职!\n");
		myparty["rank"]=CYN "天王" NOR;
		myparty["level"]=9;
		me->set("party",myparty);
		return 1;
	}
        else if ( (myparty["tasks"]>2000) && (myparty["rank"]!=HIB "瓢把子" NOR) )
	{
		command("bow "+me->query("id"));
		command("say 恭喜"+ RANK_D->query_respect(me) +"荣升瓢把子!\n");
		myparty["rank"]=HIB "瓢把子" NOR;
		myparty["level"]=10;
		me->set("party",myparty);
		return 1;
	}
         command("say "+ RANK_D->query_respect(me) +"你已经是"+myparty["rank"]+"了!\n");
        return 1;
}

int ask_counts()
{
      object me;
	mapping myfam,myparty;
	me=this_player();
	myfam=(mapping)me->query("family");
	myparty=(mapping)me->query("party");
	if ( (!myfam || myfam["family_name"]!="发梦二党" ) && ( !myparty || myparty["party_name"]!=HIG "发梦二党" NOR ))
	{
		command("say 你与本党并无瓜葛，此话从何谈起？\n");
		return 1;
	}
        if ( myfam && myfam["family_name"]=="发梦二党")
	{
		command("say 你乃本党嫡系弟子，不需要计较职位的高低。\n");
		return 1;
	}
	command("pat "+me->query("id"));
	command("say 你已经为本党做了"+chinese_number(myparty["tasks"])+"次任务，要继续努力，出人头地。\n");
	return 1;
}


