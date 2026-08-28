//    Command for reincarnating players...useful for re-openings, etc.
//    Allows players to advance levels whenever they want, so they don't
//    get waxed by fast development costs!
//
//    DarkeLIB 1.0
//    -Diewarzau 1/15/96
#include <std.h>
#include <security.h>
#include <daemons.h>

int cmd_reincarnate(string str) {
  object who, join_room, *inv;
  int lev, extra_dev, i;
  string *langs;

  if(!(who = find_player(lower_case(str)))) {
    write("Can't find '"+str+"'.");
    return 1;
  }
  if(wizardp(who)) {
    write("You can't reincarnate a wizard.");
    return 1;
  }
  who->set_property("reincarnate", 1);
  who->set_property("xp mod", 0);
  lev = (int)who->query_level() / 2;
  if(lev < 1) lev = 1;
//  extra_dev = lev * 70;
  who->remove_property("luck");
  who->remove_property("limb regen");
  who->remove_property("ambidextry");
  who->remove_property("flying");
  who->remove_property("natural ac");
  who->remove_property("extra hbeat");
  who->remove_property("extra hp regen");
  who->remove_property("extra mp regen");
  who->remove_property("sp points");
  who->remove_property("sp skills");
  who->remove_property("sp spells");
  who->reset_quests();

  inv = filter_array(all_inventory(who), (: call_other :),
    "query_auto_load");
  if(inv && sizeof(inv))
    map_array(inv, (: call_other :), "remove");
  who->set_property("old exp", (int)ADVANCE_D->get_exp(lev) + 150);
  who->set_level(1);
//  who->set_property("dev points", extra_dev);
  who->add_exp(-1 * (int)who->query_exp());
  who->reset_max_exp();
  who->move_player("/d/standard/setter", 0);
  log_file("reincarnate", sprintf("%s gave a lvl/2 reinc to %s on %s.\n", (string)previous_object()->query_name(), who->query_name(), ctime(time())));
  message("info", "%^CYAN%^%^BOLD%^You have been reincarnated!",who);
  message("info",
  "\n     You may re-create your character now. All of your former exp has been transferred "
  "into a 'exp bank,' and you may access it by typing 'advance'.  That "
  "will advance your level by 1 each time you type it, until you "
  "are out of exp.  If you advance your level naturally, you will "
  "forfeit ALL REMAINING EXP in the bank!", who);
  write((string)who->query_cap_name() + " has been reincarnated.");
  who->reset_max_exp();
  return 1;
}

int help() {
  write(
  "Usage: reincarnate 'player'\n"
  "Starts a player over with a lvl/2 penality.");
  return 1;
}


