// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

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
void special_answer(object who, string matt)
{
	string p_id;
	object rom;
	p_id=who->query_primary_id();
	rom=environment(this_object());
        switch(matt)
        {
                case "order" :
			if(p_id==master) {
				is_busy=1;

			        this_object()->targetted_action(
				"$N上前一步鞠躬道：$s在此，$R请吩咐。\n",who);
				new(__DIR__+"sc_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}
