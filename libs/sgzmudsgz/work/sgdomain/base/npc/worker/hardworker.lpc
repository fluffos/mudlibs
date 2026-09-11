// sleeper.c
inherit __DIR__+"worker";
string get_room_desc() {
	return "正忙着汗流浃背的"+p_workername+c_name+"("+my_id+")";
}

mixed extra_init() {
	set_steps(2); // just two judge way

	create_scenario("noise1");
	add_act("noise1","n1","WTO",1,"$N擦擦汗，又忙着干了起来。\n");

	create_scenario("noise2");
	add_act("noise2","n1","WTM",1,"$N对$T鞠了个躬，又在一边忙起来了。\n");

	create_scenario("noise3");
	add_act("noise3","n1","HEW",1,"sweat");
}

string get_prompt() {
	return "怎么办？问情况(a) 看(l) 揭露(0) 鼓励(1)\n";
}

string get_desc(int lv) {
	if(random(lv)<30)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	if(status<4)
		return "$m平时是一个懒散的家伙嘛。\n";
	if(status<6)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	return "$m工作一直都非常勤奋。\n";
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
		add_act("bye","kick","MTW",0,"$N对$T冷笑一声，平时这么努力就好了，别我来才这么装样子。\n");
		add_act("bye","wake","WEO",1,"fear");
		if(score>0) 
			add_act("bye","run","WTM",2,
				"$N对$T扑倒在地道：$s该死，下次再不敢了。\n");
		else
			add_act("bye","run","WEO",2,
				"doue");
		break;
	case 1:
		add_act("bye","kick","MEW",0,"spank");
		add_act("bye","wake","WEO",1,"sweat");
		if(score>0) {
			add_act("bye","run","WTM",2,
				"$N对$T道，$R放心，$s一定更加努力。\n");
			add_act("bye","leave","WTO",3,
				"$N离开干活去了。\n");
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
	add_act("start","1","HTM",1,"$N对$T道：$R请看。\n");
	add_act("start","2","MTH",2,"$N顺着$T手指的方向一看。");
	add_act("start","5","MTW",3,"发现了正在苦干的$m。\n");

	add_act("start","3","HTO",4,"$N得意地退到一边。\n");
	do_scenario("start");
}