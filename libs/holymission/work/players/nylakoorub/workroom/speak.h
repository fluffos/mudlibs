


string speak;
int free_speak;




set_speak(arg) {
    if(!arg) {
	write("Usage: freespeak on or off.\n");
	return 1;
    }
    if(arg=="off") {
	write("You turn free speak off.\n");
	say("Nylakoorub just turn free speak off.\n", this_player());
	free_speak = 0;
	return 1;
    }
    if(arg=="on") {
	write("You turn free speak on.\n");
	say("Nylakoorub just turned free speak on.\n", this_player());
	free_speak = 1;
	return 1;
    }
    return 1;
}


allowed_to_speak() {
    write("Currently who is allowed to speak: "+speak+"\n");
    return 1;
}


remove_permission_to_speak(arg) {
    object who;
    if(!arg) {
	write(
	  "Usage: removespeak <name>.\n");
	return 1;
    }
    if(arg != speak ) {
	write("That name is not in the speak flag.\n");
	return 1;
    }
    who = present(arg, environment(this_player() ) );
    if(who)  {
	tell_object(who,
	  "You have been removed the right to speak, in this room.\n");
	write("You removed "+
	  capitalize(arg)+
	  " the right to speak.\n");
	speak = "";
	return 1;
    } else {
	write("That person is not here!\n");
	return 1;
    }
    return 1;
}


give_permission_to_speak(arg) {
    object who;
    if(!arg) {
	write("Usage: grantspeak <name>.\n");
	return 1;
    }
    if(arg == speak ) {
	write("That person has the right to speak already!\n");
	return 1;
    }
    who = present(arg, environment(this_player() ) );
    if(who) {
	speak = arg;
	tell_object(who,
	  "Nylakoorub grants you the right to speak.\n");
	write("You grant "+
	  capitalize(speak)+
	  " to speak.\n");
	return 1;
    } else {
	write("That person is not here.\n");
	return 1;
    }
    return 1;
}




request() {
    object nylakoorub;
    nylakoorub = present("nylakoorub", environment(this_player() ) );
    if(nylakoorub) {
	write("You ask Nylakoorub for permission to speak.\n");
	tell_object(nylakoorub,
	  capitalize(this_player()->query_real_name()) +
	  " is asking permission to speak.\n");
	return 1;
    }
    else {
	write("Nylakoorub is not present in his workroom.\n");
	return 1;
    }
    return 1;
}


speak() {
    object nylakoorub;
    nylakoorub = present("nylakoorub", environment(this_player() ) );
    if(this_player()->query_real_name() != speak  &&
      free_speak != 1 ) {
	write(
	  "You must ask Nylakoorub to grant you the right to speak!\n"+
	  "type 'requestspeak'.\n");
	say(
	  capitalize(this_player()->query_real_name())+
	  " opened his mouth to speak, but nothing came out.\n",
	  this_player() );
	return 1;
    }
    return 0;
}



