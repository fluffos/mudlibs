/*
  lib/udp/support.c

  Routines for checking if something is supported or not

  This code is meant to be shared among all muds needing his feature.
*/
#pragma strict_types
#pragma save_binary

#include <std.h>
#include <udp.h>

#define TO this_object()

/*
 * send_support_q
 *
 * Note that param is unsupported currently
 */
int send_support_q(string host, mixed port, string cmd, string param)
{
    if (stringp(port))
	port = atoi(port);

    TO->send_udp(host, port,
		 "@@@" + UDP_SUPPORTED_Q +
		 "||NAME:" + TO->query_my_name() +
		 "||PORTUDP:" + TO->query_my_udpport() +
		 "||CMD:" + cmd +
		 (strlen(param) ? "||PARAM:" + param : "") +
		 "||ANSWERID:" + this_player()->query_real_name() +
		 "@@@\n");
    return 1;
}


/*
 * support_q
 */
int support_q(mapping p)
{
    if (strlen(p["PORTUDP"]) && strlen(p["ANSWERID"]))
    {
	if (member_array(p["CMD"], UDP_SUPPORT_ARRAY) < 0 ||
	    ((strlen(p["PARAM"]) &&
	      !call_other(TO, "support_" + p["CMD"], p["PARAM"]))))
	{
	    TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), 
			 "@@@" + UDP_SUPPORTED_A +
			 "||NAME:" + TO->query_my_name() +
			 "||PORTUDP:" + TO->query_my_udpport() +
			 "||CMD:" + p["CMD"] +
			 (strlen(p["PARAM"]) ? "||PARAM:" + p["PARAM"] : "") +
			 "||NOTSUPPORTED:yes" +
			 "||ANSWERID:" + p["ANSWERID"] +
			 "@@@\n");
	}
	else
	{
	    TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), 
			 "@@@" + UDP_SUPPORTED_A +
			 "||NAME:" + TO->query_my_name() +
			 "||PORTUDP:" + TO->query_my_udpport() +
			 "||CMD:" + p["CMD"] +
			 (strlen(p["PARAM"]) ? "||PARAM:" + p["PARAM"] : "") +
			 "||SUPPORTED:yes" +
			 "||ANSWERID:" + p["ANSWERID"] +
			 "@@@\n");
	}
	return 1;
    }
    return 0;
}

/*
 * support_a
 */
int support_a(mapping p)
{
    string id, tx;
    object ob;

    id = p["ANSWERID"];
    if (!strlen(id))
	return 0;

    ob = find_player(id);
    if (ob)
    {
	tx = p["CMD"] + " " +
	    (strlen(p["PARAM"]) ? " (" + p["PARAM"] + ") " : "");
	if (p["SUPPORTED"])
	    tell_object(ob, p["NAME"] + " supports " + tx + "\n");
	else
	    tell_object(ob, p["NAME"] + " does not support " + tx + "\n");
    }
    return 1;
}

/*
 * cmd_support - send a udp ping to another mud
 *
 * arg:		<mud / host port> cmd [param]
 */
int
cmd_support(string arg)
{
    string a, b, *ix, *args;
    int port;
    mapping p;
    int il;
    
    args = explode(arg, " ");
    ix = TO->query_known_muds();
    notify_fail("What? Give <mud / host port> cmd [param]\n");

    if (member_array(args[0], ix) >= 0)
    {
	p = TO->query_mud_info(args[0]);
	if (sizeof(args) < 2)
	    return 0;
	if (atoi(p["PORTUDP"]) < 1)
	{
	    notify_fail(args[0] + " can not answer.\n");
	    return 0;
	}
	send_support_q(p["HOSTADDRESS"], p["PORTUDP"], args[1], 
		       (sizeof(args) > 2 ? args[2] : 0));
    }
    else 
    {
	if (sizeof(args) < 3)
	    return 0;
	send_support_q(args[0], args[1], args[2], 
		       (sizeof(args) > 3 ? args[3] : 0));
    }

    write("Ok, have sent the query.\n");
    return 1;
}
