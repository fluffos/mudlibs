
string *no_kill_list = ({
	"mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

string *target_list = ({
	"/d/xiangyang/biaoju",
	"/d/beijing/haibin",
});

int do_accept(string arg)
{
	object ob, cart, biaotou, target, *living;
	object me, *team, maxplayer, place;
	int totalexp=0, maxexp, minexp;
	int i, j, teams,times;
	string endname, str;
        mixed *local,*last;

        local = localtime(time() * 60);
	me = this_player();

	if (arg != "quest") return 0;

	if (sizeof(filter_array(children(__DIR__"obj/cart"), (: clonep :))) > 4) {
		command("say 你来晚了已经有人接下这支镖了。");
		return 1;
	}

	team = me->query_team();
	if (sizeof(team) < 2 ){
		command("say 护镖路途危险，你这么少的人，我可不放心。");
		return 1;
	}
	else if(sizeof(team) > 4){
		command("say 护镖路途危险，单靠人多是没用的。");
		return 1;
	}
	if ( team[0] != me) {
		command("say 只有队伍首领才能提出接镖。");
		return 1;
	}
	for (i=0;i<sizeof(team);i++){
		if (!team[i]){
			command("say 你的队伍出现了问题，请解散并重新组建。");
			return 1;
		}
		if (team[i]->query_temp("protecting")) {
			command("say 嗯？你的队伍里怎么有如此贪婪之人？");
			return 1;
		}
		if( team[i]->query_temp("quest/busy")) //added by tangfeng 与quest冲突
		{
			command("say 你们有人在解密之中，你们还是先处理好你其他事情再说吧。");
			return 1;
		}
		if (!present(team[i],environment(this_object()))){
			command("say 咦？怎么好象人不全啊？"+team[i]->query("name")+"怎么没来？");
			return 1;
		}
		if(team[i]->query("day_jobs/hubiao/last_time"))
		{
			last = localtime(team[i]->query("day_jobs/hubiao/last_time"));
			times = team[i]->query("day_jobs/hubiao/times");

			if(last[7]!=localtime(time())[7])
				team[i]->set("day_jobs/hubiao/times",0);
			else if(last[7]==localtime(time())[7]&&times>=5)
			{
				command("say "+team[i]->query("name")+"今日的护镖次数已经用完，换个人吧。");
				return 1;
			}
		}
		if (me == team[i]) continue;
		if (!interactive(team[i])) {
			command("say "+team[i]->query("name")+"现在不在线，换成其他人吧。");
			return 1;
		}
	}
	maxexp=minexp=team[0]->query("combat_exp");
	maxplayer=team[0];
	for (i=0;i<sizeof(team);i++){

		if (!ultrap(team[i])) {
			command("say 护镖路途危险，我看这位"+RANK_D->query_respect(me)+"还需努力，早日成为武学大宗师！");
			return 1;
		}

		if (team[i]->query("combat_exp") < 500000) {
			command("say 护镖路途危险，我看这位"+RANK_D->query_respect(me)+"需要一个好搭档！");
			return 1;
		}
		if (team[i]->query("balance") < 1000000 && !wizardp(team[i])) {
			command("say 护镖是危险的事，我看"+team[i]->query("name")+RANK_D->query_respect(team[i])+"没有赔偿能力。");
			return 1;
		}
		if (team[i]->query_condition("job_busy") && !wizardp(team[i])){
			command("say 一直护镖很辛苦的，我看这位"+team[i]->query("name")+RANK_D->query_respect(team[i])+"还是去歇息片刻吧！");
			return 1;
		}
		totalexp = totalexp + team[i]->query("combat_exp");
		if(team[i]->query("combat_exp") > maxexp) {
			maxexp=team[i]->query("combat_exp");
			maxplayer=team[i];
		}
		else if(team[i]->query("combat_exp") < minexp)
			minexp=team[i]->query("combat_exp");
	}
	if( totalexp < 1000000 ){
		command("say 护镖路途危险，我看诸位似乎无此能力？？？");
		return 1;
	}

	if( totalexp < 20000000 && (maxexp-minexp) > 5000000 ){
		command("say 护镖路途危险，需要队伍协同作战，我看诸位的实力差距悬殊，还是重新组队吧。");
		return 1;
	}


	teams=sizeof(team);

// 选择护镖目的

	if(!objectp(place = find_object(target_list[random(sizeof(target_list))])))
		place = load_object(target_list[random(sizeof(target_list))]);
	if (!place) {
		command("say 暂时没有镖需要劳驾"+RANK_D->query_respect(team[0])+"出马。");
		return 1;
	}

	target = new(__DIR__"hbtarget");
	target->move(place);

	for (i=0; i<5; i++)
		target->random_move();

	place = environment(target);

 	if ( place->query("outdoors"))
		endname =  MAP_D->query_map_short(place->query("outdoors"))+place->query("short");
 	else if ( place->query("indoors"))
		endname =  MAP_D->query_map_short(place->query("indoors"))+place->query("short");
	else endname =  place->query("short");

	command("say 请护送这一笔镖银到"+endname+CYN"的"+target->name()+"手中。");

	log_file("job/hubiao",
		sprintf("%8s%-10s从林震南这里得到护镖任务，共%1s人做，需要送达"HIR"%s"NOR"。\n",
			me->name(1),
			"("+capitalize(me->query("id"))+")",
			chinese_number(sizeof(team)),
			endname
		), me
	);

	message_vision("$N将护镖押金"+chinese_number(sizeof(team)*50)+"两黄金交给了镖局。\n", me);

	say("一队镖车从内院驶出。\n");

	cart=new(__DIR__"obj/cart");
	cart->set_temp("teams", teams);

	if(teams > 3)
		cart->set_temp("team4",team[3]);
	if(teams > 2)
		cart->set_temp("team3",team[2]);
	if(teams > 1)
		cart->set_temp("team2",team[1]);
	if(teams > 0)
		cart->set_temp("team1",team[0]);

	cart->set("long", cart->query("long")+"这支镖是由福威镖局镖师"+me->query("name")+"负责送到"+HIR+endname+HIY+target->name()+NOR"手上的。\n");
	cart->set("teamhead", me->query("name"));
	cart->set("arrive", endname);
	cart->set("target", target);

	for(i=0; i < sizeof(team); i++) {
		team[i]->set("day_jobs/hubiao/last_time",time());
		team[i]->add("day_jobs/hubiao/times",1);
		team[i]->set_temp("protecting",cart);
		team[i]->apply_condition("job_busy", 45);
		team[i]->add("balance", -500000);
		team[i]->set_temp("death", team[i]->query("death_count"));
		//GIFT_D->check_count(team[i],this_object(),"护镖");
	}

	cart->move(environment());

	biaotou = new(__DIR__"biaotou");
	biaotou->set("qi", maxplayer->query("max_qi"));
	biaotou->set("eff_qi", maxplayer->query("max_qi"));
	biaotou->set("max_qi", maxplayer->query("max_qi"));
	biaotou->set("jing", maxplayer->query("max_jing"));
	biaotou->set("max_jing", maxplayer->query("max_jing"));
	biaotou->set("neili", maxplayer->query("max_neili"));
	biaotou->set("max_neili", maxplayer->query("max_neili"));
	biaotou->set("jingli", maxplayer->query("max_jingli"));
	biaotou->set("max_jingli", maxplayer->query("max_jingli"));
	biaotou->move(environment());
	biaotou->set_temp("protecting",cart);
	biaotou->set("combat_exp", maxplayer->query("combat_exp"));
	NPC_D->init_npc_skill(biaotou,NPC_D->check_level(biaotou));
	ob=new("/clone/money/silver");
	ob->set_amount(1000+random(100));
	ob->set("name","镖银");
	ob->move(cart);
/*
	ob=new(__DIR__"biaoshi");
	ob->move(environment());
	ob->set_temp("protecting", cart);

	ob=new(__DIR__"biaoshi");
	ob->move(environment());
	ob->set_temp("protecting", cart);
*/
	me->set_temp("hubiao/where", base_name(environment(target))); //设置目标
	me->set_temp("hubiao/biao_time", uptime());
	me->set_temp("hubiao/target", target);
	return 1;
}

int test_dart()
{
	object ob = this_player();

	if (ob->query_condition("job_busy")
	 || ob->query_temp("protecting")
	 || random(100) > 80) {
		command("say 现在没有镖需要劳驾"+RANK_D->query_respect(ob)+"出马。");
		return 1;
	}

	command("say 我们福威镖局受人所托，有笔镖银需要送到他处。");
	do_accept("quest");
	return 1;
}
