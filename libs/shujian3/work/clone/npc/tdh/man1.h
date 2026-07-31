// man1.h
// Creat by Lklv for tdh job
#include <job_mul.h>
void dest()
{
	object jober;
	if ( stringp(query("天地会jober"))
	&& objectp( jober = find_player(query("天地会jober")))
	&& jober->query_temp("tdhjob")
	&& jober->query_temp("天地会job/target_1id") == query("id")){
		log_file("job/tiandi", sprintf("%8s%-10s第%4d次任务失败(1)，时间：%4d，现经验：%d。",
			jober->name(), "("+jober->query("id")+")", jober->query("job_time/天地会")+1, uptime()-jober->query_temp("天地会job/time"), jober->query("combat_exp")), jober);
		jober->delete_temp("天地会job");
		jober->set_temp("天地会job/lost", query("name"));
		tell_object(jober, HIY"\n由于你动作太慢，"+this_object()->name()+"为躲避清廷追击，已先行藏匿了，你任务失败！"NOR"\n");
	}
	destruct(this_object());
}

string ask_fq()
{
	object me=this_player();

	if ( !me->query_temp("天地会job") || !me->query("天地会")
	|| me->query_temp("天地会job/target_1id") != query("id")) {
		command("fear "+me->query("id"));
		me->add_temp("asktimes", 1);
		return "不要乱说，那可是要掉脑袋的！\n";
	}
	if ( !me->query_temp("asked") ) {
		me->delete_temp("asktimes");
		command("? "+me->query("id"));
		me->set_temp("asked", 1);
		return "阁下不妨报个字号，在下也好知道是哪一路上的朋友。\n";
	}
	return "那是自然！\n";
}

string ask_qk()
{
	object me=this_player();

	if (!me->query_temp("天地会job") || !me->query("天地会")
	|| me->query_temp("天地会job/target_1id") != query("id"))
		return "什么切口？你是玩刀的？哈哈，有意思！\n";
	if ( !query("wait_answer") && me->query_temp("asked") ){
		set("wait_answer", 1);
		return "切口？哈哈，有点意思，你先说说("+ZJURL("cmds:qiekou")+ZJSIZE(22)+"qiekou"NOR")。\n";
	}
	return "地振高冈，一派溪山千古秀。\n";
}

void init()
{
	object me = this_player();

	::init();

	add_action("do_da", ({"da", "qiekou"}));

	if ( me->query("tdh_bing") == this_object()){
		kill_ob(me);
		me->kill_ob(this_object());
	}
	if (interactive(me)
	&& userp(me)
	&& me->query_temp("天地会job/target_1id") == query("id")
	&& query("天地会jober") == me->query("id") ) {
		if (stringp(me->query_temp("天地会job/get")) ) {
			remove_call_out("finish");
			call_out("finish", 0, me);
			command("nod ");
		}
		else {
			remove_call_out("checking");
			call_out("checking", 1, me);
			command("lazy ");
		}
	}
}

void heart_beat()
{
	object me, ob = this_object();
	::heart_beat();
	if ( !query("天地会jober")){
		dest();
		return;
	}
	if ( !objectp(me = find_player(query("天地会jober"))) || !environment(me) || !environment(ob)) return;
	if ( environment(ob)->query("no_fight"))
		random_move();
	if ( me->query_temp("天地会job/target_1id") != query("id"))
		dest();
}

