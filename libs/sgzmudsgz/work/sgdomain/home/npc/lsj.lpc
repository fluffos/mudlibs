// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */
#define HOUSE_D "/daemons/house_d"
#define HOMEKEY "/sgdomain/home/homekey"
inherit M_CHAR;
inherit LIVING;
void setup()
{
    set_name("lao suojiang", "老锁匠");
    set_gender(1);
    set_proper_name("老锁匠");
    set_in_room_desc("%^YELLOW%^老锁匠%^RESET%^(lao suojiang)");
    add_id("lao");
    add_id("suojiang");
    set_age(50);

    add_ask_str("cut","$N对$T道：$R能不能帮我锉把家里的钥匙？\n");
    add_question("cut","cut" );

}
string long() {
	return
"%^YELLOW%^老锁匠%^RESET%^，没有他打不开的东西。\n";
}

mixed can_i_have_key(string p_id) {
	mixed hus;
	object me=find_body(p_id);
	hus=CHAR_D->get_char(p_id,"h");
	if(!mapp(hus)) return "$N对$T道：$R还没有房子，我怎么给你配钥匙。\n";

	if(MONEY_D->sub_poket_money(me,10000)==-1) 
		return "$N对$T道：配钥匙要一两金子。你身上的钱不够。\n";
	return 1;

}
private void give_key(string p_id) {
	object me,okey;
	me=find_body(p_id);
	okey=new(HOMEKEY);
	okey->set_owner(p_id);
	this_object()->targetted_action("$N对$T道：配钥匙要一两金子。\n",me);
	DELAY_D->delay_simple_action(me,"$N道：没问题。\n",1);
	DELAY_D->delay_targetted_action(me,this_object(),"$N给$T一两黄金。\n",2);
	DELAY_D->delay_targetted_action(me,this_object(),"$T接过钱，开始锉钥匙。\n",3);

	DELAY_D->delay_targetted_action(me,this_object(),"$T抬起头：钥匙锉好了。\n",6);
	DELAY_D->delay_targetted_action(me,this_object(),"$N接过$T抵过来的钥匙，满意地点了点头。\n",7);

	okey->move(me);	
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
	}
	else {
		okey=new(HOMEKEY);
		okey->set_owner(p_id);
		this_object()->targetted_action
			("$N对$T笑嘻嘻地说：$R的房子已经搞好了，这是钥匙，快去看看吧。\n"+
			 "说完抵给$t$O\n",this_body(),okey);
		okey->move(this_body());
	}

	hus["id"]=my_house["id"];
	hus["st"]="new";
	hus["t"]=time();
	hus["a"]=my_house["a"];
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
                case "cut" :
			ret=can_i_have_key(p_id);
			if(stringp(ret)) {
			        this_object()->targetted_action( ret,who);
				return;
			}
			give_key(p_id);
                        return;
        }
}
