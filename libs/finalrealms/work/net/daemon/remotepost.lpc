#include <mail.h> 
#include <udp.h>

#define SAVE_MAILQUEUE "/net/save/remotepost"
 
private mapping __MailQueue; 
nosave private mapping __IncomingMail; 
 
protected private void save_mailqueue();
protected private void restore_mailqueue();
protected private string *local_targets(string *str);
protected private string *convert_names(string *noms);

#undef DEBUG

#ifdef DEBUG

#define DB_PER "pinkfish"

#define TP(MSG) if (find_player(DB_PER)) tell_object(find_player(DB_PER), MSG)
#else
#define TP(MSG)
#endif

void create() { 
    string *muds; 
    int i; 
 
    seteuid(getuid()); 
    __MailQueue = ([]); 
    __IncomingMail = ([]); 
/*
    seteuid(UID_SECURE_DAEMONSAVE);
    if (file_exists(SAVE_MAILQUEUE+".o"))
 */
      restore_mailqueue(); 
/*
    seteuid(getuid());
 */
    i = sizeof(muds = keys(__MailQueue)); 
    while(i--)
      __MailQueue[muds[i]][0]["in transit"] = 0; 
}  /* create() */
 
string postal_check(string mud) { 
    if (file_name(previous_object()) != (UDP_PATH+"ping_q")
        && file_name(previous_object()) != (UDP_PATH+"mail_a")) {
TP(sprintf("GErbil %O\n", previous_object()));
      return 0;
    }
    if (!__MailQueue[mud = replace_string(lower_case(mud), " ", ".")]) {
TP(sprintf("Nothing for "+mud+" %O\n", previous_object()));
      return 0;
    }
    if(__MailQueue[mud][0]["in transit"]) {
TP("Already in transit to mud "+mud+"\n");
      return 0; 
    }
TP("Ok, got mail for "+mud+"\n");
    __MailQueue[mud][0]["in transit"] = 1; 
    return __MailQueue[mud][0]["post"][0]; 
}  /* postal_check() */
 
string next_post(string mud) { 
    int x; 
 
    if (file_name(previous_object()) != (UDP_PATH+"mail_a")) {
TP("Invlid object called next_post.\n");
      return 0;
    }
    if (!__MailQueue[mud = replace_string(lower_case(mud), " ", ".")]) {
      return 0;
TP("No mud to do a next post on.\n");
    }
TP("Got a valid reply from "+mud+"\n");
    x = __MailQueue[mud][0]["in transit"]++; 
    if (sizeof(__MailQueue[mud][0]["post"]) == x) { 
/* Sent it.  Delete it from the pending array */
        __MailQueue[mud] = __MailQueue[mud][1..10000];
        if (!sizeof(__MailQueue[mud] = (mixed *)__MailQueue[mud] - ({ 0 }) ))  
          map_delete(__MailQueue, mud); 
        save_mailqueue(); 
        return 0; 
      }
TP("Returning something wonderful.\n");
    return __MailQueue[mud][0]["post"][x]; 
}  /* next_post() */
 
string resend_post(string mud) { 
    if (file_name(previous_object()) != (UDP_PATH+"mail_a"))
      return 0;
    if (!__MailQueue[mud = replace_string(lower_case(mud), " ", ".")])
      return 0;
    __MailQueue[mud][0]["in transit"] = 1; 
    return __MailQueue[mud][0]["post"][0]; 
} /* resend_post() */
 
void add_post(string mud, string *targs, mapping borg) {
    string *msg, *tmp;
    int i, maxi, x, y;
 
    if (file_name(previous_object()) != "/net/daemon/out_mail")
      return 0;
    borg["to"] = convert_names(explode(borg["to"], ","));
    borg["cc"] = explode(borg["cc"], ",");
    if (!borg["cc"])
      borg["cc"] = ({ });
    else
      borg["cc"] = convert_names((string *)borg["cc"] - ({ 0 }));
    borg["from"] = sprintf("%s@%s", borg["from"], mud_name());
    tmp = ({ sprintf("||WIZTO:%s||WIZFROM:%s%s||SUBJECT:%s||DATE:%d||MSG:",
      implode(borg["to"], ","), borg["from"],
      (sizeof(borg["cc"]) ? implode(borg["cc"], ",") : ""), borg["subject"],
      time()) });
    msg = explode(borg["message"], "\n");
    for (i=0, maxi = sizeof(msg); i<maxi; i++) {
        if ((y=strlen(tmp[x])) > 200) {
            x++;
            tmp += ({ "||MSG:" });
	  }
        tmp[x] += sprintf("%s\n", msg[i]);
      }
    tmp[x] += "||ENDMSG:1";
    if (!__MailQueue[mud])
      __MailQueue[mud] = ({ ([ "in transit": 0, "post": tmp ]) });
    else
      __MailQueue[mud] += ({ ([ "in transit": 0, "post": tmp ]) });
/*
    SERVICES_D->new_mail(mud);
 */
    save_mailqueue(); 
} /* add_post() */
     
int incoming_post(mapping info) { 
    mapping borg; 
 
    if (file_name(previous_object()) != (UDP_PATH+"mail_q")) {
TP("Failed incoming...\n");
      return 0;
    }
TP("Incoming.\n");
    info["NAME"] = replace_string(lower_case(info["NAME"]), " ", ".");
    if (info["WIZTO"])
      __IncomingMail[info["NAME"]] = info; 
    else { 
        if (!__IncomingMail[info["NAME"]])
          return 0; 
        else
          __IncomingMail[info["NAME"]]["MSG"] += info["MSG"]; 
      } 
    borg = ([]);
    if (info["ENDMSG"]) { 
        borg["to"] = __IncomingMail[info["NAME"]]["WIZTO"]; 
        borg["cc"] = __IncomingMail[info["NAME"]]["CC"]; 
        borg["from"] = __IncomingMail[info["NAME"]]["WIZFROM"]; 
        borg["subject"] = __IncomingMail[info["NAME"]]["SUBJECT"]; 
        borg["message"] = __IncomingMail[info["NAME"]]["MSG"]; 
        borg["date"] = __IncomingMail[info["NAME"]]["DATE"]; 
	MAILER->do_mail_message(borg["to"], borg["from"],
				borg["subject"], borg["cc"],
				borg["message"]);
/*
        LOCALPOST_D->add_post(local_targets(distinct_array(borg["to"] +
          borg["cc"])), copy(borg));
        seteuid(getuid()); 
 */
        map_delete(__IncomingMail, info["NAME"]); 
      } 
    return 1; 
} /* incoming_post() */
 
protected private string *local_targets(string *str) {
    string a, b; 
    int i;
 
    i = sizeof(str);
    while (i--) {
        sscanf(str[i], "%s@%s", a, b);
        if (replace_string(lower_case(b), " ", ".") == 
            replace_string(lower_case(mud_name()), " ", "."))
          str[i] = a;
    }
    return str;
}  /* local_targets() */
 
protected private void save_mailqueue() { 
    save_object(SAVE_MAILQUEUE); 
} /* save_mailqueue() */
 
protected private void restore_mailqueue() { 
    restore_object(SAVE_MAILQUEUE); 
} /* restore_mailqueue() */
         
protected private string *convert_names(string *noms) {
    string a, b;
    int i;

    i = sizeof(noms);
    while (i--) {
        if (sscanf(noms[i], "%s@%s", a, b) != 2)
          noms[i] = sprintf("%s@%s", noms[i], mud_name());
    }
    return noms;
} /* convert_names() */

mapping query_mail_queue() {
  return __MailQueue;
} /* query_mail_queue() */
