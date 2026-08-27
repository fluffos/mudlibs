/*
  lib/udp/rwho.c

  Routines for implementing a 'who' across muds

  This code is meant to be shared among all muds needing his feature.
*/
#pragma strict_types
#pragma save_binary

#include <composite.h>
#include <language.h>
#include <std.h>
#include <udp.h>

#define TO this_object()

/*
 * Function name: send_rwho_q
 * Description:   Sends a tell message to someone at another mud.
 * Argument:	  mud: The mudname
 *		  askwiz: Name of the wizard asking for rwho info
 * Returns:	  True if mud known and message sent.
 */
public int
send_rwho_q(string mud, string askwiz)
{
    mapping minfo;
    
    minfo = TO->query_mud_info(mud);

    if (!mappingp(minfo))
	return 0;

    if (stringp(minfo["HOSTADDRESS"]) && (atoi(minfo["PORTUDP"]) > 0))
    {
	TO->send_udp(minfo["HOSTADDRESS"], atoi(minfo["PORTUDP"]), 
		     "@@@" + UDP_RWHO_Q +
		     "||NAME:" + TO->query_my_name() +
		     "||PORTUDP:" + TO->query_my_udpport() +
		     "||ASKWIZ:" + askwiz +
		     "@@@\n");
	return 1;
    }
    return 0;
}

/*
 * Function name: rwho_q
 * Description:   Called when the mud receives an rwho_q package
 * Argument:	  p: mapping holding received information
 * Returns:	  True if correct message form
 */
public int
rwho_q(mapping p)
{
    string tmsg, rect;
    object pl;
    mapping minfo;

    if (stringp(p["NAME"]) && 
	stringp(p["PORTUDP"]))
    {
	if (p["NAME"] == TO->query_my_name())
	    return 0;

	minfo = TO->query_mud_info(p["NAME"]);

	/* 
	    If the mud is unknown to us we might as well ping it to get
	    some relevant info.
	*/
	if (!mappingp(minfo))
	    TO->send_ping_q(p["HOSTADDRESS"], p["PORTUDP"]);

	if (p["PORTUDP"])
	{
	    TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), 
				    "@@@" + UDP_RWHO_A +
				    "||NAME:" + TO->query_my_name() +
				    "||PORTUDP:" + TO->query_my_udpport() +
				    "||RWHO:" + TO->rwho_message() +
				    "||ASKWIZ:" + p["ASKWIZ"] +
				    "@@@\n");
				    
	    return 1;
	}
	return 0;
    }
    return 0;
}   
 
/*
 * Function name: rwho_a
 * Description:   Called when the mud receives an rwho_a package
 * Argument:	  p: mapping holding received information
 * Returns:	  True if correct message form
 */
public int
rwho_a(mapping p)
{
    string pls;
    object pl;
    mapping minfo;

    if (stringp(p["NAME"]) && 
	stringp(p["PORTUDP"]))
    {
	if (p["NAME"] == TO->query_my_name())
	    return 0;

	minfo = TO->query_mud_info(p["NAME"]);

	/* 
	    If the mud is unknown to us we might as well ping it to get
	    some relevant info.
	*/
	if (!mappingp(minfo))
	    this_object()->send_ping_q(p["HOSTADDRESS"], p["PORTUDP"]);

	if (stringp(p["ASKWIZ"]) && stringp(p["RWHO"]))
	{
	    pl = find_player(lower_case(p["ASKWIZ"]));
	    if (objectp(pl))
		tell_object(pl, "rwho@" + p["NAME"] + ":\n" +
			    p["RWHO"] + "\n");
	    return 1;
	}
	return 0;
    }
    return 0;
}    

/*
 * The actual rwho message
 */
public string
rwho_message()
{
    string r, ws;
    object *u;
    string *wiz, *mortal;
    int il;

    /* Build the rwho list
    */
    u = users();

    if (!sizeof(u))
	u = ({});

    r = SECURITY->get_mud_name() + " (" + SECURITY->do_debug("version") +
	":" + MUDLIB_VERSION + "): ";
    
    for (wiz = ({}), mortal = ({}), il = 0; il < sizeof(u); il++) {
	if (u[il] && u[il]->query_wiz_level())
	    wiz = wiz + ({ capitalize(u[il]->query_real_name()) });
	else if (u[il])
	    mortal = mortal + ({ capitalize(u[il]->query_real_name()) });
    }

    r += capitalize(LANG_WNUM(sizeof(mortal)));

    if (sizeof(mortal) == 1)
	r += " player and ";
    else
	r += " players and ";
	
    r += LANG_WNUM(sizeof(wiz));

    if (sizeof(wiz) == 1)
	r += " wizard.";
    else 
	r += " wizards.";

    if (sizeof(wiz))
	r += " ";
#ifndef	RWHO_NO_MORTALS
    else if (sizeof(mortal))
	r += " ";
#endif

    if (sizeof(wiz)) {
	if (sizeof(wiz) == 1)
	    r += "Wizard is:\n";
	else if (sizeof(wiz))
	    r += "Wizards are:\n";
	else
	    r += " wizards.\n";

	if (sizeof(wiz))
	    r += break_string(COMPOSITE_WORDS(wiz) + ".", 70, 3);
    }

#ifndef	RWHO_NO_MORTALS
    if (sizeof(mortal)) {
	if (sizeof(wiz))
	    r += "\n";
	if (sizeof(mortal) == 1)
	    r += "Player is:\n";
	else
	    r += "Players are:\n";
	r += break_string(COMPOSITE_WORDS(mortal) + ".", 70, 3);
    }
#endif

    r += "\n";

    return r;
}

/*
 * Function name: cmd_rwho
 * Description:   Called from some soul to make an rwho
 * Argument:	  str: The string typed by the wizard
 * Returns:	  1 if success
 */
public int
cmd_rwho(string mud)
{
    string *names;
    int il;


    if (!mud)
    {
#if 1
        notify_fail("Rwho which mud?\n");
        return 0;
#endif
	names = TO->query_known_muds();
	for (il = 0; il < sizeof(names); il++)
	    if (!send_rwho_q(names[il], this_player()->query_real_name()))
		names[il] = 0;
	    
	if (sizeof(names) && sizeof((names = names - ({ 0 }))))
	{
	    write("Ok, Have sent the query to:\n" + 
		  break_string(COMPOSITE_WORDS(names) + ".\n", 70, 3));
	    return 1;
	}
	else
	{
	    notify_fail("No known muds.\n");
	    return 0;
	}
    }

    if (mud == this_object()->query_my_name())
    {
        write(rwho_message());
        return 1;
    }

    if (!send_rwho_q(mud, this_player()->query_real_name()))
    {
	notify_fail("Unknown mud or mud can't answer: " + mud + "\n");
	return 0;
    }
    write("Ok, Have sent the query to: " + mud + ".\n");
    return 1;
}