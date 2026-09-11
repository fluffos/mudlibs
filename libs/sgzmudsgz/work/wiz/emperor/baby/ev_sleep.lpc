// ev_sleep.c
// by emperor on 2000.2.28
// this is used to handle player makelove
void the_end1(string id);
void the_end2(string id);
void conform_sleep(object who,object parter);
void sleep(object who,object parter,string ans);
void run_sleep(object who, object parter);

void ask_sleep(object who, object parter)
{
	int w_gender, p_gender;
	string w_id, p_id;
	int w_hp, p_hp;
	int w_food,w_drink,p_food,p_drink;
	object env;
	w_id=who->query_primary_id();
	p_id=parter->query_primary_id();
	w_gender=who->query_gender();
	p_gender=parter->query_gender();
	if(CHAR_D->get_char(p_id,"mar")==w_id) {
		if(who->query_gravidity()){
			parter->targetted_action("$N对$t说道：“$c已有身孕，不能行房。”\n",who);
			return;
		}
		if(parter->query_gravidity()){
			parter->targetted_action("$N对$t说道：“$c, 贱妾已有身孕，不能行房。”\n",who);
			return;
		}
		env=environment(parter);
/*
		if(env->query_bedroom_master()!=w_id||env->query_bedroom_master()!=p_id){
			parter->targetted_action("$N对$t说道：“$c, 到睡房里再说吧。”\n",who);
			return;
		}
*/
		w_food=who->query_sg_food();
		w_drink=who->query_sg_drink();
		p_food=parter->query_sg_food();
		p_drink=parter->query_sg_drink();
		if(!w_food){
			parter->targetted_action("$N对$t说道：“$c, 你现在很饿，你先吃些东西吧。”\n",who);
			return;
		}
		if(!w_drink){
			parter->targetted_action("$N对$t说道：“$c, 你现在很渴，你先喝些东西吧。”\n",who);
			return;
		}
		if(!p_food){
			parter->targetted_action("$N对$t说道：“$c, 我现在很饿，等我吃些东西再说吧。”\n",who);
			return;
		}
		if(!p_drink){
			parter->targetted_action("$N对$t说道：“$c, 我现在很渴，等我喝些东西再说吧。”\n",who);
			return;
		}

		w_hp=who->query_cur_hp();
		p_hp=parter->query_cur_hp();
		if((w_hp*100<who->query_cur_max_hp()*90)
			||(who->query_cur_mp()*100<who->query_cur_max_mp()*90)){
			parter->targetted_action("$N对$t说道：“$c, 你现在体力不充沛，先休息一下吧。”\n",who);
			return;
		}
		if((p_hp*100<parter->query_cur_max_hp()*90)
			||(parter->query_cur_mp()*100<parter->query_cur_max_mp()*90)){
			parter->targetted_action("$N对$t说道：“$c, 我现在体力不充沛，等会儿再说吧。”\n",who);
			return;
		}
		conform_sleep(who,parter);
	}else	if(w_gender==p_gender)
		parter->targetted_action("$N对$t喝道：$r,你脑子有病啊！\n",who);
	else if (w_gender==1)
		parter->targetted_action("$N色迷迷地对$t笑道：我好想你！\n",who);
	else parter->targetted_action("$N厉声对$t喝道：流氓，离我远点！\n",who);
	return;
}

void conform_sleep(object who,object parter){
	string w_id,p_id;
	w_id=who->query_primary_id();
	p_id=parter->query_primary_id();
	who->set_answer(p_id,  (:sleep:) );
	tell_user(p_id,"你愿意就请输入 answer yes to "+w_id+"。\n");
}

void sleep(object parter,object who,string ans){
	switch(ans)
	{
		case "yes":
		case "y":
//			who->targetted_action("$N温柔地对$T道：$c,好吧。\n",parter);
			run_sleep(who,parter);
			who->clear_answer();
			return;
		default:
//			who->targetted_action("$N遗憾地对$T道：$c，现在不行。\n",parter);
			who->clear_answer();
		return;
	}
}

void run_sleep(object who, object parter){
	string w_id, p_id;
	int w_gender, p_gender;
	int sleeptime;
	sleeptime=30+random(20);
	w_id=who->query_primary_id();
	p_id=parter->query_primary_id();
	w_gender=who->query_gender();
	p_gender=parter->query_gender();
	who->responda("drop all");
	parter->responda("drop all");
	who->responda("sit on bed");
	parter->responda("sit on bed");
	if(p_gender==1) { // male
		parter->targetted_action("$N迫不及待地抱住$t赤裸裸的身体。。。\n",who);
	}else{
		who->targetted_action("$N迫不及待地抱住$t赤裸裸的身体。。。\n",parter);
	}
	parter->start_busy(sleeptime, "你正在行房中。\n");
	who->start_busy(sleeptime, "你正在行房中。\n");
	parter->set_cur_hp(0);
	who->set_cur_hp(0);
	parter->set_cur_mp(0);
	who->set_cur_mp(0);
	call_out("the_end1",sleeptime+1,p_id);
	call_out("the_end2",sleeptime+1,w_id);
}

void the_end1(string id){
	object o=find_body(id);
	if(!objectp(o))
		return;
	o->simple_action("$N累的一点劲都没了。\n");
	if(o->query_gender()!=1)
		if(random(40)==1) o->set_gravidity();
	return;
}

void the_end2(string id){
	object o=find_body(id);
	if(!objectp(o))
		return;
	o->simple_action("$N累的一点劲都没了。\n");
	if(o->query_gender()!=1)
		if(random(40)==1) o->set_gravidity();
	return;
}



