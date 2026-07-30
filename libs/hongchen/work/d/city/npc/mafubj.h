int do_ridebj()
{
	string hname;
	object ob = this_player();
	if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
	{
		command("chat 来人啦！"+ob->query("name")+
		"这个"+RANK_D->query_rude(ob)+"想偷马！\n");
		return 1;
	}
	switch (random(3))
	{
		case 1:
			hname=MAG"紫骝马"NOR;
			break;
		case 2:
			hname=RED"枣红马"NOR;
			break;
		default:
			hname=HIY"黄骠马"NOR;
			break;
	}
	message_vision(
"马夫随手给$N牵来一匹"+hname+"。$N翻身跃上马背。动作潇洒利索。路边行人一阵
起哄: 喔噢喔噢。\n"NOR , ob );
	message_vision("\n只见$N骑两腿一夹，"+hname+"穿过客店而去。\n",ob);
	ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/beidajie2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city/beimen");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/shaolin/yidao1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/shaolin/yidao2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/shaolin/hanshui1");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"跃入汉水中奋力游向对岸。\n", ({ob}));
	ob->move("/d/shaolin/hanshui2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/shaolin/nanyang");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/shaolin/yidao3");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/shaolin/ruzhou");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road10");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road9");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road8");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road4");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road7");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road6");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/road5");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/yongding");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/nandaj2");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/nandaj1");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/kedian");
        tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路招摇疾驰而过。\n", ({ob}));
	ob->move("/d/city2/majiu");
	tell_room(environment(ob),ob->query("name")+"骑着"+hname+"一路顺利到达北京。\n");
	message_vision("\n$N身形一转，跃下马来，姿态十分优美。闲人也给$N一大哄 !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}
