#include <newudp.h>
#include <term.h>

mapping junk;

string fix_string(string str) {
  string ret, *bits;
  int i;

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

void udp_who(mapping data) {
  string str;
  int i;
  object *cre, *play, *all;

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
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
        DATA: fix_string(str),
    ]) );
} /* udp_who() */

void create() {
  seteuid(getuid());
} /* create() */
