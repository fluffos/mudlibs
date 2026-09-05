/*
 * DO NOT REMOVE THIS FILE IT IS NEEDED FOR
 * USING MUD EMOTES OVER GUILD CHANNELS.
 *
 * BEFORE ALTERING IT, YOU MUST CONTACT VERTEBRAKER.
 */
#include <ansi.h>


object * query_bcms() {
  int s;
  object *us, *peeps;
  peeps = ({ });
  s = sizeof(us = users());
  while(s --) {
    if(us[s] && present("dark_circle", us[s])) peeps += ({ us[s] });
  }
  return peeps;
}

void add_history(string str) {
  "/obj/user/chistory"->add_history("Circle", str);
}

string query_tag() {
  return YEL+"("+BOLD+"Circle"+NORM+YEL+")"+NORM;
}
