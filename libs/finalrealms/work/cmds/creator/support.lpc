/* support.c
 * Externalized by Baldrick jun '97
 */

#include <standard.h>
#include <cmd.h>
#include <udp.h>
#include <inet.h>
inherit CMD_BASE;

void setup(){

position = 1;
}
 
/*
 * Does a strange intermud ping thingy.
 */

protected int cmd(string str, object me) {
  string  mud, param, type;
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
