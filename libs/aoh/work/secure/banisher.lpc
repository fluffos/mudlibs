/* an object to banish playernames, to avoid conflicts with monsters */
/* we need this separate object to avoid problems with uids */

#include <secure/wizlevels.h>
#include <secure/config.h>

#define ME this_object()
#define PL this_player()
#define TI this_interactive()

/* Variables of the secure save file */
string name;
string password;
int level;
string *domains;
string shell;
string banished_by;
string reason;
int promotion_age;

int banish(string who, string why, string really) {
  if (!IS_WIZARD(TI))
    return notify_fail("You are not authorised!\n");
  if (!who)
    return notify_fail("Banish who?\n");
  if (!({int})"/secure/login"->ValidName(who))
    return notify_fail("Illegal name.\n");
  seteuid(getuid(ME));
  if (restore_object("secure/save/"+who[0..0]+"/" + who)) {
    if (!IS_WIZARD(TI) || !really)
      return notify_fail("That name is already used.\n");
    write("WARNING: That name is already in use by a player!\n");
  }
  if (restore_object("secure/banish/" + who))
    return notify_fail("That name is already banished.\n");
  log_file("BANISH", who+" by "+({string})TI->QueryRealName()+" because "+why+"\n");
  banished_by = ({string})TI->QueryRealName();
  reason = why;
  save_object("secure/banish/" + who);
  write("OK.\n");
  return 1;
}

int conserve(string who, string why) {
  if (!IS_WIZARD(TI))
    return notify_fail("You are not authorised!\n");
  if (!who)
    return notify_fail("Conserve Who?\n");
  if (!({int})"/secure/login"->ValidName(who))
    return notify_fail("Illegal name.\n");
  seteuid(getuid(ME));
  if (!restore_object("save/"+who[0..0]+"/" + who))
    return notify_fail("That name is not used.\n");
  if (file_size("secure/mummy/" + who) != -1
      || file_size("secure/mummy/"+who+".o") != -1
     ) {
    return notify_fail("That name is already conserved.\n");
  }
  log_file("MUMMY", who+" by "+({string})TI->QueryRealName()+" because "+why+"\n");
  banished_by = ({string})TI->QueryRealName();
  reason = why;
  save_object("secure/mummy/" + who);
  write("OK.\n");
  return 1;
}

