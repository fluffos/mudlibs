// By 山猫adx @ CuteRabbit 9:32 99-6-21
// 帮派系统 之 朝廷
// int do_kou1(string arg) 升9-7品官
// int do_kou2(string arg) 升6-2品官
// int do_chiguan(string arg) 辞官
// int do_sheng(string arg) 升玩家的官衔
// int do_jiang(string arg) 降玩家的官衔
// int do_diao(string arg) 四品以上官可以调动军队
// int do_ling(string arg) 官员每年可以领一次薪俸
// int do_tongji(string arg) 通缉某人
// int do_tongji(string arg) 解除通缉某人
// int do_jina(string arg) 出动四大名捕缉拿要犯

int do_kou1(string arg)
{
	object me;
	int i, rank;

	me = this_player();
	i = me->query("weiguan");
	rank = me->query("bhrank");

	if(!id(arg)) {
		return notify_fail("看清楚，别乱叩头？？！\n");
	}

	message_vision("$N跪了下来恭恭敬敬地磕了个响头。\n", me);

	if( i>=50 && me->query("banghui")!="朝廷" ) {
		me->set("banghui", "朝廷");
		me->set("bhrank", 9);
		command("ok");
		command("say 快去户部领你的第一笔薪俸吧！");
		return notify_fail(HIC"你现在是朝廷命官了！\n"NOR);
	}

	if( rank==9 && i>=250 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 8);
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==8 && i>=1250 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 7);
		command("rumor "+me->name()+"被任命为官府七品提督喽……！");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==7 && i>=50000 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 6);
		command("rumor "+me->name()+"被提升官府六品总兵喽……！");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==5 && rank==4 && me->query("banghui")=="朝廷" ) {
		command("bow "+me->query("id"));
		command("say 这位大人如此多礼！");
		return 1;
	}

	if( rank<=3 && me->query("banghui")=="朝廷" ) {
		command("bow "+me->query("id"));
		command("say 大人何必如此，折杀下官了！");
		return 1;
	}
	else
		command("pat "+me->query("id"));
		command("say 以后见官要懂得多叩头！");
		return 1;
}

int do_kou2(string arg)
{
	object me;
	int i, rank;

	me = this_player();
	i = me->query("weiguan");
	rank = me->query("bhrank");

	if(!id(arg)) {
		return notify_fail("看清楚，别乱叩头？？！\n");
	}

	message_vision("$N跪了下来恭恭敬敬地磕了个响头。\n", me);

	if( rank==6 && i>=200000 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 5);
		command("rumor "+me->name()+"被提升为当朝五品偏将喽……！");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==5 && i>=800000 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 4);
		command("rumor "+me->name()+"被提升为当朝四品将军喽……！");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==4 && i>=2000000 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 3);
		command("rumor "+me->name()+"被提升为当朝三品上将军喽……！");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==3 && i>=6000000 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 2);
		command("rumor "+me->name()+"担任朝廷二品大将军喽……！");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==2 && i>=18000000 && me->query("banghui")=="朝廷" ) {
		me->set("bhrank", 1);
		command("rumor "+me->name()+"担任朝廷一品大元帅喽……！");
		command("rumor gongxi");
		command("ok");
		return notify_fail(HIC"恭喜！恭喜！你升官了！\n"NOR);
	}

	if( rank==2 && me->query("banghui")=="朝廷" ) {
		command("say 这位大人如此多礼！");
		return 1;
	}

	if( rank==1 && me->query("banghui")=="朝廷" ) {
		command("say 大人请起，小王不敢当，不敢当啊！");
		return 1;
	}

	else
		command("nod "+me->query("id"));
		return 1;
}

int do_chiguan(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要向谁辞官？\n");

	if(me->query("banghui")!="朝廷")
		return notify_fail("你根本就不是朝廷官员，要辞什么？\n");

	write("你确定真的要辞官吗(Yy)(Nn)？\n");
	input_to("get_gift", me);
	return 1;
}

void get_gift(string yn, object me)
{
	if (yn[0] == 'y' || yn[0] == 'Y')
	{
		me->delete("banghui");
		me->delete("bhrank");
		me->delete("weiguan");
		command("sigh "+me->query("id"));
		command("say 好吧！"+me->name()+
		"，你今后再也不是朝廷官员了！");
		command("rumor "+me->name()+"辞去了朝廷官职！");
		command("rumor 呜呼……国家痛失栋梁，江湖再添草莽！");
	}
	else {
		command("say 好吧！"+me->name()+"，你就继续为朝廷效力吧！");
	}
}

int do_sheng(string arg)
{
	object ob, me;
	int i, inv;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="朝廷" || i>4)
		return notify_fail("朝廷的印信也是你能乱碰的吗？\n");

	if( !arg )
		return notify_fail("指令格式：sheng <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("现在没这个人。\n");

	if (ob==me)
		return notify_fail("升自己的官衔，这个主意真不错！\n");

	inv = ob->query("bhrank");
	if(ob->query("banghui")=="朝廷" && i>=inv)
		return notify_fail("对方的官职不比你低，你怎么可以……\n");

	if(ob->query("banghui")!="朝廷")
		return notify_fail("对方不是朝廷官员怎么升官呢？\n");

	if( (i==4 && inv>8) || (i==3 && inv>6)
		|| (i==2 && inv>4) || (i==1 && inv>2) )
	{
		ob->add("bhrank", -1);
	        message_vision(YEL"$N下令晋升$n官衔一级。\n"NOR, me, ob);
		command("rumor "+me->query("name")+"晋升"+
			ob->query("name")+"官衔一级！");
		return 1;
	}
	else
		return notify_fail("你无权这么做！\n");
}

