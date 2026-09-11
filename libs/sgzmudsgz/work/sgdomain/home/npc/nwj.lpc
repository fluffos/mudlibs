// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "nwj";
}
string get_type_name() {
	return "%^YELLOW%^泥瓦匠%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N对$T招了招手，伙计，伙计，过来，过来。\n");
	add_question("order","order" );
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
				"$N提着水泥桶跑了过来：$R有何吩咐？\n",who);
				is_busy=1;
				new(__DIR__+"nwj_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}
