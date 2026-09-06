/* Not much use without the Kalevala area (AREA_KALEVALA) but... */

#include <treasure.h>

#include <areas.h>
#include "../DEFS.h"

void
create_treasure()
{
    string tmp;

    set_name("instructions");
    set_id("vihta_instructions");
    set_id("instr");
    set_weight(1);
    set_short("Instructions of how to make a 'vihta'");
    tmp = 
    "Vihta (or Vasta) is a whisk of birch twigs used in Finnish Sauna. \
How is that used, well, you got to find that out yourself. Anyway, \
with these instructions you will be able to 'make vihta'. But you \
have to be in the correct location first - it's rumoured that the \
best materials for a Vihta can be found in the birch forests of Kaleva.";
    set_long(tmp);
    set_read(tmp);
    set_value(40);
}

init() {
    add_action("make","make");
}

object me; /* Store this_player(), just in case... */

make(arg) {
    object paikka;
    string tmp;

    if (!arg) {
	notify_fail("What do you want to make?\n");
	return 0;
    }

    arg = lower_case(arg);

    if (arg != "vihta" && arg != "vasta") {
	notify_fail("Interesting. But how are you going to make '" +
	  arg + "'?\n");
	return 0;
    }

    if (!(me = this_player())) return 0;

    paikka = environment(me);

#ifdef AREA_KALEVALA
    if (!paikka || sscanf("/"+object_name(paikka),
	AREA_KALEVALA+"kaleva/forest%s",tmp)!=1) {
#else
	if (1) {
#endif
	    notify_fail("You can't see any good birch trees nearby.\n");
	    return 0;
	}

	remove_call_out("vihta_jobi");

	write("Yes. You find a birch tree suitable for making a Vihta.\n");
	write("You gather some twigs and start working...\n");

	call_out("vihta_jobi",2);
	return 1;
    }

    vihta_jobi() {
	if (!me) return;
	tell_object(me, "Hmm, this is tricky!\n");
	call_out("vihta_jobi2",2); return;
    }

    vihta_jobi2() {
	if (!me) return;
	tell_object(me,
	  "Wrap this twig here and move the part A to connect into C...\n");
	call_out("vihta_jobi3",2); return;
    }

    vihta_jobi3() {
	if (!me) return;
	tell_object(me,"Hm...into which end the leaves came again...???\n");
	call_out("vihta_jobi4",2); return;
    }

    vihta_jobi4() {
	object vihta;

	if (!me) return;

	/* It doesn't succeed every time! */
	if (!random(4)) {
	    tell_object(me,
	      "Huh? It shouldn't look like this!?? Your 'vihta' seems to be more\n"+
	      "like a wreath. Perhaps you were holding the instruction paper (which\n"+
	      "crumbles to dust) upside down. You FAILED to make a vihta. *blush*\n");
	} else {
	    tell_object(me,"You manage to make a genuine finnish Vihta!\n");

	    vihta = clone_object( CITY_PATH+"finnclub/vihta");

	    if (!me->add_weight(vihta->query_weight())) {
		tell_object(me, "Gee, it's heavy. You have to drop it.\n");
		move_object(vihta,environment(me));
	    } else move_object(vihta, me);

	    if (this_player() == me) say(me->query_name() +
		  " just made a genuine finnish Vihta!\n");
	    tell_object(me, "The instruction paper crumbles into dust.\n");
	}
	destruct(this_object());
    }
