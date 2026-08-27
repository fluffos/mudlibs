#include <udp.h>
#include <inet.h>
 
void wiz_commands() {
  add_action("do_ping", "ping");
  add_action("do_support", "support");
} /* wiz_commands() */

/*	Comparison function for alphabetical sorting */
 
int compare(string one, string two) {  return strcmp(lower_case(one), lower_case(two));  }


/*
 * Does a strange intermud ping thingy.
 */
int do_ping(string str) {
  string host, port;

  if (!str || sscanf(str, "%s %s", host, port) != 2) {
    notify_fail("Syntax: ping <host> <port>\n");
    return 0;
  }
  (UDP_PATH+"ping_q")->send_ping_q(host, port);
  write("Off goes the ping, long live the ping!\n");
  return 1;
} /* do_ping() */

int do_support(string str) {
  string protocol, mud, param, type;
  mapping minfo;

  if (!str || sscanf(str, "%s %s", mud, type) != 2) {
    notify_fail("Syntax: support <mud> <type> [param]\n");
    return 0;
  }
  minfo = NAMESERVER_CD->query_mud_info(mud);
  if (!minfo) {
    notify_fail("No such mud "+mud+".\n");
    return 0;
  }
  sscanf(type, "%s %s", type, param);
  (UDP_PATH+"support_q")->send_support_q(minfo["HOSTADDRESS"], minfo["PORTUDP"],
                                        type, param);
  write("Off it wombles into the wild blue yonder.\n");
  return 1;
} /* do_support() */
