#include "defs.h"

string Lasttell; /* For 'retell' command */

int main(string arg) {

  string name, tc, who, msg, myname;
  int level, mylevel;
  object player;

  if (query_verb() == "retell" && Lasttell) {
    who = arg;
    arg = Lasttell;
    if (!who) {
      notify_fail("Usage: retell <player>\n");
      return 0;
    }
    if (!Lasttell) {
      notify_fail("You haven't sent a tell yet.\n");
      return 0;
    }
  }
  else
  if ((!arg) || sscanf(arg,"%s %s",who,arg) != 2) {
    write("Usage: tell <player> <message>\n");
    return 1;
  }

  Lasttell = arg;
  who = lower_case(who);
  player = find_living(who);

  if (!player) {
    write("Nobody logged on with that name.\n");
    return 1;
  }

  level = (int)player->query_level();
  if (!interactive(player)) {
    write("That recipient is not interactive.\n");
    return 1;
  }
  if (level >= 21 && player->query_tellblock()) {
    write("That person is blocking tells.\n");
    return 1;
  }
  if (this_player()->query_invis() && level < 20)
    myname = "(Earwax)";
  else
    myname = "Earwax";
  player->Replyer("earwax");
  player->add_tellhistory(myname+" tells you: "+arg);
  tc = (string)player->get_ansi_pref("tell");
  if (tc) 
    msg = tc + myname + " tells you: " + arg + NORM + "\n";
  else {
    tc = NORM;
    msg = HIK + myname + NORM + " tells you: " + arg + "\n";
  }

  tell_object(player,msg);
  write("You tell " + tc + capitalize(who) + NORM + ": "+arg+".\n");
  return 1;
}
