
#include <std.h>

inherit SENSE_CMD;

int cmd_listen(string str) {
  string name, what;
  set_sense("listen");
  set_verb("listen to");
  set_msg_failenvdef("You hear nothing unusual.");
  set_msg_failenv("You don't hear that here.");
  set_msg_failobdef("There is nothing on $O to hear.");
  set_msg_failob("You don't hear that on $O.");
  set_msg_totgt("$N listens to you.");
  set_msg_toenvdef("$N listens intently.");
  set_msg_toenv("$N listens to $I.");
  set_msg_toenvown("$N listens to $P $R.");
  set_msg_toenvob("$N listens to $O.");
  if (str && str[0..2] == "to ")
    str = str[3..<1];
  if (str && sscanf(str, "%s about %s", name, what) == 2)
    str = what + " from " + name;
  return ::cmd(str);
}

void help() {
  string s = implode(Separators, "|"); // this is from SENSE_CMD
  message("help",
    "Syntax: listen\n"
    "        listen to [what]\n"
    "        listen to [object]\n"
    "        listen to [person]\n"
    "        listen to [person] about [what]\n"
    "        listen to [what] ("+s+") [object]\n"
    "        listen to [what] ("+s+") [person]\n"
    "        listen to [person]'s [object]\n\n"
    "Allows you to listen to things you encounter.",
    this_player() );
}

