#include <treasure.h>
#include "../priest.h"

string
show_list() {
    int i;
    string str, tmp;

    if(!IS_PRIEST(this_player()))
	return "You don't understand the writing.";
    if(this_player()->query_level() < 10)
	return "You are still too young to understand the writing.";

    str = "Officers of the Priest Guild:";
    for(i=VG_RANK;i>=1;i--) {
	tmp = OFFICER_D->get_officer(i);
	if(tmp)
	    str += sprintf("\n%-20s %s", OFFICER_D->get_long_office(i),
	      capitalize(tmp));
    }
    return str;
}

void
create_treasure() {
    set_name("list of officers");
    set_id("list");
    set_long(#'show_list);
}

status get() { return 0; }
status drop() { return 1; }
