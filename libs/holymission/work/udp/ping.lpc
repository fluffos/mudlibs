/*
  lib/udp/ping.c

  Routines for checking pinging another mud

  This code is meant to be shared among all muds needing his feature.
*/
#include <std.h>
#include <udp.h>

#define TO this_object()
#define STANDARD_MUDS ({"129.16.79.12",2000,"129.16.117.17",2500,\
			    "129.234.202.104",2500}) 

int atoi(string num)
{
    int inum;

    if (sscanf(num, "%d", inum) == 1)
	return inum;
    else
	return 0;
}

/*
 * Send a ping package
 */
void
send_ping_q(string host, mixed port)
{
    if (stringp(port))
	port = atoi(port);

    TO->send_udp(host, port,
		 "@@@" + UDP_PING_Q +
		 "||NAME:" + TO->query_my_name() +
		 "||PORTUDP:" + TO->query_my_udpport() +
		 "@@@\n");
}

/*
 */  
int 
ping_q(mapping p)
{
    mapping mi;

    if (p["PORTUDP"])
    {
	TO->send_udp(p["HOSTADDRESS"], atoi(p["PORTUDP"]), 
		     "@@@" + UDP_PING_A +
		     SECURITY->startup_udp() + "@@@\n");

	mi = TO->query_mud_info(p["NAME"]);

	/* Ping from an unknown mud? Then ping it.
	 */
	if (stringp(p["NAME"]) && !mappingp(mi))
	    TO->send_ping_q(p["HOSTADDRESS"], atoi(p["PORTUDP"]));

	return 1;
    }
    return 0;
}

/*
 */  
int 
ping_a(mapping p)
{
    if (stringp(p["NAME"]) && p["NAME"] != TO->query_my_name())
    {
	TO->set_mud_info(p["NAME"], p);
	return 1;
    }
    return 0;
}

/*
 * ping_cmd - send a udp ping to another mud
 */
int
cmd_ping(string arg)
{
    string a, b, *ix;
    int port,i;
    mapping p;
    int il;

    if (!arg)
    {
	ix = STANDARD_MUDS;
	for (i=0; i<sizeof(ix)-1; i+=2)
	{
	    send_ping_q(ix[i],ix[i+1]);
	    write("Ping on "+ix[i]+" at port "+ix[i+1]+".\n");
	    TO->query_mud_info(ix[i]+" "+ix[i+1]);
	}
	write("Ok.\n");
	return 1;
    }
    
    ix = TO->query_known_muds();

    if (member_array(arg, ix) >= 0)
    {
	p = TO->query_mud_info(arg);
	send_ping_q(p["HOSTADDRESS"], p["PORT"]);
    }
    else if (stringp(arg) && sscanf(arg,"%s %s", a, b) == 2)
    {
	send_ping_q(a, b);
    }
    else
    {
	notify_fail("Ping what? Give host port / mudname\n");
	return 0;
    }
    write("Ok.\n");
    return 1;
}
