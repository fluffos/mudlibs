// armour object used by barkskin-spell

#include <armour.h>
#include <invis_levels.h>
#include <living_defs.h>
#include "../priest.h"

status no_unwear;


create_armour() {
    set_name("barkskin");
    set_weight(0);
    set_invis(IL_TOTALLY_INVISIBLE);
    set_type("free magic");
}


void destruct_me() {
    object plr;

    no_unwear = 0;
    plr = query_worn_by();
    if(plr) {
	environment(plr)->tell_here(({":%<cap(me.gen_possessive)>% skin \
returns back to normal."}), ({LIV_CAN_SEE}),0,0,plr,0,0);
	if(plr->unwear(this_object(),1))
	    plr->tell_me("*ERROR* When destructing barkskin.");
    }

    destruct(this_object());
}


int
make_barkskin(object plr, int dur, int armour_class) {
    object ob;

    set_ac(armour_class);

    if(ob=plr->wear(this_object(), 1)) {
	plr->tell_me("*ERROR* Can't create barkskin.");
	if(plr->query_coder_level())
	    plr->tell_me(sprintf("Object causing problems: %O", ob));
	destruct(this_object());
	return 1;
    }

    no_unwear = 1;
    call_out(#'destruct_me, dur);
    plr->tell_me("Your skin becomes thick and hard as oak's bark.");
    // let's tell this message only to those who can see us
    environment(plr)->tell_here(({":%<me.gen_possessive>% skin seems to \
become thicker."}), ({LIV_CAN_SEE}), 0, plr, plr, 0, 0);
    return 0; // ok
}


string extra_look() {
    object plr;

    if(plr = query_worn_by()) {
	return capitalize(plr->query_name()) + 
	"'s skin looks like oak's bark.";
    }
    return 0;
}

varargs status
unwear_me(object who, status silent) {
    if(no_unwear) return 0;
    return ::unwear_me(who, silent);
}

status add_damage(int amount) {
    return 0; // can't be damaged
}
