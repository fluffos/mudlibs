#include "udp.h"
#define CHAR "/net/daemon/chars/"


void create() {
  seteuid(getuid());
} /* create() */

/*
 * Finger a wiz on another mud.
 */
void send_gfinger_q(string mud, string wiz) {
  mapping minfo;

  if (mud == mud_name())
    return ;
  minfo = NAMESERVER_CD->query_mud_info(mud);
  if (!minfo)
    return ;
  NAMESERVER_CD->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                          "@@@"+UDP_GFINGER_Q+
                          "||NAME:"+mud_name()+
                          "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                          "||PLAYER:"+wiz+
                          "||ASKWIZ:"+this_player()->query_name()+
                          "@@@\n");
} /* send_gtell() */

void incoming_request(mapping info) {
  string finger,
         *bits;
  int i;

  if (info["NAME"] && info["PORTUDP"]) {
    if (info["NAME"] == mud_name())
      return ;

    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

    finger = "/secure/finger"->finger_info(lower_case(info["PLAYER"]));
    if (!finger) finger = "I am most dreadfully sorry, but "+info["PLAYER"]+
                          "has not visited here yet.  Try again later :)\n";
    else {
      info["PLAYER"] = lower_case(info["PLAYER"]);
      if (find_player(info["PLAYER"])) {
        object ob;

        ob = clone_object(CHAR+"in_finger_demon");
        ob->setup_finger(info["PLAYER"]);
      }
    }
    bits = explode(finger, "\n");
    finger = "";
    for (i=0;i<sizeof(bits);i++) {
      if (strlen(finger) + strlen(bits[i]) > 256) {
        NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                        "@@@"+UDP_GFINGER_A+
                        "||NAME:"+mud_name()+
                        "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                        "||ASKWIZ:"+info["ASKWIZ"]+
                         "||MSG:"+finger+
                        "@@@\n");
        finger = "";
      }
      finger += bits[i] + "\n";
    }
    if (strlen(finger))
      NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                        "@@@"+UDP_GFINGER_A+
                        "||NAME:"+mud_name()+
                        "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                        "||ASKWIZ:"+info["ASKWIZ"]+
                         "||MSG:"+finger+
                        "@@@\n");
  }
} /* incoming_request() */

void dest_me() { destruct(this_object()); }
