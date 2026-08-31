#include <std.h>
#include <amun.h>
void eject(object tp) {
    object ob, *all;
    int i;
    message("info", "%^BOLD%^%^RED%^You are not allowed to enter the guild of the Last Saints.%^RESET%^", tp, );
    tp->move("/d/nopk/tirun/square");
    tp->set_paralyzed(20, "");
    message("info", "\nA shadow says: "+capitalize(tp->query_name())+" was caught trespassing.", environment(tp), tp);
    all = users();
    i = sizeof(all);
    while(i--) {
	ob = all[i];
	if(ob->query_guild() == "last saints" && !wizardp(ob))
	    message("info", "%^BOLD%^%^RED%^\n"+capitalize(tp->query_name())+" just got caught entering our guild hall!", ob, );
    }
}
