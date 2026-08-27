#include <udp.h>
/*
 * Affirmation of something.
 */
void incoming_request(mapping info) {
  object ob;

  if (!info["NAME"])
    return ;
  if (stringp(info["WIZFROM"]) && info["WIZFROM"][0..3] == "GWIZ") {
    if (!random(10))
      this_object()->send_affirmation_a(info["HOSTADDRESS"], info["PORTUDP"],
        "affirmation@"+mud_name(), "yappo", "We got your affirmation of "+
        "getting the gwizmsg message.\n", "affirmation");
    return ;
  }
  if (info["WIZTO"]) {
    if (ob = find_player(lower_case(info["WIZTO"])))
      tell_object(ob, info["WIZFROM"]+" Affirms that "+info["MSG"]+"");
  }
} /* incoming_request() */

void send_affirmation_a(string host, string port, string from, string to,
                        string msg) {
  NAMESERVER_CD->send_udp(host, port,
                          "@@@"+UDP_AFFIRMATION_A+
                          "||NAME:"+mud_name()+
                          "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                          "||WIZTO:"+to+
                          "||WIZFROM:"+from+
                          "||MSG:"+msg+"@@@\n");
} /* send_affirmation_a() */
