string *jjrooms = ({
			__DIR__"center",
			__DIR__"west",
			__DIR__"east",
			__DIR__"north",
			__DIR__"south",
		});

static object *total = ({ });
static object *jjnpc = ({ });

private void init_player(object me);
private void message_competition(string msg);
private void auto_check();
private void give_bouns(object me);
private void kickout_players();
private void restore_status(object me);
int check_out(object me);

void init()
{
	add_action("jjsign","jjsign");
}

int valid_leave(object me, string dir)
{
	if(me->query_temp(FAMILY+"-jjsign"))
	{
		tell_object(me,HIR"你离开了竞技场，报名自动取消。再进入需要重新报名！！！！！！！！！！"NOR"\n");
		me->delete_temp(FAMILY+"-jjsign");
	}
	return ::valid_leave(me, dir);
}

int jjsign()
{
	int now = time();
	object me = this_player();

	if(localtime(now)[6]!=MENPAI_DAY||localtime(now)[2]!=MENPAI_HOUR||localtime(now)[1]>MENPAI_PRE)
		return notify_fail(ZJOBLONG"报名时间：每周"+chinese_number(MENPAI_DAY)+MENPAI_HOUR+":00-"+MENPAI_HOUR+":10。\n");

	if(!me->query("family/family_name")||me->query("family/family_name")!=FAMILY)
		return notify_fail("你不是"+FAMILY+"中人，还是回自己的门派报名吧！\n");

	if (me->query("combat_exp",1)<200000)
		return notify_fail("你年纪尚小，还是把功夫练好再来吧。\n");

	me->set_temp(FAMILY+"-jjsign",1);
	tell_object(me,"报名成功，请在此稍后，"+MENPAI_HOUR+"点10分自动进入竞技场中。\n");
	set_heart_beat(1);
	return 1;
}

private void auto_check()
{
	object ob;
	string msg;
	string room;
	object *lost;
	int i,pot,exp;

	lost = ({ });
	for (i = 0; i < sizeof(total); i++)
	{
		if (! objectp(total[i]))
			continue;
		room = base_name(environment(total[i]));
		if (member_array(room,jjrooms)==-1)
		{
			// not in pk room
			restore_status(total[i]);
			total[i] = 0;
			continue;
		}
		if (total[i]->query("qi") < 1 || total[i]->query("jing") < 1)
			lost += ({ total[i] });
	}

	foreach (ob in jjnpc)
	{
		if (!objectp(ob))
			jjnpc -= ({ ob });
	}

	// kickout the players who lost competition
	foreach (ob in lost)
		check_out(ob);

	total -= ({ 0 });

	if (sizeof(total) < 1)
	{
		msg = "听说"+FAMILY+"门派竞技参赛者死的死，逃的逃，现在一个人都没有啦！";
	} else
	if (sizeof(total)==1&&sizeof(jjnpc)==0)
	{
		// change the daemon's state
		msg = "听说"+FAMILY+"门派竞技大赛圆满结束，" + total[0]->name(1) + "获得"+FAMILY+"首席弟子称号！";
		FAMILY_D->set_family_leader(FAMILY,total[0]->query("id"));
		give_bouns(total[0]);
	} else
		return;

	set_heart_beat(0);
	delete("pre_start");
	delete("start");
	message_competition(msg);
}

private void init_player(object me)
{
	tell_object(me, HIY "你眼前忽然一花..."NOR"\n");
	me->set_override("unconcious", (: call_other, __FILE__, "check_out" :));
	me->set_override("die", (: call_other, __FILE__, "check_out" :));
	me->set_override("quit", (: call_other, __FILE__, "check_quit" :));
	me->set_temp("backup/killer", me->query_killer());
	me->set_temp("backup/want", me->query_want());
	me->set_temp("in_pkd", 1);
	me->delete_temp(FAMILY+"-jjsign");

	me->set("backup/condition", me->query_condition());
	me->clear_condition();
}

private void kickout_players()
{
	object ob;
	string room;
	mapping my;

	if (! arrayp(total))
		return;

	foreach (ob in total)
	{
		if (! objectp(ob))
			continue;
		room = base_name(environment(ob));
		if (member_array(room,jjrooms)==-1)
			// not in pk room
			continue;

		my = ob->query_entire_dbase();
		my["eff_qi"] = my["max_qi"];
		my["eff_jing"] = my["max_jing"];
		my["qi"] = 1;
		my["jing"] = 1;

		tell_object(ob, HIC "本次竞技结束，你被送出比赛场地！”"NOR"\n");

		restore_status(ob);
		ob->move(this_object());
		message("vision", "只见" + ob->name() + "悻悻的走了出来。\n",	environment(ob), ({ ob }));
		if (! living(ob))
			ob->revive();
	}

	total = ({ });
}

private void kickout_jjnpc()
{
	object ob;
	string room;
	mapping my;

	if (! arrayp(jjnpc))
		return;

	foreach (ob in jjnpc)
	{
		if (! objectp(ob))
			continue;
		destruct(ob);
	}

	jjnpc = ({ });
}

private void message_competition(string msg)
{
	CHANNEL_D->do_channel(this_object(), "rumor", msg);
}

