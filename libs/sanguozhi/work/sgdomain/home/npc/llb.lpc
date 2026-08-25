// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
#define HOUSE_D "/daemons/house_d"
#define HOMEKEY "/sgdomain/home/homekey"
inherit M_CHAR;
inherit LIVING;
private
void setup()
{
    set_name("lu laoban", "鲁老板");
    set_gender(1);
    set_proper_name("鲁老板");
    set_in_room_desc("盖房巧匠%^H_GREEN%^鲁老板%^RESET%^(lu laoban)");
    add_id("lu");
    add_id("laoban");
    set_age(50);

    add_ask_str("buy","$N对$T道：$S想造一间房子. . . .\n");
    add_question("buy","buy" );

    add_ask_str("move","$N对$T道：$S想搬家了。\n");
    add_question("move","move" );

    add_ask_str("update","$N对$T道：$S想把房子改造改造. . . .\n");
    add_question("update","update" );

    add_ask_str("get","$N对$T道：$S的房子造好了吗？\n");
    add_question("get","get" );
}
string long() {
	return
"%^H_GREEN%^鲁老板%^RESET%^，相传是春秋名匠鲁班的后人，善常建房。\n";
}

mixed can_i_buy(string p_id,string h_id) {
	int p_price,p_level,my_level;

	if(!CHAR_D->get_char(p_id,"area")) 
		return "$N对$T道：$R还没有择地定居，我在哪里给你建房呀。\n";
	if(mapp(CHAR_D->get_char(p_id,"h")))
		return "$N对$T道：$R已经有一套房子了，先把它卖了在来盖新房吧。\n";
	p_price=HOUSE_D->get_house(h_id,"price");
	if(!p_price) 
		return "$N对$T道：$R要盖的房子我怎么没听说过。\n";
	p_level=HOUSE_D->get_house(h_id,"level");
	my_level=CHAR_D->get_char(p_id,"ju");
	my_level++;
	my_level/=2;
	if(my_level<p_level)
		return "$N对$T道：$R的爵位太低，不能盖这样高级的房子。\n";
	if(MONEY_D->sub_all_money(find_body(p_id),p_price*10000)==-1) 
		return "$N对$T道：$R的钱好像不够，还是先去想办法挣点钱吧。\n";

	return 1;

}
mixed can_i_update(string p_id,string h_id) {
	int p_price,p_level,my_level;
	int p_curprice;
	string cur_house;
	mixed hus;
	object me=find_body(p_id);
	hus=CHAR_D->get_char(p_id,"h");
	if(!mapp(hus)) return "$N对$T道：$R还没有房子，我拿什么给你改造。\n";
	if(hus["st"]=="building") return "$N对$T道：$R的房子正在造呢。\n";
	if(hus["st"]=="updating") return "$N对$T道：$R的房子正在改造呢。\n";
	if(hus["st"]=="moving") return "$N对$T道：$R的房子正在搬呢。\n";

	p_price=HOUSE_D->get_house(h_id,"price");
	if(!p_price) 
		return "$N对$T道：$R要盖的房子我怎么没听说过。\n";

	cur_house=hus["id"];
	p_curprice=HOUSE_D->get_house(cur_house,"price")/2;
	p_price-=p_curprice;
	p_price=bmax(10,p_price); // at least 10 gold

	p_level=HOUSE_D->get_house(h_id,"level");
	my_level=CHAR_D->get_char(p_id,"ju");
	my_level++;
	my_level/=2;

	if(my_level<p_level)
		return "$N对$T道：$R的爵位太低，不能改造成这样高级的房子。\n";
	if(MONEY_D->sub_all_money(me,p_price*10000)==-1) 
		return "$N对$T道：$R的钱好像不够，还是先去想办法挣点钱吧。\n";

	return 1;

}

