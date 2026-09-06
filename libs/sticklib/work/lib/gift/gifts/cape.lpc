#include <treasure.h>

void
create_treasure()
{       set_id("cape");
    set_name("Penquis Knight Cape");
    set_short("Penquis Knight Cape (worn)");
    set_long("This long flowing crimson cape surrounds the wearer, the \
hood made to conceal the wearer. In the front a golden clasp holds it \
tight, on the right shoulder of the cape it says 'Penquis Knight'. ");
    set_weight(1);
    set_value(0);
}

string query_auto_load() {
    int    dummy;
    string chainname;
    sscanf(object_name(this_object()),"%s#%d",chainname,dummy);
    return chainname+":";

}


void
init_treasure()
{
    add_action("show", "show");
}

show(string arg)
{
    if (arg && present(lower_case(arg), environment()) == this_object())
    {
	this_player()->tell_me("Others see:");
	environment(this_player())->tell_here(
	  (string)this_player()->query_name() +
	  " Shows you a extreamly beutiful cape, and on the right shoulder you can read 'Penquis Knight'");
	return 1;
    }
    notify_fail("Hmm something went wrong...blablabla.");
    return 0;
}

int get() { return 1; }
int drop() { return 1; }

