// leitai.h

void init()
{
	object me = this_player();

	if (!userp(me)) return;
	if (!wizardp(me) && !me->query_temp("leitai")) {
		message_vision("突然飞出一只大脚，将$N从擂台给踢了出去！\n", me);
		me->move(query("dest_room"));
		message_vision("“啊……”的一声，$N被人从擂台给踢了出来。\n", me);
	}

	if (!query_temp("leitai")
	&& base_name(me) == "/cmds/leitai/leitaiuser") {
		me->quit(me);
		return;
	}

	if (!wizardp(me)) message_vision("$N急急忙忙地走进了擂台。\n", me);
	else {
		add_action("do_load", "login");
           add_action("do_open", "xinxi");
		add_action("do_tui", "tui");
	}
	add_action("do_leave", "leave");
    add_action("do_set","set");
	add_action("do_ok", "ok");
        add_action("do_set", "set");
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
				  "kill", "fight", "study", "practice", "exercise", "halt",
				  "quit", "save" , "throw", "suicide", "yield", "shout",
				  "rumor", "chat", "party", "group", "irc", "sj" }));
}

int do_set(string arg)
{
    object me = this_player();

    "/cmds/usr/set"->main(me,arg);
    return 1;
}

int do_action(string arg)
{
	if(!wizardp(this_player())){
		write("擂台上只能比武，请不要做不相关的事！\n");
		return 1;
	}
	return 0;
}

int open = 0;


int do_open(string arg)
{
	object me = this_player();

	if( wiz_level(me) < 3 )
		return notify_fail("只有 (wizard) 以上的巫师才能打开擂台信息。\n");
   if( !arg && arg != "close" && arg != "open")
		return notify_fail("目前的擂台信息状况是："+(open == 0?"close":"open")+"\n");

	if( arg == "open" ){
		open = 1;
		message("leitai", HIY +"\n【"+environment(me)->query("short")+"擂台】：开放此擂台结果信息，不希望看见的玩家请 set block_leitai 。\n"NOR"\n", users());
		return notify_fail("你打开了擂台的信息状况。\n");
	}

	if( arg == "close" ){
		open = 0;
		message("leitai", HIY +"\n【"+environment(me)->query("short")+"擂台】：关闭此擂台结果信息。\n"NOR"\n", users());
		return notify_fail("你关闭了擂台的信息状况。\n");
	}
	return notify_fail("你可以设定擂台信息状况是 open (所有人都能看见结果) 还是 close (只有看台的人才看见结果)\n");
}


void end_fight(object me, object ob, string fam)
{
	string fam2, color;

	fam2 = ob->query("family/family_name")?ob->query("family/family_name"):"普通百姓";
	color = ob->query("color")?" "+ob->query("color"):" ";
	fam2 = fam2 + color + ob->query("name") + NOR + "(" + capitalize(ob->query("id")) + ")";
	message_vision("\n"+fam+" 被 "+fam2+" 击败。\n", me, ob);
	if( open > 0 )
		message("leitai", HIY +"\n【"+environment(me)->query("short")+"擂台】比武已经决出胜负："+ fam+HIY" 被 "+fam2+HIY" 击败！\n"NOR"\n",
		filter_array(users(), (:  !$1->query("env/block_leitai") :)));
	//Log.
	log_file("leitai", sprintf("%s(%s) 在擂台上击败 %s(%s)。\n", ob->name(1), ob->query("id"), me->name(1), me->query("id")	), ob->query("id"), ({ me->query("id") }) );
}

