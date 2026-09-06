int emote_cmd(string str) {
    if (str) {
	if (this_player()->query_invis()) {
	    write("Invisible people cannot use emote.\n");
	} else {
	    int i;

	    i = sizeof(str);
	    while (i--) {
		if (str[i] < ' ' || str[i] > 127) {
		    write("Illegal characters on emote line.\n");
		    return 1;
		}
	    }
	    tell_room(environment(this_player()),
	      sprintf("%s %-=65s\n", (string)this_player()->query_name(),
		str ));
	}
	return 1;
    }

    return notify_fail("Emote what?\n"), 0;
}
