/*
  udp/gfinger.c

  Routines for implementing a 'finger' across muds

  This code is meant to be shared among all muds needing his feature.
*/
#pragma strict_types
#pragma save_binary

#include <std.h>
#include <udp.h>
#include <time.h>

#define TO this_object()

/*
 * Function name: send_gfinger
 * Description:   Sends a finger message to another mud.
 * Argument:	  mud: The mudname
 *		  wiz_from: The wizard name of sender
 *		  wiz_to: The wizard name of receiver
 * Returns:	  True is mud known and message sent.
 */
public int
send_gfinger_q(string mud, string wiz_from, string wiz_to)
{
    mapping minfo;
    
    minfo = TO->query_mud_info(mud);

    if (!mappingp(minfo))
	return 0;

    if (stringp(minfo["HOSTADDRESS"]) && atoi(minfo["PORTUDP"]))
    {
	TO->send_udp(minfo["HOSTADDRESS"], atoi(minfo["PORTUDP"]), 
		     "@@@" + UDP_GFINGER_Q +
		     "||NAME:" + TO->query_my_name() +
		     "||PORTUDP:" + TO->query_my_udpport() +
		     "||ASKWIZ:" + capitalize(wiz_from) +
		     "||PLAYER:" + capitalize(wiz_to) + "@@@\n");

	return 1;
    }
    return 0;
}

/*
 * Function name: gfinger_q
 * Description:   Called when the mud receives a gfinger query package
 * Argument:	  p: mapping holding received information
 * Returns:	  True if correct message form
 */
public int
gfinger_q(mapping p)
{
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

	if (!stringp(p["ASKWIZ"]) || !stringp(p["PLAYER"]))
	    return 0;

if (p["PLAYER"] == "info")
{
    TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), "@@@" + UDP_GFINGER_A
          + "||NAME:" + TO->query_my_name() + "||PORTUDP:"
          + TO->query_my_udpport() + "||ASKWIZ:" + p["ASKWIZ"] + "||MSG:"
          + read_file("/d/Standard/doc/intermud/info.1") + "@@@\n");
    TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), "@@@" + UDP_GFINGER_A
          + "||NAME:" + TO->query_my_name() + "||PORTUDP:"
          + TO->query_my_udpport() + "||ASKWIZ:" + p["ASKWIZ"] + "||MSG:"
          + read_file("/d/Standard/doc/intermud/info.2") + "@@@\n");
    TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), "@@@" + UDP_GFINGER_A
          + "||NAME:" + TO->query_my_name() + "||PORTUDP:"
          + TO->query_my_udpport() + "||ASKWIZ:" + p["ASKWIZ"] + "||MSG:"
          + read_file("/d/Standard/doc/intermud/info.3") + "@@@\n");
    return 1;
}

	TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]),
		     "@@@" + UDP_GFINGER_A +
		     "||NAME:" + TO->query_my_name() +
		     "||PORTUDP:" + TO->query_my_udpport() +
		     "||ASKWIZ:" + p["ASKWIZ"] +
		     "||MSG:" + TO->finger_player(p["PLAYER"]) +
		     "@@@\n");
	return 1;
    }
    return 0;
}    

/*
 * Function name: gfinger_a
 * Description:   Called when the mud receives a gfinger_a package
 * Argument:	  p: mapping holding received information
 * Returns:	  True if correct message form
 */
public int
gfinger_a(mapping p)
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

	if (stringp(p["ASKWIZ"]) && stringp(p["MSG"]))
	{
	    pl = find_player(lower_case(p["ASKWIZ"]));
	    if (objectp(pl))
		tell_object(pl, p["MSG"] + "\n");
	    return 1;
	}
	return 0;
    }
    return 0;
}    

/*
 * The actual finger message
 */
public string
finger_player(string player)
{
    object  ob, *dlist;
    int    li, log_time, mw;
    string str1, str2, str3;
    string pron;
    string str;

    str = "";

    if (ob = find_player(lower_case(player))) {
	str = ob->query_name() + " is currently in the game.\n";
	li = 1;
    }
    else {
	ob = (object)SECURITY->finger_player(lower_case(player));
	li = 0;
    }

    if (!ob)
	return "No such player on " + SECURITY->get_mud_name() + ".\n";

    str += ob->long(this_object());

    pron = capitalize((string)ob->query_pronoun());

    str += pron + " holds the rank of "+
	capitalize(WIZ_RANK_NAME(SECURITY->query_wiz_rank(ob->query_real_name()))) + ".\n";
    str1 = lower_case((string)ob->query_real_name());

    str2 = (string)SECURITY->query_wiz_dom(str1);
    if (strlen(str2)) {
        str3 = (string)SECURITY->query_domain_lord(str2);
	if (SECURITY->query_wiz_rank(ob->query_real_name()) == WIZ_LORD)
	    str += pron + " is liege of the domain " + str2 + ".\n";
	else {
            if (strlen(str3))
                str += pron + " is a member of the domain " + str2 +
		      " with the liege " + capitalize(str3) + ".\n";
	    else
		str += pron + " is a member of the domain " + str2 +
		      " with no lord.\n";
	}
	if (SECURITY->query_domain_madwand(str2) == str1)
	    str += pron + " is the Madwand of the " + str2 + " domain.\n";
    }

    if (li) {
	str += "Currently logged on from: " + ob->query_login_from() + "\n";
	if (query_ip_number(ob)) {
	    if (query_idle(ob) > 0)
		str += "Idle time: " + CONVTIME(query_idle(ob)) + ".\n";
	}
	else
	    str += pron + " is link dead.\n";
    }
    else {
        ob->set_adj();   /* Fixa adjektiv */
        log_time = time() - (int)ob->query_login_time();
	str1 = CONVTIME(log_time);

	str += "Last login: " + str1 + " ago from " +
	      ob->query_login_from() + ".\n";
    }

    str += "Age: " + CONVTIME(ob->query_age() * 2) +".\n";
    str += "Email: " + ob->query_mailaddr() + "\n";

    if (!li)
	ob->remove_object();

    return str;
}

/*
 * Function name: cmd_gfinger
 * Description:   Called from some soul to make a gfinger
 * Argument:	  str: The string typed by the wizard
 * Returns:	  1 if success
 */
public int
cmd_gfinger(string str)
{
    string wiz, mud, msg;

    notify_fail("Finger whom at mud?\n");

    if (!str)
	return 0;

    if (sscanf(str,"%s@%s", wiz, mud) != 2)
    {
	if (sscanf(str,"%s.%s", wiz, mud) != 2)
	    return 0;
    }

    if (mud == this_object()->query_my_name())
    {
        write(finger_player(wiz));
        return 1;
    }

    if (!send_gfinger_q(mud, this_player()->query_real_name(), wiz))
    {
	notify_fail("Unknown mud or mud can't anwer: " + mud + "\n");
	return 0;
    }
    write("Ok, query sent to: " + mud + ".\n");
    return 1;
}
