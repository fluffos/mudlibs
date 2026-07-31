// by ranger_游侠
// DuoBaoLeiTai.java

inherit ROOM;
int ask_biwu(string arg);
int ask_biwu2(string arg);

void create()
{
	set("short", "赏金擂台(PK)");
	set("long", "这是一个四丈见方的擂台。粗壮结实的木柱撑起一片平台，四角的支柱上高挂着四副对联，四面的观众都能清楚地看到台上的手起脚落。擂台角上有个兵器架，刀剑鞭棒样样俱全。");
	set("exits", ([
		"north" : __DIR__"ximen",
	]));
	set("objects", ([
		__DIR__"npc/dashou" : 1,
	]));
	set("action_list", ([
		"黄金比武":"biwu",
		"灵石比武":"biwu2",
	]));
	setup();
}
void init()
{
	object me = this_player();
	
	add_action("ask_biwu","biwu");   
	add_action("ask_biwu2","biwu2");   
	add_action("discmds",({"respitate","exert","array","ansuan","touxi","persuade",
		"teach","exert","exercise","study","learn","sleep","kill","steal","cast","expell",
		"fight","hit","perform","prcatice","scribe","surrender"}));
	if (userp(me) && me->query("no_get") )
		call_out("do_recover",15,me);
}
int ask_biwu(string arg)
{
	object me = this_player();
	object room, look_fight_room;
	object *obs, ob, obj;
	int k=0, unit, unit2;
	string str, id, name;
	
	if (me->query_temp("biwu_time") > time())
		return notify_fail("别急，先休息调整一会儿再上吧！\n");
	
	if (unit2 = me->query("bet/balance/unit") > 0)
	{
		me->add("balance", unit2);
		me->delete("bet/balance");
		return notify_fail("你上次比武未完成，赌注"+MONEY_D->money_str(unit2)+"退还至你钱庄！\n");
	}
	
	if (!look_fight_room=find_object(__DIR__"leitaiyi"))
		look_fight_room=load_object(__DIR__"leitaiyi");
	
	if (look_fight_room)
	{
		obs = all_inventory(look_fight_room);
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				k++;
				if (k > 0) {
					unit2 = ob->query("bet/balance/unit");
					name = ob->name();
				}
			}
		}
		if (k >=2)
			return notify_fail("擂台上已经有人在决斗，你还是等会再上吧！\n");
	}
	
	if (me->is_busy())
		return notify_fail("你正忙呢！\n");
	
	if (me->is_fighting())
		return notify_fail("你已经在打架了，打完再说！\n");
	
	if (me->query("balance") < 10000)
		return notify_fail("比武需要1两黄金做为入场费，你钱庄存款不足1两黄金！\n");
	
	if (!arg) {
		str = sprintf("%s", "我要比武(进入):biwu yes" + ZJSEP);
		str += sprintf("%s", "打酱油的(取消):biwu no");
		tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else
	if (arg == "no") {
		tell_object(me, "你觉得比武这种事太危险了，还是去打酱油比较安全。\n");
		return 1;
	}
	
	if (sscanf(arg, "%s %s %d", arg, id, unit) != 3 ) {
		if (look_fight_room) {
			if (unit2 > 0) {
				str = sprintf("%s", "谁怕谁(进入):biwu yes no " + (unit2/10000) + ZJSEP);
				str += sprintf("%s", "算了(取消):biwu no");
				tell_object(me, ZJOBLONG + name+"目前想赌金钱："
					+MONEY_D->money_str(unit2)+"，你确定进入吗？\n"
											+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
				return 1;
			}
		}
		
		obs = all_inventory(this_object());
		str = sprintf("%s%s", "自由挑战:biwu yes no 1" + ZJSEP, "算了(取消):biwu no");
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				if (ob != me)
					str += sprintf(ZJSEP+"%s", HIC+ob->name() + NOR":biwu yes " + ob->query("id") + " 1");
			}
		}

		tell_object(me, ZJOBLONG + "你想邀请谁和你进行比赛？\n"
										+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else {
		if (unit < 10 || unit > 10000)  {
			write(INPUTTXT("下赌注(黄金)：(10-1万黄金)","biwu yes "+(id != "no" ? id : "no")+" $txt#")+"\n");
			return 1;
		}
		
		unit *= 10000;
		
		if (me->query("balance") < unit + 10000) {
			tell_object(me, "你钱庄存款不足"+MONEY_D->money_str(unit+10000) +NOR"。\n");
			return 1;
		}
		
		if (obj = present(id, environment(me)))
		{
			me->set_temp("biwu/id", obj->query("id"));
			
			if (obj->query_temp("biwu/id") != me->query("id") ) {
				if ( me->query_temp("biwu/time") < time()) {
					me->set_temp("biwu/time", time() + 5);
					str = sprintf("%s", "谁怕谁(进入):biwu yes " + me->query("id") + " " + (unit/10000) + ZJSEP);
					str += sprintf("%s", "惹不起(取消):biwu no");
					tell_object(obj, ZJOBLONG + me->name()+"想和你赌金钱："
								+MONEY_D->money_str(unit) +"，你敢应战吗？\n"
											+ZJOBACTS2+ZJMENUF(3,2,9,30) + str+"\n");
				} 
				tell_object(me, "你已经向"+obj->name()+"发起挑战了，请耐心等待对方的答复。\n");
				return 1;
			}
		} else if (id != "no") {
			tell_object(me, "你想比武的人已经离开了。\n");
			return 1;
		}
		
		if (obj) {
			if (obj->query("balance") >= unit + 10000) {
				obj->add("balance", -(unit));
				obj->set("bet/balance/unit", (unit));
				tell_object(obj, "你下了赌注："+ MONEY_D->money_str(unit) +NOR"\n");
				log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
														"赌注："+MONEY_D->money_str(unit), ctime(time())));
			} else {
				tell_object(me, obj->name() + "钱庄存款不足以下注，比赛取消。\n");
				tell_object(obj, "你的钱庄存款不足以下注，比赛取消。\n");
				return 1;
			}
			
			obj->add("balance", -10000);
			obj->move(__DIR__"leitaiyi");
			tell_object(obj, "你和"+me->name()+"双双跃上了擂台！\n");
			tell_object(me, "你和"+obj->name()+"双双跃上了擂台！\n");
			obj->delete_temp("biwu");
			tell_object(obj, ("你缴纳了1两黄金做为比武入场费！本场比赛时间为：三分钟，赌注为："+MONEY_D->money_str(obj->query("bet/balance/unit"))+"\n"));
		}
		
		if (!me->query("bet/balance/unit")) {
			me->add("balance", -(unit));
			me->set("bet/balance/unit", (unit));
			tell_object(me, "你下了赌注："+ MONEY_D->money_str(unit) +NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"赌注："+MONEY_D->money_str(unit), ctime(time())));
		} else if ( unit2 > 0) {//如果擂台上有人
			me->add("balance", -((unit)-me->query("bet/balance/unit")));
			me->set("bet/balance/unit", (unit));
			tell_object(me, "你赌注变更为："+ MONEY_D->money_str(unit)+NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"赌注："+MONEY_D->money_str(unit), ctime(time())));
		} else
			tell_object(me, ("你决定将上次的赌赛继续进行("+
										MONEY_D->money_str(me->query("bet/balance/unit"))+")！\n"));
		
		me->add("balance", -10000);
		me->move(__DIR__"leitaiyi");
		me->delete_temp("biwu");
		tell_object(me, ("你缴纳了1两黄金做为比武入场费！本场比赛时间为：三分钟，赌注为："+MONEY_D->money_str(me->query("bet/balance/unit"))+"\n"));
	}
	return 1;
}
int ask_biwu2(string arg)
{
	object me = this_player();
	object room, look_fight_room;
	object *obs, ob, obj;
	int k=0, unit, unit2;
	string str, id, name;
	
	if (me->query_temp("biwu_time") > time())
		return notify_fail("别急，先休息调整一会儿再上吧！\n");
	
	if (unit2 = me->query("bet/yuanbao/unit") > 0)
	{
		me->add("yuanbao", unit2);
		me->delete("bet/yuanbao");
		return notify_fail("你上次比武未完成，赌注"+(unit2)+"灵石退还至你账户！\n");
	}
	
	if (!look_fight_room=find_object(__DIR__"leitaier"))
		look_fight_room=load_object(__DIR__"leitaier");
	
	if (look_fight_room)
	{
		obs = all_inventory(look_fight_room);
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				k++;
				if (k > 0) {
					unit2 = ob->query("bet/yuanbao/unit");
					name = ob->name();
				}
			}
		}
		if (k >=2)
			return notify_fail("擂台上已经有人在决斗，你还是等会再上吧！\n");
	}
	
	if (me->is_busy())
		return notify_fail("你正忙呢！\n");
	
	if (me->is_fighting())
		return notify_fail("你已经在打架了，打完再说！\n");
	
	if (me->query("yuanbao") < 1)
		return notify_fail("比武需要1灵石做为入场费，你账户存款不足1灵石！\n");
	
	if (!arg) {
		str = sprintf("%s", "我要比武(进入):biwu2 yes" + ZJSEP);
		str += sprintf("%s", "打酱油的(取消):biwu2 no");
		tell_object(me, ZJOBLONG + "\n"+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else
	if (arg == "no") {
		tell_object(me, "你觉得比武这种事太危险了，还是去打酱油比较安全。\n");
		return 1;
	}
	
	if (sscanf(arg, "%s %s %d", arg, id, unit) != 3 ) {
		if (look_fight_room) {
			if (unit2 > 0) {
				str = sprintf("%s", "谁怕谁(进入):biwu2 yes no " + (unit2) + ZJSEP);
				str += sprintf("%s", "算了(取消):biwu2 no");
				tell_object(me, ZJOBLONG + name+"目前想赌灵石："
										+unit2+"，你确定进入吗？\n"
											+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
				return 1;
			}
		}
		
		obs = all_inventory(this_object());
		str = sprintf("%s%s", "自由挑战:biwu2 yes no 0" + ZJSEP, "算了(取消):biwu2 no");
		
		foreach(ob in obs) {
			if (userp(ob))
			{
				if (ob != me)
					str += sprintf(ZJSEP+"%s", HIC+ob->name() + NOR":biwu2 yes " + ob->query("id") + " 0");
			}
		}

		tell_object(me, ZJOBLONG + "你想邀请谁和你进行比赛？\n"
										+ZJOBACTS2+ZJMENUF(3,3,9,30) + str+"\n");
		return 1;
	} else {
		if (unit < 10 || unit > 1000)  {
			write(INPUTTXT("下赌注(灵石)：(10-1000灵石)","biwu2 yes "+(id != "no" ? id : "no")+" $txt#")+"\n");
			return 1;
		}
				
		if (me->query("yuanbao") < unit + 1) {
			tell_object(me, "你账户存款不足"+(unit + 1)+ "灵石"+"。\n");
			return 1;
		}
		
		if (obj = present(id, environment(me)))
		{
			me->set_temp("biwu/id", obj->query("id"));
			
			if (obj->query_temp("biwu/id") != me->query("id") ) {
				if ( me->query_temp("biwu/time") < time()) {
					me->set_temp("biwu/time", time() + 5);
					str = sprintf("%s", "谁怕谁(进入):biwu2 yes " + me->query("id") + " " + (unit) + ZJSEP);
					str += sprintf("%s", "惹不起(取消):biwu2 no");
					tell_object(obj, ZJOBLONG + me->name()+"想和你赌："
								+unit + "灵石"+"，你敢应战吗？\n"
											+ZJOBACTS2+ZJMENUF(3,2,9,30) + str+"\n");
				} 
				tell_object(me, "你已经向"+obj->name()+"发起挑战了，请耐心等待对方的答复。\n");
				return 1;
			}
		} else if (id != "no") {
			tell_object(me, "你想比武的人已经离开了。\n");
			return 1;
		}
		if (obj) {
			if (obj->query("yuanbao") >= unit + 1) {
				obj->add("yuanbao", -(unit));
				obj->set("bet/yuanbao/unit", (unit));
				tell_object(obj, "你下了赌注："+ unit + "灵石"+NOR"\n");
				log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
														"赌注："+unit + "灵石", ctime(time())));
			} else {
				tell_object(me, obj->name() + "账户灵石不足以下注，比赛取消。\n");
				tell_object(obj, "你的账户存款不足以下注，比赛取消。\n");
				return 1;
			}
			obj->add("yuanbao", -1);
			obj->move(__DIR__"leitaier");
			tell_object(obj, "你和"+me->name()+"双双跃上了擂台！\n");
			tell_object(me, "你和"+obj->name()+"双双跃上了擂台！\n");
			obj->delete_temp("biwu");
			tell_object(obj, ("你缴纳了1灵石做为比武入场费！本场比赛时间为：三分钟，赌注为："+obj->query("bet/yuanbao/unit")+"元……\n"));
		}
		if (!me->query("bet/yuanbao/unit")) {
			me->add("yuanbao", -(unit));
			me->set("bet/yuanbao/unit", (unit));
			tell_object(me, "你下了赌注："+ unit + "灵石"+NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"赌注："+unit + "灵石", ctime(time())));
		} else if ( unit2 > 0) {//如果擂台上有人
			me->add("yuanbao", -((unit)-me->query("bet/yuanbao/unit")));
			me->set("bet/yuanbao/unit", (unit));
			tell_object(me, "你赌注变更为："+ (unit + "灵石")+NOR"\n");
			log_file("dubo_pk", sprintf("%s %s   time:%s\n", me->name()+"("+me->query("id")+")",
													"赌注："+unit + "灵石", ctime(time())));
		} else
			tell_object(me, ("你决定将上次的赌赛继续进行("+
										MONEY_D->money_str(me->query("bet/yuanbao/unit"))+")！\n"));
		me->add("yuanbao", -1);
		me->move(__DIR__"leitaier");
		me->delete_temp("biwu");
		tell_object(me, ("你缴纳了1灵石做为比武入场费！本场比赛时间为：三分钟，赌注为："+me->query("bet/yuanbao/unit")+"灵石。\n"));
	}
	return 1;
}

void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
	me->delete("no_get");
	if (!living(me)) me->revive();
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("max_jing"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
	if (me->query("neili")<me->query("max_neili"))
		me->set("neili",me->query("max_neili"));
	if (me->query("jingli")<me->query("max_jingli"))
		me->set("jingli",me->query("max_jingli"));
	me->start_busy(0);
	tell_object(me,HIW "这里似乎有一种神秘的力量，你活动了一下经骨，发现并没有受伤！"NOR"\n");
}
int discmds()
{
	tell_object(this_player(),"现在你还是专心看比武吧！\n");
     return 1;
}
