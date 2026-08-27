#include <udp.h>
/* 
 * locate_q. Handles our locate requests, and sends a message to a locating
 * Mud. Modified to be used with DW lib by Turrican@Discworld.
 * 30-1-95
 */
 
void send_locate_q(string who) {
    mapping info;
    string *muds;
    int i;
    
    info = NAMESERVER_CD->query_known_muds();
    muds = keys(info);
    for (i=0;i<sizeof(muds);i++) {
      if (!mapp(info[muds[i]]))
        continue;
      if( muds[i] == mud_name() ) continue;
        NAMESERVER_CD->send_udp(info[muds[i]]["HOSTADDRESS"],
          info[muds[i]]["PORTUDP"], "@@@"+UDP_LOCATE_Q+
      "||NAME:"+mud_name()+
      "||PORTUDP:" + NAMESERVER_CD->query_my_port()+
      "||TARGET:"+lower_case(who)+
      "||ASKWIZ:"+(string)this_player()->query_name()+
        "@@@\n");
    }
    return;
}
 
void incoming_request(mapping info) {
    string field;
 
    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if(!info["TARGET"]) field = "NO";
    else field = (find_player(lower_case(info["TARGET"])) ? "YES" : "NO");
    NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
      "@@@"+UDP_LOCATE_A+"||NAME:"+mud_name()+
      "||PORTUDP:"+(int)NAMESERVER_CD->query_my_port()+
      "||LOCATE:"+field+
      "||TARGET:"+info["TARGET"]+
      "||ASKWIZ:"+info["ASKWIZ"]+"@@@\n");
}

void create() { seteuid(getuid()); }
void dest_me() { destruct(this_object()); }
