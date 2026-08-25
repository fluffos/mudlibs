// sleeper.c
inherit __DIR__+"worker";
string get_room_desc() {
	return "正在呼呼大睡的"+p_workername+c_name+"("+my_id+")";
}

mixed extra_init() {
	set_steps(2); // just two judge way

	create_scenario("noise1");
	add_act("noise1","n1","WTO",1,"$N翻了个身，又呼呼地睡了。\n");

	create_scenario("noise2");
	add_act("noise2","n1","WTO",1,"$N不知道梦到了什么，嘿嘿嘿地笑了。\n");

	create_scenario("noise3");
	add_act("noise3","n1","WTO",1,"$N的呼噜声引起了其他"+p_workername+
		"的注意。大家纷纷转过头来看。\n");
	add_act("noise3","n2","HTO",2,"$N瞪了他们一眼，大家吓得赶快转过身继续干活。\n");
}

string get_prompt() {
	return "怎么办？问情况(a) 看(l) 一脚踢醒(0) 让"+query_pronoun()+"睡(1)\n";
}

string get_desc(int lv) {
	if(random(lv)<20)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	if(status<4)
		return "$m平时就是一个懒散的家伙。\n";
	if(status<6)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	return "$m平时是一个非常勤奋的"+p_workername+"。\n";
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
		add_act("bye","kick","MEW",0,"kick");
		add_act("bye","wake","WEO",1,"pain");
		if(score>0) 
			add_act("bye","run","WTM",2,
				"$N一看是$T，吓得调头就跑去干活去了。\n");
		else
			add_act("bye","run","WTM",2,
				"$N不满地嘟囔着：三天都没合眼了，哼。$M慢慢腾腾地干活去了。\n");
		break;
	case 1:
		add_act("bye","kick","MTH",0,"$N对$T小声道："+c_name+
			"工作辛苦，让"+query_pronoun()+"多睡会儿。\n");
		add_act("bye","wake","WEO",1,"wake");
		if(score>0) {
			add_act("bye","run","WTM",2,
				"$N一看是$T，连忙鞠躬道：\n"+"$R体恤$s，$s定将更加努力。\n");
			add_act("bye","leave","WTO",3,
				"$N离开干活去了。\n");
		}
		else {
			add_act("bye","run","WEO",2,"hehe");
			add_act("bye","leave","WTO",3,"$N磨磨蹭蹭地离开干活去了。\n");
		}
		break;
	}
	disappear();
}
void show_start() {
	create_scenario("start");
	add_act("start","1","MTH",1,"$N正和$T在"+p_roomname+
		"中巡视，突然听到地上传来一阵呼噜声。\n");
	add_act("start","2","MTO",2,"$N脸一沉。低头一看，地上正躺着一个人在睡大觉。\n");
	add_act("start","3","HTO",3,"$N尴尬地退到一边。\n");
	do_scenario("start");
}