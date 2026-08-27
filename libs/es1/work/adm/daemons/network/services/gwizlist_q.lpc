/*    /adm/daemons/network/services/gwizlist_q.c
 *    from TMI-2
 *    handles incoming gwizlist respnses, and outgoing queries
 *    created by Descartes of Borg 940804
 */

#include <mudlib.h>
#include <net/macros.h>
#include <net/dns.h>
#define DNS_GWIZLIST_A "/adm/daemons/network/services/gwizlist_a"
#define DNS_GWIZLIST_Q "/adm/daemons/network/services/gwizlist_q"

inherit DAEMON;

void incoming_request(mapping info) {
    string tmp;

    if(!info["CHANNEL"]) tmp = "Channel not supported.";
    else tmp = (string)("/adm/daemons/channels")->display_channel("gwiz");
    DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||GWIZLIST:%s||CHANNEL:%s||"
        "ASKWIZ:%s@@@\n", DNS_GWIZLIST_A, Mud_name(), (int)DNS_MASTER->query_udp_port(), tmp,
        info["CHANNEL"], info["ASKWIZ"]));
}

void send_gwizlist_q(string chan, string mud) {
    mapping info;

    if(!(info = (mapping)DNS_MASTER->query_mud_info(mud))) return;
    DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
      sprintf("@@@%s||NAME:%s||PORTUDP:%d||CHANNEL:%s||ASKWIZ:%s@@@\n",
      DNS_GWIZLIST_Q, Mud_name(), (int)DNS_MASTER->query_udp_port(), "CREATOR",
      (string)this_player()->query("name")));
}
