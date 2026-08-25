// sleeper.c
inherit __DIR__+"worker";
string get_room_desc() {
	return "衣衫褴褛的"+p_workername+c_name+"("+my_id+")";
}

mixed extra_init() {
	set_steps(2); // just two judge way

	create_scenario("noise1");
	add_act("noise1","n1","MTW",1,"$N看$T那么认真地干活，穿得却破破烂烂，心里很过意不去。\n");

	create_scenario("noise2");
	add_act("noise2","n1","WTO",1,"$N一不小心，背上的汗衫有撕开一条口子。\n");

	create_scenario("noise3");
	add_act("noise3","n1","HEW",1,"scowl");
}

string get_prompt() {
	return "怎么办？问情况(a) 看(l) 责骂(0) 赏赐五两银子(1)\n";
}

string get_desc(int lv) {
	if(random(lv)<20)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	if(status<4)
		return "$m平时就是一个吝啬鬼。\n";
	if(status<6)
		return "$m与其他"+p_workername+"没有什么不同。\n";
	return "$m家有老母，体弱多病，生活很艰苦。\n";
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
		add_act("bye","kick","MTW",0,"$N对$T生气地说道：工钱也不低，穿得这么破破烂烂的象什么样。\n");
		add_act("bye","wake","WEO",1,"inn");
		if(score>0) 
			add_act("bye","run","WTM",2,
				"$N忙赔笑道：$s该死，早知道$R来视察，应当穿件新衣服才对。\n");
		else
			add_act("bye","run","WTM",2,
				"$N不满地嘟囔着：还不是被你们这帮$r剥削的。\n");
		break;
	case 1:
		MONEY_D->sub_all_money(master,500);
		add_act("bye","kick","MTW",0,"$N对$T道：听说你是个孝敬的儿子，有点钱都给老母亲看病了。\n"+
			"这里有五两银子，拿去买件新布衣吧。\n");
		add_act("bye","dd","MTW",1,"$N塞给$T五两银子。\n");
		if(score>0) {
			add_act("bye","run","WEM",2,"courage1");
			add_act("bye","leave","WTO",3,
				"$N离开干活去了。\n");
		}
		else {
			add_act("bye","run","WEO",2,"grin");
			add_act("bye","leave","WTO",3,"$N把钱塞进鞋底，磨磨蹭蹭地离开干活去了。\n");
		}
		break;
	}
	disappear();
}
void show_start() {
	create_scenario("start");
	add_act("start","1","MTW",1,"$N低头看到了$T。咦，这里怎么有个要饭的。\n");
	add_act("start","2","HTW",2,"$N忙解释道：不是不是，这是我们的"+p_workername+
		"，叫$m。\n");
	add_act("start","3","MEO",3,"oh");
	do_scenario("start");
}