private void give_bouns(object me)
{
	int exp;
	int pot;
	string msg;
	object ob;

	restore_status(me);
	tell_object(me, "这次真是爽呆了...\n");
	me->move(this_object());
	message("vision", me->name() + "慢慢的走了过来，一脸奸笑。\n",environment(me), ({ me }));

	// bouns

	tell_object(me, HIY"恭喜你获得了本门首席弟子称号，你可以每天到师门那里领取一次奖励"NOR"。\n");
}

private void restore_status(object me)
{
	mapping my;
	mapping cnd;
	string *ks;
	int i;

	me->delete_temp("in_pkd");
	me->delete_override("unconcious");
	me->delete_override("die");
	me->delete_override("quit");
	me->remove_all_enemy(1);
	me->remove_all_killer();
	me->clear_condition();
	me->receive_damage("qi", 0);
	me->apply_killer(me->query_temp("backup/killer"));
	me->apply_want(me->query_temp("backup/want"));

	cnd = me->query("backup/condition");
	me->delete("backup/condition");
	me->delete_temp("block_msg/all");
	if (! mapp(cnd)) return;
	ks = keys(cnd);
	for (i = 0; i < sizeof(ks); i++)
		me->apply_condition(ks[i], cnd[ks[i]]);

	my = me->query_entire_dbase();
	if (my["qi"] < 1)       my["qi"] = 1;
	if (my["eff_qi"] < 1)   my["eff_qi"] = 1;
	if (my["jing"] < 1)     my["jing"] = 1;
	if (my["eff_jing"] < 1) my["eff_jing"] = 1;
}

void heart_beat()
{
	int i,now = time();
	object room,*inv,ob;
	string file;

	room = this_object();

	if(!query("pre_start")&&localtime(now)[1]==MENPAI_PRE)
	{
		set("pre_start",1);
		tell_room(this_object(),"1分钟后将进入竞技场，请做好准备。。。\n");
	}
	else if(!query("start")&&localtime(now)[1]==(MENPAI_PRE+1))
	{
		set("start",1);
		inv = filter_array(all_inventory(this_object()), (: playerp($1)&&$1->query_temp(FAMILY+"-jjsign") :));
		if(sizeof(inv)<MENPAI_USER_MIN)
		{
			tell_room(this_object(),"报名人数不足"+MENPAI_USER_MIN+"人，本次活动未能成功进行。。。\n");
			delete("pre_start");
			delete("start");
			set_heart_beat(0);
			return;
		}
		total = inv;
		for(i=0;i<sizeof(inv);i++)
		{
			init_player(inv[i]);
			inv[i]->move(jjrooms[random(sizeof(jjrooms))]);
			tell_object(inv[i], HIY "你定神一看，才发现自己到了" + environment(inv[i])->short() + NOR "。\n");
		}
		foreach (file in jjrooms)
		{
			ob = new("/kungfu/class/generate/jjnpc");
			ob->setup_family(FAMILY);
			NPC_D->init_npc_skill(ob, 5 + random(2));
			ob->move(file);
			jjnpc += ({ ob });
		}
	}
	else if(localtime(now)[1]>MENPAI_PRE)
	{
		auto_check();
	}
	else if(localtime(now)[1]>(MENPAI_PRE+MENPAI_TIME))
	{
		message_competition("听说"+FAMILY+"门派竞技大赛众弟子势均力敌，未能选首席弟子！");
		delete("pre_start");
		delete("start");
		kickout_players();
		kickout_jjnpc();
		set_heart_beat(0);
	}
}

int check_quit(object me)
{
	message_competition("听说" + me->name(1) + "临阵脱逃，从"+FAMILY+"门派竞技场溜走了。");
	restore_status(me);
	if (arrayp(total))
		total -= ({ me });

	tell_object(me, "你逃出了竞技场。\n");

	me->move(this_object());
	message("vision", "只见" + me->name() + "慌里慌张的跑了出来。\n",environment(me), ({ me }));
	return 1;
}

int check_out(object me)
{
	object ob;
	mapping my;
	string msg;
	string room;
	int score;

	room = base_name(environment(me));
	if (member_array(room,jjrooms)==-1)
	{
		// not in pk room
		total -= ({ me });
		return 0;
	}

	my = me->query_entire_dbase();
	my["eff_qi"] = my["max_qi"];
	my["eff_jing"] = my["max_jing"];
	my["qi"] = 1;
	my["jing"] = 1;

	tell_object(me, HIR "\n你觉得眼前一阵模糊...这下完了！"NOR"\n");
	if (ob = me->query_last_damage_from())
	{
		msg = "听说" + me->name(1) + "在"+FAMILY+"门派竞技中惨遭" + ob->name(1) + "的毒手，被无情淘汰。";
	} else
		msg = "听说" + me->name(1) + "在"+FAMILY+"门派竞技中运气不佳，本领有限、已经惨遭淘汰。";
	message_competition(msg);

	restore_status(me);
	total -= ({ me });
	me->move(this_object());
	message("vision", "一个黑影倏的窜了出来，随即就是“啪”的一声，就见" + me->name() +"摔倒了地上，一副半死不活的样子。\n", environment(me), ({ me }));
	tell_object(me, "半昏半迷中，你觉得被人拎了起来，又重重的摔倒了地上。\n");
	if (! living(me))
		me->revive();
	return 1;
}
