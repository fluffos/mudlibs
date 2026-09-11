// by fire
/* Do not remove the headers from this file! see /USAGE for more info. */
#include <ansi.h>
#define BOOK_FILE "/sgdomain/obj/other/bs"
inherit LIVING;
inherit M_BLOCKEXITS;

private mapping m_list=([
"cz1" : (["name" : "《三略·沉着篇》", "skill" : "chenzhuo" , "lev" : 30,"vol" : 1]),
"cz2" : (["name" : "《三略·沉着篇》", "skill" : "chenzhuo" , "lev" : 60,"vol" : 2]),
"cz3" : (["name" : "《三略·沉着篇》", "skill" : "chenzhuo" , "lev" : 90,"vol" : 3]),
"fire1" : (["name" : "《孙子兵法·火攻篇》", "skill" : "jbhj" , "lev" : 30,"vol" : 1]),
"fire2" : (["name" : "《孙子兵法·火攻篇》", "skill" : "jbhj" , "lev" : 60,"vol" : 2]),
"fire3" : (["name" : "《孙子兵法·火攻篇》", "skill" : "jbhj" , "lev" : 90,"vol" : 3]),
"water1" : (["name" : "《吴子兵法·水攻篇》", "skill" : "jbsj" , "lev" : 30,"vol" : 1]),
"water2" : (["name" : "《吴子兵法·水攻篇》", "skill" : "jbsj" , "lev" : 60,"vol" : 2]),
"water3" : (["name" : "《吴子兵法·水攻篇》", "skill" : "jbsj" , "lev" : 90,"vol" : 3]),
"hl1" : (["name" : "《六韬·混乱篇》", "skill" : "hunluan" , "lev" : 30,"vol" : 1]),
"hl2" : (["name" : "《六韬·混乱篇》", "skill" : "hunluan" , "lev" : 60,"vol" : 2]),
"hl3" : (["name" : "《六韬·混乱篇》", "skill" : "hunluan" , "lev" : 90,"vol" : 3]),
"sq1" : (["name" : "《孟德新书·士气篇》", "skill" : "guwu" , "lev" : 30,"vol" : 1]),
"sq2" : (["name" : "《孟德新书·士气篇》", "skill" : "guwu" , "lev" : 60,"vol" : 2]),
"sq3" : (["name" : "《孟德新书·士气篇》", "skill" : "guwu" , "lev" : 90,"vol" : 3]),
"jm1" : (["name" : "《兵法二十四编·叫骂篇》", "skill" : "jiaoma" , "lev" : 30,"vol" : 1]),
"jm2" : (["name" : "《兵法二十四编·叫骂篇》", "skill" : "jiaoma" , "lev" : 60,"vol" : 2]),
"jm3" : (["name" : "《兵法二十四编·叫骂篇》", "skill" : "jiaoma" , "lev" : 90,"vol" : 3]),
"qb1" : (["name" : "《鬼谷子·奇兵篇》", "skill" : "qibing" , "lev" : 30,"vol" : 1]),
"qb2" : (["name" : "《鬼谷子·奇兵篇》", "skill" : "qibing" , "lev" : 60,"vol" : 2]),
"qb3" : (["name" : "《鬼谷子·奇兵篇》", "skill" : "qibing" , "lev" : 90,"vol" : 3]),
"hb1" : (["name" : "《鬼谷子·疑兵篇》", "skill" : "huangbao" , "lev" : 30,"vol" : 1]),
"hb2" : (["name" : "《鬼谷子·疑兵篇》", "skill" : "huangbao" , "lev" : 60,"vol" : 2]),
"hb3" : (["name" : "《鬼谷子·疑兵篇》", "skill" : "huangbao" , "lev" : 90,"vol" : 3]),
"jcml1" : (["name" : "《孙子兵法·诡道篇》", "skill" : "fakeorder" , "lev" : 30,"vol" : 1]),
"jcml2" : (["name" : "《孙子兵法·诡道篇》", "skill" : "fakeorder" , "lev" : 60,"vol" : 2]),
"jcml3" : (["name" : "《孙子兵法·诡道篇》", "skill" : "fakeorder" , "lev" : 90,"vol" : 3]),
"nh1" : (["name" : "《兵法二十四编·用间篇》", "skill" : "neihong" , "lev" : 30,"vol" : 1]),
"nh2" : (["name" : "《兵法二十四编·用间篇》", "skill" : "neihong" , "lev" : 60,"vol" : 2]),
"nh3" : (["name" : "《兵法二十四编·用间篇》", "skill" : "neihong" , "lev" : 90,"vol" : 3]),
"ss1" : (["name" : "《三略·收拾篇》", "skill" : "shoushi" , "lev" : 30,"vol" : 1]),
"ss2" : (["name" : "《三略·收拾篇》", "skill" : "shoushi" , "lev" : 60,"vol" : 2]),
"ss3" : (["name" : "《三略·收拾篇》", "skill" : "shoushi" , "lev" : 90,"vol" : 3]),
"mf1" : (["name" : "《鬼谷子·伏兵篇》", "skill" : "maifu" , "lev" : 30,"vol" : 1]),
"mf2" : (["name" : "《鬼谷子·伏兵篇》", "skill" : "maifu" , "lev" : 60,"vol" : 2]),
"mf3" : (["name" : "《鬼谷子·伏兵篇》", "skill" : "maifu" , "lev" : 90,"vol" : 3]),
"ff1" : (["name" : "《孟德新书·奋发篇》", "skill" : "fenfa" , "lev" : 30,"vol" : 1]),
"ff2" : (["name" : "《孟德新书·奋发篇》", "skill" : "fenfa" , "lev" : 60,"vol" : 2]),
"ff3" : (["name" : "《孟德新书·奋发篇》", "skill" : "fenfa" , "lev" : 90,"vol" : 3]),
"mh1" : (["name" : "《吴子兵法·灭火篇》", "skill" : "miehuo" , "lev" : 30,"vol" : 1]),
"mh2" : (["name" : "《吴子兵法·灭火篇》", "skill" : "miehuo" , "lev" : 60,"vol" : 2]),
"mh3" : (["name" : "《吴子兵法·灭火篇》", "skill" : "miehuo" , "lev" : 90,"vol" : 3]),
"ls1" : (["name" : "《六韬·落石篇》", "skill" : "luoshi" , "lev" : 30,"vol" : 1]),
"ls2" : (["name" : "《六韬·落石篇》", "skill" : "luoshi" , "lev" : 60,"vol" : 2]),
"ls3" : (["name" : "《六韬·落石篇》", "skill" : "luoshi" , "lev" : 90,"vol" : 3]),
"rs1" : (["name" : "《孙子兵法·绝地篇》", "skill" : "luanshe" , "lev" : 30,"vol" : 1]),
"rs2" : (["name" : "《孙子兵法·绝地篇》", "skill" : "luanshe" , "lev" : 60,"vol" : 2]),
"rs3" : (["name" : "《孙子兵法·绝地篇》", "skill" : "luanshe" , "lev" : 90,"vol" : 3]),
"zc1" : (["name" : "《鬼谷子·侦察篇》", "skill" : "scout" , "lev" : 30,"vol" : 1]),
"zc2" : (["name" : "《鬼谷子·侦察篇》", "skill" : "scout" , "lev" : 60,"vol" : 2]),
"zc3" : (["name" : "《鬼谷子·侦察篇》", "skill" : "scout" , "lev" : 90,"vol" : 3]),
"sg1" : (["name" : "《鬼谷子·速攻篇》", "skill" : "sugong" , "lev" : 30,"vol" : 1]),
"sg2" : (["name" : "《鬼谷子·速攻篇》", "skill" : "sugong" , "lev" : 60,"vol" : 2]),
"sg3" : (["name" : "《鬼谷子·速攻篇》", "skill" : "sugong" , "lev" : 90,"vol" : 3]),
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
        set_name("lao taijian", "老太监");
        set_gender(0);
        set_in_room_desc("老太监(lao taijian)");
        set_age(60);
    add_id("taijian");
        add_question("book","book");
        add_ask_str("book","$N对$T道：蒙圣上恩准，特来御书房借兵书一读。有劳公公了。\n");
        add_question("list1","list1");
        add_ask_str("list1","$N对$T道：请问公公都有些什么兵书呀。\n");
        add_question("list2","list2");
        add_ask_str("list2","$N对$T道：请问公公都有些什么兵书呀。\n");
        add_question("list3","list3");
        add_ask_str("list3","$N对$T道：请问公公都有些什么兵书呀。\n");
        add_block("south");

}
string long() {
        return "一个慈眉善目的老太监，手执拂尘，对着你微微一笑。\n";
}
void input_book(object who, string str) {
	object u,bk,shoyu;
	string *list;
	string p_id;
	if(!objectp(who)) return;
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_pop();
	if(!str) str="";
	list=keys(m_list);
	if(member_array(str,list)==-1) {
		this_object()->targetted_action(
"$N对$T道：$R所需兵书，我怎么从没听说过呀。\n",who);
		return;
	}
	 shoyu=present("ysf pass",who);
        if(objectp(shoyu)) {
                shoyu->remove();
        }
        shoyu=present("shouyu",who);
        if(objectp(shoyu)) {
                shoyu->remove();
		}
	bk=new(BOOK_FILE);
	bk->add_id(m_list[str]["name"]+"第"+chinese_number(m_list[str]["vol"])+"卷");
	bk->set_skill(m_list[str]["skill"]);
	bk->set_lev(m_list[str]["lev"]);
	who->targetted_action("$N对$T说了些什么。\n",this_object());
	this_object()->targetted_action("$N交给$T$O。\n",who,bk);
	bk->move(who);
}
void ask_book(object who) {
	object u;
	object shoyu;
	string p_id;
	shoyu=present("ysf pass",who);
	if(!objectp(shoyu)) {
		this_object()->targetted_action(
"$N对$T道：没有圣上的手谕，老奴才岂敢擅自借书。\n",who);
		return ;
	}
	shoyu->remove();
	this_object()->targetted_action(
"$N对$T道：好说，好说，不知$R要读哪部兵书。\n",who);
	u=who->query_link();
	if(!objectp(u)) return;
	u->modal_push((: input_book, who :),"请输入书代号。\n");
}

void ask_list1(object who, int v) {
	string msg;
	string *list;

	this_object()->targetted_action(
"$N对$T道：这里书是不少，兵书却不多，现在有以下几本。\n",who);
        msg="id               书名\n";
	list=keys(m_list);
	foreach(string l in list) {
		if(m_list[l]["vol"]!=v) continue;
		msg+=sprintf("%-7s  %-24s %s\n",l,m_list[l]["name"],"第"+
			chinese_number(m_list[l]["vol"])+"卷");
	}
	tell_user(who->query_primary_id(),msg);
	return ;
}


void special_answer(object who, string matt)
{
	switch(matt) {
		case "book":
			ask_book(who);
			return ;
		case "list1":
			ask_list1(who,1);
			return ;

		case "list2":
			ask_list1(who,2);
			return ;
                case "list3":
                        ask_list1(who,3);
                        return ;

	}
}
