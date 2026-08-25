/*
   //
   //  File    :  mail_q.c
   //  Author  :  Inspiral@Tabor
   //  Created :  93-12-20
   //  Purpose :  Handles the receipt/transmission of udp mail messages
   //
   //  Modified to be used with DW mudlib by Turrican 18-1-95
   //  Cleaned up somewhat by Turrican 14-6-95
*/

#include <mail.h>
#include <udp.h>

#undef DEBUG

#ifdef DEBUG
#define WHO	find_player("turrican")
#define TELL(x) if (WHO) tell_object(WHO, x + "\n")
#else
#define TELL(x)
#endif

#define MAIL_PACKET_SIZE 512

/*
// keys: mudname
// values: int representing the index of the msg we are on.
*/
mapping mail_outgoing;

/*
// keys: mudname
// values: the fields in the mail message...WIZTO, CC, MSG, etc.
*/
mapping mail_incoming;

create() {
  seteuid(getuid());
  mail_outgoing = ([ ]);
  mail_incoming = ([ ]);
}


string strip_backspace(string str) {
  mixed str_arr;
  int i;

  if (!stringp(str) || !(i = strlen(str)))
    return str;
  str_arr = allocate(i);
  while(i--) {
    if (i < 0)
      break;
    if (str[i] == '\b') {
      i--;
      continue;
    }
  str_arr[i] = str[i..i];
  }
  str_arr -= ({ 0 });
  str = implode(str_arr, "");
  return str;
}

#undef SECURE_FUNCTIONS

mixed copy(mixed var) {
  if (mapp(var)) {
    mapping res;
    mixed * index;
    int     i;

    res = var + ([ ]);
    i = sizeof(index = keys(var));
    while(i-- > 0)
#ifdef SECURE_FUNCTIONS
      if (pointerp(res[index[i]]) || mapp(res[index[i]]) 
          || functionp(res[index[i]]))
#else
      if (pointerp(res[index[i]]) || mapp(res[index[i]]))
#endif
	res[index[i]] = copy(var[index[i]]);
    return res;
  }
  else
    if (pointerp(var))
      return map_array(var, "copy", this_object());
#ifdef SECURE_FUNCTIONS
    else
      if (functionp(var))
        return(:(function)var[0], (function)var[1]:);
#endif
  return var;
}

/* We're sent here by mail_a or ping_a */
varargs void check_for_mail(string mudname, int flag) {
  mapping outmsg, info;
  string  package;
  int     index, size;

  mudname = replace(mudname, " ", ".");
  outmsg = ([ ]);
  outmsg = (mapping)NETMAIL_D->check_for_mail(mudname);

  switch(flag)
  {
    case 3:
      /*
      // A ping_a calls this, as does the netmail server.
      // It simply means: start sending if there's anything to send,
      // or continue with the current message we are sending.
      */
      if (!mail_outgoing[mudname]) {
        /*
	// We will have something to send to this mud, and currently,
	// there is nothing in our mail_q outgoing buffer.  So, we 
	// properly initialize it.
        */
        mail_outgoing[mudname] = ([ ]);
      }
      if (!sizeof(outmsg)) {
	map_delete(mail_outgoing, mudname);
	break;
      }
      /*
      // If more than 5 minutes have passed since the last time we've
      // sent to this mud, start over, since something on one or both ends
      // could be out of sync.
      */
      if (time() - mail_outgoing[mudname]["time"] > 300)
        mail_outgoing[mudname] = (["time" : time(), "index" : 0]);
      else
	return;
      /*
      // Do nothing, since it came from a ping while we are sending.
      */
      break;
    case 2:
    case 1:
      /*
      // case 1 is when the other mud wants us to resend the current
      // message, case 2 is when they want us to send our next message,
      // if we have one.
      */
      if (!sizeof(outmsg)) {
        /*
        // Nothing to be sent out now, so clear the status.
	// We shouldn't get here from case 1, only case 2.
        */
	map_delete(mail_outgoing, mudname);
	break;
      }
      /*
      // Reset the index and time;
      */
      mail_outgoing[mudname] = (["time" : time(), "index" : 0]);
      break;
    case 0:
      /*
      // We get 0 from mail_a, so we continue sending the current message.
      */
      mail_outgoing[mudname]["time"] = time();
      mail_outgoing[mudname]["index"] += MAIL_PACKET_SIZE;
      break;
  }
  /*
  // One last check on our stack for this mud, before we send data.
  */
  if (!sizeof(outmsg) || !mail_outgoing[mudname])
    return;
  info = (mapping)NAMESERVER_CD->query_mud_info(mudname);
  if (!info || !info["NAME"] || !info["PORTUDP"])
    return;
  TELL("MAILQ: Sending to " + mudname);
  outmsg["MSG"] = replace_string(outmsg["MSG"], "|", " \b|");
  outmsg["MSG"] = replace_string(outmsg["MSG"], "@", " \b@");
  TELL("message size: " + strlen(outmsg["MSG"]));
  package =
	"@@@" + UDP_MAIL_Q +
	"||NAME:" + mud_name() +
	"||PORTUDP:" + NAMESERVER_CD->query_my_port();
  if (!mail_outgoing[mudname]["index"]) {
    package +=
          "||WIZTO:" + outmsg["WIZTO"] +
	  "||DATE:" + outmsg["DATE"] +
	  "||WIZFROM:" + outmsg["WIZFROM"] +
	  "||SUBJECT:" + outmsg["SUBJECT"];
    if (outmsg["CC"])
      package += "||CC:" + outmsg["CC"];
  }
  index = mail_outgoing[mudname]["index"];
  size = strlen(outmsg["MSG"]);
  if (size <= MAIL_PACKET_SIZE || ((index - 1) + MAIL_PACKET_SIZE) >= size) {
    TELL("Sending ENDMSG:1.");
    package += "||ENDMSG:1";
  }
  TELL("MAILQ: Sending: " + (index) + ".." + ((index - 1) + MAIL_PACKET_SIZE));
  package += "||MSG:" + outmsg["MSG"][(index)..((index - 1) + MAIL_PACKET_SIZE)];
  package += "@@@\n";
  NAMESERVER_CD->send_udp(info["HOSTADDRESS"],
		          info["PORTUDP"],
			  package);
  return;
}

