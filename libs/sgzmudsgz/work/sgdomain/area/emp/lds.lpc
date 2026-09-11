// by fire
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <ansi.h>
#define BOOK_FILE "/sgdomain/obj/other/bs"
inherit LIVING;
inherit M_BLOCKEXITS;

private mapping m_list=([
"tpys1" : (["name" : "《太平要术.天变篇》", "skill" : "tianbian" , "lev" : 30,"vol" : 1]),
"tpys2" : (["name" : "《太平要术.风变篇》", "skill" : "fengbian" , "lev" : 30,"vol" : 1]),
"tpys3" : (["name" : "《太平要术.天变篇》", "skill" : "tianbian" , "lev" : 60,"vol" : 2]),
"tpys4" : (["name" : "《太平要术.风变篇》", "skill" : "fengbian" , "lev" : 60,"vol" : 2]),
"tpys5" : (["name" : "《太平要术.天变篇》", "skill" : "tianbian" , "lev" : 90,"vol" : 3]),
"tpys6" : (["name" : "《太平要术.风变篇》", "skill" : "fengbian" , "lev" : 90,"vol" : 3]),
"yj1" : (["name" : "《易经.卜算篇》", "skill" : "zhanbu" , "lev" : 30,"vol" : 1]),
"yj2" : (["name" : "《易经.卜算篇》", "skill" : "zhanbu" , "lev" : 60,"vol" : 2]),
"yj3" : (["name" : "《易经.卜算篇》", "skill" : "zhanbu" , "lev" : 90,"vol" : 3]),
"sd1" : (["name" : "《毒经》", "skill" : "shidu" , "lev" : 30,"vol" : 1]),
"sd2" : (["name" : "《毒经》", "skill" : "shidu" , "lev" : 60,"vol" : 2]),
"sd3" : (["name" : "《毒经》", "skill" : "shidu" , "lev" : 90,"vol" :3]),
"jd1" : (["name" : "《青囊书》", "skill" : "jiedu" , "lev" : 30,"vol" : 1]),
"jd2" : (["name" : "《青囊书》", "skill" : "jiedu" , "lev" : 60,"vol" : 2]),
"jd3" : (["name" : "《青囊书》", "skill" : "jiedu" , "lev" : 90,"vol" : 3]),
]);

private mapping d_list=([
"yyd" : (["name" : "  养颜丹", "day" : 49 , "gold" : 100,"strday": "七七四十九天"]),
"csd" : (["name" : "  长生不老丹", "day" : 81 , "gold" : 500,"strday": "九九八十一天"]),

]);


private mixed handle_blocks( string dir )
{
	object o;
        o=present("cang shu",this_body());
	if(objectp(o)) {
		this_body()->targetted_action(
"$N把$O交给了$T。\n",this_object(),o);
		o->remove();
	}
	return 0;
}

void setup()
{
        set_name("zixu shangren", "紫虚上人");
        set_gender(1);
        set_in_room_desc("紫虚上人(zixu shangren)");
        set_age(60);
	add_id("daoshi");
        add_question("book","book");
        add_ask_str("book","$N对$T道：听说仙长有不少奇书，可否借$s一观。\n");
        add_question("list","list");
        add_ask_str("list","$N对$T道：请问仙长都有些什么奇书和灵丹呀。\n");
        add_question("dan","dan");
        add_ask_str("dan","$N对$T道：听说仙长山中多有奇遇，能炼不少灵丹，$s有一请求，不知能不能. . . .\n");

        add_question("good","good");
        add_ask_str("good","$N对$T道：我想要的丹，也不知道长练好了没有。\n");

        add_block("south");

}
string long() {
        return "他是在川中锦屏山上修道的异人，却不知道为什么到了这里为皇帝炼丹。\n";
}
void input_book(object who, string str) {
	object u,bk,shoyu;
	string *list;
	if(!objectp(who)) return;
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_pop();
	if(!str) str="";
	list=keys(m_list);
	if(member_array(str,list)==-1) {
		this_object()->targetted_action(
"$N对$T道：$R所要的书，我怎么从没听说过呀。\n",who);
		return;
	}
	bk=new(BOOK_FILE);
	bk->add_id(m_list[str]["name"]+"第"+chinese_number(m_list[str]["vol"])+"卷");
	bk->set_skill(m_list[str]["skill"]);
	bk->set_lev(m_list[str]["lev"]);
	who->targetted_action("$N对$T说了些什么。\n",this_object());
	this_object()->targetted_action("$N交给$T$O\n",who,bk);
	bk->move(who);

	shoyu=present("ysf pass",who);
	if(objectp(shoyu)) {
		shoyu->remove();
	}

}
void ask_book(object who) {
	object u;
	object shoyu;
	shoyu=present("ysf pass",who);
	if(!objectp(shoyu)) {
		this_object()->targetted_action(
"$N对$T道：没有圣上的手谕，老朽的这几本旧书也不敢乱给人看。\n",who);
		return ;
	}
	shoyu->remove();
	this_object()->targetted_action(
"$N对$T道：好说，好说，不知$R要读哪部书。\n",who);
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_push((: input_book, who :),"请输入书代号。\n");
}