int start_biwu(object fighter, object fighter2, int num)
{
	object *ob;
	int i;

	if (!fighter || environment(fighter) != this_object()) {
		if(fighter2) fighter2->quit(fighter2);
		tell_room(this_object(), "\n"+query("short")+"比赛中止！\n");
		return 1;
	}

	if (!fighter2 || environment(fighter2) != this_object()) {
		if(fighter) fighter->quit(fighter);
		tell_room(this_object(), "\n"+query("short")+"比赛中止！\n");
		return 1;
	}

	num++;

	if( num <= 1 ){
		fighter->set_temp("last_damage_from", fighter2);
		fighter2->set_temp("last_damage_from", fighter);

		ob = all_inventory(this_object());
		i = sizeof(ob);
		while (i--) {
			if(!userp(ob[i]) && !ob[i]->query_temp("leitai"))
				destruct(ob[i]);
		}
		tell_room(this_object(), HIR+"\n\t"+query("short")+HIR"上传来第一声锣响！\n"NOR"\n");
	}
	else if( num >= 3 ){
		message_vision(HIR"只听第三声锣响，$N和$n比武正式开始！"NOR"\n", fighter, fighter2);
		if( open > 0 )
			message("leitai", HIY +"\n【"+query("short")+"擂台】：各位江湖同道，\n\t\t"
			NOR+fighter->short(1)+HIY" 与\n\t\t"NOR+fighter2->short(1)+HIY" 比武正式开始！\n"NOR"\n",
			filter_array(users(), (:  !$1->query("env/block_leitai") :)));
		else message_vision(HIY +"\n【"+query("short")+"擂台】"
			+fighter->short(1)+HIY" 与 "+fighter2->short(1)+HIY" 比武正式开始！"NOR"\n",
			fighter, fighter2);

		fighter->delete("last_death_time");
		fighter2->delete("last_death_time");
		fighter2->kill_ob(fighter);
		fighter->kill_ob(fighter2);
		return 1;
	} else
		tell_room(this_object(), HIR+"\n\t"+this_object()->query("short")+HIR"上传来第"+chinese_number(num)+"声锣响！\n"NOR"\n");

	remove_call_out("start_biwu");
	call_out("start_biwu", 2, fighter, fighter2, num);
	return 1;
}

int do_ok()
{
	object ob, me = this_player();

	if (!me->query_temp("leitai") || base_name(me) != "/cmds/leitai/leitaiuser")
		return notify_fail("此命令只有上台比武的选手可用。\n");
	if(me->query_temp("leitai") == 2)
		return notify_fail("你已经出言挑战了。\n");

	me->set_temp("leitai", 2);
	if (!objectp(ob = this_object()->query_temp("fighter"))){
		set_temp("fighter", me);
		message_vision("\n$N作了个揖："+RANK_D->query_self(me)+"已经准备好了，愿接受挑战！\n", me);
	}
	else if (environment(ob) != this_object()) {
		ob->quit();
		set_temp("fighter", me);
		message_vision("\n$N作了个揖："+RANK_D->query_self(me)+"已经准备好了，愿接受任何挑战！\n", me);
	} else {
		delete_temp("fighter");
		message_vision("\n$N对$n作了个揖："+RANK_D->query_self(me)+"冒昧，挑战"+RANK_D->query_respect(ob)+"！\n", me, ob);
		start_biwu(me, ob, 0);
	}

	return 1;
}

void leaving(object me)
{
	if (!me || me->is_fighting() ) return;
	if (!me->query_temp("leitai"))
		return;
	message_vision(HIW"\n$N一脸高傲的神态：竟然没人敢来挑战，看来"+RANK_D->query_self(me)+"真是天下无敌了！"NOR"\n", me);
	me->die();
}

int do_leave()
{
	object me = this_player();

	if (!me->query_temp("leitai") || base_name(me) != "/cmds/leitai/leitaiuser")
		return notify_fail("此命令只有上台比武的选手可用。\n");

	message_vision(HIW"\n$N深叹了一口气："+RANK_D->query_self(me)+"技不如人，情愿认输！"NOR"\n", me);
	me->die();
	return 1;
}

