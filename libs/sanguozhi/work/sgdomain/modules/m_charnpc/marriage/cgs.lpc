// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;
inherit M_SMARTMOVE;
#define MARRY_GATE "/sgdomain/area/marriage/marry_gate"
#define PICPATH "/sgdomain/modules/m_charnpc/marriage/huajiao/"
string p_boy,p_girl;
string p_boyname,p_girlname;
string p_area;
string p_step;
int p_life;
nosave protected string *desc=({
        "你往红红的轿帘外看去，却什么也看不清楚。\n",
        "你想着他的样子，一片红云飘上了脸颊。\n",
        "轿子晃悠悠的在走，你的心也晃悠悠在动。\n",
        "你悄悄掀开大红布头的一角来，偷偷的往轿外看。\n",
        "喜乐声声，想着今天晚上。。。你羞红了脸。\n",
        "大家在看我吧。。。你想起他，心里泛起一阵甜蜜。\n",     
});
nosave protected string *chaois=({
    "一群小孩跟着花轿跑着，跳着，要着喜糖。\n",
    "吹鼓手的小号滴，滴，哒，哒的好不热闹。\n",
    "一人高喊，新娘笑了，众人哄堂大笑。\n",
    "爆竹霹雳啪啦响个不听，好象过年一样。\n",
});
private string* pics=({});
void load_pic() {
	string *fs;
	string p;
	fs=get_dir(PICPATH+"*.pic");
	foreach(string f in fs) {
		p=read_file(PICPATH+f);
		pics+=({p});
	}
}
string show_pic(){
	return "\n四个轿夫抬这一顶花轿\n"+
pics[random(sizeof(pics))]+
"一群吹鼓手吹吹打打，好不热闹。\n"+
"一个精明能干的轿夫头(jiaofu tou)\n"; 

}
void setup()
{
    set_name("jiaofu tou", "轿夫头");
    set_gender(1);
    load_pic();
    set_in_room_desc((: show_pic :));

/*     set_in_room_desc("\n四个轿夫抬这一顶花轿\n\n"+
"%^RED%^          __________________
          {|   ________   |}
          {|  [~~~~~~~~]  |}
          {|  [$$$$$$$$]  |}
          {|  [$$$$$$$$]  |}
  ==================================%^RESET%^\n\n"+
"一群吹鼓手吹吹打打，好不热闹。\n"+
"一个精明能干的轿夫头(jiaofu tou)\n"); */
   set_max_capacity(VERY_LARGE*2) ;
    add_ask_str("xinren","$N对$T小声道：谁结婚呀，这么排场。\n");
    add_question("xinren","xinren" );
	call_out("check",10);

}
void finish() {
	object *os;
	remove_call_out("check");
	this_object()->simple_action(
	"众轿夫和吹鼓手一哄而散，全离开了。\n");
	os=this_object()->all_inventory();
	if(sizeof(os)) {
		foreach(object o in os) 
			o->move(environment(this_object()));
	}
	this_object()->remove();
}
void chaois() {
	string msg;
	msg=chaois[random(sizeof(chaois))];
	this_object()->simple_action(msg);
}
void go_boy_city() {
	string p_area;
	p_area=CHAR_D->get_char(p_boy,"area");

	this_object()->simple_action(
		"$N朗声道：大伙听着：新郎官"+p_boyname+
		"家住"+AREA_D->get_area(p_area,"name")+
		"，新郎官只要一指示，就马上出发了。\n");
	this_object()->responda("tell "+p_boy+" 准备好了就：%^RED%^ask jiaofu tou about qijiao%^RESET%^。\n");
	
}
void catch_girl() {
	object o_girl,o_boy;
	o_girl=find_body(p_girl);
	if(!objectp(o_girl)) return ; // impossible
	if(o_girl->query_room()!=this_object()->query_room()) {
		this_object()->simple_action(
		"$N奇怪地道：新娘子在哪，谁见到新娘子"+p_girlname+"了，大活儿快去找找。\n");
		return;
	}
	this_object()->targetted_action("$N一指$T，啊，新娘子在那，快扶上轿里，别让她跑了。\n",o_girl);
	o_girl->simple_action("几个大汉一拥而上，把$N抱住，头上蒙上一快红布，一把塞进花轿里。\n");
	o_girl->move(this_object());
	p_step="go_boy_city";	
	o_boy=find_body(p_boy);
	if(!objectp(o_boy)) return ; // impossible

   	o_boy->set_asklist("qijiao","target","jiaofu tou");
   	o_boy->set_asklist("qijiao","filename",file_name(this_object()));
   	o_boy->set_asklist("qijiao","funname","ask_qijiao");

}
void check() {
	object o_boy,o_girl;
	o_boy=find_body(p_boy);
	o_girl=find_body(p_girl);
	p_life++;
	remove_call_out("check");
	call_out("check",5+random(5));

	if(!objectp(o_boy)) {
		this_object()->simple_action(
		"$N奇怪地道：新郎官不见了，看来婚礼是办不成了，大伙回去吧。\n");
		finish();
		return ;
	}
	if(!objectp(o_girl)) {
		this_object()->simple_action(
		"$N奇怪地道：新娘子不见了，看来婚礼是办不成了，大伙回去吧。\n");
		finish();
		return;
	}
	switch (p_step) {
		case "catchgirl": 
			catch_girl();
			break;
		case "go_boy_city":
			go_boy_city();
			break;
		case "move_to_dongfang":
			chaois();
			break;

		default :
		this_object()->simple_action(
		"$N奇怪地道：现在我也不知道该干什么，看来婚礼是办不成了，大伙回去吧。\n");
		finish();

	}
}
int set_boygirl(string boy,string girl) {
	p_boy=boy,p_girl=girl;
	p_boyname=CHAR_D->get_char(p_boy,"name");
	p_girlname=CHAR_D->get_char(p_girl,"name");
	p_area=CHAR_D->get_char(p_boy,"area");
	p_step="catchgirl";
	p_life=1;
	remove_call_out("check");
	call_out("check",3);
	return 1;
}
string long() {
	return
"一个精明能干的轿夫头，正在老练地领导这一只送亲队伍。\n";
}

