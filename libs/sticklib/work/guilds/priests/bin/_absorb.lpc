#include "../priest.h"

#define STAFF_DELAY 2

status
absorb_cmd(object who, object sym, string s)
{
    string t, u, tmp, tmp2;
    int a, amount, has_sp;
    object staff;

    notify_fail("Absorb what?\n");
    if(!s || sscanf(s,"%d %s from %s", amount, t, u) < 3)
	return 0;
    staff = STAFF_D->query_staff(who);
    if(!staff || (environment(staff) != who)) return 0;
    if(!staff->id(u)) return 0;

    if(!t || member(SP_NAMES, t) < 0)
	return notify_fail("Absorb what from the " + u + "?\n"),0;

    if(amount < 1) return 
	notify_fail("Absorb how many spell points from the "+u+"?"),0;

    if(time() < staff->query_last_use() + STAFF_DELAY + random(2)) {
	who->tell_me("Your mind is not yet capable of absorbing \
more mental energy from the staff.");
	return 1;
    }
    tmp = "";
    a = who->query_max_sp() / 4;
    if (amount > a) {
	amount = (a / 2 + random(a / 2 + 1));
	tmp += sprintf("Your mind can't absorb that amount of mental \
energy in one piece! You try to absorb %d sps instead.\n", amount);
    }
    t = who->query_short();
    tmp += "You hold the staff very tight and start absorbing its energy!\n";
    if(t) tmp2 = ":%<me.capname>% holds the staff very tight as if trying \
to squeeze something from it.";
    has_sp = staff->query_cur_sps();
    if(has_sp < amount) {
	tmp += "Suddenly you feel that there isn't any more energy left \
in the staff...\nYou loosen your grip.";
	if(t) tmp2 += "\nSuddenly %<me.name>% loosens %<me.possessive>% \
grip and looks a bit disappointed.";
	amount = has_sp;
    } else {
	tmp +=
	"You drain all the energy you need, and then loosen your grip.";
	if(t) tmp2 += "\n%<me.capname>% loosens %<me.possessive>% grip.";
    }
    who->tell_me(tmp);
    who->add_sp(amount);
    staff->add_sps(-amount);
    staff->set_last_use(time());
    if(t)
	environment(who)->tell_here(tmp2,0,0,who,who,0,0);
    return 1;
}
