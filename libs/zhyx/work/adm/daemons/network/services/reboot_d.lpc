/*
 * File    : reboot_d.c
 * Creator : xdie@SDXL
 * When    : 03-10-23
 *
 *
 * This protocol is used to reboot a mud.
 */


#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

void send_reboot_q(string mud, object source)
{
	mapping minfo;
	int code;

	if(!ACCESS_CHECK(previous_object())) return;

	mud = htonn( mud );

	if(mud == mud_nname() || !geteuid(source)) return;

	minfo = (mapping)DNS_MASTER->query_mud_info(mud);
	if (!minfo) return ;

	code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
	if( minfo["ENCODING"] == "GB" )	code = 0;

	if( code == 1 ) {
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"],
		atoi(minfo["PORTUDP"]),
		"@@@" + "reboot_q" +
		"||NAME:" + LANGUAGE_D->toBig5(Mud_name()) +
		"||PORTUDP:" + udp_port() +
		"||WIZTO:" + "none" +
		"||WIZFROM:" + capitalize(geteuid(source)) +
		"||CNAME:" + LANGUAGE_D->toBig5(source->name(1)) + "@@@\n");
	} else {
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"],
		atoi(minfo["PORTUDP"]),
		"@@@" + "reboot_q" +
		"||NAME:" + Mud_name() +
		"||PORTUDP:" + udp_port() +
		"||WIZTO:" + "none" +
		"||WIZFROM:" + capitalize(geteuid(source)) +
		"||CNAME:" + source->name(1) + "@@@\n");

	}
}

// Some mud or other has decied to tell us to shut down...
void incoming_request(mapping info)
{
	mapping mud_info;

	if(!ACCESS_CHECK(previous_object())) return;

	if(!info["NAME"])
		return;

	mud_info = (mapping)DNS_MASTER->query_mud_info(info["NAME"]);
		if(!mud_info || !DNS_MASTER->dns_mudp(info["NAME"]))
			return;
}

void create()
{
	seteuid(ROOT_UID);
}
