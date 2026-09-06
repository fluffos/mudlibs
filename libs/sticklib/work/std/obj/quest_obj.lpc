/*
 * This is a standard quest object.
 * Configure it to make it look the way you want.
 */

inherit "/basic/id";

string hint_string;

void
set_hint(string h)
{
    hint_string = h;
}

void
create()
{
    set_short("A quest");
    set_long("It's an unnamed quest.");
    set_name("quest");
    set_id(({ "quest" }));	// Just to be sure we'll have this as id.
    this_object()->create_quest();
}

varargs string
query_long(string s, object who)
{
    return "This is the quest '" + query_name() + "':\n"+hint_string;
}

string hint() { return hint_string; }

void set_quest(string s) { set_name(s); }

string query_quest() { return query_name(); }
string query_hint() { return hint_string; }
