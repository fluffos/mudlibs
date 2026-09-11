// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit __DIR__+"leader";

protected string r_id;
protected string room_name;

void setup(string a_id,string fd,string rid)
{
	object o_h;
	mapping m_head;
	p_area=a_id;
	f_id=fd;
	r_id=rid;
	o_h=SGBASE(p_area,f_id);
	m_head=o_h->get_room(r_id,"head");
	if(!mapp(m_head)) {
		destruct(this_object());
		return;
	}
	base_name=BASE_D->get_base(f_id,"name");
	set_name(fd+" head",m_head["sname"]+m_head["gname"]);
	add_id("head");
       set_gender(m_head["gender"]);
    set_proper_name(m_head["sname"]+m_head["gname"]);

   	set_in_room_desc(AREA_D->get_area(p_area,"name")+
		base_name+BASE_D->get_base(f_id,"headname")+
		m_head["sname"]+m_head["gname"]+"("+f_id+" head)");
	set_age(m_head["age"]);
	set_sg_rongmao(m_head["rongmao"]);

	add_ask_str("order","$N对$T看了一眼\n");
	add_question("order","order" );
	m_busy=0;	
}
void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
    switch(matt)
    {
	case "order":
		if(((CHAR_D->get_char(p_id,"area")==p_area)&&
			(CHAR_D->get_char(p_id,"ranklocal")>0))||wizardp(p_id))
		{
			if(m_busy) {
				this_object()->targetted_action(
					"$N连忙躬身道：$R请稍等。\n",who);
				return;
			}
			this_object()->targetted_action(
				"$N连忙躬身道：$m$R真是折杀小人了，$R有和吩咐。\n",who);
			new (__DIR__+"farm_head_menu")->start_head_menu(who,this_object(),p_area,f_id,r_id);
			set_busy(1);
		}
		else {
			this_object()->responda("hehe "+p_id);
		}
		break;
	default:
	}
}

string get_r_id() {
	return r_id;
}