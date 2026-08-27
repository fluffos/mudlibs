#include <udp.h>
/*
 * gwizmsg...  The global wizard chat line.
 */
string *allowed_array, last;

void create() {
  allowed_array = ({ "bing", "flame", "Discworld", "actuator" });
} /* create() */

void send_gwizmsg(string msg, int emoted) {
  int i;
  string *allowed_array;
  mapping minfo, muds, sent;

  if (!interactive(previous_object())) {
    event(users(), "inform", file_name(previous_object())+
        " attempted to send unauthorised gwiz message", "cheat");
    return ;
  }
  muds = NAMESERVER_CD->query_known_muds();
  allowed_array = keys(muds);
  msg = replace(msg, ({ "", "^G", "|", "", "@@@", "" }));
  sent = ([ ]);
  for (i=0;i<sizeof(allowed_array);i++)
    if (lower_case(allowed_array[i]) != lower_case(mud_name())
        && !sent[lower_case(allowed_array[i])]) {
      if (!mapp(muds[allowed_array[i]]))
        continue;
      minfo = muds[allowed_array[i]];
      NAMESERVER_CD->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                              "@@@"+UDP_GWIZMSG+
                              "||NAME:"+mud_name()+
                              "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                              "||WIZNAME:"+this_player()->query_cap_name()+
                              "||GWIZ:"+msg+
                              "||CHANNEL:CREATOR"+
                              (emoted?"||EMOTE:1":"")+"@@@\n");
      sent[lower_case(allowed_array[i])] = 1;
    }
  event(users(), "intermud_tell", sprintf("%s%s", 
      this_player()->query_cap_name(), (emoted?" ":": ")), msg,
      "gwiz");
} /* send_gwizmsg() */

void incoming_request(mapping info) {
  mapping minfo;
  string tmsg;

  if (info["NAME"] && info["PORTUDP"]) {
    if (lower_case(info["NAME"]) == lower_case(mud_name()))
      return ;

    minfo = NAMESERVER_CD->query_mud_info(info["NAME"]);
    if (!minfo || !strlen(info["WIZNAME"])) {
/* We don't accept the message.  But ping them anyway. */
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
      return ;
    }
    if (info["EMOTE"])
      tmsg = info["WIZNAME"]+"@"+info["NAME"]+" "+info["GWIZ"];
    else
      tmsg = info["WIZNAME"]+"@"+info["NAME"]+": "+info["GWIZ"];
#ifdef PARANOID
    if (member_array(info["NAME"], allowed_array) == -1)
      return ;
#endif
    tmsg = replace(tmsg, "", "^G");
    if (info["HOSTADDRESS"] != minfo["HOSTADDRESS"]) {
/* Faked.  sheeze... */
      log_file("UDP_fakewizmsg", sprintf("%s: %s\n@%s", ctime(time()),
               info["HOSTADDRESS"]+tmsg));
      NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                              "@@@"+UDP_WARNING+
                              "||NAME:"+mud_name()+
                              "||MSG: Fake gwiz msg "+tmsg+
                              "||FAKEHOST:"+info["HOSTADDRESS"]+
                              "@@@\n");
      return ;
    }
    if (tmsg != last)
      event(users(), "intermud_tell", sprintf("%s@%s%s", 
          info["WIZNAME"], info["NAME"], (info["EMOTE"] == "1"?" ":": ")),
          info["GWIZ"], "gwiz");
    last = tmsg;
  }
} /* incoming_request() */