void finish(object me)
{
	object target, ob = this_object();
	mapping tdh;
	string str;
	int exp, pot, time;

	if (!me
	 || !present(me, environment(ob))
	 || !mapp( tdh = me->query_temp("天地会job")) )
		return;

	if ( tdh["target_2"] && objectp(target = present(tdh["target_2"], environment(me))) ){
		me->add_busy(2);
		target->set_leader(0);
		if ( tdh["killer"] >= 7 ){
			me->query("gender")=="男性"? str = me->name()+"兄":str = me->name()+"姐";
			message_vision(CYN"$N作揖道：“ "+target->name()+"兄、"+str+"，路上辛苦了，多谢"+str+"相助！”"NOR"\n", ob, me);
			message_vision(CYN"$N对$n道：“在下和"+target->name()+"兄还有要事在身，先告辞了。”"NOR"\n", ob, me);
			command("bye ");

/*
			exp = 550 + random(300);
			time = uptime() - me->query_temp("天地会job/time");
			if ( exp / time > 35/18)
				exp = to_int(35/18.0 * time);
			
			exp = me->add_exp_combat(exp,this_object(),"天地会");
						
			pot = exp/5 + random(exp/10);						
			me->add("potential", pot);
			if ( me->query("potential", 1) > me->query("max_pot"))
				me->set("potential" , me->query("max_pot"));
*/
						
			me->set("job_name", "天地会");
			me->clear_condition("job_busy");
/*
                   tell_object(me, HIY"恭喜你任务顺利完成，你获得了"+chinese_number(exp)+"点经验，"+chinese_number(pot)+"点潜能的奖励。"NOR"\n");
			log_file("job/tiandi", sprintf("%8s%-10s第%4d次任务完成(1)，经验：%4d，潜能：%3d，时间：%4d，现经验：%d。",
				me->name(), "("+me->query("id")+")", me->query("job_time/天地会"), exp, pot, time, me->query("combat_exp")), me);
*/

                   TASKREWARD_D->get_reward(me,"天地会",1,0,0,8,0,0,0,this_object());

			me->delete_temp("天地会job");
			me->delete_temp("tdhjob");
			
			destruct(target);
			destruct(ob);
			return;
		}
		else if ( tdh["shiwei"] > 14){
			me->query("gender")=="男性"? str = me->name()+"兄":str = me->name()+"姐";
			message_vision(CYN"$N作揖道：“ "+target->name()+"兄、"+str+"，路上辛苦了，多谢"+str+"相助！”"NOR"\n", ob, me);
			message_vision(CYN"$N对$n道：“看来靼子来势汹汹，我们还是分别撤退吧。”"NOR"\n", ob, me);
			command("bye ");

/*
			exp = 300 + random(200);
			
			//< Added by mxzhao 2005/01/09
			exp = me->add_exp_combat(exp,this_object(),"天地会");
			//> Added by mxzhao 2005/01/09

			pot = exp/5 + random(exp/10);

			//< Modified by mxzhao 2005/01/09
			//奖励控制开始
			//if (me->query("registered")==3){
			//	exp = exp * TDH_JOB_MUL * VIP_MUL /10000;
			//			pot = pot * TDH_JOB_MUL * VIP_MUL /10000;
			//}
			//else
			//{
			//	exp = exp * TDH_JOB_MUL /100;
			//		pot = pot * TDH_JOB_MUL /100;
			//}
			//奖励控制结束	
			//
			//me->add("combat_exp", exp);
			//> Modified by mxzhao 2005/01/09
*/
/*
			me->add("potential", pot);
			if ( me->query("potential", 1) > me->query("max_pot"))
				me->set("potential" , me->query("max_pot"));
			time = uptime() - me->query_temp("天地会job/time");
			me->add("job_time/天地会", 1);
			GIFT_D->check_count(me,this_object(),"天地会");
*/

			me->set("job_name", "天地会");
			me->clear_condition("job_busy");

/*
			tell_object(me, HIY"任务完成，你获得了"+chinese_number(exp)+"点经验，"+chinese_number(pot)+"点潜能的奖励。"NOR"\n");
			log_file("job/tiandi", sprintf("%8s%-10s第%4d次任务完成(2)，经验：%4d，潜能：%3d，时间：%4d，现经验：%d。",
				me->name(), "("+me->query("id")+")", me->query("job_time/天地会"), exp, pot, time, me->query("combat_exp")), me);
*/

                   TASKREWARD_D->get_reward(me,"天地会",1,0,0,5,0,0,0,this_object());

			me->delete_temp("天地会job");
			me->delete_temp("tdhjob");
			destruct(target);
			destruct(ob);
			return;
		}
		else if (!query("miss")) {
			set("miss", 1);
			me->query("gender")=="男性"? str = me->name()+"兄":str = me->name()+"姐";
			message_vision(CYN"\n$N拱手道：“"+target->name()+"兄、"+str+"，请借一步说话。”\n", ob, me);
			message_vision(HIW"只听$N向远处大喝一声：“狗贼，鬼鬼祟祟跟到这里，还不出来受死！”喊声中气十足。"NOR"\n", ob, me);
			remove_call_out("addbing");
			call_out("addbing", 3, me, ob, target);
		}
	}
	remove_call_out("checking");
	call_out("checking", 5, me);
	return;
}

