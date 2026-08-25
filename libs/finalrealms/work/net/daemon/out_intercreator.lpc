#include "intercreator.h"
#include "inet.h"
#include "udp.h"

void create()
{
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
}

void do_intercreator(string str, int emoted) {
  string bing, start;

  if (!interactive(previous_object()))
    return ;
/*
 * Ok, scrap this, making the intercreator channel cd compatible
  INETD->datagram_message("intercserver", INTERCREATOR_SERVER,
                          MUD_NAME+" "+
                          previous_object()->query_cap_name()+" "+str);
 */
  event(users(), "inter_creator_tell", mud_name(),
                 previous_object()->query_cap_name(), str,
                 previous_object(), emoted);
  (UDP_PATH+"gwizmsg")->send_gwizmsg(str, emoted);
} /* do_intercreator() */
