#include <std.h>
#include <flags.h>
#include <daemons.h>
#include <security.h>

#define FAIL(s) return notify_fail(s+"\n")

#define MIN_MATURE_LEVEL 5

inherit DAEMON;

void getpass(string str);

void help() {
  message("help",
    "Syntax: <mature on|off>\n\n"
    "The mature line is a global, uncensored channel where "
    "vulgarity is allowed. Racial slurs, extreme lewdness, "
    "and any specific targetting of other players with extreme "
    "vulgarity is still not allowed.\n"
    "You must be at least level "+MIN_MATURE_LEVEL+" to use the "
    "mature line.\n"
    "After entering <mature on> you will be prompted to enter "
    "your password. Then you will have to log out and back in "
    "to use the line.",
    this_player() );
}

int cmd_mature(string str) {
  object tp = this_player();
  int mat = (int)tp->query_property("mature channel");

  if (tp->query_level() < MIN_MATURE_LEVEL && !mat)
    FAIL("You must be at least level "+MIN_MATURE_LEVEL+
         " to use the mature line.");

  if (!str || str == "")
    return CHAT_D->do_chat("mature", 0);

  if (str == "off") {
    if (!mat)
      FAIL("You have not enabled the mature line.");

    tp->remove_property("mature channel");
    CHAT_D->remove_user( ({ "mature" }), tp);
    message("info", "Mature line disabled.", tp);
    return 1;
  }

  if (str == "on") {
    if (mat)
      FAIL("You have already enabled the mature line.");

    message("info", "\nPlease enter your password to enable the mature line: ", tp);
    input_to("getpass", I_NOECHO | I_NOESC);
    return 1;
  }

  else return CHAT_D->do_chat("mature", str);

  return 1;
}

void getpass(string str) {
  object tp = this_player();
  string pass;
  
  seteuid(UID_USERACCESS);
  pass = tp->query_password();
  seteuid(getuid());

  if (crypt(str, pass) != pass && oldcrypt(str, pass) != pass) {
    message("info", "Incorrect password.", tp);
    return;
  }


  tp->set_property("mature channel", 1);

  if (wizardp(tp)) {
    CHAT_D->add_user( ({ "mature" }), tp);
    message("info", "Mature line enabled.", tp);
  }
  else
    message("info", "Mature line enabled.\n"
                    "Please log out and back in to access it.", tp);

}

