// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "dcs";
}
string get_type_name() {
	return "%^YELLOW%^大厨师%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N对$T看了一眼，看来是肚子饿了。\n");
	add_question("order","order" );
}
void special_answer(object who, string matt)
{
	string p_id;
	object rom;
	p_id=who->query_primary_id();
	rom=environment(this_object());
        switch(matt)
        {
                case "order" :
			if(p_id==master||p_id==CHAR_D->get_char(master,"mar")) {
				is_busy=1;
				if(rom->get_type()!="kitchen") {
				        this_object()->targetted_action(
						"$N对$T点头到，$R要用膳，我得先去厨房准备。\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());
					return;

				}
				if(rom->get_status()<50) {
				        this_object()->targetted_action(
						"$N叹口气道：厨房早已破烂不堪，火都生不起来。\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());
					return;
				}
			        this_object()->targetted_action(
				"$N点头道，$R饿了吧，要用点什么。\n",who);
				new(__DIR__+"dcs_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}