void ask_list(object who) {
	string msg;
	string *list;
	this_object()->targetted_action(
"$N对$T道：这里有几本旧书，我还能炼一点仙丹。\n",who);
        msg="id               名称\n";
	list=keys(m_list);
	foreach(string l in list) {
		msg+=sprintf("%-7s  %-24s %s\n",l,m_list[l]["name"],"第"+
			chinese_number(m_list[l]["vol"])+"卷");
	}
	list=keys(d_list);
	foreach(string l in list) {
                msg+=sprintf("%-7s  %-24s %s\n",l,d_list[l]["name"],
			chinese_number(d_list[l]["gold"])+"金");
	}

	tell_user(who->query_primary_id(),msg);
	return ;
}
void input_dan(object who, string str) {
	object u;
	string *list;
	int p_gold,p_id;
	object shoyu;
	if(!objectp(who)) return;
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_pop();
	p_id=who->query_primary_id();
	if(!str) str="";
	list=keys(d_list);
	if(member_array(str,list)==-1) {
		this_object()->targetted_action(
"$N对$T道：$R所需的仙丹，我怎么从没听说过呀。\n",who);
		return;
	}
	p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_gold<d_list[str]["gold"]) {
		this_object()->targetted_action(
"$N对$T道：$R帐上的钱不够嘛。\n",who);
		return;
	}
	CHAR_D->set_char(p_id,"gold",p_gold-d_list[str]["gold"]);
	tell_user(p_id,"你帐上的"+chinese_number(d_list[str]["gold"])+"两黄金被道士划走了。\n");
	CHAR_D->set_char(p_id,"lian_dan",(["time" : time(),"dan" : str]));
	this_object()->targetted_action(
"$N对$T道：$R所要的"+d_list[str]["name"]+"需练"+d_list[str]["strday"]+
"，到时就来领取仙丹吧。\n",who);
	shoyu=present("ysf pass",who);
	destruct(shoyu);

}
void ask_dan(object who) {
	object u;
	object shoyu;
	string p_id;

	shoyu=present("ysf pass",who);
	p_id=who->query_primary_id();
	if(p_id!=CHAR_D->get_char(p_id,"nation")) // this is not king
	{
		this_object()->targetted_action(
		  "$N对$T道：我只给一国之君炼丹。\n",who);
		return ;
	}

	if(!objectp(shoyu)) {
		this_object()->targetted_action(
"$N对$T道：没有圣上的手谕，老朽也不敢乱给人练丹。\n",who);
		return ;
	}
	shoyu->remove();
	this_object()->targetted_action(
"$N对$T道：好说，好说，不知$R要练什么丹。\n",who);
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_push((: input_dan, who :),"请输入仙丹代号。\n");

}
void ask_good(object who) {
	string p_id;
	mixed my_dan;
	string d_id;
	int t_time;
	object o_dan;
	p_id=who->query_primary_id();
	my_dan=CHAR_D->get_char(p_id,"lian_dan");
	if(!mapp(my_dan)) {
		this_object()->targetted_action(
"$N对$T道：$R没在这儿练丹吧。\n",who);
		return ;
	}
	d_id=my_dan["dan"];
	if(!mapp(d_list[d_id])) {
		this_object()->targetted_action(
"$N对$T道：很抱歉，$R所练的丹被巫师取消了。\n",who);
		return ;
	}
	t_time=time();
	t_time-=my_dan["time"];
	t_time/=60; t_time/=16;
	t_time=d_list[d_id]["day"]-t_time;
	if(t_time>0) {
		this_object()->targetted_action(
"$N对$T道：$R所练的丹还需要等"+chinese_number(t_time)+"天。\n",who);
		return ;
	}
	o_dan=new(__DIR__+"dan/"+d_id);
	o_dan->move(this_body());
	CHAR_D->set_char(p_id,"lian_dan",0);
	this_object()->targetted_action(
"$N对$T道：$R所练的丹已经好了，$M给$n1p$O。\n",who,o_dan);
	
}
void special_answer(object who, string matt)
{
	switch(matt) {
		case "book":
			ask_book(who);
			return ;
		case "list":
			ask_list(who);
			return ;
		case "dan":
			ask_dan(who);
			return ;
		case "good":
			ask_good(who);
			return ;

	}
}
