// Petrarch
// Merentha Lib 1.0
// <promote>

int command(string str) {
object ob;
string pos;
  if(!str) return notify_fail("Syntax: promote <person> <position>\n");
  sscanf(str, "%s %s", str, pos);
  ob=find_player(str);
  if(!ob) ob=present(str, environment(this_player()));
  if(!ob) return notify_fail("Could not find "+str+".\n");
  ob->set_position(pos);
  ob->save_player(ob->query_name());
  message("command", ob->query_cap_name()+" promoted to "+pos+".", this_player());
  message("command", "You have been promoted to "+pos+".", ob);
  mkdir("/realms/"+ob->query_name());
  return 1;
}

string help() {
return "Syntax: promote <person> <level>\n\nPromotes a player to admin or admin to a player.\nExamples: promote petrarch admin\n          promote petrarch player";
}

