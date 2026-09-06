#include "../priest.h"
#include <channels.h>
#include <coder_levels.h>
#include <daemons.h>


#define WRITE me->tell_me

#define CH_NAME "priest"

#ifndef TP
#define TP this_player()
#endif

nomask int
usage()
{
    TP->tell_me("Usage: " + query_verb() + " " +
      "[-<on/off/toggle/tail/more/ban/mass> / <message>]\n");
    return 1;
}

nomask int
comm_cmd(object me, object sym, string arg)
{
    object ob;
    string cmd, msg, tmp, *tmp2;
    int i, p;

    p = (int)me->query_coder_level();

    if(!CHANNEL_D->can_read_channel(me, CH_NAME) ||
      me->query_channel_ban(CH_NAME))
    {
	WRITE("You can't access channel \"priest\".");
	return 1;
    }

    if(!arg) {
	me->more((string *)CHANNEL_D->list_channel(CH_NAME, me));
	return 1;
    }

    if ((sscanf(arg, "-%s %s", cmd, msg) != 2) &&
      (sscanf(arg, "-%s", cmd) != 1))
    {
	if (!me->is_on_channel(CH_NAME)) {
	    WRITE("You are not on the channel called \"priest\".");
	    return 1;
	}

	if (stringp(tmp = (string)CHANNEL_D->valid_channel_message(arg))) {
	    WRITE(tmp);
	    return 1;
	}

	if (!CHANNEL_D->send_channel_message(me, CH_NAME, arg))
	    WRITE("Couldn't send message!");
	return 1;
    }

    switch(cmd) {
    case "ban":
	if (!p && !CHANNEL_D->query_is_channel_admin(me, CH_NAME)) {
	    WRITE("You are not privileged to ban anyone from the priest channel.");
	    break;
	}

	ob = find_player(msg);
	if (!ob) {
	    WRITE("There is no player \"" + msg + "\" logged in.");
	    break;
	}

	i = ((int)ob->query_channel_status(CH_NAME) & CHANNEL_BAN);
	ob->set_channel_ban(CH_NAME, !i);

	WRITE("Ok. " + (!i ? "Banned" : "Unbanned") + " " +
	  capitalize(msg) + " from channel \"priest\".");
	break;

    case "more":
	me->more((string *)CHANNEL_D->more_channel(CH_NAME));
	break;

    case "tail":
	CHANNEL_D->tail_channel(CH_NAME, this_player());
	break;

    case "on":
	if (me->is_on_channel(CH_NAME)) {
	    WRITE("You already are on channel \"priest\".");
	    break;
	}
	CHANNEL_D->join_channel(CH_NAME, me);
	me->channel_on(CH_NAME);
	WRITE("Ok. You are on channel \"priest\".");
	break;

    case "toggle":
	i = me->is_on_channel(CH_NAME);
	if(i) me->channel_off(CH_NAME);
	else me->channel_on(CH_NAME);

	WRITE("Ok. You are " + (i ? "off" : "on") +
	  " channel \"priest\".");
	break;

    case "off":
	me->channel_off(CH_NAME);
	WRITE("Ok. You are off channel \"priest\".");
	break;

    case "mass":
	tmp = VESPER_D->query_vespers();
	if(tmp) me->tell_me(sprintf("There's %s going on.", tmp));
	else me->tell_me("It's not time for mass."); 
	break;

    default:
	usage();
    }
    return 1;
}
