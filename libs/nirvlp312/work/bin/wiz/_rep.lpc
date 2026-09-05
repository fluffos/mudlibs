smart_report(str) {
  string who;
  string current_room;

  current_room=object_name(environment(this_player()));
  if (!str || !current_room || sscanf(current_room, "players/%s/", who) != 1)
	  return;
  log_file(who + ".rep", ctime()[4..15] + " " + current_room + " " + str + "\n");
    return 1;
}
