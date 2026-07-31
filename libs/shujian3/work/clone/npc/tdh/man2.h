// man2.h
// Creat by Lklv for tdh job

void dest()
{
	object jober;
	if ( stringp(query("天地会jober"))
	 && objectp( jober = find_player(query("天地会jober")))
	 && jober->query_temp("tdhjob")
	 && jober->query_temp("天地会job/get") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s第%4d次任务失败(2)，时间：%4d，现经验：%d。",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/天地会")+1, uptime()-jober->query_temp("天地会job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("天地会job");
		jober->set_temp("天地会job/lost", query("name"));
		tell_object(jober, HIY"\n由于你动作太慢，"+this_object()->name()+"为躲避清廷追击，已先行藏匿了，你任务失败！"NOR"\n");
	}
	destruct(this_object());
}

int ask_tdh()
{
	object me=this_player();

	if (!me->query_temp("天地会job") || !me->query("天地会") ) {
		command("oh "+me->query("id"));
		command("say 常听人说天地会的都是好汉子，只是无缘结交。");
		return 1;
	}
	command("look "+me->query("id"));
	command("say 你可知道他们做的是什么事？");
	return 1;
}

int ask_fq()
{
	string tk, tname, str;
	object me=this_player();
	object ob=this_object();

	tk = me->query("天地会/tangkou");
	tname = me->query("天地会/title");
	str = me->query_temp("天地会job/target_1");

	if ( !me->query_temp("天地会job")
	|| !me->query("天地会")
	|| query("天地会jober") != me->query("id") ) {
		command("fear "+me->query("id"));
		command("say 不要乱说，那可是要掉脑袋的！");
		return 1;
	}
	if ( stringp(str)
	&& !stringp(query("have_leader")) ) {
		message_vision(CYN"$N对$n道：在下天地会"+tk+tname+me->name()+"，受命前来保护先生。"NOR"\n", me, ob);
		command("touch "+me->query("id"));
		command("follow "+me->query("id"));
		set_leader(me);
		set("have_leader", me->query("id"));
		me->set_temp("天地会job/get", ob->query("id"));
		me->set_temp("天地会job/get_name", ob->name());
		message_vision(CYN"$n对$N道：多谢阁下援手，在下这里先谢过了。请带我去见"+str+"。"NOR"\n", me, ob);
		remove_call_out("happen");
		call_out("happen", 1, me, ob);
		return 1;
	}
	command("noshame "+me->query("id"));
	set_leader(me);
	return 1;
}

void init()
{
	object me = this_player();

	::init();

	if ( me->query("tdh_bing2") == this_object()){
		kill_ob(me);
		me->kill_ob(this_object());
	}
	if (interactive(me)
	&& userp(me)
	&& query("天地会jober") == me->query("id") ){
		if ( query("have_leader")
		&& !random(4)
		&& stringp(me->query_temp("天地会job/3a"))
		&& me->query_temp("天地会job/killer") < 7
		&& !(environment(me)->query("no_fight")) ) {
			me->add_busy(1 + random(1));
			remove_call_out("addbing");
			call_out("addbing", 0, me, this_object() );
		}
		else if (!query("miss")) {
			remove_call_out("greeting");
			call_out("greeting", 1, me);
		}
	}
}

void heart_beat()
{
	object me, ob;

	::heart_beat();

	ob = this_object();
	if ( !ob) return;
	if ( ! query("have_leader") || ! query("天地会jober")) return;
	if ( !(	me = find_player(query("天地会jober"))) || !environment(me) || !environment(ob)) return;
	if ( environment(ob)->query("no_fight") && ! me->query_temp("天地会job/get"))
		random_move();
	if ( me->query_temp("天地会job/target_2") != query("id")) {
		dest();
		return;
	}
	if ( environment(me) != environment(ob) && ! ob->is_fighting()){
		ob->move(environment(me));
		message_vision("$N紧跟着$n快步走了过来。\n", ob, me);
	}
	if ( environment(me) != environment(ob) && ob->is_fighting()){
		ob->receive_wound("qi", 300);
	}
}