void incoming_request(mapping info) {
  string field;

  if (!info["NAME"] || !info["PORTUDP"])
    return;
  if (!NAMESERVER_CD->query_mud_info(info["NAME"]))
    PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
  /*
  // Here we put the info in something netmail can use.
  */
  if (info["CC"])
    info["CC"] = explode(info["CC"], ",");
  info["MSG"] = strip_backspace(info["MSG"]);
  if (info["WIZTO"]) {
    info["WIZTO"] = explode(info["WIZTO"], ",");
    /*
    // If they send us a WIZTO field, we assume (rightly) that this
    // is a new message, so we effectively set our buffer for this
    // particular mud with whatever we've been sent.
    */
    mail_incoming[info["NAME"]] = info;
  }
  else {
    /*
    // If we have no data in the incoming buffer for this mud, and
    // the mud didn't send us a WIZTO field, something must have gone
    // wrong, so we ask them to RESEND the message from the beginning.
    */
    if (!mail_incoming[info["NAME"]])
      info["RESEND"] = 1;
    else
      mail_incoming[info["NAME"]]["MSG"] += info["MSG"];
  }
  /*
  // Send them an affirmation that we receive the mail, and suitable
  // affirm also if they sent us an ENDMSG flag (which indicates that
  // we can process the message.
  // If we send RESEND:1, we are asking them to resend the message.
  */
  NAMESERVER_CD->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
		          "@@@" + UDP_MAIL_A + "||NAME:" + mud_name() +
			  "||PORTUDP:" + NAMESERVER_CD->query_my_port() +
			  (info["ENDMSG"] ? "||ENDMSG:1" : "") +
			  (info["RESEND"] ? "||RESEND:1" : "") +
			  "@@@\n");
  TELL("MAILQ: Sending mail_a " +
       (info["ENDMSG"] ? ", ENDMSG:1 " : "") +
       (info["RESEND"] ? ", RESEND:1" : "") + ".");
  if (info["ENDMSG"]) {
    /*
    // If we received an ENDMSG, then we are ready to process the contents
    // of our buffer.  So, we send off the packet, and clear the incoming
    // buffer for that mud.
    */
    TELL("MAILQ: Sending to netmail.");
    catch(NETMAIL_D->incoming_mail(copy(mail_incoming[info["NAME"]])));
    info = mail_incoming[info["NAME"]];
    info["WIZFROM"] = info["WIZFROM"][0..strsrch(info["WIZFROM"], '@') - 1];
    field = "Received mail for: " + implode(info["WIZTO"], ", ") + ".\n";
    catch((UDP_PATH+UDP_AFFIRMATION_A)->send_affirmation_a(info["HOSTADDRESS"],
						       info["PORTUDP"],
						       "POSTMASTER",
						       info["WIZFROM"],
						       field, "mail_q"));
    map_delete(mail_incoming, "NAME");
  }
}

void clear_queues() {
  mail_outgoing = ([ ]);
  mail_incoming = ([ ]);
}

/* EOF */
