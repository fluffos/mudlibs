// Petrarch
// Merentha Lib 1.0
// <look>

string help() {
return "Syntax: look <object>\n\n\
This command allows you to examine your environment when no object is \
mentioned or allows you to look at an object, person or item in the \
same area as yourself when you also supply an optional argument.";
}

varargs int command(string str) {
object env,ob;
string desc;
  if(!env=environment(this_player())) {
    message("command", "You have no environment.", this_player());
    return 1;
  }
  if(!str) {
    message("command", env->describe_room(1), this_player());
    return 1;
  }
  if (ob=present(str, env)) {
    message("command", this_player()->query_cap_name()+" looks over "+ob->query_short()+".", env, this_player());
    message("command", ob->query_long(), this_player());
    return 1;
  }
  if (ob=present(str, this_player())) {
    message("command", this_player()->query_cap_name()+" inspects some of the items "+this_player()->query_he()+" is carrying.",env, this_player());
    message("command", ob->query_long(), this_player());
    return 1;
  }
  if (desc=env->query_item(str)) {
    message("command", this_player()->query_cap_name()+" looks over "+str+".", env, this_player());
    message("command", desc, this_player());
    return 1;
  }

  return notify_fail("You do not see that here.\n");
}


