int do_ridebj()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat 來人啦！"+ob->query("name")+
		"這個"+RANK_D->query_rude(ob)+"想偷馬！\n");
		return 1;
	}
	switch (random(3))
	{
		case 1:
			hname=MAG"紫騮馬"NOR;
			break;
		case 2:
			hname=RED"棗紅馬"NOR;
			break;
		default:
			hname=HIY"黃驃馬"NOR;
			break;
	}
	message_vision(
"馬夫隨手給$N牽來一匹"+hname+"。$N翻身躍上馬背。動作瀟洒利索。路邊行人一陣
起哄: 喔噢喔噢。\n"NOR , ob );
	message_vision("\n只見$N騎兩腿一夾，"+hname+"穿過客店而去。\n",ob);
	ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city/beidajie2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city/beimen");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/shaolin/yidao1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/shaolin/yidao2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/shaolin/hanshui1");
	tell_room(environment(ob),ob->query("name")+"騎著"+hname+"躍入漢水中奮力游向對岸。\n", ({ob}));
	ob->move("/d/shaolin/hanshui2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/shaolin/nanyang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/shaolin/yidao3");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/shaolin/ruzhou");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road10");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road9");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road8");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road4");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road7");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road6");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/road5");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/yongding");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/nandaj2");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/nandaj1");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/kedian");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/city2/majiu");
	tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路順利到達北京。\n");
	message_vision("\n$N身形一轉，躍下馬來，姿態十分優美。閑人也給$N一大哄 !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}
