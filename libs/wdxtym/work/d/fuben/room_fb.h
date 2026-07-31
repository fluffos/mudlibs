
//可搜索到的物品列表
string *random_ob = ({
    "/clone/money/gold",
    "/clone/money/coin",
    "/clone/money/silver",
});

int clean_up()
{
	return 1;
}

void init()
{	
	set("no_clean_up_fb", 1);
	add_action("do_sousuo", "sousuo");
/*
	set("action_list", ([
		"搜索":"sousuo",
	]));
*/
	//识别隐藏房间
	if ( this_object()->query("anniu_hide")) 
		add_action("do_anniu", "anniu");
	if ( this_object()->query("jiguan")) 
		add_action("do_anniu", "anniu");
	
}
int do_sousuo(object me)
{
	object ob;
	object oba, obb, obc, obd;
	string id = random_ob[random(sizeof(random_ob))];//随机物品
	me = this_player();
	
	oba = present("tu fei", environment(me));
	obb = present("tufei tou", environment(me));
	obc = present("han fei", environment(me));
	obd = present("hanfei tou", environment(me));
	
	if (oba) {
		oba->kill_ob(me);
		me->kill_ob(oba);
		return notify_fail(oba->name()+"对你大吼道：活得不耐烦了？敢在大爷面前偷东西！\n");
	}
	if (obb) {
		obb->kill_ob(me);
		me->kill_ob(obb);
		return notify_fail(obb->name()+"对你大吼道：想在我这里偷东西？我看你是找死！\n");
	}
	
	if (obc) {
		obc->kill_ob(me);
		me->kill_ob(obc);
		return notify_fail(obc->name()+"对你“嘿嘿！”一笑，你看得毛骨悚然！\n");
	}
	if (obd) {
		obd->kill_ob(me);
		me->kill_ob(obd);
		return notify_fail(obd->name()+"对你“嘿嘿！”一笑，你看得毛骨悚然！\n");
	}
	/*
	if (me->query_temp("sousuo_buy", 1) > time()) 
		return notify_fail(sprintf("你正忙着搜索，别着急！\n"));
	*/
	if (query_temp("sousuo")) 
		return notify_fail(sprintf("这里已经被你翻得底朝天了，换个地方吧！\n"));
	
	//福缘越高几率越大
	if (random(200) < me->query("kar")) {
		ob = new(id);
		ob->move(me);
		tell_object(me, sprintf("恭喜你居然找到了%s！\n", ob->name()));
	} else
		tell_object(me, sprintf("你像做贼似的这里瞅瞅，那里翻翻，结果什么也没找到。\n"));
	
	//me->set_temp("sousuo_buy", time() + random(3) + 2);
	add_temp("sousuo", 1);
	return 1;
}
