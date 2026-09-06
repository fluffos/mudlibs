#include "../../priest.h"

status
add_officer_cmd(object who, object sym, string s) {
    string name;
    int t;

    if(!who->query_coder_level()) return 0;

    if(sscanf(s, "%s %d", name, t) != 2)
	return notify_fail("Usage: add_officer <name> <office n>\n"),0;

    OFFICER_D->add_officer(name, t);
    who->tell_me("Officer list modified.");
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