void greeting(object me)
{
	object ob = this_object();

	if (!me || !ob || !present(me, environment(ob)) || query("天地会jober") != me->query("id"))
		return;

	set("miss", 1);
	if ( !stringp(me->query_temp("天地会job/get")) ) {
		message_vision(HIW"\n$N老远看见一人，样子恍惚和"+me->query_temp("天地会job/target_1")+"说的那人很像。"NOR"\n", me, ob);
		message_vision(CYN"$N走上前去，作揖道：“请问阁下可是"+ob->name()+"？” 那人答道：“正是。”"NOR"\n", me, ob);
		return;
	}

	command("look "+me->query("id"));
	command("say 鞑子找的是我，和其他人无关。");
	return;
}

void happen( object me, object ob )
{
	object target;

	if ( !ob || !me || query("天地会jober") != me->query("id"))
		return;

	if ( me->query_temp("天地会job/meet") > 0) {
		call_out("addbing", 15, me, ob );
		return;
	}

	if ( me->query_temp("天地会job/lost")){
		command("sigh");
		command("bye "+ me->query("id"));
		dest();
		return;
	}

	target = new(__DIR__"bing");
	target->set("天地会jober", me->query("id"));
	target->set("tdh_bing2", ob);
	copy_npc(me, target, 110);

	target->move(environment(ob));
	me->add_temp("天地会job/meet", 1);
	target->kill_ob(ob);
	ob->kill_ob(target);
	message_vision(CYN"\n一个官差模样的人向$n道：‘反贼$n，老子奉命来拿你，走一趟吧！’"NOR"\n", target, ob);
	message_vision(CYN"$N哼道：“$n，你去死吧！”。"NOR"\n", ob, target);
	message_vision(CYN"$N怒道：“官府缉拿钦犯，闲杂人等闪开！”说罢便与$n战在了一起。"NOR"\n",target, ob);

	remove_call_out("addbing");

	if (query ("have_leader"))
		call_out("addbing", 15, me, ob );
	else
		call_out("addbing", 20, me, ob );
}

void addbing( object me, object ob )
{
	object target;

	if ( !ob || !me || query("天地会jober") != me->query("id"))
		return;

	if ( me->query_temp("天地会job/lost")){
		command("sigh");
		command("bye "+ me->query("id"));
		dest();
		return;
	}
	if ( me->query_temp("天地会job/meet") < 2) {
		target = new(__DIR__"bing");
		target->set("天地会jober", me->query("id"));
		copy_npc(me, target, 110);
		target->set("tdh_bing2", ob);
		target->move(environment(me));
		me->add_temp("天地会job/meet", 1);
	}
	else {
		call_out("addbing", 20, me, ob );
		return;
	}

	me->add_busy(1 + random(2));
	command("escape "+me->query("id"));
	message_vision(HIR"\n远处飞奔过来个人影，边跑边叫：“御前侍卫$N在此！天地会反贼休走！”。\n", target);
	message_vision(CYN"$N叫道：“缉拿钦犯，闲杂人等闪开！”说罢便与$n战在了一起。"NOR"\n", target, me);
	message_vision(CYN"$N直向$n扑了过去，嘴里大喊道：“反贼！快快束手就擒吧！”"NOR"\n", target, ob);
	target->kill_ob(me);
	return;
}

void kill_ob(object ob)
{
	object me=this_player();

	if (!me) return;

	if (userp(me) && query("have_killer") != me->name()){
		command("say 好你个鞑子的走狗！今天我来为民除害！");
		command("chat "+me->name()+"奸诈险恶，竟然投靠清廷做了鞑子的走狗，大家小心...");
		set("have_killer", me->name());
		set("job_npc",1);///added by Ciwei
	}
	::kill_ob(ob);
}

void die()
{
	object jober, killer;

	killer = query_temp("last_damage_from");

	if ( objectp(killer) && userp(killer) ){
		killer->add("shen", -DE_LVL* 20);
		killer->set_temp("kill_tdhnpc", this_object()->name());
	}
	if ( stringp(query("天地会jober"))
	 && objectp( jober = find_player(query("天地会jober")))
	 && jober->query_temp("tdhjob")
	 && jober->query_temp("天地会job/get") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s第%4d次任务失败(4)，时间：%4d，现经验：%d。",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/天地会")+1, uptime()-jober->query_temp("天地会job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("天地会job");
		jober->set_temp("天地会job/lost", query("name"));
		message_vision(HIY"\n糟了！"+this_object()->name()+"死亡，任务失败！"NOR"\n", jober);
	}

	command("say 做了鬼我也还是要反清复明！");
	::die();
}
