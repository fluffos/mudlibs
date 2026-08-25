inherit "/net/inherit/telnet";
inherit "/std/object";
#include <socket.h>

#define DISCONNECTED "telnet"
#define CONNECTED "telnet (whirring)"

void create() {
  telnet::create();
  object::create();
} /* create() */

void setup() {
  set_name("telnet");
  set_short(DISCONNECTED);
  set_long("Its a boring thingy.  You can probaly 'connect' to somewhere.\n");
  set_verbosity(0);
} /* setup() */

void handler(string event) {
  switch (event) {
    case "open" :
      set_short(CONNECTED);
      tell_object(environment(this_object()),
        "The telnet whirs and gleams.\n");
      break;
    case "close" :
      tell_object(environment(this_object()),
        "The telnet's colour fades and it stops glowing.\n");
      set_short(DISCONNECTED);
      break;
    default:
      break;
  }
} /* handler() */

int do_connect(string str) {
  if (query_connected()
      || !"/secure/master"->high_programmer(previous_object()->query_name())
      || !interactive(previous_object())) {
    return 0;
  }
/*
  say((string)this_player()->query_cap_name() + " opens "
    + this_player()->query_possessive() + " dictionary.\n");
 */
  return telnet::connect(str);
} /* do_connect() */

int do_close() {
  if (!query_connected()) {
    return 0;
  }
/*
  if (this_player())
    say((string)this_player()->query_cap_name() + " closes "
      + this_player()->query_possessive() + " dictionary.\n");
 */
  return telnet::disconnect();
} /* do_close() */

int do_send(string arg) {
  int result;

  if (!query_connected()) {
    notify_fail("The dictionary isn't open!\n");
    return 0;
  }
  telnet::send(arg);
  return 1;
} /* do_send() */

void init() {
  add_action("do_connect", "connect");
  add_action("do_close", "close");
  add_action("do_send", "send");
} /* init() */

void receive_message(string str) {
  tell_object(environment(), replace(str, ({ "\r", "", "\n", "\n*" })));
} /* receive_message() */
