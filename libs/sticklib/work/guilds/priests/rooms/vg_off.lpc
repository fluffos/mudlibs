#include "priest_room.h"

#define AUD_ROOM PRIEST_ROOM_DIR "vg_aud"

void create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(NO_CLEANUP);

    set_short("The Vicegerant's Office");
    set_long("You are in the Vicegerant's Office. This is a functional \
office, although the quality and richness of the furnishings do convey \
the cast prestigee and honour of " GOD_NAME "'s Vicegerant in the \
Mortal World. There is a large desk, several leather chairs, and a \
window with a magnificient view over the Realm.");

    set_items(([
	"window": "The view is indeed really magnificent.",
	"desk": "The desk is made of polished mahogany and it's imposing \
size fits well the overall looks of the room.",
	// write the rest of them
      ]));

    set_exits(([
	"south": AUD_ROOM,
      ]));
}


void
init_room() {
    object ob;
    int rank;

    if(!(ob = this_player()->query_guild_object()))
	return;
    rank = (int) ob->query_rank();
    if(rank == VG_RANK || rank >= 10) {
	add_action("admit","admit");
	add_action("refuse","refuse");
	add_action("guest_add","guest");
	add_action("revoke","revoke");
	add_action("vg_help","vg_help");
    }
}


status
knock(string who) {
    tell_here(":A Templar quitly pops his head in and says: %<me.name>% \
would like an audience your Grace. Shall I admit %<me.objective>%?"
      ,0,0,0,who,0,0);
    return 1;
}


/* 'gaze' moved to diet */      
vg_help(){
    this_player()->tell_me("\
Vicegerant Office Commands:\
\nadmit  <player> -- give templar orders to allow player to enter your office.\
\nrefuse <player> -- give player the polite brush off.\
\nguest  <player> -- allow a heathen access to the Cathedral.\
\nrevoke <player> -- revoke a player's guest status.");
    return 1;
}


status
admit(string who) {
    object who_p;

    who_p = find_player(lower_case(who));
    AUD_ROOM->admit(who_p);
    return 1;
}


status
refuse(string who) {
    object who_p;

    who_p = find_player(lower_case(who));
    who_p->tell_me("Templar tells you: I'm sorry. The Vicegerant is \
very busy right now and cannot fit you into the schedule.");
    return 1;
}


status
guest_add(string guest) {
    object *guests;
    int i;
    string blah;

    if(!guest) {
	this_player()->tell_me(GUEST_D->query_guests());
	return 1;
    }

    guest = (string)lower_case(guest);

    if(GUEST_D->query_guest(guest)) {
	notify_fail("That player is already a guest.\n");
	return 0;
    }

    GUEST_D->add_guest(guest);

    this_player()->tell_me("You quickly scrible a note for the Templars, \
informing them to allow "+capitalize(guest)+" access to the cathedral.");
    return 1;
}


status
revoke(string guest) {
    if(!guest){
	notify_fail("You must 'revoke <name>' someone's guest status.\n");
	return 0;
    }

    guest=lower_case(guest);

    if(!(GUEST_D->query_guest(guest))){
	notify_fail("But that player is not on the guest list.\n");
	return 0;
    }

    GUEST_D->remove_guest(guest);

    this_player()->tell_me("You notify the Templar's to keep \
"+capitalize(guest)+" out of the Cathedral.");
    return 1;
}

