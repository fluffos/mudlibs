#include "../../priest.h"

status
pretitle_cmd(object who, object sym, string str) {
    object prt; 

    if(str == "on") {
	if(sym->query_pretitle_object()) {
	    return notify_fail("You feel the weight of " GOD_NAME "'s \
displeasure and remember that your God hates redundance.\n"),0;
	    who->tell_me("PING!");
	    return 1;
	}
	who->tell_me("Your pretitle is set.");
	prt = clone_object(PRIEST_OBJ_DIR "pretitle_obj");
	sym->set_pretitle_object(prt);
	prt->do_shadow(who,sym->query_rank());
	return 1;
    }
    if(str == "off") {
	if(!sym->query_pretitle_object()) {
	    return notify_fail("You feel the weight of " GOD_NAME "'s \
displeasure and remember that your God hates redundance.\n"),0;
	}
	who->tell_me("Your pretitle is now off.");
	destruct(sym->query_pretitle_object());
	return 1;
    }
    return notify_fail("Syntax: pretitle [on/off]\n"),0;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