int do_tui(string arg)
{
	object ob;

	if (wiz_level(this_player()) < 3)
		return notify_fail("只有 (wizard) 以上的巫师才能将人推出擂台！\n");

	if (!arg) return notify_fail("你要推谁？\n");

	if (!ob = present(arg,this_object()))
		return notify_fail("找不到 "+arg+" 这个玩家。\n");

	if (!userp(ob))
		return notify_fail("找不到 "+arg+" 这个玩家。\n");

	if (!ob->query_temp("leitai") || base_name(ob) != "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name()+"不是通过正当途径进入擂台，不能被推出擂台。\n");

	message_vision("$N耍了个太极，将$n一把推出了擂台。\n", this_player(), ob);
	ob->quit();
	return 1;
}

int load_user(object player)
{
	object user;
	string arg, color;

	arg = player->query("id");

	if (!arg
	|| this_object()->query_temp("leitai") > 1
	|| base_name(player) == "/cmds/leitai/leitaiuser")
		return 0;

	seteuid(arg);
	user = new("/cmds/leitai/leitaiuser", arg);   // 去掉了save()，擂台中的一切和本身无关。
	player->save();
	if (!user->restore()) {
		destruct(user);
		write("User Restore Error，请通知巫师。\n");
		return 0;
	}

	user->delete("worker");
	user->setup();
	user->set_temp("leitai", 1);
	exec(user, player);
	user->set("link_ob", player);
	user->set_temp("link_ob", player->query_temp("link_ob"));
	this_object()->add_temp("leitai", 1);
	user->move(this_object());
	user->clear_condition();
	user->reincarnate();
	user->delete_temp("combat_yield");
	user->set("channels", ({ "rumor", "err" }) );
	tell_object(user, YEL"你进入比武擂台，目前处于最佳状态中。"NOR"\n""
需要兵器请从物品架上拿"YEL" na"NOR" 。
如果你准备好了请打"YEL" ok"NOR"。
如果你要放弃比赛，请打"YEL" leave"NOR"。\n");

	arg = user->query("family/family_name")?user->query("family/family_name"):"普通百姓";
	color = user->query("color")?" "+user->query("color"):" ";
	arg += color + user->query("name") + NOR "(" + capitalize(user->query("id")) + ")";
	tell_room(this_object(), arg + YEL"进入比武擂台。"NOR"\n", ({ user }));
	player->set_temp("apply/short", ({player->name()+"("+player->query("id")+")"YEL" <打擂中>"NOR}));
	player->set_leader(0);
	call_out("leaving", 90, user);
	return 1;
}

int do_load(string arg)
{
	object me, user, ob;
	string arg1, arg2;

	if (!arg) return 0;
	if(sscanf(arg, "%s with %s", arg1, arg2)!=2){
		if(!me = find_player(arg))
			return notify_fail("命令格式: login <player name1> with <player name2>。\n");
		else return load_user(me);
	}

	me = this_player();

	if (query_temp("leitai") > 1)
		return notify_fail("这里正在比武呢，你先等他们分出胜负再说吧。\n");

	if (wiz_level(me) < 3)
		return notify_fail("只有 (wizard) 以上的巫师才能在擂台login其他player。\n");

	if (wiz_level(me) < wiz_level(arg1))
		return notify_fail("你不能装载巫师级别比你高的玩家。\n");

	ob = find_player(arg2);
	if (!ob) return notify_fail("让谁为代表进入擂台？\n");
	if (ob->query_temp("leitai")
	|| base_name(ob) == "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name()+"正在别的擂台比武中。\n");

	seteuid(arg1);
	user = new("/cmds/leitai/leitaiuser", arg1);   // 去掉了save()，擂台中的一切和本身无关。
	if(!user->restore()) {
		destruct(user);
		return notify_fail("你想让哪个玩家的拷贝进入擂台？\n");;
	}
	if(!environment(ob)->query("no_fight"))
		ob->move("/d/city/chmiao");  // 防止比武时本身被杀
	user->delete("worker");
	user->setup();
	if (wiz_level(user) > wiz_level(me)){
		user->quit();
		return notify_fail("你不能装载巫师级别比你高的玩家。\n");
	}

	user->set_temp("leitai", 1);
	exec(user, ob);
	user->set("link_ob", ob);
	user->set_temp("link_ob", ob->query_temp("link_ob"));
	this_object()->add_temp("leitai", 1);
	user->move(this_object());
	user->clear_condition();
	user->reincarnate();
	user->delete_temp("combat_yield");
	user->set("channels", ({ "rumor" , "err"}) );
	tell_object(user, YEL"你代表"+user->query("name")+"进入擂台，目前处于最佳状态中。"NOR"\n""
需要兵器请从兵器架上拿"YEL" na"NOR" 。
如果你准备好了请打"YEL" ok"NOR"。
如果你要放弃比赛，请打"YEL" leave"NOR"。\n");
	tell_room(environment(user),YEL+ob->query("name")+"代表"+user->name()+"进入比武擂台。\n"NOR"\n", ({ user }));
	ob->set_temp("apply/short", ({ob->name()+"("+ob->query("id")+")"YEL" <打擂中>"NOR}));
	return 1;
}
