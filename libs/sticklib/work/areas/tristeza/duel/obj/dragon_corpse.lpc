
/*
**
** Dead body of the Black Dragon
**
** Design & Code:  Tron
********************************/

#include <corpse_defs.h>
#include <areas.h>
#include <generic_items.h>

inherit CORPSE_FILE;

#define	OMEM	AREA_TRISTEZA "duel/obj/omem"



int
query_weight() { return 18; }

void
set_name(string n) {

    name=n;
    call_out("my_decay", 40);
}

void
my_decay() {

    object ob;
    decay -= 1;

    if(decay > 0) {
	call_out("my_decay", 40);
	return;
    }
    say("There is a bright flash and the bones turn to something else...\n");
	if (!find_object(AREA_TRISTEZA "duel/obj/dragonarm")) {
		move_object(AREA_TRISTEZA "duel/obj/dragonarm",environment());
    }


// Now now. This is a poor way to make unique items. Should use
// the better way to add uniqueness (UNIQUE_D etc). -+ Doomdark 08-Sep-98 +-
	if (!find_object(GENERIC_FOCUS_STONE)) {
		move_object(GENERIC_FOCUS_STONE, environment());
    }
    destruct(this_object());
}


