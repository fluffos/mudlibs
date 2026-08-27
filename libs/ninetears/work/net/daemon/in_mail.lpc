/*
 * Intermud mail server, used by Huthar's mailer daemon
 * Original author: Huthar
 * Rewritten to conform to new socket efun specs,  Blackthorn (10/31/92)
 * Modified by Truilkan for use in Basis mudlib (11/01/92)
 * Modified by Pinkfish for use in the Discworld mudlib (5 jan 92)
 * (Stupid american date formats).
 */

#include "mail.h"
#include "nameserver.h"
#include "inet.h"
#define SAVE "/net/save/"
 
#define report(x) log_file("MAIL",ctime(time())+" "+x+"\n")
#define log(x) log_file("MS", x)
#define MS_SAVE "mail-queue"
#define FLUSH_TIME 86400
#define AGE_TIME 604800
#define EOF "%EOF%"
#define EOT "%EOT%"

#define DEBUG 1
/*
#undef DEBUG
*/

#ifdef DEBUG
#define TP(STR) tell_object(find_player("tester"), STR)
#else
#define TP(STR)
#endif
 
nosave string upd;
nosave mapping new_mail_queue, sockets;
nosave string receiver, from, to, subject, message,cc;
nosave int date;
nosave string mud;
nosave mixed mqi;
nosave mixed outgoing;
 
mixed mail_queue;
int date_last_flushed;
 
void process_message(int fd);
void flush_mail_queue();
void age_queue();
void bad_port(string mud, string from, string message);
 
void create() {
  seteuid((string)"/secure/master"->creator_file(this_object()));
  sockets = ([ ]);
} /* create() */

/*
 * This adds on the lmud and lname bit if it is not in name@address
 * format.
 */
string convert_name(string lname, string lmud) {
  string tmp, tmpaddr;
 
  if (sscanf(lname, "%s@%s", tmp, tmpaddr) != 2) {
    tmp = lname;
    tmpaddr = lmud;
  }

/*
 * this doe not handle aliases for the same mud at the moment.  I
 * will add in some new code here real soon now.  Maybe...
 */ 
  if (tmpaddr != MUD_NAME) return tmp + "@" + tmpaddr;
  return tmp;
} /* convert_name() */

void dest_me() {
  destruct(this_object()); 
} /* dest_me() */
 
void close_callback(int id) {
  TP("IN_MAIL: Doing close. Id:"+id+"\n");
  process_message(id);
  map_delete(sockets, id);
  return;
} /* close_callback() */
 
void connected(int id) {
  sockets[id] = ([ "msg" : "" ]);
} /* connected() */
 
void read_callback(int id, string data) {
  string str1, str2;

/* Hmm.  I dont think we actually nedd this here...
  if (sscanf(data, "%s"+EOF+"%s", str1, str2) == 2) {
    sockets[id]["msg"] += data;
    process_message(id);
    return;
  }
 */
  TP("IN_MAIL: data:"+data+"\n");
  sockets[id]["msg"] += data;
} /* read_callback() */
 
void process_message(int id) {
  mixed tmp, tmp2;
  string *totmp, *cctmp;
  int i, j, res;

  TP("IN_MAIL: "+sprintf("%O\n", sockets[id]["msg"])); 
  sscanf(sockets[id]["msg"], "%s\n%s", mud, tmp);
  sockets[id]["msg"] = tmp;
  TP("IN_MAIL: Processing message, mud name "+mud+"\n");
 
  tmp = explode(sockets[id]["msg"], EOF);
  tmp = tmp[0..sizeof(tmp)-2];
  /*
  Isthar 20-aug-1993

  For some rare reason, big files have no EOF mark a end
  (we can put it)
  */
  if (sizeof(tmp)==0) {
    sockets[id]["msg"]=sockets[id]["msg"]+"\n"+EOF+"\n"+EOT;
    tmp = explode(sockets[id]["msg"], EOF);
    tmp = tmp[0..sizeof(tmp)-2];
  }
  tmp2 = allocate(sizeof(tmp));

  TP("IN_MAIL: Number of messages "+sizeof(tmp)+"\n"); 
  for (i = 0; i < sizeof(tmp); i++) {
    tmp2[i] = explode(tmp[i], "\n");
  }
  for (i = 0; i < sizeof(tmp2); i++) {
    receiver = convert_name(tmp2[i][0], MUD_NAME);
    totmp = explode(tmp2[i][1], " ");
    for (j = 0; j < sizeof(totmp); j++)
      totmp[j] = convert_name(totmp[j], mud);
    cctmp = explode(tmp2[i][2], " ");
    if (cctmp[0])
      for (j = 0; j < sizeof(cctmp); j++)
        cctmp[j] = convert_name(cctmp[j], mud);
    else
      cctmp = ({ });
    from = convert_name(tmp2[i][3], mud);
    subject = tmp2[i][4];
    sscanf(tmp2[i][5], "%d", date);
    TP("IN_MAIL: To: "+receiver+"*\n");
    TP("IN_MAIL: From: "+from+"*\n");
    TP("IN_MAIL: Cc: "+tmp2[i][2]+"*\n");
    TP("IN_MAIL: Subject: "+subject+"*\n");
    report("R "+from+" "+receiver);
    message = implode(tmp2[i][6..sizeof(tmp2[i]) - 1], "\n");
/*
 * Ok...  IN here we need to do a call out to check the validity
 * of the mud this is comming from.
 *
 */
    NAME_D->lookup_mud(mud, "got_address", ({ socket_address(id),
                                              receiver, totmp, cctmp,
                                              from, subject, date,
                                              message }));
  }
} /* process_message() */

void mail_postmaster(string from, string subject, mixed *args) {
  MAILER->do_mail_message("postmaster", from, subject,
                       0, ">From: "+args[4]+"\nTo: "+
                       implode(args[2], ", ")+"\nCc: "+
                       implode(args[3], ", ")+"\nSubject: "+
                       args[5]+"\nDate: "+ctime(args[6])+
                       "\n"+args[7], 1);
} /* mail_postmaster() */

void got_address(string host, string addr, mixed *args) {
  object ob;
  string *to, name, name2;
  int port;
  TP("IN_MAIL: "+host+" "+addr+"\n");

  if (!addr) {
/* Unknown mud just tried to mail us... */
/*
 * Now, what exactly should I do about it?  Mail it to the postmaster?
 * Yeah, sounds good to me...
 */
    TP("IN_MAIL: From unknown mud\n");
    mail_postmaster(args[4], "From unknown mud", args);
/* Don't bother returning it to them. */
    return ;
  }
  sscanf(addr, "%s %d", name, port);
  sscanf(args[0], "%s %d", name2, port);
  if (!name || !name2) {
    TP("IN_MAIL: Strange error\n");
    mail_postmaster(args[4], "Strange error", args);
    return ;
  }
  if (name != name2) {
    mail_postmaster(args[4], "Forged mail", args);
    return ;
  }
/* Ok, its right.  Now deliver it... */
  report("D "+args[4]+" "+implode(args[2],","));
  MAILER->do_mail_message(implode(args[2], ","), args[4], args[5],
                       implode(args[3], ","), args[7], 0, args[1]);
} /* got_address() */
