//   sets nochat status
#include <security.h>

int cmd_nochat(string str) {
  object who;
  string name;
  int amt;
  
   if(!archp(this_player())) return 0;
  name=str;
  who = find_player(lower_case(name));
  if (archp(who)){
     write("You can't nochat and arch!");
     return 1;
  }
  if(!who) {
    write("Could not find: "+name);
    return 1;
  }
  if (who->query_property("no chat")==0) {
  seteuid(UID_ROOT);
  who->set_property("no chat", 1);
  seteuid(getuid());
  write(who->query_cap_name()+" has been nochatted.\nOk.");
//   "/daemon/chat"->send_chat( "chat", "Chat Daemon", who->query_cap_name()+" has been nochatted by "+this_player()->query_cap_name());  
  return 1;
  }
  if (who->query_property("no chat")==1) {
  seteuid(UID_ROOT);
  who->set_property("no chat", 0);
  seteuid(getuid());
  write(who->query_cap_name()+" has been removed from nochat.\nOk.");
//   "/daemon/chat"->send_chat( "chat", "Chat Daemon", who->query_cap_name()+" has been removed from nochat by "+this_player()->query_cap_name());  
  return 1;
  }

}

int help() {
  message("help",
  "This command is used to ban people from using all public lines.\n"+
  "Syntax: nochat <player>", this_player());
  return 1;
}
