// sleeper.c
inherit __DIR__+"worker";
string get_room_desc() {
	return "正在呆望天空的"+p_workername+c_name+"("+my_id+")";
}

mixed extra_init() {
	set_steps(2); // just two judge way

	create_scenario("noise1");
	add_act("noise1","n1","WEO",1,"idle");

	create_scenario("noise2");
	add_act("noise2","n1","WTO",1,"$N背着双手走来走去，嘴里还不停地念叨着什么。\n");

	create_scenario("noise3");
	add_act("noise3","n1","HEW",1,"hmm");
}

string get_prompt() {
	return "怎么办？问情况(a) 看(l) 命令干活 (0) 不去打扰(1)\n";
}

string get_desc(int lv) {
	if(random(lv)<25)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	if(status<4)
		return "$m平时一干活就喜欢发呆。\n";
	if(status<6)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	return "$m喜欢动脑筋，经常有些好主意。\n";
}
string get_look_desc() {
	int sk;
	sk=CHAR_D->get_skill(p_id,"sk_zhimou");
	return get_desc(sk);
}
string get_ask_desc() {
	object bs;
	mixed hd;
	int sk;
	bs=SGBASE(p_area,f_id);
	hd=bs->get_room(r_id,"head");
	sk=hd["pw"];
	return get_desc(sk);
}

void final_act(int sel,int err) {
	int score;

	if(err<=1) 
		score=2;
	else if(err<=2)
		score=1;
	else if(err<=3)
		score=0;
	else 
		score=-1;
	if(objectp(p_menu))
		p_menu->add_score(score);
	announce_score(score);

	create_scenario("bye");
	switch(sel) {
	case 0:
		add_act("bye","kick","MEW",0,"hit");
		add_act("bye","wake","WEO",1,"pain");
		if(score>0) 
			add_act("bye","run","WTM",2,
				"$N对$T扑倒在地道：$s该死，下次再不发呆了。\n");
		else
			add_act("bye","run","WEO",2,
				"doue");
		break;
	case 1:
		add_act("bye","kick","MEW",0,"greet");
		add_act("bye","wake","WEO",1,"great");
		if(score>0) {
			add_act("bye","run","WTM",2,
				"$N对$T道，我刚想出一个好点子，讲给你听听。\n");
			add_act("bye","run2","WTM",2,
				"$N给$T介绍了一些新的主意。\n");
			add_act("bye","leave","MEW",3,
				"great");
		}
		else {
			add_act("bye","run","WEO",2,"grin");
			add_act("bye","leave","WTM",3,"$N偷笑道：这个白痴。\n");
		}
		break;
	}
	disappear();
}
void show_start() {
	create_scenario("start");
	add_act("start","1","MTW",1,"$N突然一回头，发现了正在发呆的$T。\n");
	add_act("start","2","MEH",2,"en");
	add_act("start","5","HEM",3,"dunno");
	do_scenario("start");
}