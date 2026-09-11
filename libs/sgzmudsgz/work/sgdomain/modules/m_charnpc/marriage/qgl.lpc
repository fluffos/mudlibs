// written by yuner , fire and row
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;

mixed ask_jiehun(object who);
mixed ask_lihun(object who);
mixed ask_parterner(string t_id);
mixed check();
void answer_agree1(object me,object tar,string ans);
void divorce();
void answer_agree(object me,object girl,string ans);
void answer_parter(object me, object who,string ans);
void special_answer(object who, string matt);

void setup()
{
    set_name("qiao guolao", "乔国老");
    set_gender(1);
    set_proper_name("乔老爷");
    set_in_room_desc("吴郡德高老者%^H_GREEN%^乔国老%^RESET%^(qiao guolao)");
    add_id("qiao");
    set_age(70);

    add_ask_str("jiehun","$N悄悄凑到$T耳边低声道：我有一事相求，不知。。。\n$N一时说不出口，羞得满脸通红。\n");
    add_question("jiehun","jiehun" );
	add_ask_str("lihun","$N低着头对$T道：老先生，我想离婚。\n");
	add_question("lihun","lihun");
}
string long() {
	return
"一个七十开外的老者，鹤发童言，满面笑容。\n";
}
mixed ask_jiehun(object who) {
	string p_id=who->query_primary_id();
	int p_gender;
	int p_age;

	p_gender=who->query_gender();
	if(p_gender==2) return "$N对$T叹了一口气，女人家也能问这样的事情，这世道。\n";
	if(p_gender!=1) return "$N把$T从头到脚打量了一变，连连摇头，不知什么地方不对劲。\n";

	p_age=who->query_age();
	if(p_age<16) return "$N轻轻拍了拍$T的头，说道：这么小就学会啦，等你们长大再来吧。\n";

	if(CHAR_D->get_char(p_id,"reputation")<10000) 
		return "$N对$T道：好男儿事业为重，$R还是先去成就一番事业，有些名声，才好成家业。\n";
	if(CHAR_D->get_char(p_id,"mar")) 
		return "$N对$T「哼」了一声：想重婚？门都没有！再问就抓起来！\n";
	return 1;
}
mixed ask_lihun(object who) {
	string p_id=who->query_primary_id();
	int p_gender;
	int p_age;

	p_gender=who->query_gender();
	if(p_gender!=1) return "$N把$T从头到脚打量了一变，连连摇头，不知什么地方不对劲。\n";

	if(!CHAR_D->get_char(p_id,"mar")) 
		return "$N对$T「哼」了一声：你疯了不成？！还没结婚就想离婚？\n";
	return 1;
}
mixed ask_parterner(string t_id) {
	object o_t;
	string t_name;
	if(!CHAR_D->char_exist(t_id))
		return "$N对$T奇怪地道："+t_id+"，我怎么没听说过。\n";
	t_name=CHAR_D->get_char(t_id,"name");
	if(CHAR_D->get_char(t_id,"type")!=TYPE_PLAYER)
		return "$N对$T冷笑道："+t_name+"不是凡间俗人，岂能随意亵渎。\n";
	if(CHAR_D->get_char(t_id,"gender")!=2)
		return "$N对$T冷笑道：你和"+t_name+"两个来搅局的是吧，再闹给我抓起来。\n";
	if(CHAR_D->get_char(t_id,"age")<15)
		return "$N对$T笑道："+t_name+"太小了，你也不能这么性急呀。\n";

	if(CHAR_D->get_char(t_id,"mar")) 
		return "$N对$T笑道："+t_name+"早有婆家了，哈，哈。\n";

	o_t=CHAR_D->find_char(t_id);
	if(!objectp(o_t))
		return "$N对$T笑道："+t_name+"没来，我要亲自问问她，这事可不能马虎。\n";
	if(o_t->query_room()!=this_object()->query_room())	
		return "$N对$T笑道："+t_name+"没来，我要亲自问问她，这事可不能马虎。\n";
	return 1;
}
mixed check()
{
	object o_t;
	string p_id=this_body()->query_primary_id();
	string t_id,t_name;
	t_id=CHAR_D->get_char(p_id,"mar");
	this_object()->clear_answer();
	if(!CHAR_D->char_exist(t_id)){
	this_object()->targetted_action("$N点点头，对$T道：原来你的伴侣不在人世，你既不愿守节，老夫便做个顺水人情吧。\n",this_body());
	CHAR_D->set_char(p_id,"ever_mar",1);
	call_out("divorce",3);
	return 1;}
	t_name=CHAR_D->get_char(t_id,"name");
	if(CHAR_D->get_char(t_id,"type")!=TYPE_PLAYER){
	this_object()->targetted_action("$N奇怪地看着$T："+t_name+"不是凡间俗人，这是孽缘，孽缘！得赶快斩断。\n",this_body());
	call_out("divorce",3);
	return 1;}
	o_t=CHAR_D->find_char(t_id);
	if(!objectp(o_t)){
	this_object()->targetted_action("$N对$T摇头道："+t_name+"没来，我要亲自问问，这事可不同儿戏。\n",this_body());
	return 1;}
	if(o_t->query_room()!=this_object()->query_room()){
	this_object()->targetted_action("$N对$T摇头道："+t_name+"没来，我要亲自问问，这事可不同儿戏。\n",this_body());
	return 1;}
	this_object()->targetted_action("$N对$T到：$R先不要着急，待我问问$o的意见。\n",this_body(),o_t);
	this_object()->targetted_action("$N问$T道：$R愿意和$o解除婚约吗？\n",o_t,this_body());
	tell_user(t_id,"愿意就：%^RED%^answer yes to qiao%^RESET%^。\n");
	CHAR_D->set_char(t_id,"pre_div",p_id);
	this_object()->set_answer(t_id, (:answer_agree1:) );
}
void answer_agree1(object me,object tar,string ans) {
	string p1,p2;
	object tar1;
	me->clear_answer();
	p1=tar->query_primary_id();
	p2=CHAR_D->get_char(p1,"pre_div");
	CHAR_D->set_char(p1,"pre_div",0);
	tar1=CHAR_D->find_char(p2);
	if(ans!="yes") {
		me->responda("sigh "+p2);
		me->targetted_action("$N对$T道：对方不同意，你们回去商量好了再来吧。\n",tar1);
		return; 
	}
	me->responda("hmm");
	me->targetted_action("$N对$T和$o道：好吧，既然双方心甘情愿，老夫也不再多说了。\n",tar1,tar);
	CHAR_D->set_char(p1,"mar",0);
	CHAR_D->set_char(p1,"ever_mar",1);
	CHAR_D->set_char(p2,"mar",0);
	CHAR_D->set_char(p2,"ever_mar",1);
	tell(users(),"%^H_MAGENTA%^【姻缘】%^H_GREEN%^乔国老%^H_YELLOW%^："+CHAR_D->get_char(p2,"name")+"自愿与"+
	CHAR_D->get_char(p1,"name")+"解除婚约，从此二人成路人，不再是夫妻了。\n");
	return;
}
void divorce()
{
	string p_id=this_body()->query_primary_id();
	CHAR_D->set_char(p_id,"mar");
	tell(users(),"%^H_MAGENTA%^【姻缘】%^H_GREEN%^乔国老%^H_YELLOW%^：世间诸事，怎一个『情』字了得。老夫今日做主，还"+CHAR_D->get_char(p_id,"name")+"自由身。\n");
	return;
}	
void answer_agree(object me,object girl,string ans) {
	string p_boy,p_girl;
	object boy;
	me->clear_answer();
	p_girl=girl->query_primary_id();
	p_boy=CHAR_D->get_char(p_girl,"pre_mar");
	CHAR_D->set_char(p_girl,"pre_mar",0);
	boy=CHAR_D->find_char(p_boy);
	if(ans!="yes") {
		me->responda("poor "+p_boy);
		me->targetted_action("$N对$T道：好男儿志在四方，大丈夫何患无妻。再去努力，找一个更漂亮的。\n",boy);
		return; 
	}
	me->responda("great");
	if(CHAR_D->get_char(p_girl,"ever_mar")||CHAR_D->get_char(p_boy,"ever_mar"))
	{
	me->simple_action("$N满脸笑容地道：你二人中有人再婚，依老夫看，就不必大操大办了吧。\n");
	boy->responda("ok");
	girl->responda("ok");
	CHAR_D->set_char(p_girl,"mar",p_boy);
	CHAR_D->set_char(p_boy,"mar",p_girl);
	tell(users(),"%^H_MAGENTA%^【姻缘】%^H_GREEN%^乔国老%^H_RED%^："+CHAR_D->get_char(p_boy,"name")+"与"+
	CHAR_D->get_char(p_girl,"name")+"不计前嫌，愿成百年之好，祝他们幸福。%^RESET%^\n");
	return;
	}
	me->targetted_action("$N对$T和$o道：好好，二位先去准备彩礼，良辰一到即刻拜堂成亲。\n"+
		"$n又补充道：未正式成婚之前可不许胡来啊。\n",boy,girl);
	CHAR_D->set_char(p_girl,"pri_mar",p_boy);
	CHAR_D->set_char(p_boy,"pri_mar",p_girl);
	tell(users(),"%^H_MAGENTA%^【姻缘】%^H_GREEN%^乔国老%^H_RED%^："+CHAR_D->get_char(p_boy,"name")+"愿与"+
	CHAR_D->get_char(p_girl,"name")+"成百年之好，祝他们早日成婚。%^RESET%^\n");
	return;
}
void answer_parter(object me, object who,string ans) {
	mixed ret;
	object o_t;
	string p_id;
	p_id=who->query_primary_id();
	me->clear_answer();
	ret=ask_parterner(ans);
	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}
	o_t=CHAR_D->find_char(ans);
	me->targetted_action("$N对$T到：$R先不要着急，待我先问问$o的意见。\n",who,o_t);
	me->targetted_action("$N对$T微笑道：$R愿意嫁给$o吗？\n",o_t,who);
	tell_user(ans,"愿意就：%^RED%^answer yes to qiao%^RESET%^。\n");
	CHAR_D->set_char(ans,"pre_mar",p_id);
	me->set_answer(ans, (:answer_agree:) );

}
void special_answer(object who, string matt)
{
	mixed ret;
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "jiehun" :
			ret=ask_jiehun(who);
			if(stringp(ret)) {
				this_object()->targetted_action(ret,who);
				return;
			}
		        this_object()->targetted_action(
				"$N对$T笑到：不必扭扭捏捏，年轻人想结婚呀，相中了谁了？\n",who);
			this_object()->set_answer(p_id, (:answer_parter:) );
			tell_user(p_id,"用%^RED%^answer <对象ID> to qiao%^RESET%^来回答。\n");
                        return;
			case "lihun":
			ret=ask_lihun(who);
			if(stringp(ret)){
				this_object()->targetted_action(ret,who);
				return;
			}
			this_object()->targetted_action(
			"$N看了$T一眼，道：哦？要离婚，待老夫查查。\n$N返身取出一册%^H_MAGENTA%^姻缘簿%^RESET%^查看了起来。\n",who);
			call_out("check",2);
			return;
        }
}