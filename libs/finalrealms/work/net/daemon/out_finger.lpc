#include "socket.h"
#include "inet.h"
#include "udp.h"

object pl;
string who;
int got_something;

void dest_me();

void create() {
  seteuid(getuid());
} /* create() */

int do_finger(string str) {
  string name, host;
  object ob;

  if (sscanf(str, "%s@%s", name, host) == 2) {
    lower_case(name);
/*
    if (name == "")
      name = "EVERYONE";
 */
    ob = clone_object(file_name(this_object()));
    ob->finger_away(name, host, this_player());
    return 1;
  }
/*
 * Should be a local finger...  no idea why they want to do that though.
 * shrug.
 */
  return 0;
} /* do_finger() */

void finger_away(string name, string host, object me) {
  who = name;
  pl = me;
  if (NAMESERVER_CD->query_mud_info(host)) {
/* Its a cd one...  finger them the cd way... */
    if (name == "")
      (UDP_PATH+"rwho_q")->send_rwho_q(host);
    else
      (UDP_PATH+"gfinger_q")->send_gfinger_q(host, name);
    dest_me();
    return ;
  }
  INETD->open_to_service("finger", INETD_TYPE, host, name+"\ndiscworld");
  call_out("dest_me", 5*60*60);
} /* finger_away() */

void read_callback(int fd, string mess) {
  got_something = 1;
  tell_object(pl, mess);
  pl->finger_callback(2, mess);
} /* read_callback() */

void connected(int fd) {
  if (who)
    previous_object()->write_fd(fd, who+"\n");
  else {
    previous_object()->write_fd(fd, "EVERYONE\n");
    previous_object()->write_fd(fd, "\n");
  }
  who = 0;
} /* write_callback() */

void close_callback() {
  if (!got_something)
    tell_object(pl, "Did not recieve anything in your intermud finger.\n");
  pl->finger_callback(0);
  dest_me();
} /* close_callback() */

void failed(string reason) {
  pl->finger_callback(1, reason);
  tell_object(pl, "We failed for "+reason+" reason.\n");
  dest_me();
} /* failed() */

void dest_me() {
  destruct(this_object());
} /* dest_me() */
