// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_CHAR;
inherit LIVING;
protected string master,master_name;
protected int is_busy;
protected string p_id;

void set_busy(int i) {
	is_busy=i;
}
int get_busy() {
	return is_busy;
}
string get_type() {
	return "free";
}
string get_type_name() {
	return "%^H_RED%^闲人%^RESET%^";
}
void extra_init() {
}

void setup(string m_id,string u_id)
{
	object o_h;
	mixed c;
	string per_id;
	o_h=SGHOME(m_id);

	if(!objectp(o_h)) {
		destruct(this_object());
		return;
	}
	
	master=m_id;
	master_name=CHAR_D->get_char(m_id,"name");
	p_id=u_id;

	c=o_h->get_npc(u_id);
	if(!mapp(c)) {
		destruct(this_object());
		return;
	}

	per_id=c["pre_id"];

	set_name(u_id,c["sname"]+c["gname"]);
	add_id(per_id);
	set_gender(c["gender"]);
    	set_proper_name(c["sname"]+c["gname"]);

    	set_in_room_desc(master_name+"家的"+get_type_name()+"，"+
		c["sname"]+c["gname"]+"("+per_id+")");
//	add_id(get_type());
	add_id("pu ren");
	set_age(c["age"]);
	set_sg_rongmao(c["rongmao"]);

	add_ask_str("order","$N对$T招了招手，过来，过来，有你的事干了。\n");
	add_question("order","order" );

	is_busy=0;
	extra_init();
}
void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "order" :
			if(p_id==master||p_id==CHAR_D->get_char(master,"mar")) {
			        this_object()->targetted_action(
				"$N忙上前鞠躬道：$R有何吩咐？\n",who);
				is_busy=1;
				new(__DIR__+"free_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}
string get_id() {
	return p_id;
}
string get_master() {
	return master;
}