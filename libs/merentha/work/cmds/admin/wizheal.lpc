// Petrarch
// Merentha Lib 1.0
// <wizheal>

int command(string str) {
object ob;
  if(!ob=find_player(str)) return notify_fail("Count not find them.\n");
  ob->heal(100000);
message("command", "You heal "+ob->query_cap_name(), this_player());
  return 1;
}

string help() {
return "Syntax: wizheal <person>\n\nHeals a player 100000 points.";
}