mixed can_i_move(string p_id,string w_id) {
	int p_curprice,p_dis;
	string cur_house,w_cur;
	mixed hus;
	object me=find_body(p_id);
	hus=CHAR_D->get_char(p_id,"h");

	if(!mapp(hus)) return "$N对$T道：$R还没有房子，我给你搬什么家呀。\n";
	if(hus["st"]=="building") return "$N对$T道：$R的房子正在造呢。\n";
	if(hus["st"]=="updating") return "$N对$T道：$R的房子正在改造呢。\n";
	if(hus["st"]=="moving") return "$N对$T道：$R的房子正在搬呢。\n";

	w_cur=hus["a"];
	if(w_id==w_cur) return "$N对$T道：$R的房子目前正在"+AREA_D->get_area(w_cur,"name")+"\n";
	if(!AREA_D->area_exist(w_id)) return "$N对$T道：没听说过"+w_id+"这个地区，在哪里呀。\n";

	p_dis=AREA_D->get_distance(w_cur,w_id);

	cur_house=hus["id"];
	p_curprice=HOUSE_D->get_house(cur_house,"price")*500;
	p_curprice*=p_dis;

	if(MONEY_D->sub_all_money(me,p_curprice)==-1) 
		return "$N对$T道：$R的钱好像不够，还是先去想办法挣点钱吧。\n";
	return 1;
}

void answer_type(object me, object who,string ans) {
	mixed ret;
	string p_id;

	mapping hus=([]);
	object hs;
		
	p_id=who->query_primary_id();
	me->clear_answer();

	ret=can_i_buy(p_id,ans);
	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}

	hus["id"]=ans;
	hus["st"]="building";
	hus["t"]=time();
	hus["a"]=CHAR_D->get_char(p_id,"area");

	hus["builder"]=this_object()->query_primary_id();

	hus["t_need"]=(HOUSE_D->get_house(ans,"level")*2+2)*16*60;

	CHAR_D->set_char(p_id,"h",hus);

	hs=SGHOME(p_id);
	if(objectp(hs)) hs->init_rooms();
	me->targetted_action("$N对$T到：$R先不要着急，活已经接下了，过"+
		chinese_number(HOUSE_D->get_house(ans,"level")*2+2)+"天再来听消息吧。\n",who);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"伙计们，有生意啦，接到"+
		"为"+CHAR_D->get_char(p_id,"name")+
		"在"+AREA_D->get_area(hus["a"],"name")+"盖"+
		HOUSE_D->get_house(ans,"name")+"的活了。"); 
}


void answer_move_where(object me, object who,string ans) {
	mixed ret;
	string p_id;
	int p_dis;
	mapping hus=([]);
	p_id=who->query_primary_id();
	me->clear_answer();

	ret=can_i_move(p_id,ans);

	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}


	hus=CHAR_D->get_char(p_id,"h");
	hus["st"]="moving";
	hus["t"]=time();
	p_dis=AREA_D->get_distance(hus["a"],ans);
	hus["a"]=ans;
	hus["builder"]=this_object()->query_primary_id();

	hus["t_need"]=(HOUSE_D->get_house(hus["id"],"level")*p_dis/2+1)*16*60;

	CHAR_D->set_char(p_id,"h",hus);

	me->targetted_action("$N对$T到：$R先不要着急，活已经接下了，过"+
		chinese_number(HOUSE_D->get_house(hus["id"],"level")*p_dis/2+1)+"天再来听消息吧。\n",who);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"伙计们，有生意啦，接到"+
		"为"+CHAR_D->get_char(p_id,"name")+
		"搬家的活了。"); 
}

void answer_update_type(object me, object who,string ans) {
	mixed ret;
	string p_id;

	mapping hus=([]);
	p_id=who->query_primary_id();
	me->clear_answer();

	ret=can_i_update(p_id,ans);
	if(stringp(ret)) {
		me->targetted_action(ret,who);
		return;
	}


	hus=CHAR_D->get_char(p_id,"h");
	hus["id"]=ans;
	hus["st"]="updating";
	hus["t"]=time();
	hus["builder"]=this_object()->query_primary_id();
	
	hus["t_need"]=(HOUSE_D->get_house(ans,"level")*2+2)*16*60;

	CHAR_D->set_char(p_id,"h",hus);

	me->targetted_action("$N对$T到：$R先不要着急，活已经接下了，过"+
		chinese_number(HOUSE_D->get_house(ans,"level")*2+2)+"天再来听消息吧。\n",who);
	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"伙计们，有生意啦，接到"+
		"为"+CHAR_D->get_char(p_id,"name")+
		"在"+AREA_D->get_area(hus["a"],"name")+"把房子改装成"+
		HOUSE_D->get_house(ans,"name")+"的活了。"); 
}


