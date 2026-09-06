#include <treasure.h>

#include "../DEFS.h"

int cond; /* Condition */

string do_long(string id, object me);

reset_value() { set_value(5 + cond * 8); }

void
create_treasure()
{
    set_name("vihta");
    set_id("vasta");
    set_weight(2);
    set_short("A genuine finnish vihta");
    set_long(#'do_long);
    cond = 5;
    reset_value();
}

string
do_long(string id, object me)
{
    string s;

    s = "Vihta (or Vasta) is a whisk of birch twigs used in Finnish Sauna.\
 How is this thing used, well, you got to find that out yourself.\n";
    if (cond > 4) return s +"It is in excellent condition.";
    if (cond > 2) return s +"It is still useable, though not perfect.";
    if (cond > 1) return s + "It is badly worn and used.";
    return s + "It is falling apart. Perhaps it can still be used once.";
}

/* More different uses? */
init() {
    add_action("hit","hit");
    add_action("hit","lash");
    add_action("hit","whip");
    add_action("hit","pound");
    add_action("hit","beat");
}

hit(arg) {
    string who, with;
    object target;

    if (!arg) {
	notify_fail("Who do you want to " + query_verb() + "?\n");
	return 0;
    }

    arg = lower_case(arg);

    if (sscanf(arg, "%s with %s", who, with) != 2) {
	notify_fail("Who do you want to " + query_verb() +
	  ", and with what?\n");
	return 0;
    }

    if (who == "me" || who == "myself") target = this_player();
    if (!target) target = present(who, environment(this_player()));
    if (!target) {
	notify_fail("You can't see any " + who + " around here...\n");
	return 0;
    }

    if (!id(with)) {
	notify_fail("What is that \"" + with + "\"?\n");
	return 0;
    }

    if (!living(target)) {
	write("But why would you do that?\n");
	return 1;
    }

    write("Ok. You " + query_verb() + " ");
    say(this_player()->query_name() + " " + query_verb() + "s ");

    if (target == this_player()) {
	write("yourself");
	say( this_player()->query_objective() + "self");
    } else {
	write(target->query_name());
	tell_object(target, "you");
	say(target->query_name(), target);
    }

    write(" with " + with + "!\n");
    say(" with " + with + "!\n");

    if ("/"+object_name(environment(target)) == CITY_PATH+"finnclub/sauna") {
	tell_object(target,"Aaaahh!!! That feels GREAT!\n");
	target->heal_self(2 + random(4) + cond);
    }

    cond--; reset_value();

    write("Some leaves are ripped off, and some twigs snap.\n");

    if (!cond) {
	write("The vihta falls apart.\n");
	environment()->add_weight(-this_object()->query_weight());
	move_object(this_object(),"room/void");
	destruct(this_object());
	return 1;
    }

    write("However, the vihta is still useable.\n");
    return 1;
}
