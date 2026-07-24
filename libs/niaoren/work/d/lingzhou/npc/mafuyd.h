int do_rideyd()
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
	message_vision("\n只見$N騎兩腿一夾，"+hname+"穿過車馬店而去。\n",ob);
	ob->move("/d/lingzhou/chema");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/nandajie");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/nanmen");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/huangyangtan");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/xiaoba");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/qingtongxia");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/mingshazhou");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/lingzhou/xuanhebao");
	tell_room(environment(ob),ob->query("name")+"騎著"+hname+"躍入黃河中奮力游向對岸。\n", ({ob}));
	ob->move("/d/huanghe/guchangcheng");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/yinpanshui");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/bingcao");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/shixiazi");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/tumenzi");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/wuwei");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/wuqiao");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/dacaigou");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/gulang");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/yongdeng");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/kedian");
        tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路招搖疾馳而過。\n", ({ob}));
	ob->move("/d/huanghe/majiu");
	tell_room(environment(ob),ob->query("name")+"騎著"+hname+"一路順利到達永登。\n");
	message_vision("\n$N身形一轉，躍下馬來，姿態十分優美。閑人也給$N一大哄 !\n" ,ob);
	ob->delete_temp("marks/horserent");
	return 1;
}
