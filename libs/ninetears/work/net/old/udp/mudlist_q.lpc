#include "udp.h"
/*
 * Incoming mudlist query.  They want to know which muds we know.
 * We will only tell them about the CD ones we know and not the
 * mudos ones...
 */

string *build_mudlist(mapping muds) {
  string *names, *ret;
  int i, pos;

  names = keys(muds);
  ret = ({ "" });
  for (i=0;i<sizeof(names);i++) {
    if (!mapp(muds[names[i]])) continue;
    ret[pos] += "||"+i+":"+
           "|NAME:"+names[i]+
           "|HOST:"+muds[names[i]]["HOST"]+
           "|HOSTADDRESS:"+muds[names[i]]["HOSTADDRESS"]+
           "|PORT:"+muds[names[i]]["PORT"]+
           "|PORTUDP:"+muds[names[i]]["PORTUDP"];
    if (strlen(ret[pos]) > 256) {
      ret += ({ "" });
      pos++;
    }
  }
  return ret;
} /* build_mudlist() */

void send_mudlist_q(string host, string port) {
  NAMESERVER_CD->send_udp(host, port, "@@@"+UDP_MUDLIST_Q+
                                   "||NAME:"+mud_name()+
                                   "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                                   "@@@\n");
} /* send_mudlist_q() */

void incoming_request(mapping info) {
  int i;
  string *bits;

  if (info["PORTUDP"]) {
    bits = build_mudlist((mapping)NAMESERVER_CD->query_known_muds());
    for (i=0;i<sizeof(bits);i++) 
      NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                    "@@@"+UDP_MUDLIST_A+
                    bits[i]+
                    "@@@\n");
  }
} /* incoming_request() */

void create() {
  seteuid(getuid());
} /* create() */
