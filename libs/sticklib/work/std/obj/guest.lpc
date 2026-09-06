
/************************************************
 NAME:    guest.c

 PURPOSE: New guest object for simple guests.

 AUTHOR:  Tron
 ***********************************************/

#include "/sys/configuration.h"

#include <config.h>
#include <mud_name.h>
#include <generic_rooms.h>

string name;
int qnumber;

nomask void
create() {
    configure_object(this_object(), OC_COMMANDS_ENABLED, 1);
}

nomask status
query_prevent_shadow() { return 1; }

nomask string
valid_read(string str) {
    string tmp;

    if(sscanf(str, "/%s", tmp)) str = tmp;
    if(sscanf(str, PATH_USER_FNAME "%s", tmp)) return 0;
    return str;
}

nomask string
valid_write(string str) {
    string tmp;

    if(!(str = valid_read(str))) return 0;
    if(sscanf(str, "open/%s", tmp)) return str;
    if(sscanf(str, "log/%s", tmp)) return str;
    return 0;
}

nomask void
tell_me(string s) {

    if(!s) return;

    tell_object(this_object(), sprintf("%-=78s\n", s));
}

nomask string
short() {

    if(!name) return "Guest"; 
    else return capitalize(name);
}

nomask void
long() {

    write("Guest of "+MUD_NAME+".\n");
}

nomask status
id(string str) {

    return (str == name || str == "guest");
}

nomask string
query_name() { return name; }

nomask string
query_real_name() { return (name ? name : "guest"); }

nomask int
hit_player(int a) {

    write("The Guest vanishes in a puff of smoke.\n");
    tell_object(this_object(), "You Die!!!\n");
    destruct(this_object());
    return 1;
}

nomask void
move_player(string dest, mixed optional) {
    string dir;
    string file;

    if(!optional) {
	if(!dest) return;
	if(sscanf(dest, "%s#%s", dir, file) < 2) return;
    }
    else {
	dir = dest;
	file = optional;
    }

    say("Guest leaves "+dest+"\n");
    move_object(this_object(), file);
    "bin/pub/_look"->look_cmd(0, this_object());
    say("Guest arrives.\n");

}

nomask status
query_can_see() { return 1; }

nomask status
test_dark() {
    if(set_light(0) > 0) return 0;
    else return 1;
}

nomask int
query_level() { return 1; }

nomask int
query_guest() { return qnumber; }

nomask private void
_guestInfo(status leaves) {
    object *o;
    int i;

    o = users();
    i = sizeof(o);

    while (i--) {

	if(o[i] != this_object()) {
	    if(o[i]->query_info()) {
		tell_object(o[i], "INFO: "+capitalize(name));
		if(leaves) tell_object(o[i], " leaves "+MUD_NAME+".\n");
		else tell_object(o[i], " enters "+MUD_NAME+".\n"); 
	    }
	}
    }
}

nomask void
initialize() {

    object *u;
    int max;
    int i, n;

    u = users();
    i = sizeof(u);
    while(i--) {
	if(u[i] != this_object()) {
	    if( (n = (int)u[i]->query_guest()) > max) max = n;
	}
    }

    qnumber = max + 1;
    name = sprintf("%s%d", "guest", qnumber);

    configure_object(this_object(), OC_HEART_BEAT, 1);

    add_action("guest_say", "say");
    add_action("guest_tell", "tell");
    add_action("guest_quit", "quit");
    add_action("guest_help", "help");
    add_action("guest_look", "look");
    add_action("guest_look", "examine", 3);

    _guestInfo(0);
    cat("/data/login/NEWS");
    move_object(this_object(), GENERIC_ROOM_CHURCH);
}

nomask private string
_allowedStr(string s) {
    int i;
    string tmp;

    if(!s) return 0;

    i = sizeof(s);
    if(!i) return "";

    tmp = "";
    while(i--) {
	if(s[i] < 32 || s[i] > 126) continue;
	tmp += s[i..i];
    }

    return tmp;
}

nomask status
guest_look(string s) {

    if(query_verb() == "examine")
	return (status)"/bin/pub/_examine"->examine_cmd(s, this_object());

    return (status)"/bin/pub/_look"-> look_cmd(s, this_object());
}

nomask status
guest_say(string s) {
    if(!s) { notify_fail("Say what?\n");
	return 0;
    }

    s = _allowedStr(s);
    say(capitalize(name)+" says: "+s+"\n");
    return 1;
}

nomask status
guest_tell(string s) {
    string who;
    string what;
    object ob;

    if(!s) {
	notify_fail("Tell whom?\n");
	return 0;
    }

    if(sscanf(s, "%s %s", who, what) != 2) {
	notify_fail("Tell what?\n");
	return 0;
    }

    ob = find_player(who);
    if (!ob) {
	notify_fail("No such player, sorry.\n");
	return 0;
    }
    if(!ob->query_coder_level()) {
	notify_fail("You can only tell this to a coder.\n");
	return 0;
    }

    what = _allowedStr(what);
    ob->tell_me(capitalize(name)+" tells you: "+what);
    write("Ok.\n");
    return 1;
}

nomask status
guest_quit() {
    write("Come back soon, but next time as a player :).\n");
    destruct(this_object());
    _guestInfo(1);
    return 1;
}

nomask status
guest_help(string s) {
    if(!s) s = "all";
    return (status)"/bin/pub/_help"->help_cmd(s);
}

nomask void
heart_beat() {
    if(!interactive(this_object())) {
	configure_object(this_object(), OC_HEART_BEAT, 0);
	tell_room(environment(), "Purple Dragon arrives and stomps poor "+
	  capitalize(name)+ " under its foot.\n");
	destruct(this_object());
    }
}
