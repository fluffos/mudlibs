#include "priest_room.h"

string guest;
string officer_title;

void create_room(){
    officer_title = "*test*";
    set_light_level(LT_DIM);
    set(ROOM_WD, WD_INDOORS);
    set_short("Inherit this file!");
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);
    set(NO_CLEANUP);

    add_command("allow", "allow_player");
}

status
allow_player(string name) {
    object basement;

    name = lower_case(name);
    if(!find_player(name)) {
	notify_fail("Cannot find a player with that name!\n");
	return 0;
    }
    basement = find_object(PRIEST_ROOM_DIR "basement");
    if(!basement) {
	call_other(PRIEST_ROOM_DIR "basement", "???");
	basement = find_object(PRIEST_ROOM_DIR "basement");
    }
    if(!present("templar", basement)) {
	notify_fail("The templar is not present outside your office. Anyone \
can enter without your permission.");
	return 0;
    }
    tell_here(sprintf("%s may now enter the office.",
	capitalize(name)));
    basement->tell_here(sprintf("Templar says: %s may now enter %s's office.",
	capitalize(name), officer_title));
    guest = name;
    call_out("reset_guest",60);
    return 1;
}

void
reset_guest() {
    guest = "";
}


status
is_allowed(string name) {
    return name == guest;
}

void
init_room() {
    if(this_player()->query_real_name() == guest)
	guest = "";
}
