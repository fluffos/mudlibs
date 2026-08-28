// Reincarnation Daemon
#include <security.h>
#include <dirs.h>
#include <rooms.h>
#include <daemons.h>

int reinc_time;
int exp_cut;

void save_me();

void set_auto_reinc() {
  reinc_time = time();
  save_me();
  return;
}

void save_me() {
  seteuid(UID_DAEMONSAVE);
  save_object(DIR_DAEMONS_SAVE+ "/reincarnate");
  seteuid(getuid());
  return;
}

void set_exp_cut(int amt) {
  if(amt < 0) return;
  exp_cut = amt;
  save_me();
}

void create() {
  reinc_time = -1;
  exp_cut = 0;
  seteuid(UID_DAEMONSAVE);
  if(file_exists(DIR_DAEMONS_SAVE+ "/reincarnate.o"))
    restore_object(DIR_DAEMONS_SAVE+ "/reincarnate");
  seteuid(getuid());
  return;
}

void check_reincarnate(object who) {
  int i = 0;
  object *inv;

  if(wizardp(who)) return;
  who->remove_property("checked out");
  if(!who->query_level() || (int)who->query_level() <= 1) {
    who->set_property("last reinc", time());
    who->reset_max_exp();
    return;
  }
  if((int)who->query_birthday() > reinc_time)
    return;
  /*  Temp section */
  who->set_property("last reinc", time());
  return;
  /* end temp */
  i = (int)who->query_property("last reinc");
  if(!i) i = 0;
  if(i >= reinc_time)
    return;
  who->set_property("reincarnate", 1);
  who->init_spells();

  seteuid(UID_ROOT);
  who->reset_quests();
  seteuid(getuid());
  who->remove_property("UNPURE");
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
  inv = filter_array(all_inventory(who), (: call_other :),
    "query_auto_load");
  if(inv && sizeof(inv)) {
    i = sizeof(inv);
    while(i--)
      if(!inv[i]->id("clan symbol")) inv[i]->remove();
  }
  who->set_property("xp mod", 0);
  i = (int)who->query_exp();
  if(i < (int)ADVANCE_D->get_exp((int)who->query_level()))
    i = (int)ADVANCE_D->get_exp((int)who->query_level());
  i += 150;
  if(exp_cut) i -= (i*exp_cut)/100;
  who->set_property("old exp", i + (int)who->query_property("old exp"));
  who->set_level(1);
  who->add_exp(-1 * (int)who->query_exp());
  who->reset_max_exp();
  who->move(ROOM_SETTER);
  who->set_property("last reinc", time());
  who->set_property("reincarnate", 1);
  message("info", "%^CYAN%^%^BOLD%^You have been reincarnated!",who);
  message("info",
  "\n     You may re-create your character now.  All of your former exp has been transferred "
  "into a 'exp bank,' and you may access it by typing 'advance'.  That "
  "will advance your level by 1 each time you type it, until you "
  "are out of exp.  If you advance your level naturally, you will "
  "forfeit ALL REMAINING EXP in the bank!", who);
  return;
}

