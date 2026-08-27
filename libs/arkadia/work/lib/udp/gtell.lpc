/*
  udp/gtell.c

  Routines for implementing a 'tell' across muds

  This code is meant to be shared among all muds needing his feature.
*/
#pragma strict_types
#pragma save_binary

#include <udp.h>
#include <stdproperties.h>

#define TO this_object()

/*
 * Function name: send_gtell
 * Description:   Sends a tell message to someone at another mud.
 * Argument:	  mud: The mudname
 *		  wiz_from: The wizard name of sender
 *		  wiz_to: The wizard name of receiver
 *		  msg: The message to send
 * Returns:	  True is mud known and message sent.
 */
public int
send_gtell(string mud, string wiz_from, string wiz_to, string msg)
{
    mapping minfo;
    
    minfo = TO->query_mud_info(mud);

    if (!mappingp(minfo))
	return 0;

    msg = implode(explode(msg,"|"),"");
    msg = implode(explode(msg,"@@@"),"");

    if (stringp(minfo["HOSTADDRESS"]) && atoi(minfo["PORTUDP"]))
    {
	TO->send_udp(minfo["HOSTADDRESS"], atoi(minfo["PORTUDP"]), 
		     "@@@" + UDP_GTELL +
		     "||NAME:" + TO->query_my_name() +
		     "||PORTUDP:" + TO->query_my_udpport() +
		     "||WIZFROM:" + capitalize(wiz_from) +
		     "||WIZTO:" + capitalize(wiz_to) +
		     "||MSG:" + msg +  "@@@\n");
	return 1;
    }
    return 0;
}

/*
 * Function name: gtell
 * Description:   Called when the mud receives a tell package
 * Argument:	  p: mapping holding received information
 * Returns:	  True if correct message form
 */
public int
gtell(mapping p)
{
    string tmsg, rect;
    object pl;
    mapping minfo;
    int busy;

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

	if (!stringp(p["WIZFROM"]) || !stringp(p["WIZTO"]))
	    return 0;
	
	tmsg = p["WIZFROM"] + "@" + p["NAME"];
	rect = p["WIZTO"] + " : " + p["MSG"];

	if (mappingp(minfo) && minfo["HOSTADDRESS"] != p["HOSTADDRESS"])
	{
	    log_file("UDP_fakegtell", sprintf("%s: %s\n@ %s\n",
					     ctime(time()), p["HOSTADDRESS"],
					     tmsg + "> " + rect + "\n"));
	    TO->send_udp(minfo["HOSTADDRESS"], atoi(minfo["PORTUDP"]),
			 "@@@" + UDP_WARNING +
			 "||MSG:Faked gtell message, " + tmsg + "> " + rect +
			 "||FAKEHOST:" + p["HOSTADDRESS"] +
			 "@@@");
	    return 0;
	}
	pl = find_player(lower_case(p["WIZTO"]));
	if (!pl) {
	    if (p["WIZTO"] != "UDPmanager")
		send_gtell(p["NAME"], "UDPmanager", p["WIZFROM"],
			   p["WIZTO"] + " was not found.\n");
	    return 0;
	}
	if (!query_ip_number(pl)) {
	    send_gtell(p["NAME"], "UDPmanager", p["WIZFROM"],
		       p["WIZTO"] + " is link-dead.\n");
	    return 0;
	}
	busy = pl->query_prop(WIZARD_I_BUSY_LEVEL);
	if (busy & 8 || busy & 16 || busy & 128 || busy & 512 ||
	    !pl->query_wiz_level()) {
	    send_gtell(p["NAME"], "UDPmanager", p["WIZFROM"],
		       p["WIZTO"] + " does not accept messages at this time.\n");
	    if (!pl->query_wiz_level())
		log_file("UDP_mortalgtell", sprintf("%s: %s\n@ %s\n",
					     ctime(time()), p["HOSTADDRESS"],
					     tmsg + "> " + rect + "\n"));
	    return 0;
	}
	pl->catch_msg(tmsg + " tells you: " +  p["MSG"] + "\n");
	return 1;
    }
    return 0;
}    

/*
 * Function name: cmd_gtell
 * Description:   Called from some soul to make a gtell
 * Argument:	  str: The string typed by the wizard
 * Returns:	  1 if success
 */
public int
cmd_gtell(string str)
{
    string wiz, mud, msg;

    notify_fail("Tell what to whom and what mud?\n");

    if (!str)
	return 0;

    if (sscanf(str,"%s@%s %s", wiz, mud, msg) != 3)
    {
	if (sscanf(str,"%s.%s %s", wiz, mud, msg) != 3)
	    return 0;
    }

    if (!send_gtell(mud, this_player()->query_real_name(), wiz, msg))
    {
	notify_fail("Unknown mud: " + mud + "\n");
	return 0;
    }
    write("Ok.\n");
    return 1;
}
