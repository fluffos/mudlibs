// this is the abstract part for the worker
// all other worker will inherit this
inherit M_CHAR;
inherit LIVING;

#define PPLTYPE "/sgdomain/modules/m_charnpc/ppl/name"

protected object master,slave,room;
protected string p_area,f_id,r_id,p_id;
protected string p_roomname,p_workername;
protected string task;
protected object peer;
protected string peer_id;
protected string my_id,c_name;
protected int p_type;
protected string ser;
protected object p_menu;

protected int status,steps; 
protected mapping p_scenario=([]);
string get_prompt();
string get_look_desc();
string get_ask_desc();
mixed extra_init();
void final_act(int sel,int err);


void set_menu(object o) {
	p_menu=o;
}

// this is the main part to make the worker to speak
// There are at most 4 char in this sence, they are

// Role part
// W means the worker
// H means the head in this field (id head, obj slave)
// M means the officer you, id p_ic, obj master
// P means the peer worker (if has, id peer_id, ob peer)
// O means no body

// Act part
// S Say sthing
// E do emote
// T do action


// One sentence include 5 part they are
// <X the obj><A the Act><Y the target><T the delay><S the real thing>
// X = one of <W,H,M,P>
// A = <S,E,T>
// Y = one of <W,H,M,P,O>
// T = delay 0-9;
// S = the string part


void worker_act(string str) {
	string s_s,s_v,s_o,s_str;
	int s_t;
	mixed o_o;
	object o_s;
	if(strlen(str)<4) return;
	s_s=str[0..0]; s_v=str[1..1]; s_o=str[2..2];
	s_t=to_int(str[3..3]);
	s_str=str[4..<1];

	switch(s_s) {
	case "W": o_s=this_object(); break;
	case "H": o_s=slave; break;
	case "M": o_s=master; break;
	case "P": o_s=peer; break;
	default : return;
	}
	switch(s_o) {
	case "W":
		if((s_v=="S")||(s_v=="T")) o_o=this_object();
		else o_o=my_id;
		break;
	case "H": 
		if((s_v=="S")||(s_v=="T")) o_o=slave;
		else o_o=f_id+" head"; // the head's id
		break;
	case "M":
		if((s_v=="S")||(s_v=="T")) o_o=master;
		else o_o=p_id; // the head's id
		break;

	case "P":
		if((s_v=="S")||(s_v=="T")) o_o=peer;
		else o_o=peer_id; // the head's id
		break;

	default : o_o=0;
	}

	if(s_v=="S") {
		if(s_o=="O")
			s_str="$N说道："+s_str;
		else
			s_str="$N对$T说道："+s_str;
		s_v="T";
	}

//	tell_user("fire",sprintf(
//		"str is %s ,o_s is %O o_o is %O, s_str is %s, s_t is %d\n",
//		str,o_s,o_o,s_str,s_t));


	switch(s_v) {
	case "T":
		if(objectp(o_o))
			DELAY_D->delay_targetted_action(o_s,o_o,s_str,s_t);
		else
			DELAY_D->delay_simple_action(o_s,s_str,s_t);
		break;
	case "E":
		DELAY_D->delay_emote(o_s, s_str,s_t,o_o);
		break;
	}
}

void do_scenario(string what) {
	string sent;
	if(!mapp(p_scenario[what])) return;
	if(!sizeof(p_scenario)) return;
	foreach(string tit,mixed *par in p_scenario[what]) {
		sent=par[0]+par[1]+par[2];
		worker_act(sent);
	}
}
int has_scenario(string what) {
	if((!mapp(p_scenario[what]))||(!sizeof(p_scenario[what])))
		return 0;
	return 1;
}
void create_scenario(string what) {
	p_scenario[what]=([]);
}
int add_act(string scen,string what,string typ,int delay,string str) {
	if(!mapp(p_scenario[scen]))
		p_scenario[scen]=([]);
	p_scenario[scen][what]=({typ,delay,str});

}

