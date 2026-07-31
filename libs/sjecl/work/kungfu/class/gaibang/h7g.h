int ask_ji()
{
	object me = this_player();

	if (!me->query_temp("marks/jiaohua-ji")){
		command("say "+RANK_D->query_respect(me)+"，我告诉你吧，这天下最好吃的叫化鸡就是蓉儿那个小丫头做的！");
		command("say 修文这笨小子不知跑哪玩去了，叫他去襄阳帮我带只鸡，好久也不回来。");
		me->set_temp("marks/jiaohua-ji",1);
		return 1;
	}
	command("say 你也想吃吗？");
	return 1;
}

int kanglong(object me, object ob)
{
	if(!ob || !me || !living(ob) || !living(me)
		|| environment(ob) != environment(me)
		|| ob->is_fighting() || me->is_fighting())
		return 0;

	command("consider");
	command("say 你这娃娃真是不赖，能做出和黄丫头同样好的美味来。");
	if ( random((int)me->query_con()) > 15 ){
		command("say 我也不能白吃了你的菜，这样吧。");
		command("whisper "+me->query("id")+" 你去西域"YEL"鸣沙山"NOR"住上一阵子，有没有造化就看你自己了。");
		me->set_temp("xlz/hang", 1);
		return 1;
	}
	command("say 今天的鸡不错，你真是有心，下次记得再给我弄几只来。");
	return 1;
}

int ask_wugou()
{
	int i, j, x;
	object me = this_player();

	i = me->query("gb/baih7g");
	j = me->query("combat_exp");
	x = me->query("dgb/wugou");

	if ( x >= 5 || me->query_temp("get_wugou") ) {
		command("knock "+me->query("id")+"");
		return 1;
	}
	if ( me->query_temp("noget_wugou") && !wizardp(me)) {
		if (me->query_temp("noget_wugou") > 10) {
			command("say 去去，小孩子一边玩去！");
			command("kick3 "+me->query("id")+"");
			me->delete_temp("get_wugou");
			me->delete_temp("get_wugou2");
			tell_room(environment(), "\n洪七公大力飞起一脚，将"+ me->name()+ "踢飞出门外！\n"NOR, ({ me }));
			me->move("/d/gb/pomiao");
			me->add_busy(2);
			tell_room(environment(me), "\n只见"+ me->name()+ "屁股上带着个泥脚印，大叫一声飞了过来，摔了个狗吃屎！\n"NOR, ({ me }));
			return 1;
		}
		if (me->query_temp("noget_wugou") > 8) {
			command("say 这就是打狗棒法里我最擅长的一招：【天下无狗】！ ");
			command("club "+me->query("id")+"");
		}
		else switch( random(8) ){
			case 7 :
				command("dunno "+me->query("id")+"");
				break;
			case 6 :
				command("nip "+me->query("id")+"");
				break;
			case 5 :
				command("bored "+me->query("id")+"");
				break;
			case 4 :
				command("heng "+me->query("id")+"");
				break;
			case 3 :
				command("look "+me->query("id")+"");
				break;
			case 2 :
				command("hehe "+me->query("id")+"");
				break;
			case 1 :
				command("oh "+me->query("id")+"");
				break;
			case 0 :
				command("mimi "+me->query("id")+"");
				break;
		}
		me->add_temp("noget_wugou", 1);
		return 1;
	}
	if ( (!i || me->query("family/family_name") !="丐帮") && !wizardp(me) ) {
		command("en "+me->query("id"));
		me->add_temp("noget_wugou", 1);
		return 1;
	}
	if ( x && x < 5 ){
		command("kick2 "+me->query("id")+"");
		switch(random(2)){
			case 1:
			command("say 最近我没空，过几天再来。");
			break;
			case 0:
			command("say 过几天再来，最近没空。");
		}
		me->set_temp("get_wugou2", 1);
		if(random(2)) me->add_temp("noget_wugou", 1);
		return 1;
	}
	x = localtime(TIME_TICK)[2];
	if ((x >= 12 && x <= 21
	 && random(i) > 200000 && random(j+i) > 1000000) || wizardp(me)) {
		command("nod "+me->query("id"));
		command("whisper "+me->query("id")+" 我想出来几招打狗棒的新招式，明晚三更时分你到嘉兴铁枪庙等我，到了记得喊我一声。");
		me->set_temp("get_wugou", time() + 27 * 60);	// 判断时间为明天半夜
		return 1;
	}
	command("look "+me->query("id"));
	switch(random(3)){
		case 2 :
			command("consider");
			break;
		case 1 :
			command("nip");
			break;
		case 0 :
			command("pei");
			break;
	}
	me->add_temp("noget_wugou", 1);
	return 1;
}
