#include "udp.h"
#define TELL_DEMON "/net/daemon/chars/tell_demon"

void create() {
  seteuid(getuid());
} /* create() */

/*
 * Tell a wiz on another mud.
 */
void send_gtell(string wiz_to, string mud, string msg) {
  mapping minfo;

  if (mud == mud_name())
    return ;
  minfo = NAMESERVER_CD->query_mud_info(mud);
  if (!minfo)
    return ;
  msg = replace(msg, ({ "|", "", "@@@", "" }));
  NAMESERVER_CD->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                          "@@@"+UDP_GTELL+
                          "||NAME:"+mud_name()+
                          "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                          "||WIZTO:"+wiz_to+
                          "||WIZFROM:"+this_player()->query_cap_name()+
                          "||MSG:"+msg+"@@@\n");
} /* send_gtell() */

void incoming_request(mapping info) {
  object ob;
  mapping minfo;
  object pl;

  if (info["NAME"] && info["PORTUDP"]) {
    if (info["NAME"] == mud_name())
      return ;
    minfo = NAMESERVER_CD->query_mud_info(info["NAME"]);
    if (!minfo)
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if (minfo && minfo["HOSTADDRESS"] != info["HOSTADDRESS"]) {
/* Its been faked! */
      log_file("UDP_faketell", info["WIZFROM"]+"@"+info["NAME"]+
               "("+info["HOSTADDRESS"]+") telling "+info["WIZTO"]+" "+
               info["MSG"]+"\n");
      NAMESERVER_CD->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                              "@@@"+UDP_WARNING+
                              "||MSG: Faked gtell message "+info["WIZFROM"]+
                              "@"+info["NAME"]+"> "+info["WIZTO"]+
                              " "+info["MSG"]+
                              "||FAKEHOST:"+info["name"]+
                              "@@@\n");
      return ;
    }
    pl = find_player(lower_case(info["WIZTO"]));
    if (pl) {
      if (!random(10))
        (UDP_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
                info["PORTUDP"], "Gtell@"+mud_name(), info["WIZFROM"],
                info["WIZTO"]+" successfully didn't see the message.\n");
      else if (!random(10))
        (UDP_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
                info["PORTUDP"], "Gtell@"+mud_name(), info["WIZFROM"],
                info["WIZTO"]+" successfully ate the message.\n");
      else
        (UDP_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
                info["PORTUDP"], "Gtell@"+mud_name(), info["WIZFROM"],
                info["WIZTO"]+" successfully saw the message.\n");
    ob = clone_object(TELL_DEMON);
    ob->setup_tell(info["WIZFROM"], info["NAME"], 
                   lower_case(info["WIZTO"]), info["MSG"]);
    } else
      (UDP_PATH+"affirmation_a")->send_affirmation_a(info["HOSTADDRESS"],
                info["PORTUDP"], "Gtell@"+mud_name(), info["WIZFROM"],
                info["WIZTO"]+" is not logged on, sorry we don't have "+
                "an answering machine yet.\n");
  }
} /* incoming_request() */
