// call.c  //招随从 Jan 1999
#include <mudlib.h>
inherit CMD;
inherit "/sgdomain/home/npc/free";

string get_type() {
	return "sc";
}
string get_type_name() {
	return "%^H_GREEN%^随从%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N对$T招了招手。\n");
	add_question("order","order" );
}
void special_answer(object who, string matt, object o_gj)
{
	string p_id;
	object rom;
	p_id=who->query_primary_id();
	rom=environment(o_gj);
        switch(matt)
        {
                case "order" :
				is_busy=1;

			        o_gj->targetted_action(
				"$N上前一步鞠躬道：$s在此，$R请吩咐。\n",who);
				new("wiz/listen/sc/sc_menu")->start_menu(who,o_gj);
				return;
			}
		return;
       
}

int no_need_hp()
{ // this is used if player doesnt have food and drink
	return 1;
}

void call_guanjia(string p_id) {
	object o_h;
	string *gjs,gj;
	object o_gj;
	o_h=SGHOME(p_id);
	gjs=o_h->check_npc("pos","gj");
	if(!sizeof(gjs)) {
		write("你现在还没有雇佣管家。\n");
		return;
	}
	gj=gjs[0];
	o_gj=o_h->load_npc(gj);
	if(environment(o_gj)!=(this_body()->query_room())) {
		o_gj->move(environment(this_body()));
		o_gj->simple_action("$N风风火火地跑了过来。\n");
	}
	o_gj->special_answer(this_body(),"order");
	return;

}
void call_suicong(string p_id) {
	object o_h;
	string *gjs,gj;
	object o_gj;
	o_h=SGHOME(p_id);
	if(!objectp(o_h)) {
		write("你现在还没有家，哪里来的随从。\n");
		return;
	}
	gjs=o_h->check_npc("pos","sc");
	if(!sizeof(gjs)) {
		write("你现在还没有雇佣随从。\n");
		return;
	}
	gj=gjs[0];
	o_gj=o_h->load_npc(gj);
	if(environment(o_gj)!=(this_body()->query_room())) {
		o_gj->move(environment(this_body()));
		o_gj->simple_action("$N风风火火地跑了过来。\n");
	}
	special_answer(this_body(),"order",o_gj);
	return;

}

void main(string arg)
{
    	object env,o;
    	mixed myarmy;
	string p_id,n_id,p_room;
    	p_id=this_body()->query_id()[0];
    	env=this_body()->query_room();
        this_body()->simple_action("$N回头喊了一声：来人哪！");

	if((env->is_home())&&(env->get_owner()==p_id)) {
		call_guanjia(p_id);
		return;
	}
	call_suicong(p_id);
	return ;
}