/* Modified version of "on_fire" object in Ered-Mithrin */

#include <treasure.h>
#include <macros.h>

int count;
object owner;

void
create_treasure() {
    set_name("flames");
    set_id("on_fire");
    set_short(0);
    set_long("The flames burn you.");
}

get() { return 1; }
drop() { return 1; }

void
init_treasure() {
    if (!TP || !ENV || TP != ENV) return;

    count = 20 + random(30)+1;
    remove_call_out("on_fire");
    call_out("on_fire", 5+ random(5));
    owner = ENV;
}

void
on_fire() {
    count -= random(2) + 1;
    if (!owner || count < 1 || !living(owner) ) {
	destruct(this_object());
	return;
    }
    // Fix by Ki'eve -- the flames kept burning after death.
    if (owner->query_ghost()) {
	environment(owner)->tell_here("The flame charrs the corpse "
	  "and extinguishes.", owner);
	destruct(this_object());
	return;
    }

    environment(owner)->tell_here(":%<me.capname>% screams as %<me.pronoun>% \
is consumed by raging fire!",0,0,owner,owner,0,0);

    owner->tell_me( ({
	"Your clothes are on fire!",
	"Holy fire burns you!",
	"Blue flames burns you making you scream in pain!",
      })[random(3)] );

    owner->add_hp(-(5 + random(5)), 1);

    call_out("on_fire", 10 + random(10));
}