void checking(object me)
{
	object ob, target;
	mapping tdh;
	ob = this_object();

	if (!me || !ob || !present(me, environment(ob)) || !mapp( tdh = me->query_temp("天地会job")) )
		return;

	if ( stringp(tdh["lost"]) ) {
		message_vision(CYN"\n$N对$n深深叹了口气：‘"+tdh["lost"]+"已经遇害了。’说完摇了摇头，转身走了。"NOR"\n", ob, me);
		me->delete_temp("天地会job");
		me->delete_temp("asked");
		me->delete_temp("tdhjob");
		destruct(ob);
		return;
	}
	if ((!ob->query("qi") >= ob->query("max_qi")/2)
	&& (ob->query("cure") < 5)){
		 ob->add("qi",ob->query("max_qi")/8);
		 ob->add_temp("cure",1);
		 tell_room(environment(ob), ob->name()+"深深的吸了口气，脸色顿时好了许多。\n", ({ob}));
	}
	if ( stringp(tdh["get"])
	&& objectp(target = present(tdh["target_2"], environment(me)))
	&& tdh["killer"] < 7
	&& tdh["shiwei"] < 14 ) {
		remove_call_out("addbing");
		call_out("addbing", 5, me, ob, target);
	}
	else if ( stringp(tdh["get"])
	 && objectp(target = present(tdh["target_2"], environment(me)))
	 && tdh["meet"] < 1
	 && tdh["shiwei"] >= 14){
	 	target->set_leader(0);
		remove_call_out("finish");
		call_out("finish", 0, me);
	}
	else if ( stringp(tdh["get"])
	&& objectp(target = present(tdh["target_2"], environment(me)))
	&& tdh["meet"] < 1
	&& tdh["killer"] >= 7 ) {
		me->add_busy(2);
		target->set_leader(0);
		remove_call_out("finish");
		call_out("finish", 0, me);
	}
	else if ( stringp(tdh["get"]) ){
		remove_call_out("finish");
		call_out("finish", 15, me);
	}
	remove_call_out("checking");
	call_out("checking", 15, me);
}

void addbing(object me, object ob, object ob2)
{
	object target;
	int i;

	if ( !ob || !ob2 || !me || query("天地会jober") != me->query("id") )
		return;

	if ( me->query_temp("天地会job/meet") > 0) {
		remove_call_out("checking");
		call_out("checking", 5, me);
		return;
	}
	for (i =0; i < 3; i++){
		target = new(__DIR__"bing");
		target->set("天地会jober", me->query("id"));
		target->set("tdh_bing", ob);
		target->set("tdh_bing2", ob2);
		copy_npc(me, target, 80);
		target->move(environment(me));
		me->add_temp("天地会job/meet", 1);
		me->add_temp("天地会job/shiwei", 1);
		target->kill_ob(me);
	}

	me->add_busy(1 + random(2));
	command("grpfight ");

	tell_room(environment(ob), HIR"围观的人群中突然有人喊道：‘御前侍卫"+target->name()+"等在此！反贼休走！’。"NOR"\n", ({ob}));
	tell_room(environment(ob), CYN+target->name()+"叫道：“缉拿钦犯，闲杂人等闪开！”说罢便与"+me->name()+"等战在了一起。"NOR"\n",({ob}));
//	message_vision(CYN"$N吼道：‘反贼！还不乖乖束手就擒！’说罢直向$n扑了过去。"NOR"\n", target2, ob);
//	message_vision(CYN"$N喝道：‘去死吧！’向$n扑了过去。"NOR"\n", target3, ob2);
	remove_call_out("checking");
	call_out("checking", 5, me);
}

