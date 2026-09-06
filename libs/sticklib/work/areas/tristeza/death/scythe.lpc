#include <weapon.h>

void
create_weapon()
{
    set_name("wicked scythe");
    set_id(({
	"scythe", "deaths_item", "death_scythe"
      }));
    set_short("wicked scythe");
    set_long(
      "An extremely sharp scythe. It's so sharp that gusts of wind actually try \
to turn away from the edge rather than be sliced in two by the \
wicked-looking blade. It does strange things with light as well as \
unlucky photons halve their amplitudes when they hit the blade.");

    /* Was: "photons split into their sub-components when they hit the blade.\n");
       *** photons do NOT have any sub-components *** 10.5.1992 //Frobozz */

    set_wc(25); /* This is illegal! Don't you ever do this! */
    set_weight(0);
    // Not to mention _this_ is illegal (weight == 0).
    set_value(5000);
    // set_blunt(1); /* Scythe is not going to blunt! 3.8.1992 //Frobozz */
    // No no no. _Old_ way. Now, let's use this one instead:
    set(WP_STAYS_SHARP);	// -+ Doomdark +-

    set(WP_TROLL_WEAPON);
}

void
init_weapon()
{
    if(this_player() && !this_player()->is_npc())
	call_out("check_me",2);
}

// Oh shit. Why not use hbs instead... stupid. :-(
check_me() {
    remove_call_out("check_me");
    if(environment())
	check_env(environment());
    call_out("check_me",4);
}

check_env(ob) {
    if(!living(ob) && environment(ob))
	check_env(environment(ob));
    if(!environment(ob))
	self_dest();
    if(living(ob)) {
	string dummy;
	if ( strstr(object_name(environment(ob)),"/death/")==-1)
	    self_dest();
    }
}

self_dest() {
    if(environment() && living(environment())) {
	environment()->tell_me("You remove the scythe.");
	environment()->unwield(this_object(),1);
    }
    destruct(this_object());
}
