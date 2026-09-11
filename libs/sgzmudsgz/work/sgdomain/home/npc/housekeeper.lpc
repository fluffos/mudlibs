// written by fire 
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit M_CHAR;
inherit LIVING;
private string master,master_name;
private is_busy;
void setup(string p_id)
{
	master=p_id;
	master_name=CHAR_D->get_char(p_id,"name");
	set_name(p_id+" dgj","大管家");
	set_gender(1);
    	set_proper_name("大管家");
    	set_in_room_desc(master_name+"家的%^H_GREEN%^大管家%^RESET%^("+p_id+ " dgj)");
	add_id("dgj");
	set_age(45);

	add_ask_str("order","$N回过头看了$T一眼。\n");
	add_question("order","order" );
	is_busy=0;
}

string long() {
	return master_name+"家的%^H_GREEN%^大管家%^RESET%^("+master+ " dgj)";
}

void special_answer(object who, string matt)
{
	string p_id;
	p_id=who->query_primary_id();
        switch(matt)
        {
                case "order" :
			if(p_id==master) {
			        this_object()->targetted_action(
				"$N忙上前鞠躬道：$R有何吩咐？\n",who);
				return;
			}
		        this_object()->targetted_action(
				"$N瞪了$T一眼。\n",who);
				return;
        }
}
