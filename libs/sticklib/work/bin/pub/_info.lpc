/* info_cmd 18.8.1992 //Frobozz */
/* Moved to /bin/pub 30-sep-94. */

#include <cmd.h>
#include <player_defs.h>

varargs nomask status
info_cmd(string what, object me)
{
    int x;
    if (!me && !(me = this_player())) return 0;

    if (what && what != "on" && what != "off" && what != "toggle") return
	notify_fail("Info what? (\"info [on/off/toggle]\")\n"), 0;
    switch(what) {
    case "on":
	me -> set(PLR_INFO_ON);
	me -> tell_me("Ok, your info is now on.");
	break;
    case "off":
	me -> set(PLR_INFO_OFF);
	me -> tell_me("Ok, your info is now off.");
	break;
    default:
	me -> set((x = (int) me->query(PLR_INFO_ON)) ?
	  PLR_INFO_OFF : PLR_INFO_ON);
	me -> tell_me("Ok, your info is now " + (x ? "off" : "on") + ".");
    }
    return 1;
}
