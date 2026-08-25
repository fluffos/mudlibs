#include "udp.h"
#include "term.h"
/*
 * Someone has asked us for a remote who...
 * Lets oblige them.
 */

mapping junk;

string fix_string(string str) {
  int i;
  string *bits;
  string ret;

  if (!junk) {
    junk = TERM_HANDLER->set_term_type("dumb");
    junk["RESET"] = "";
  }
  ret = "";
  bits = explode(str, "%^");
  for (i=0;i<sizeof(bits);i++)
    if (stringp(junk[bits[i]]))
      ret += junk[bits[i]];
    else
      ret += bits[i];
  return ret;
} /* fix_string() */

void incoming_request(mapping info) {
  string str;
  int i;
  object *cre, *play, *all;

  if (stringp(info["NAME"]) && stringp(info["PORTUDP"])) {
    if (info["NAME"] == mud_name())
      return ;
    if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
      PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
    if (info["FULL"])
      str = "/global/player"->who_string(75);
    else {
      all = users();
      cre = play = ({ });
      for (i=0;i<sizeof(all);i++)
        if (!all[i]->query_invis() && (string)all[i]->short() && (string)all[i]->query_name() != "logon")
          if (all[i]->query_creator())
            cre += ({ all[i] });
          else
            play += ({ all[i] });
      if (!sizeof(cre) && !sizeof(play))
        str = "There is no one at all on "+mud_name()+", I am depressed "+
              "are you depressed?\n";
      else if (!sizeof(cre))
        str = "There are only players on "+mud_name()+".\n"+
              sprintf("They are: %-=70s\n", query_multiple_short(play)+".");
      else if (!sizeof(play))
        str = "There are only creators on "+mud_name()+".\n"+
              sprintf("They are: %-=70s\n", query_multiple_short(cre)+".");
     else
        str = "There are people playing "+mud_name()+", in fact "+
              (sizeof(cre)+sizeof(play))+" of them.\n"+
              sprintf("These are the creators: %-=50s\n",
                      query_multiple_short(cre)+".")+
              sprintf("These are the players: %-=52s\n",
                       query_multiple_short(play)+".");
    }
    NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                            "@@@"+UDP_RWHO_A+
                            "||NAME:"+mud_name()+
                            "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                            "||RWHO:"+(info["DISCWORLD"]?str:fix_string(str))+
                            "||ASKWIZ:"+info["ASKWIZ"]+
                            "@@@\n");
  }
} /* incoming_request() */

void send_rwho_q(string mud) {
  mapping info;
  string askwiz;

  askwiz = this_player()->query_name();
  info = NAMESERVER_CD->query_mud_info(mud);
  if (!info)
    return ;
  NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
                          "@@@"+UDP_RWHO_Q+
                          "||NAME:"+mud_name()+
                          "||PORTUDP:"+NAMESERVER_CD->query_my_port()+
                          "||ASKWIZ:"+askwiz+
                          "||@@@\n");
} /* send_rwho_q() */

void create() {
  seteuid(getuid());
} /* create() */
