string *tells=({}), *says=({}), *emotes=({});

int cmd_intercept(string s) {
	string name;
	name=this_player()->query_name();
	if(!s || s=="") {
		write("Intercepts off.");
		tells -= ({ name });
                says -= ({ name });
                emotes -= ({ name });
		return 1;
	}
	switch(s) {
		case "tells":
			if(member_array(name, tells) != -1) { tells -= ({ name });  write("Tell intercept disabled."); } else {
			tells += ({ name }); write("Tell intercept enabled."); } break;
                case "says":
                        if(member_array(name, says) != -1) { says -= ({ name });  write("Say intercept disabled."); } else {
                        says += ({ name }); write("Say intercept enabled."); } break;
                case "emotes":
                        if(member_array(name, emotes) != -1) { emotes -= ({ name });  write("Emote intercept disabled."); } else {
                        emotes += ({ name }); write("Emote intercept enabled."); } break;
                case "all":
                        if(member_array(name, tells) != -1) { tells -= ({ name }); says -= ({ name }); emotes -= ({ name }); write("All intercepts disabled."); } else {
                        tells += ({ name }); says += ({ name }); emotes += ({ name }); write("All intercepts enabled."); } break;
		default:
			write("Arguments are: tells, says, emotes, all.");
			break;
	}
	return 1;
}

int global(string t, string out) {
	string *tmp;
	int i;
	switch(t) {
		case "tell": tmp = tells; break;
                case "say": tmp = says; break;
                case "emote": tmp = emotes; break;
		default: write("Invalid sequence."); return 0; break;
	}
	i=sizeof(tmp);
	while(i--) {
		if(find_player(tmp[i])) message("system", "%^BOLD%^%^CYAN%^intercept> "+out+"\n%^RESET%^", find_player(tmp[i]));
	}
}
