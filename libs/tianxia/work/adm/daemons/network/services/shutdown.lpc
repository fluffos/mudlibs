// File    : shutdown.c

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

void incoming_request(mapping info)
{
	mapping mud_info;

	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID)
	|| !info["NAME"] )
		return;

	mud_info = (mapping)DNS_MASTER->query_mud_info(info["NAME"]);

	if(!mud_info || !DNS_MASTER->dns_mudp(info["NAME"]))
		return;

	if(info["HOSTADDRESS"] != mud_info["HOSTADDRESS"])
	{
		dns_log("dns_fake", sprintf("Shutdown from: %s for %s (%s) @%s\n",
			mud_info["HOSTADDRESS"], info["NAME"],
			info["HOSTADDRESS"], ctime(time()) ));

		DNS_MASTER->send_udp(mud_info["HOSTADDRESS"], mud_info["PORTUDP"],
			"@@@"+DNS_WARNING+
			"||MSG: Faked shutdown message from "+
			info["HOSTADDRESS"] + "||FAKEHOST:" +
			info["NAME"] + "@@@");
		return;
	}

	DNS_MASTER->zap_mud_info(info["NAME"]);
}

void send_shutdown(string host, int port)
{
	if(!previous_object()
	|| (geteuid(previous_object()) != ROOT_UID) )
		return;

	DNS_MASTER->send_udp(host, port, "@@@"+DNS_SHUTDOWN+
		"||NAME:"+Mud_name()+
		"||PORTUDP:"+udp_port()+
		"@@@\n");
}
