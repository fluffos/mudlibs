#include <cmd.h>

nomask int
starthere_cmd(string str)
{
    object me;
    object env;
    me = this_player();
    env = environment(me);

    if (!CHECK) return 0;

    //    if (!(me = this_player())) return 0;
    if (!me) return 0;

    if (!str) {
	//	object env;
	string file;

	//	env = environment(me);
	if (!env->query_is_start_location()) {
	    if (!me->query_coder_level()) {
		me->tell_me(
		  "This place isn't suitable for starting the game.\n\
Check 'help starthere'.");
		return 1;
	    }
	    me->tell_me("This location is unsuitable for mortals but you \
don't care.");
	}

	file = object_name(env);
	me->tell_me( ((string)this_player()->set_start_location(file) == file)
	  ? "Ok. From now on you arrive here at login."
	  : "Error... please inform admins." );
    } else if (str == "clear") {
	if ( env->forbid_clearing_of_start_location() ) {
	    me->tell_me("Can't clear your start location here!");
	}
	else {
	    me->set_start_location(0);
	    me->tell_me("Ok. Removed the starting location.");
	}
    } else {
	notify_fail("Usage: starthere [clear]\n");
	return 0;
    }
    return 1;
}