int base_scenario_init(){
	create_scenario("bye");
	add_act("bye","gc","WSO",1,"时候不早了，$s先干活去了。\n");
	add_act("bye","aggree","MEW",2,"nod");
	add_act("bye","bow","WEM",3,"bow");
	add_act("bye","bow2","WEH",3,"bow");
	add_act("bye","leave","WTO",4,"$N转身离开了。");

	create_scenario("noise4");
	add_act("noise4","n1","HTM",1,"$N悄声对$T道：$R看怎么办。\n");
	add_act("noise4","n2","MEO",2,"pat");

	create_scenario("look");
	add_act("look","lk","MEO",0,"look"); // just a simple look
	add_act("look","lkb","MTW",1,"$N对$T从上到下仔仔细细打量了一番。\n");
	add_act("look","lbr","MTW",2,"$N发现：\n"+get_look_desc());

	create_scenario("ask");
	add_act("ask","a1","MTH",0,"$N用询问的目光看了看$T。\n"); // just a simple look
	add_act("ask","a2","HTM",1,"$N对$T会意地点点头。\n");
	add_act("ask","lbr","HTW",2,"$N道："+get_ask_desc());

}

void remove_me() {
	destruct(this_object());
}
void disappear() {
	object usr;
	usr=find_user(p_id);
	if(objectp(usr)) usr->modal_pop();

	do_scenario("bye");
	call_out("remove_me",5);
}
void show_noise() {
	switch(random(4)) {
		case 0: do_scenario("noise1"); break;
		case 1: do_scenario("noise2"); break;
		case 2: do_scenario("noise3"); break;
		default: do_scenario("noise4"); break;
	}
}

string get_room_desc() {
	return p_workername+c_name+"("+my_id+")";
}
void self_init() {
	string sname,gname,age;
	p_type=random(6)+1;
	sname=PPLTYPE->get_surname(p_type);
	gname=PPLTYPE->get_given_name(p_type);
	c_name=sname+gname;

	my_id="worker"+ser;
	set_name(my_id,c_name);
	
	add_id("npc worker");
	set_gender(PPLTYPE->get_gender(p_type));
    set_proper_name(c_name);
   	set_in_room_desc(get_room_desc());
	

	AREA_D->get_area(p_area,"name")+
	set_sg_rongmao(PPLTYPE->get_rongmao(p_type));
	set_age(PPLTYPE->get_age(p_type));
}

void  init(object m,object s,string t,string se){
	master=m;
	slave=s;
	p_area=s->get_area();
	f_id=s->get_f_id();
	r_id=s->get_r_id();
	p_id=master->query_primary_id();
	p_roomname=BASE_D->get_base(f_id,"roomname");
	p_workername=BASE_D->get_base(f_id,"workername");
	room=master->query_room();
	task=t;
	if(!se) se="";
	ser=se;
	self_init();
	extra_init(); // for different npcs
}

//////////////////////// to judge if all right ///////////////////
int set_steps(int s) {
	steps=s;
	status=random(5*s);
	base_scenario_init(); // relate to the status
	return status;
}

int judge_error(int i) {
	int dis,tmp,lv;
	if(i>=steps) i=steps-1;
	if(i<0) i=0;
	tmp=i*5+2;
	if(tmp<status)  dis= status-tmp;
	else dis=tmp-status;
	lv=CHAR_D->get_skill(p_id,"sk_meili");
	lv=random(lv);
	if(lv>50)
		dis-=2;
	else if(lv>30)
		dis-=1;
	else if(lv<15)
		dis+=1;
	if(dis<0) dis=0;
	if(dis>4) dis=4;
	final_act(i,dis);
}
void solve_problem(string inp) {
	object usr;
	int val;
	if(inp=="l") {
		do_scenario("look");
		return;
	}
	if(inp=="a") {
		do_scenario("ask");
		return;
	}
	val=to_int(inp);
	if((val==0)&&(inp!="0"))
		return;
	if(val<0) return;
	if(val>=steps) return;
	judge_error(val);
}
void gave_problem() {
	object usr=find_user(p_id);
	if(!objectp(usr))
		disappear();
	tell_user(p_id,get_prompt());	
     usr->modal_push((: solve_problem :), get_prompt());
}

void announce_score(int score) {
	create_scenario("announce");
	if(score>0) 
		add_act("announce","a1","MTO",7,"%^H_GREEN%^$N工作不错，大家的干劲涨了"+score+"点。%^RESET%^\n"); 
	else if(score==0) 
		add_act("announce","a1","MTO",7,"$N工作没有什么成绩。\n"); 
	else 
		add_act("announce","a1","MTO",7,"%^H_RED%^$N工作失误，大家的干劲降了"+((-1)*score)+"点。%^RESET%^\n"); 

	do_scenario("announce");

}
