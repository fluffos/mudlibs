//Nulvect <cre> ah, here's something that's relatively simple
//Nulvect <cre> make a command called assist that puts you into combat with
//everyone who is attacking someone
//Nulvect <cre> "assist daos" when you're fighting 3 goblins would put me in
//combat with those 3 goblins
//Nulvect <cre> and some kind of message like "You assist Daos in combat."
//"Nulvect assists Daos/you in combat."
// query_current_attacker() and add_attacker() 



#include <std.h>

int cmd_assist2(string str) {
    object tp = this_player();
    object env = environment(tp);
    object targ;
    object *att;

    // first handle the preliminary checks
    if (!str || !targ = present(str, env)) return notify_fail("There is no such thing.");
    if (!targ->is_living()) return notify_fail("They have to be alive.");
    if (targ == tp) return notify_fail("You can't assist yourself.");
    if (tp->query_busy()) return notify_fail("You are busy doing something else.");

    att = targ->query_attackers();

    // next see if anyone is in combat
    if (!sizeof(att)) {
	return notify_fail("There is no one to assist.");
    }

    // find out if you are in combat with them
    if (member_array(tp, att) != -1) {
	return notify_fail("You are already in combat");
    }

    message("info", "%^BOLD%^RED%^You assist "+targ->query_cap_name()+" in combat%^RESET%^.", tp);
    message("info", "%^BOLD%^RED%^"+tp->query_cap_name()+" assists you in combat%^RESET%^.", targ);

    // add player to the attacker lists
    att->add_attacker(tp);
    tp->set_attackers( tp->query_attackers() | att );
    return 1;
}







