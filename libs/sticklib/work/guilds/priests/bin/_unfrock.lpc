#include "../priest.h"

status
unfrock_cmd(object who, object sym, string str) {
    if(sym->query_rank()<7)
	return notify_fail("You don't have that power.\n"),0;

    if(!str)
	return notify_fail("You need to supply a name.\n"),0;

    str = lower_case(str);
    notify_fail("That player is already unfrocked!\n");
    return EXCOM_D->ban_me(str,0);
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
