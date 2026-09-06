/*********** ********** ********* ******** ******* ****** ***** **** *** ** *
  This is a packet of chewing gum to ease the withdrawals when player tries
  to quit smoking. It calls the smoke daemon when player starts chewing it.

		Coded by Mclaud for StickMUD in January 1996.

 * ** *** **** ***** ****** ******* ******** ********* ********** ***********/

inherit "/basic/id";
inherit "/basic/object/dimensions";

#include <daemons.h>
#include <pipe_defs.h>

int amount;

int query_value() {
    if (amount > 0) return ((15 * amount * 2) / 3);
    return 0;
}

string query_name() {
    return "packet of chewing gum";
}

varargs status
id(string s, object who)
{
    return s == "gum" || s == "chewing gum";
}

void
init()
{
    add_action("chew", "chew");
}

void
reset(int arg)
{
    if (!arg) {
	amount = 20;
	set_weight(1);
    }
}

varargs string
query_long(string s, object who)
{
    mixed txt;
    txt = "This is a packet of chewing gum. It should help you get\
 through the hardest withdrawals when you try to quit smoking. It tastes like\
 shit, and it makes your breath smell like shit. Use with caution.\n";

    if (amount > 0) txt += "There are "+amount+" gums left.";
    else txt += "It's empty.";
    return txt;
}

varargs string                           
query_short(string s, object who)
{
    return "Packet of chewing gum";
}

varargs status
chew(string what)
{
    int sweat;
    if (what != "gum") return 0;

    if ((status) SMOKE_D->query_chewing(this_player()) == YES) {
	notify_fail("You are already chewing some.\n");
	return 0;
    }

    if ((status) SMOKE_D->query_smoking(this_player()) == YES) {
	notify_fail("While smoking? In your dreams.\n");
	return 0;
    }

    if (!amount) {
	notify_fail("You don't have any gum left.\n");
	return 0;
    }
    if ((int) SMOKE_D->query_sweat(this_player()) == NO) {
	notify_fail("You really don't need that right now.\n");
	return 0;
    }

    amount --;
    SMOKE_D->start_chewing(this_player());
    this_player()->tell_me("Ok. You put the disgusting thing in your mouth\
 and start chewing it.");
    environment(this_player())->tell_here(this_player()->query_name()+ " starts\
 chewing a bubblegum.", this_player());
    if (amount == 0) call_out("clean", 120);
    return 1;
}

void clean() {
    if (environment())
	environment()->tell_me("Empty chewing gum packet falls in pieces.");
    destruct(this_object());
}

status
get(int silent)
{
    return 1;
}
