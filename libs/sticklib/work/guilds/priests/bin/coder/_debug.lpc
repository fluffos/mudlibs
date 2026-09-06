#include "../../priest.h"

debug_cmd(object who, object sym, string s) {
    object target, tsym;

    if(!who->query_coder_level()) return 0;

    if(target = sym->query_debuggee()) {
	who->tell_me(sprintf("Ok, you stop debugging %s.",
	    capitalize(target->query_real_name())));
	target->query_guild_object()->set_debugger(0);
	sym->set_debuggee(0);
	return 1;
    }
    if(!s) {
	sym->set_debugger(who);
	sym->set_debuggee(who);
	who->tell_me("Ok, debugging yourself.");
	return 1;
    }
    target = find_player(s);
    if(!target) return notify_fail("No such player.\n"),0;
    tsym = target->query_guild_object();
    if(tsym->query_debugger()) return
	notify_fail(sprintf("That players is already being debugged by %s.\n",
	    capitalize(tsym->query_debugger()->query_real_name()))),0;
    tsym->set_debugger(who);
    sym->set_debuggee(target);
    who->tell_me("Ok.");
    return 1;
}
