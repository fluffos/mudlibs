#include <std.h>
#include <amun.h>
void eject(object tp) {
    object ob, *all;
    int i;
    message("info", "%^BOLD%^%^RED%^You are not allowed to enter the guild of the Last Saints.%^RESET%^", tp, );
    tp->move("/d/nopk/tirun/square");
    tp->set_paralyzed(4, "");
    message("info", "\nA shadow says: "+capitalize(tp->query_name())+" was caught trespassing.", environment(tp), tp);
    all = users();
    i = sizeof(all);
    while(i--) {
	ob = all[i];
	if(ob->query_original_guild() == "lastsaints" && !wizardp(ob))
	    message("info", "%^BOLD%^%^RED%^\n"+capitalize(tp->query_name())+" just got caught entering our guild hall!", ob, );
    }
}
