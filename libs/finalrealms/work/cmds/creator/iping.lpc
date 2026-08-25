/* iping.c
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
  string host, port;

  if (!str || sscanf(str, "%s %s", host, port) != 2) {
    notify_fail("Syntax: ping <host> <port>\n");
    return 0;
  }
  (UDP_PATH+"ping_q")->send_ping_q(host, port);
  write("Off goes the ping, long live the ping!\n");
  return 1;
} /* do_ping() */