mixed my_house_ready(string p_id) {
	mapping my_house;
	string h_id;
	int t_need;
	my_house=CHAR_D->get_char(p_id,"h");
	if((!mapp(my_house))||((my_house["st"]!="building")&&(my_house["st"]!="updating")
		&&(my_house["st"]!="moving"))||
		(my_house["builder"]!=this_object()->query_primary_id()))
		return "$N对$T道：$R搞错了吧，我们没有收到给您做的活呀。\n";
	h_id=my_house["id"];
	t_need=(my_house["t_need"]);
	t_need=t_need-(time()-my_house["t"]);
	if(t_need>0) 
		return "$N对$T道：$R太性急了，还要再等"+chinese_number(t_need/16/60+1)+
			"天，你的活才能搞定。\n";
	return 1;
	
}
private void get_my_house(string p_id) {
	mapping my_house,hus;
	object okey;
	my_house=CHAR_D->get_char(p_id,"h");
	hus=CHAR_D->get_char(p_id,"h");
	if(hus["st"]=="updating") {
		object o;
		o=SGHOME(p_id);
		o->set_room("front","l",
			read_file("/sgdomain/home/pic/"+hus["id"]+".pic"));
		o->set_id(hus["id"]);
	}
	else if(hus["st"]=="building"){
		okey=new(HOMEKEY);
		okey->set_owner(p_id);
		this_object()->targetted_action
			("$N对$T笑嘻嘻地说：$R的房子已经搞好了，这是钥匙，快去看看吧。\n"+
			 "说完抵给$t$O\n",this_body(),okey);
		okey->move(this_body());
	}
	else {
	}

	hus["id"]=my_house["id"];
	hus["st"]="new";
	hus["t"]=time();
	hus["a"]=my_house["a"];
	map_delete(hus,"t_need");
	CHAR_D->set_char(p_id,"h",hus);


	CHANNEL_D->deliver_tell("gossip",this_object()->short(),
		"恭喜恭喜，"+CHAR_D->get_char(p_id,"name")+
		"在"+AREA_D->get_area(hus["a"],"name")+"的"+
		HOUSE_D->get_house(hus["id"],"name")+"已经造好了，大家去敲他一顿吧。"); 
}
void special_answer(object who, string matt)
{
	string p_id;
	mixed ret;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "buy" :
		        this_object()->targetted_action(
				"$N对$T笑到：要盖房子呀，恭喜，恭喜，不知$R选得是什么样式？\n",who);
			this_object()->set_answer(p_id, (:answer_type:) );
			tell_user(p_id,"用%^RED%^answer <房子ID> to lu%^RESET%^来回答。\n");
                        return;
                case "update" :
		        this_object()->targetted_action(
				"$N对$T笑到：要改造房子呀，恭喜，恭喜，不知$R选得是什么样式？\n",who);
			this_object()->set_answer(p_id, (:answer_update_type:) );
			tell_user(p_id,"用%^RED%^answer <房子ID> to lu%^RESET%^来回答。\n");
                        return;

                case "move" :
		        this_object()->targetted_action(
				"$N对$T笑到：$R要搬家呀，恭喜，恭喜，不知$R要搬到何处？\n",who);
			this_object()->set_answer(p_id, (:answer_move_where:) );
			tell_user(p_id,"用%^RED%^answer <地区ID> to lu%^RESET%^来回答。\n");
                        return;
                case "get" :
			ret=my_house_ready( p_id);
			if(stringp(ret)) {
			        this_object()->targetted_action(ret,who);
				return;
			}
			get_my_house(p_id);
			return ;
        }
}
