// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;

void setup()
{
    set_name("jiaohang laoban", "轿行老板");
    set_gender(1);
    set_in_room_desc("色迷迷的%^YELLOW%^轿行老板%^RESET%^(jiaohang laoban)");
    add_id("laoban");
    set_age(40);

    add_ask_str("jiaozi","$N对$T道：老板，我需要一顶花轿。\n");
    add_question("jiaozi","jiaozi" );

}
string long() {
	return
"一个色迷迷的%^YELLOW%^轿行老板%^RESET%^。\n";
}

mixed ask_jiaozi(object who) {
	int p_gender;
	string p_boy,p_girl;

	p_boy=who->query_primary_id();

	p_gender=who->query_gender();
	if(p_gender==2) return "$N对$T看了一眼，色迷迷地说道：小妹妹要什么花轿，\n"+
		"在我这儿住下了，天天给你做花轿。\n";
	p_girl=CHAR_D->get_char(p_boy,"pri_mar");
	if(!p_girl) 
		return "$N对$T笑到：要请花轿抱妹妹，先去乔老爷那里登记一下吧。\n";
	if(p_boy!=CHAR_D->get_char(p_girl,"pri_mar"))
		return "$N对$T笑到：你们关系不明不白，要请花轿抱妹妹，去乔老爷那里从新登记一下吧。\n";
		
	if(objectp(CHAR_D->find_char("jiaofu tou"))) 
		return "$N对$T笑到：轿子都租出去了，等一下再来吧。\n";
	if(objectp(CHAR_D->find_char("li guan"))) 
		return "$N对$T笑到：现在有人正在举行婚礼，你们再等等吧。\n";

	return 1;
}
void pay(string p_boy,int price) {
	object o_boy;
	int p_money;
	string p_girl;
	p_girl=CHAR_D->get_char(p_boy,"pri_mar");
	o_boy=find_body(p_boy);
	if(!objectp(o_boy)) return;
	o_boy->simple_action("$N道：好说，好说，这就给钱。\n");
	p_money=o_boy->query_all_con_money();
	price*=10000;
	if(p_money<price) {
		o_boy->simple_action("$N突然脸一红道：啊，啊，钱没带够。\n");
		this_object()->responda("admit "+p_boy);
		return;
	}
	
	o_boy->set_all_con_money(p_money-price);
	price/=10000;
	o_boy->targetted_action("$N给了$T"+chinese_number(price)+"两金子。\n",this_object());
	DELAY_D->delay_simple_action(this_object(),"$N满意地点了点手中的钱。\n",2);
	DELAY_D->delay_targetted_action(this_object(),o_boy,"$N对$T道：花轿已经准备好了，就在%^YELLOW%^虹桥%^RESET%^，快去把。\n",2);
	CHAR_D->add_char("jiaofu tou");
	CHAR_D->set_char("jiaofu tou","body","marriage/cgs");
	CHAR_D->set_char("jiaofu tou","is_tmp",1);
	CHAR_D->appear("jiaofu tou","wujun","wj_hq","$N领着一个送亲队伍开了过来。\n");
	CHAR_D->find_char("jiaofu tou")->set_boygirl(p_boy,p_girl);
	CHAR_D->remove_char_d("jiaofu tou");
	tell(users(),"%^H_RED%^【婚礼】轿行老板色迷迷地思量着：今晚"+
	CHAR_D->get_char(p_boy,"name")+"就要和"+CHAR_D->get_char(p_girl,"name")+"行房，有好戏看了。嘿嘿. . . \n");
}
void before_check(object who) {
	string p_boy,p_girl;
	object o_boy,o_girl;
	string msg;
	int price;
	int p_rongmao;
	p_boy=who->query_primary_id();
	o_boy=CHAR_D->find_char(p_boy);
	p_girl=CHAR_D->get_char(p_boy,"pri_mar");
	o_girl=CHAR_D->find_char(p_girl);
	if((!objectp(o_girl))||(o_girl->query_room()!=this_object()->query_room())) {
		this_object()->targetted_action("$N对$T道：小妹妹在哪里呀，要找来看看才好备轿。\n",o_boy);
		return;
	}
	p_rongmao=CHAR_D->get_char(p_girl,"gift")["rongmao"];
	this_object()->targetted_action("$N迷着色眼，把$T从上倒下仔仔细细地看了一边。\n",o_girl);
	this_object()->respanda("look "+p_girl);
	if(p_rongmao>25) {
		msg="$N对$T呀的一声，不得了，不得了，"+CHAR_D->get_char(p_boy,"name")+"从哪里找到这等尤物，我受不了了。\n"+
			"一定要坐头等花轿，说着口水都流了出来。\n";
		price=100;
	}
	else if(p_rongmao>20) {
		msg="$N对$T道，小妹妹长得不错呀，要安排上等花轿，说这在$t的脸蛋上掐了一把。\n";
		price=50;
	}
	else if(p_rongmao>15) {
		msg="$N对$o道：你的老婆还可以，长得不是太好，就安排个普通轿子吧。\n";
		price=20;
	}
	else {
		msg="$N对$T呀了一声，这么丑的丫头，不知"+CHAR_D->get_char(p_boy,"name")+"从哪里找到的，真受不了了。\n"+
			"算我开眼送你们个便宜轿子吧。\n";
		price=10;
	}
	this_object()->targetted_action(msg,o_girl,o_boy);

	DELAY_D->delay_targetted_action(this_object(),o_boy,"$N对$T道：费用"+chinese_number(price)+
		"两金子，$R就请先交钱吧。\n",3);
	call_out("pay",6,p_boy,price);
}
void special_answer(object who, string matt)
{
	mixed ret;
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "jiaozi" :
			ret=ask_jiaozi(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}
			before_check(who);
        }
}
