#include <cmd.h>
#include <player_defs.h>

varargs nomask status
brief_cmd(string arg, object me)
{
    status on_off;
    string s;
    if (!me && !(me = this_player())) return 0;
    if (arg)
	if (sscanf(arg, "%s off", s)) {
	    on_off = 1;
	    arg = s;
	} else if (sscanf(arg, "%s on", s)) {
	    on_off = 2;
	    arg = s;
	}
    if (arg == "weather") {
	if (on_off) {
	    if (--on_off) me->set(LIV_BRIEF_WEATHER);
	    else me->set(LIV_NOT_BRIEF_WEATHER);
	}
	else me -> set((on_off = (int) me->query(LIV_NOT_BRIEF_WEATHER)) ?
	      LIV_BRIEF_WEATHER : LIV_NOT_BRIEF_WEATHER);
	if (on_off) me -> tell_me(
	      "No weather messages (you can look at sky to see the weather).");
	else me -> tell_me("Verbose weather messages.");
	return 1;
    }
    if (arg == "off") on_off = 1;
    else if (arg == "on") on_off = 2;
    else if (arg) return
	notify_fail("Brief what? (\"brief [weather] [on/off]\")\n"), 0;
    if (on_off) {
	if (--on_off) me->set(LIV_BRIEF);
	else me->set(LIV_NOT_BRIEF);
    }
    else me -> set((on_off = (int) me->query(LIV_NOT_BRIEF)) ?
	  LIV_BRIEF : LIV_NOT_BRIEF);
    if (on_off) me -> tell_me("Brief mode.");
    else me -> tell_me("Verbose mode.");
    return 1;
}
