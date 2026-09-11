// written by yuner and fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
inherit M_CHAR;
inherit LIVING;
void setup()
{
    set_name("qiao guolao", "乔国老");
    set_gender(1);
    set_proper_name("乔老爷");
    set_in_room_desc("吴郡德高老者%^H_GREEN%^乔国老%^RESET%^(qiao guolao)");
    add_id("qiao");
    set_age(70);

    add_ask_str("jiehun","$N悄悄凑到$T耳边低声道：我有一事相求，不知..一时说不出口，羞得满脸通红。\n");
    add_question("jiehun","jiehun" );

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
void answer_agree(object me,object girl,string ans) {
	string p_boy,p_girl;
	object boy;
	p_girl=girl->query_primary_id();
	p_boy=CHAR_D->get_char(p_girl,"pre_mar");
	CHAR_D->set_char(p_girl,"pre_mar",0);
	boy=CHAR_D->find_char(p_boy);
	if(ans!="yes") {
		me->responda("poor "+p_boy);
		me->targetted_action("$N对$T到，好男儿志在四方，大丈夫何患无妻。\n",boy);
		return; 
	}
	me->responda("great");
	me->targetted_action("$N对$T和$o道：好好，二位先去准备彩礼，良辰一到即刻拜堂成亲。\n"+
		"$n又补充道：未正式成婚之前可不许胡来啊。\n",boy,girl);
	CHAR_D->set_char(p_girl,"pri_mar",p_boy);
	CHAR_D->set_char(p_boy,"pri_mar",p_girl);
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
        }
}