string get_arrival_msg()
{
  return "热热闹闹的送亲队伍开了过来。\n";
}
string get_departure_msg()
{
  return "热热闹闹的送亲队伍向$o开了过去。\n";

}

string *get_player_message(string message, mixed arg) {
    string mess;
    if ( message == "leave" )
      {
    mess = get_departure_msg();
      }
    else if ( message == "enter" )
      {
    mess = get_arrival_msg();
      }
    return action( ({ this_object() }), mess, arg);
}

void do_looking(int forced_look)
{
	string msg;
	msg="你在花轿里，外面的情况一点也看不见，只能听到一阵阵欢笑声和吵闹声。\n";
	msg+=desc[random(sizeof(desc))];
	write(msg);
}

void answer_move(object me,object o_boy,string dir) {
	string fn;
	this_object()->simple_action("$N笑道：好，好，咱们就往%^RED%^"+dir+"%^RESET%^方向走。\n");
	this_object()->clear_answer();	
	this_object()->responda("go "+dir);
	fn=file_name(environment(this_object()));
	if(fn==MARRY_GATE) {
		object o_girl;
		this_object()->simple_action("$N高声叫道：到了！\n");
		o_girl=find_body(p_girl);
		o_girl->move(load_object(MARRY_GATE));
		o_girl->simple_action("$N在众人搀扶下下了花轿。\n");
		tell(users(),"%^H_RED%^【婚礼】轿夫头：花轿已经送到，"+
		p_boyname+"和"+p_girlname+"的婚礼就要开始了，大家都来看呀。\n");
		finish();
	}
}
void ask_move(object o_boy) {
       o_boy->targetted_action("$N对$T小声道：时辰不早了，咱们快走吧。\n",this_object());
        this_object()->simple_action("$N对众人道：看看，看看，新郎官等不及了，众人一阵哄堂大笑。\n");
	this_object()->targetted_action("$N对$T道：咱们要往那个方向走呀。\n",o_boy);
	this_object()->set_answer(p_boy, (:answer_move:) );
	return;
}
void ask_qijiao(object who) {
	object rom,gate;
	who->clear_asklist("qijiao");

       who->targetted_action("$N对$T小声道：准备好了，出发吧。\n",this_object());

	this_object()->simple_action("$N高呼：起轿。\n"+
	"众轿夫在吹鼓手的鼓乐声中，浩浩荡荡地向"+
	AREA_D->get_area(p_area,"name")+"发去。\n");

	gate=load_object(AREA_D->get_area(p_area,"path")+
		AREA_D->get_area(p_area,"go"));
	CHAR_D->appear("jiaofu tou",p_area,AREA_D->get_area(p_area,"go"),
		"$N领这一只送亲队伍在一阵鼓乐声中，浩浩荡荡地开了过来。\n");

	this_object()->move(gate);

	p_step="move_to_dongfang";
	
   	who->set_asklist("move","target","jiaofu tou");
   	who->set_asklist("move","filename",file_name(this_object()));
   	who->set_asklist("move","funname","ask_move");
	rom=load_object("/a/"+p_area+"/"+AREA_D->get_area(p_area,"meeting"));
	rom->add_exit("litang" , MARRY_GATE);
	rom=load_object(MARRY_GATE);
	rom->add_exit("out","/a/"+p_area+"/"+AREA_D->get_area(p_area,"meeting"));

	CHAR_D->add_char("li guan");
	CHAR_D->set_char("li guan","body","marriage/lg");
	CHAR_D->set_char("li guan","is_tmp",1);
	CHAR_D->appear("li guan",p_area,"meeting","$N兴致勃勃地走了过来。\n");
	CHAR_D->find_char("li guan")->set_boygirl(p_boy,p_girl);
	CHAR_D->remove_char_d("li guan");

	CHAR_D->add_char("si yi");
	CHAR_D->set_char("si yi","body","marriage/sy");
	CHAR_D->set_char("si yi","is_tmp",1);
	CHAR_D->put_char("si yi","/sgdomain/area/marriage/marry_tang");
	CHAR_D->find_char("si yi")->set_boygirl(p_boy,p_girl);
	CHAR_D->remove_char_d("si yi");

}
void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "xinren" :
			this_object()->targetted_action(
				"$N对$T神秘地道：$R不知：新人乃大名鼎鼎的"+
				p_boyname+"和"+p_girlname+"呀。\n",who);
			return; 

        }
}

int query_light() {
	return 1;
}
int query_clean_up() {
	return (p_life<200); // if p_life<200 can't clean up
}
