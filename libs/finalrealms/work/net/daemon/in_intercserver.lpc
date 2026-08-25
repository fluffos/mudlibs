/*
 * This will be a udp channel...
 * We will only accept messages from certain sources.
 * Once we get a message we do a reverse lookup to see if they are
 * allowed to send messages to us.  If not, well.  We send them back
 * a intercreator message saying they are not allowed to do this.
 * We also don't send back intercreator messages to the person who
 * send it.
 * Ok.  There are also two types of intercreator server :)
 * The server server (this one) and the message handler.  It just
 * tells messages to everyone on, checking first to see if it came
 * from the server...
 */
#include "intercreator.h"
#include "inet.h"

string *allowed;

void create() {
  allowed = ({ "discworld", "bing", "nanvaent" });
} /* create() */

void read_callback(int fd, string mess, string addr) {
  string mud_name;

  sscanf(mess, "%s %s", mud_name, mess);
  NAMESERVER->lookup_mud(mud_name, "finish_lookup", ({ addr, mess }));
} /* read_callback() */

void finish_lookup(string name, string addr, mixed *args) {
  string j_addr1, j_addr2, *blue;
  int i;

  if (!addr) {
    return ;
  }
/* First lets see if the mud is who they say they are... */
  sscanf(addr, "%s %s", j_addr1); 
  sscanf(args[0], "%s %s", j_addr2);
/* If they arent, ignore the message totaly. */
  if (j_addr1 != j_addr2) {
    return ;
  }
  if (member_array(name, allowed) == -1) {
    INETD->datagram_message("intercreator", name, MUD_NAME+":"+
            "intercreator_server@"+MUD_NAME+" says: You are "+
            "not allowed to send messages to this channel.\n");
    return ;
  }
/* They are allowed! */
  blue = allowed - ({ name, MUD_NAME });
  for (i=0;i<sizeof(blue);i++)
    INETD->datagram_message("intercreator", blue[i], name+" "+args[1]);
  if (name != MUD_NAME && member_array(MUD_NAME, allowed) != -1) {
    IN_CREATOR->finish_lookup(MUD_NAME, 0, ({ "", name+" "+args[1] }), 1);
  }
} /* finish_revese() */
