// old.c
// inherited by gini for help newbie function
void set_my_task(mixed s);
mixed get_my_task();
string get_my_master();
string get_my_master_name();
private string ol_id,ol_name,ol_state;
private string ol_mname,ol_method;
void op_method(string str) {
	object od,o,u;
	string my_area;
	mixed bn;
	od=find_body(ol_id);
	o=find_body(get_my_master());
	
	if(!objectp(od)) return;

	my_area=(o->query_room())->get_area();
	bn=AREA_D->get_area(my_area,"bn");
	if(!sizeof(bn)) bn=([]);
	if(bn[ol_id]>time()) {
		u=find_user(ol_id);
		if(!objectp(u)) return;
		u->modal_pop();		
		remove_call_out("no_select_answer");
		ol_method="stay";
                tell_user(ol_id,"由于你已被列入"+AREA_D->get_area(my_area,"name")+
                  "的黑名单，如此你便不必亲赴现场指导了，请远程帮助我的主人吧。\n");
this_object()->targetted_action(
"%^H_BLUE%^$N对$T到：你目前的工作就是帮助我的主人%^H_RED%^$o%^H_BLUE%^。
五分钟后，我会问我主人对你的帮助满不满意，
如果满意，你会得到奖励；反之我将以大精灵的名义罚你%^H_RED%^坐牢五分钟。%^RESET%^\n",od,o);
		this_object()->responda("say "+ol_name+"can't come，就让他遥控指导了。");

		ol_state="beg_help";
		set_my_task("op");
		return;
	}	
	if((str=="y")||(str=="Y")) {
		u=find_user(ol_id);
		if(!objectp(u)) return;
		u->modal_pop();		
		remove_call_out("no_select_answer");
		ol_method="come";

		od->simple_action("$N被一阵风卷起。\n");
		od->move(o->query_room());
		od->simple_action("$N从空中掉了下来。\n");
		this_object()->targetted_action(
"%^H_BLUE%^$N对$T到：你目前的工作就是帮助我的主人%^H_RED%^$o%^H_BLUE%^。
五分钟后，我会问我主人对你的帮助满不满意，
如果满意，你会得到奖励；反之我将以大精灵的名义罚你%^H_RED%^坐牢五分钟。%^RESET%^\n",od,o);
		ol_state="beg_help";
		set_my_task("op");
	}
	if((str=="n")||(str=="N")) {
		u=find_user(ol_id);
		if(!objectp(u)) return;
		u->modal_pop();		
		remove_call_out("no_select_answer");
		ol_method="stay";

this_object()->targetted_action(
"%^H_BLUE%^$N对$T到：你目前的工作就是帮助我的主人%^H_RED%^$o%^H_BLUE%^。
五分钟后，我会问我主人对你的帮助满不满意，
如果满意，你会得到奖励；反之我将以大精灵的名义罚你%^H_RED%^坐牢五分钟。%^RESET%^\n",od,o);
		this_object()->responda("say "+ol_name+"不愿现场指导，就让他遥控指导了。");
		ol_state="beg_help";
		set_my_task("op");
	}
}
void no_select_answer() {
	tell_user(ol_id,"不回答表示愿意现场指导。\n");
	op_method("y");
}
void my_call_old_player() {
	object o,od;
	object *usr,*use;
	string p_id;
	string m_m;
	m_m=get_my_master();
	GINI_D->gini_act(m_m,"call_old_player");
	o=find_body(m_m);
	if(!objectp(o)) return;
	if(sizeof(get_my_task())) {
		GINI_D->gini_act(m_m,"busy");
		return;	
	}
	if(o->query_literate()>30) {
		GINI_D->gini_act(m_m,"noneed");
		return ;	
	}
	if((o->get_gini_q("op_time"))>(time()-3600)) // one hour
	{
		GINI_D->gini_act(m_m,"toosoon");
		return ;
	}
	usr=users()->query_body();
	usr-=({0});
	use=({});
	foreach(object ob in usr) {
		if(wizardp(ob)) continue;  // wizard
		if(ob->query_literate()<100) continue;  // literate < 100
		p_id=ob->query_primary_id();
		if(!CHAR_D->char_exist(p_id)) continue; // not a char
		if(CHAR_D->get_char(p_id,"task")) continue;  // has tasks
		if(query_idle(ob->query_link())>120) continue; // idle more than 2 mins
		use+=({ob});
	}
	if(!sizeof(use)) {
		GINI_D->gini_act(m_m,"nooldplyer");
		return;
	}
	GINI_D->gini_act(m_m,"magic");
	p_id=use[random(sizeof(use))]->query_primary_id();
//	p_id="fire";
	o->set_gini_q("op_time",time());
	o->set_gini_q("op",p_id);
	ol_id=p_id;
	od=find_body(p_id);
	ol_name=od->query_chinese_id();
	od->resign_job("helper");
	od->add_job("helper");
	od->set_job("helper","memo","帮助"+get_my_master_name());
	this_object()->responda("tell "+p_id+" "+
"亲爱的"+ol_name+"：你被选择指导我家主人"+get_my_master_name()+"("+get_my_master()+")"+
"五分钟。\n"+"你愿不愿意亲临现场指导，这样会使你的奖励加倍。");
	tell_user(p_id,"\n");
	// set_this_player(od); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
	find_user(p_id)->modal_push((: op_method :), "请问，你愿意亲临现场帮助吗？<y|n>：",0,0,0);
	ol_state="select_method";
	call_out("no_select_answer",30);
	this_object()->responda("say 让"+ol_name+"帮助你，看他会不会亲自来。");

}

void op_award(object usr)
{
    int isrobot;
    string p_id,p_name;
    object ob;
    set_my_task("");
    isrobot=usr->query_robot();
    ob=usr->query_body();
    p_id=ob->query_primary_id();
    p_name=CHAR_D->get_char(p_id,"name");
    if(isrobot)
    {   this_object()->simple_action(
         "$N暗笑道：真是个白痴,嘿嘿，不必给奖了。\n");
    }
    else
    {
        this_object()->simple_action("$N说到：不错，不错．\n");
	ob->award_exp(100);
        CHAR_D->set_char(p_id,"reputation",
		CHAR_D->get_char(p_id,"reputation")+100);

	if(ol_method=="come") {
		ob->award_exp(100);
	        CHAR_D->set_char(p_id,"reputation",
			CHAR_D->get_char(p_id,"reputation")+100);
	}

        tell_user(p_id,"你的声望和技能提高了。\n");
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
	   p_name+"积极帮助新手，"+p_name+"的声望和技能提高了。");
    }
}
void op_input(string inp) {
	object u,o,od;
	string p_id,p_name;
	remove_call_out("no_answer_sat");
	u=find_user(get_my_master());
	o=find_body(get_my_master());
	if(!objectp(u)) return;
	if(!objectp(o)) return;
	p_id=o->get_gini_q("op");
	p_name=CHAR_D->get_char(p_id,"name");
	od=find_body(p_id);
	if((inp=="y")||(inp=="Y")) {
		od->finish_job("helper");
		u->modal_pop();
		o->targetted_action("$N对$T一拱手道：多谢$R的帮助，$s感谢不尽。\n",od);
		ol_state="test_rob";
		ROBOT->robot_test(od->query_link(),(:op_award:));
		return ;
	}
	if((inp=="n")||(inp=="N")) {
		od->finish_job("helper");
		set_my_task("");
		u->modal_pop();
		o->targetted_action("$N对$T道：气死我了，给我把$o赶走。\n",this_object(),od);
		this_object()->targetted_action("$N把$T一脚踢走了。\n",od);
		CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		   p_name+"不肯帮助新手，"+p_name+"被关进监狱了。");
		CHAR_D->put_prison(p_id,5);
		return ;
	}
}
void no_answer_sat() {
	this_object()->responda("say 不回答就是满意。");
	op_input("y");
}
void my_test_op() {
	object o,od,u;
	string p_id,p_name,p_area;
	int p_time;
	o=find_body(get_my_master());
	if(!objectp(o)) return;
	p_id=o->get_gini_q("op");
	od=find_body(p_id);
	p_name=CHAR_D->get_char(p_id,"name");
	p_area=CHAR_D->get_char(p_id,"area");
	if(!objectp(od)) {
		this_object()->responda("say "+p_name+"胆敢逃跑，我把他送进大牢。");
		set_my_task("");
		CHAR_D->put_prison(p_id,5);
		return;
	}

	switch(ol_state) {
		case "select_method" :
			this_object()->responda("say 还不知道"+p_name+"来不来。");
			this_object()->responda("tell "+p_id+" 你到底来还是不来。");
			return;
		case "beg_help" :
			p_time=o->get_gini_q("op_time");
			if((time()-p_time)<300) // less than 5 min
			{
				this_object()->targetted_action(
				"$N对$T道：好好帮助我家主人$o，会有奖赏的。\n",od,o);
				return ;
			}
			u=o->query_link();
			if(!objectp(u)) return;
			this_object()->targetted_action(
				"$N对$T道：你现在就等我家主人$o对你的评价了。\n",od,o);
			tell_user(get_my_master(),"请问，你对" + p_name + 
                                "的帮助满意吗？<y|n>：\n");
			ol_state="wait_answer";
			// set_this_player(o); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
			u->modal_push((: op_input :), "请问，你对" + 
				p_name + "的帮助满意吗？<y|n>：");
			call_out("no_answer_sat",30);
			return ;
		case "wait_answer" :
			this_object()->targetted_action(
				"$N对$T道：你现在就等我家主人$o对你的评价了。\n",od,o);
			tell_user(get_my_master(),"请问，你对" + p_name + 
                                "的帮助满意吗？<y|n>：\n");
			return ;
		case "test_rob":
			this_object()->responda("say "+ol_name+"正在进行智能测试。");
			return ;

		default :
			this_object()->responda("say 有bug,快报告wiz吧。");
	}
}
