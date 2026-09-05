status cmd_whisper(string str) {
  object ob;
  string who;
  string msg;
  string cap_name;

  if ((int)this_player()->query_ghost()) {
    write("You fail.\n");
    return 1;
  }
  if (!str || sscanf(str, "%s %s", who, msg) != 2) {
    write("Whisper what?\n");
    return 1;
  }
  who = lower_case(who);
  ob = find_player(who, 1);
  if (!ob || !present(who, environment(this_player()))) {
write("No player with that name in this room.\n");
return 1;
  }
  who = (string)ob->query_name();
  cap_name = (string)this_player()->query_name();
  tell_object(ob, cap_name + " whispers to you: " + msg + "\n");
  write("Ok.\n");
  this_player()->checked_say(cap_name + " whispers something to " + who + ".\n");
  return 1;
}

