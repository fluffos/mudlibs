/*    /daemon/services/who.c
 *    from the Nightmare IV LPC Library
 *    handles the Intermud 3 who service
 *    created by Descartes of Borg 950623
 *    Modified for Discworld by Turrican 1-11-95
 */

#include "/net/intermud3/intermud_cfg.h"

#ifdef SERVICE_WHO

void eventReceiveWhoReply(mixed *packet) {
    string list = "";  mixed *who;
    string start;
    mapping positions = ([ ]);
    object ob;
    string thekey, thedata;

    if( file_name(previous_object()) != INTERMUD_D ) return;
    if( !packet[5] || !(ob = find_player(packet[5])) ) return;
      start = "\nRemote who information from " + packet[2] + ":\n";

    foreach(who in packet[6]) {
      if(!positions[who[2]])
        positions[who[2]] = "";

      if ((int)who[1] > 120)
        positions[who[2]] += "    " + who[0] + " (Idle " + 
                             ((int)who[1] / 60) + ")\n";
      else
        positions[who[2]] += "    " + who[0] + "\n";
    }

    foreach(thekey, thedata in positions)
      list += "  " + thekey + "s:\n" + sprintf("%-#*s\n", 
                      (ob->query_cols() - strlen(thekey) - 2), thedata);

    tell_object(ob, start + list);
}

string query_status(object ob) {
  string obtype;

  obtype = (string)ob->query_object_type();

  if(POSITIONS[obtype])
    return POSITIONS[obtype];
  else
    return "Unknown";
}

void eventReceiveWhoRequest(mixed *packet) {
    mixed *msg;

    if( file_name(previous_object()) != INTERMUD_D ) return;

    if(!sizeof(users())) {
      msg = ({ ({ "Nobody is logged on!", 0, "None" }) });
    }
    else {
      msg = map(filter(users(), (: (!(int)$1->query_invis()
#ifndef PLAYER_WHO
                                    && (int)$1->query_creator()
#endif
                                   ) :)),
                       (: ({ (string)$1->query_cap_name(), query_idle($1), 
                             query_status($1) }) :));

#ifndef PLAYER_WHO
      msg += ({ ({ (sizeof(users()) - sizeof(msg)) + "", 0, "Player" }) });
#endif

    }

    INTERMUD_D->eventWrite(({ "who-reply", 5, mud_name(), 0, packet[2],
			      packet[3], msg }));
}

void eventSendWhoRequest(string mud, string who) {
    INTERMUD_D->eventWrite(({ "who-req", 5, mud_name(), who, mud, 0 }));
}

#endif
