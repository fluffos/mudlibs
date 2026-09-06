#include "../priest.h"

status
store_cmd(object who, object sym, string s) {
    object ob, room, staff;
    int amount;
    string t, u, my_tell, other_tell;

    notify_fail("Store what to where?\n");
    if(!s || sscanf(s,"%d %s to %s", amount,t,u) != 3)
	return 0;
    staff = STAFF_D->query_staff(who);
    if(!staff || (environment(staff) != who)) return 0;
    if(!staff->id(u)) return 0;

    if(!t || member(SP_NAMES, t) < 0) {
	notify_fail("Store what to the " + u + "?\n");
	return 0;
    }
    if(amount < 1) {
	notify_fail("Store how many spell points to the " + u + "?\n");
	return 0;
    }
    room = environment(who);
    if(who->is_fighting()) {
	who->tell_me("You can't concentrate on that while fighting!");
	return 1;
    }
    if(who->query_sp() < amount) {
	who->tell_me(
	  "You don't have that many spell points to store!");
	return 1;
    }
    my_tell = "You close your eyes and hold the staff tight...\n\
You feel your mental energy flow to the staff...";

    if(who->query_short())
	other_tell = ":%<me.capname>% closes %<me.possessive>% eyes \
and holds the staff tight. You sense mystical powers flow between the \
staff and %<me.name>%.";

    who->add_sp(-amount);
    amount = (95 + random(5)) * amount / 100;
    /* So that 1 - 5 % of sps are lost every time. */
    if(staff->add_sps(amount)) {
	my_tell +=
	"\nSuddenly you feel that the staff can't hold any more energy.";
	if(other_tell) other_tell +=
	    "\n%<me.capname>% suddenly opens %<me.possessive>% eyes as if been \
interrupted by something unexpected...";
    }
    else if(other_tell)
	other_tell += "\n%<me.capname>% opens %<me.possessive>% eyes.";
    my_tell += "\nYou open your eyes.";
    who->tell_me(my_tell);
    if(other_tell) 
	room->tell_here(other_tell,0,0,who,who,0,0);
    return 1;
}
