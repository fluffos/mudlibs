// Petrarch
// Merentha Lib 1.0
// <say>

string help() {
return "Syntax: say <something>\n\n\
This command allows you to speak to everyone in the same room as yourself. \
Anything you say will be seen by everyone in the same area as youself.";
}

varargs int command(string str) {
string type;
  if(!this_player()) return 1;
  if(!str) return notify_fail("Say what?\n");
  if(!environment(this_player())) return notify_fail("You can not talk with no environment.\n");
  while(str[0..0]==" ") str=str[1..<1];
  type=str[<1..<1];
  if (type=="?") type="ask";
  else if (type=="!") type="exclaim";
  else type="say";
  message("communication", "You "+type+": "+str, this_player());
  message("communication", this_player()->query_cap_name()+" "+type+"s: "+str, environment(this_player()), this_player());
  return 1;
}

