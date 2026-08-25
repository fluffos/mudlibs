/* 
 * Externalize by Baldrick june '97.
 */

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
inherit WIZ_CMD_BASE;

void setup(){

position = 1;
}

protected int cmd(string str, object me) {
    string func, thing, s, ping;
    object *obs, fish;
    int i;

    notify_fail("Usage: find function() <object(s)>\n");
    if(!str) return 0;
    if(sscanf(str, "%s() %s", func, thing) != 2)
	if(sscanf(str, "%s %s", func, thing) != 2)
	    return 0;

    obs = wiz_present(thing, me);

    if (!sizeof(obs)) {
	notify_fail("Can't find " + thing + ".\n");
	return 0;
    }
    s = "";
    for (i=0; i < sizeof(obs); i++) {
	if(ping = function_exists(func, obs[i]))
	    s += "*** " + desc_object(obs[i])+": "+func+"() found in " + ping + "\n";
	else
	    s += "*** " + desc_object(obs[i]) + ": " + func + "() not found.\n";
	fish = obs[i];
	while(fish = shadow(fish, 0))
	    if(function_exists(func, fish))
		s += "      Shadowed by " + file_name(fish) + "\n";
    }
    write(s);
    me->set_trivial_action();
    return 1;
} /* do_find() */

