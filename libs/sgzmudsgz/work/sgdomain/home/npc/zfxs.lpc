// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */


inherit __DIR__+"free";

string get_type() {
	return "zfxs";
}
string get_type_name() {
	return "%^H_RED%^帐房先生%^RESET%^";
}
void extra_init() {
	add_ask_str("order","$N对$T点了点头，$S要查查帐目。\n");
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

				if(rom->get_type()!="zhangfang") {
				        this_object()->targetted_action(
						"$N一模胡子道：查帐要去帐房才行。\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());

					return;

				}
				if(rom->get_status()<50) {
				        this_object()->targetted_action(
						"$N一模胡子道：帐房早已破烂不堪，帐根本没法记。\n",who);
					new(__DIR__+"free_menu")->start_menu(who,this_object());

					return;
				}
			        this_object()->targetted_action(
				"$N抱出一摞帐本：$R请过目。\n",who);
				new(__DIR__+"zfxs_menu")->start_menu(who,this_object());
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}