int do_jiang(string arg)
{
	object ob, me;
	int i, inv;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="朝廷" || i>4)
		return notify_fail("朝廷的印信也是你能乱碰的吗？\n");

	if( !arg )
		return notify_fail("指令格式：jiang <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("现在没这个人。\n");

	if (ob==me)
		return notify_fail("你要降自己的官衔，那不如去辞官！\n");

	inv = ob->query("bhrank");
	if(ob->query("banghui")=="朝廷" && i>=inv)
		return notify_fail("对方的官职不比你低，你怎么可以……\n");

	if(ob->query("banghui")!="朝廷")
		return notify_fail("对方不是朝廷官员怎么降职呢？\n");

	if( (i==4 && inv>=8) || (i==3 && inv>=6)
		|| (i==2 && inv>=4) || (i==1 && inv>=2) )
	{
		ob->add("bhrank", 1);
	        message_vision(YEL"$N下令降$n官衔一级。\n"NOR, me, ob);
		command("rumor "+me->query("name")+"降"
			+ob->query("name")+"官衔一级！");
		if(ob->query("bhrank")==10)
		{
			ob->delete("banghui");
			ob->delete("bhrank");
			message_vision(YEL"$N下令开除$n。\n"NOR, me, ob);
			command("rumor "+ob->query("name")+"被"
				+me->query("name")+"逐出朝廷了！");
		}
		return 1;
	}
	else
		return notify_fail("你无权这么做！\n");
}

int do_tongji(string arg)
{
	object ob, me;
	int i;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="朝廷" || i>2)
		return notify_fail("不要乱碰这里的东西！\n");

	if( !arg )
		return notify_fail("指令格式：tongji <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("现在没这个人。\n");

	if (ob==me)
		return notify_fail("你要通缉自己？大笨瓜！\n");

	if(ob->query("banghui")=="朝廷")
		return notify_fail("不能通缉朝廷官员！\n");

	if(ob->query("gender")=="无性")
		return notify_fail("此人难以分辨男女，恐怕抓不到！\n");

	if(!ob->query_condition("killer"))
	{
		ob->apply_condition("killer", 500);
	        message_vision(YEL"$N下令通缉$n。\n"NOR, me, ob);
		command("rumor "+me->query("name")+"下令通缉"
			+ob->query("name")+"了！");
		return 1;
	}
	else
		return notify_fail(ob->query("name")+"已经在被通缉了！\n");
}

int do_untongji(string arg)
{
	object ob, me;
	int i;

	me = this_player();
	i = me->query("bhrank");

	if(me->query("banghui")!="朝廷" || i>2)
		return notify_fail("不要乱碰这里的东西！\n");

	if( !arg )
		return notify_fail("指令格式：untongji <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob)
		return notify_fail("现在没这个人。\n");

	if(ob->query_condition("killer"))
	{
		ob->apply_condition("killer", -500);
	        message_vision(YEL"$N下令解除通缉$n。\n"NOR, me, ob);
		command("rumor "+me->query("name")+"下令解除通缉"
			+ob->query("name")+"了！");
		return 1;
	}
	else
		return notify_fail(ob->query("name")+"没有被通缉啊！\n");
}

int do_diao(string arg)
{
	object me, bing, obj;
	int rank;

	me = this_player();
	rank = me->query("bhrank");
	obj = new("/d/changan/obj/lingjian");

	if(!arg || (arg != "bing")) {
		return notify_fail("你要调什么？？！\n");
	}

	if(me->query_temp("diaobing")==1 ||
		me->query_condition("diaobing") )
		return notify_fail("你如果需要调动更多的兵马要先征得"+
			"摄政王的同意！\n不过恐怕你指挥不了！！\n\n");

	if ( me->query("banghui")=="朝廷" )
	{
		me->set_temp("diaobing", 1);
		me->apply_condition("diaobing", 1000);
		obj->move(me);

		switch(rank)
		{
			case 1: 
				command("bow "+me->query("id"));
				command("say 是，大人！请先拿好令箭！");
				command("say 来人哪！跟"+me->query("name")+"元帅去办事！");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
              		case 2: 
				command("bow "+me->query("id"));
				command("say 好的大人！请先拿好令箭！");
				command("say 来人哪！跟"+me->query("name")+"大将军去办事！");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
              		case 3: 
				command("bow "+me->query("id"));
				command("say 行，大人！请先拿好令箭！");
				command("say 来人哪！跟"+me->query("name")+"上将军去办事！");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
              		case 4: 
				command("say 来人哪！跟"+me->query("name")+"大人去办事！");
				bing=new("/d/changan/npc/bing");
	 			bing->move(environment(me));
				return 1;
		}
	}
	else
		command("pat "+me->query("id"));
		command("say 你无权调派军队！");
		return 1;
}

int do_ling(string arg)
{
	object me;
	int rank, i, xinfeng;

	me = this_player();
	rank = me->query("bhrank");

	if(!arg||arg!="xinfeng")
		return command("say 你是要领薪俸(xinfeng)吗？");

	if(me->query("banghui")!="朝廷")
		return command("say "+me->name()+
		"你哪有什么薪俸可领？");

	if(me->query_condition("xinfeng"))
		return command("say "+me->name()+
		"你已经领过薪俸了，每年才发一次薪俸呢！");

	i = me->query("mud_age")/5;
	xinfeng = me->query("wieguan") + i;

	me->apply_condition("xinfeng", 5760);
	me->add("balance", xinfeng);
	command("say 好吧！"+me->name()+
	"你今年的薪俸是"+MONEY_D->price_str(xinfeng)+
	"，钱已经存入钱庄你的帐户了！");
	return 1;
}
