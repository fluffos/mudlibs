// the body of ppl
#include <ppl.h>
#define NAME __DIR__+"name"
inherit PMODULES+"m_charnpc";
private int typ;
private string p_surname,p_id,p_givenname;
private int p_age,p_rongmao,p_gender,p_salary;
private string m_id;
mapping get_info () {
	mapping ret=([]);
	ret["typ"]=typ;
	ret["sname"]=p_surname;
	ret["gname"]=p_givenname;
	ret["age"]=p_age;
	ret["rongmao"]=p_rongmao;
	ret["gender"]=p_gender;
	ret["salary"]=p_salary;
	ret["cometime"]=time();
	return ret;
}
string get_p_id() {
	return p_id;
}
int set_salary(int s) {
	p_salary=s;
	return s;
}
void setup()
{
	object jia;
	typ=random(6)+1;
	p_surname=(NAME)->get_surname(typ);
	p_givenname=(NAME)->get_given_name(typ);
	p_age=(NAME)->get_age(typ);
	p_gender=(NAME)->get_gender(typ);
	p_rongmao=(NAME)->get_rongmao(typ);
	p_id=(NAME)->get_id(typ);
	m_id="r"+time()+random(50);	
	p_salary=(NAME)->get_salary(typ);
	p_salary+=p_rongmao;

	set_name(m_id,p_surname+p_givenname);
	add_id("ppl");
	add_id(p_id);
	set_gender(p_gender);
	set_age(p_age);
	set_sg_rongmao(p_rongmao);
	set_in_room_desc((NAME)->get_desc(typ)+p_surname+p_givenname+"("+p_id+")");
	//printf("NAME = %s, typ = %d\n",NAME,typ);
	jia=OBJ_D->clone_obj((NAME)->get_dress(typ));
	jia->move(this_object());
	jia->do_wear();

   	add_question("followme","followme");
	
	add_ask_str("followme","$N对$T一拱手道：$R在家闲者多没意思，\n"+
"到我家去做事吧，有吃有喝有钱决不会亏待你的。\n");
	
}


int is_ppl() {
	return 1;
}
mixed can_ask_followme(object who) {
	int r_num,n_num;
	string m_id=who->query_primary_id();
	object o_h;
	o_h=SGHOME(m_id);
	if(!objectp(o_h)) 
		return "$N对$T道：你自己都没家可回，还让我去你家，吹牛。\n";
	r_num=o_h->get_room("size");
	n_num=o_h->get_npc("size");
	if(n_num>r_num)
		return "$N对$T道：你家地方太小，人太多，我不想去。\n";
	return 1;
}

void answer_yes(object me, object who,string ans) {
	object o_h;
	if(ans!="yes") {
		me->targetted_action(
		"$N不满地对$T说道：一两金子都不肯给，$r也太小气了。\n",who);
		me->simple_action("$N转身离开了。\n");
		destruct(me);
		return;
	}
	if(MONEY_D->sub_poket_money(who,10000)!=1) {
		who->targetted_action(
			"$N一模口袋，脸一红，对$T不好意思地说，对不起，身上没有代钱。\n",me);
		me->targetted_action(
		"$N不满地对$T说道：身上连一两金子都没有，$r也太小气了。\n",who);
		me->simple_action("$N转身离开了。\n");
		destruct(me);
		return;
	}
	who->targetted_action(
		"$N给$T一两金子。\n",me);
	me->responda("rich");
	me->targetted_action(
		"$N对$T说道：我准备一下，随后就到$R家中去。\n",who);
	o_h=SGHOME(who->query_primary_id());
	o_h->add_npc(me);
	me->simple_action("$N转身离开了。\n");
	destruct(me);
}

void answer_salary(object me, object who,string ans) {
	
	int m_salary=to_int(ans);
	me->clear_answer();
	if(m_salary<=p_salary) {
		me->targetted_action(
		"$N不满地对$T说道：一月才"+CHINESE_D->chinese_value(m_salary*100)+
		"，$r也太小气了。\n",who);
		me->simple_action("$N转身离开了。\n");
		destruct(me);
		return;
	}
	p_salary=m_salary;
	me->responda("jump");
	me->targetted_action(
		"$N对$T道：$R真是太好了，不过我还需要一两金子的定金，可以给我吗？\n",who);
	tell(who,"用 answer yes to "+p_id+" 表示同意。\n");

	me->set_answer(who->query_primary_id(), (:answer_yes:) ); 

}


void special_answer(object who, string matt)
{
	mixed ret;
  	switch(matt)
	{
	      case "followme" :
		ret=can_ask_followme(who);
		if(stringp(ret)) {
			this_object()->targetted_action(ret,who);
			return;
		}
		this_object()->responda("consider");
		this_object()->targetted_action(
			"$N对$T道：你给我多少月钱呀？\n",who);
		tell(who,"用 answer <数字> to "+p_id+" 来回答 <数字> 代表每月多少两银子。\n");
		this_object()->set_answer(who->query_primary_id(), (:answer_salary:) );
       	        return;
  	}
}
string query_name() {
	return p_surname+p_givenname;
}