int do_da(string arg)
{
	object me, ob, target, *living, fname, troom;
	string tk, t_title, tname, str, where;
	int i, j, x, y;

	if ( arg || !query("wait_answer") ) return 0;

	me = this_player();
	ob = this_object();

	if ( !ob || !me
	|| !me->query_temp("asked")
	|| me->query_temp("天地会job/target_2")
	|| !me->query_temp("天地会job/start_place") )
		return 0;
	if ( me->query("id") != ob->query("天地会jober"))
		return 0;
	if ((!me->query("天地会") && !wizardp(me))
	|| me->is_fighting() || me->is_busy() ) {
		command("bored "+me->query("id"));
		return 1;
	}
	me->delete_temp("asked");
	tk = ob->query("天地会/tangkou");
	t_title = ob->query("天地会/title");
	tname = tk+t_title+ob->name();

	message_vision(HIY"$N对$n大声道：“地振高冈，一派溪山千古秀。”"NOR"\n", me, ob);
	message_vision(HIY"$n对$N朗声道：“门朝大海，三河合水万年流。”"NOR"\n", me, ob);
	random(2)>0 ? command("touch "+me->query("id")) : command("hug "+me->query("id"));
	command("say 原来大家是自己人，在下"+tname+"。");
	ob->set_temp("title", HIW"天地会"+tk+t_title+NOR);

	x = me->query("kar");
	y = ob->query("kar");
//	if (x > y){
	//在此处准备写福缘比较，决定A、B 分支，够变态吧，哈哈！
	// 产生下一个npc target_2，开始 job 第二步，A 分支 -> 3a

	set("job3a", 1);
	living = livings();
	for (i=0 ;i < sizeof(living); i++){
		j = random(sizeof(living));
		if (!j || j == sizeof(living) -1) continue;
		if(check(living[j]) ){
			fname = living[j];
			troom = environment(fname);
			str = troom->query("short");
			if (!sizeof(troom->query("exits"))
			|| str == "武僧堂"
			|| str == "西门"
			|| str == "东门"
			|| str == "南门"
			|| str == "北门"
			|| str == "城门"
			|| str == "衙门"
			|| str == "兵营"
			|| str == "僧舍"
			|| str == "休息室"
			|| str == "女休息室"
			|| str == "男休息室"
			|| str == "龙池"
			|| str == "凤池"
			|| str == HIR"心禅堂"NOR
			|| str == "金刚伏魔圈" ) continue;
			if ( get_place(base_name(environment(fname))) == get_place(base_name(environment(ob)))) continue;
			if ( get_place(base_name(environment(fname))) != "" ) break;
		}
	}

	if( !fname ) {
		command("say 暂时没有事情需要做，以后再说吧。");
		return 1;
	}

	// 下一个npc 设定
	target = new(__DIR__"man2");
	target->set("天地会jober", me->query("id") );
	target->move(troom);

	for (i=0; i < 5; i++)
		target->random_move();

	if (environment(target)->query("no_fight"))
		target->random_move();

	copy_npc(me, target, 125);

	if (strsrch(file_name(environment(target)), "/d/zhiye/") >= 0
	 || strsrch(file_name(environment(target)), "/d/group/") >= 0){
	 	if ( environment(target)->query("outdoors"))
			where =  environment(target)->query("outdoors")+environment(target)->query("short");
	 	else if ( environment(target)->query("indoors"))
			where =  environment(target)->query("indoors")+environment(target)->query("short");
		else where =  environment(target)->query("short");
	}
	else where = get_place(base_name(environment(target)))+environment(target)->query("short");

	me->set_temp("天地会job/goon_place", where);
	me->set_temp("天地会job/3a", ob->query("id"));
	me->set_temp("天地会job/target_2", target->query("id"));

	command("say 在"+where+"有一位叫做"+target->name()+"的兄弟，他想加入我们天地会。");
	command("whisper "+me->query("id")+" 他的相貌是…这个…样子的，凭你的眼力一眼就认得出来。");
	command("say 朝廷已经派人在缉拿他，请尽快赶到，兄弟还有要事在身，就请你走一趟了。");

	log_file("job/tiandi", sprintf("%8s%-10s继续第%4d次任务，目标：%s的%s，目前经验：%d。\n",
		me->name(),"("+me->query("id")+")", me->query("job_time/天地会")+1, where,target->name(), me->query("combat_exp")), me);
	return 1;

	// B 分支，去另外一个分堂联络。-> 3B
}

string ask_tdh()
{
	object me=this_player();
	if (!me->query_temp("天地会job"))
		return "常听人说天地会的都是好汉子，只是无缘结交。\n";
	return "你可知他们做的是什么事？\n";
}

string ask_chen()
{
	object me=this_player();
	message_vision(CYN"$N对$n道：常听人说‘平生不识陈近南，就称英雄也枉然。’不知老兄可识得陈总舵主否？"NOR"\n", me, this_object());
	if (me->query_temp("asktimes") > 10)
		return"你胡乱打听什么？就不怕我们总舵主的凝血神爪？\n";
	if (!me->query("天地会"))
		return "总舵主岂是你随便见的。\n";
	return "我也很想见总舵主一面，不过不知道他老人家在哪里。\n";
}

string ask_zheng()
{
	object me=this_player();
	if (me->query("天地会"))
		return "国姓爷是当世第一英雄，第二嘛，就要数我们总舵主了。\n";
	return "他老人家是当世第一英雄。\n";
}

string ask_target()
{
	string str;
	object me=this_player();

	if (!me->query("天地会")) return 0;
	if (!me->query_temp("天地会job/goon_place"))
		return "我们一直在联络各地的反清志士。\n";
	str = me->query_temp("天地会job/goon_place");
	return "速去"+ str +CYN"，快去快回。\n";
}
                                                                                                    
