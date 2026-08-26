// Petrarch
// Merentha Lib 1.0
// <say>

string help() {
return "Syntax: emote <something>\n\n\
Allows you to emote an action.  For example \"emote walks around in \
circles.\" Will tell everyone in the room that you walk around in \
circles.";
}

varargs int command(string str) {
string type;
  if(!this_player()) return 1;
  if(!str) return notify_fail("Emote what?\n");
  if(!environment(this_player())) return notify_fail("You can not emote with no environment.\n");
  while(str[0..0]==" ") str=str[1..<1];
  type=str[<1..<1];
  message("communication", "You emote: "+this_player()->query_cap_name()+" "+str, this_player());
  message("communication", this_player()->query_cap_name()+" "+str, environment(this_player()), this_player());
  return 1;
}

