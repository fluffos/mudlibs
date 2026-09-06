#include "priest_room.h"

string show_candidates() {
    return VOTING_D->query_candidates();
}


void
create_room(){
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(NO_PK);
    set_short("The voting room of the Holy Order");
    set_long(
      "This is the voting room for the Holy Order. In order to vote,\n\
please use the command line: \n\n\
    vote <name> for <office> \n\n\
Valid Offices are Vicegerant, Hospitilar, and Templar. Hospitilar \n\
and Templar stand for the corresponding Preceptor's spot. You may only\n\
vote once for each office, and once you vote your choice is final.\n\
To become a candidate, please use the command line:\n\n\
    run for <office> \n\n\
Only lords can run for an office, and one player can run only for one \
office at a time. Good luck to all candidates.\n\
There's a board containing a list of candidates here.");
    set_items(([
	"board": #'show_candidates,
      ]));
    add_exit("exit", PRIEST_ROOM_DIR "library");
    set_commands( ([
	"vote": "vote",
	"run": "run",
      ]));
}

status
vote(string str) {
    return VOTING_D->vote(str);
}

status
run(string str) {
    string office;
    string name;

    if(!str)
	return notify_fail("Usage: run for <office>\n"),0;

    if(sscanf(str, "for %s", office) != 1)
	return notify_fail("Usage: run for <office>\n"),0;

    if(!IS_PRIEST(this_player()))
	return notify_fail("Heathens are not allowed to vote.\n"),0;
    /*
	if(this_player()->query_level() < 25)
	    return notify_fail("Only lords can run for a position.\n"),0;
    */
    name = this_player()->query_real_name();
    if(VOTING_D->query_elections())
	return notify_fail("Elections are not open.\n"),0;

    switch(office) {
    case "vicegerant":
	if(!VOTING_D->add_vg_candidate(name)) return 0;
	break;
    case "templar":
	if(!VOTING_D->add_pt_candidate(name)) return 0;
	break;
    case "hospitilar":
	if(!VOTING_D->add_ph_candidate(name)) return 0;
	break;
    default:
	return notify_fail("Valid offices are 'vicegerant', 'templar', \
and 'hospitilar'.\n"),0;
    }
    this_player()->tell_me("You run for " + office +".");
    return 1;
}
