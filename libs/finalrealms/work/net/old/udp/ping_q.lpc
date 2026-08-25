#include "udp.h"
/*
 * Someone wants us to ping them.
 */
void incoming_request(mapping info) {
  string str;

  if (info["PORTUDP"]) {
    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
   if (lower_case(info["NAME"]) != lower_case(mud_name()))
     NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                             "@@@"+UDP_PING_A+NAMESERVER_CD->start_message()+
                             "@@@\n");
   "/net/udp/mail_q"->check_for_mail(info["NAME"], 3);
  }
} /* incoming_request() */

void send_ping_q(string host, int port) {
  NAMESERVER_CD->send_udp(host, port, "@@@"+UDP_PING_Q+
                          "||NAME:"+mud_name()+
                          "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                          "@@@\n");
} /* send_ping_q() */

void create() {
  seteuid(getuid());
} /* create() */
