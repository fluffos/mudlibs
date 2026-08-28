//   sets legend status

#include <security.h>

int cmd_setlegend(string str) {
  object who;
  string name;
  int amt;
  
  if(!archp(this_player())) return 0;
  name=str;
  who = find_player(lower_case(name));
  if(!who) {
    write("Could not find: "+name);
    return 1;
  }
  seteuid(UID_ROOT);
  who->set_property("legend", 1);
  seteuid(getuid());
  write("Ok.");
  message("shout", "%^BLUE%^%^BOLD%^The Demiurge Shouts:%^RESET%^ "+who->query_cap_name()+" has been promoted to Legendary Status!", users());
  return 1;
}

int help() {
  message("help",
  "This command is used promote players to legendary status.\n"+
  "Syntax: setlegend <player>", this_player());
  return 1;
}
