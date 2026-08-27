#include <mudlib.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>
 
inherit DAEMON;

void send_locate_q(string who) {
    mapping info;
    string *muds;
    int i;
 
    i = sizeof(muds = keys(info=(mapping)DNS_MASTER->query_muds()));
    while(i--) {
      if( muds[i] == Mud_name() ) continue;
        DNS_MASTER->send_udp(info[muds[i]]["HOSTADDRESS"],
          info[muds[i]]["PORTUDP"], "@@@"+DNS_LOCATE_Q+
      "||NAME:"+Mud_name()+
      "||PORTUDP:" + udp_port() +
      "||TARGET:"+lower_case(who)+
      "||ASKWIZ:"+(string)this_player()->query("name")+
        "@@@\n");
    }
    return;
}
 
void incoming_request(mapping info) {
    string field;
 
    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!DNS_MASTER->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if(!info["TARGET"]) field = "NO";
    else field = (find_player(lower_case(info["TARGET"])) ? "YES" : "NO");
    DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
      "@@@"+DNS_LOCATE_A+"||NAME:"+Mud_name()+
      "||PORTUDP:"+(int)DNS_MASTER->query_udp_port()+
      "||LOCATE:"+field+
      "||TARGET:"+info["TARGET"]+
      "||ASKWIZ:"+info["ASKWIZ"]+"@@@\n");
}


