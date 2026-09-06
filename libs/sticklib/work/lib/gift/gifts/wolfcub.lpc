// Third pet --  01-16-98   Kieve
// Modified to become Nova's pet
// Cost:
//   100 000  -- initial gift cost
//   100 000  -- 5 random emotes
//   150 000  -- speaking ability
//   150 000  -- emoting ability
//    20 000  -- ability to change 'says' at any time
//  ~~~~~~~~
//   520 000  Total Cost

// +20k extra for a change in descriptions.
// May 28, 1998 - Kieve

#include <pet.h>

void create_pet() {
    set_name("wolf");
    set_id( ({ "wolf", "wolfcub", "cub", "solar" }) );
    set_short("Wolf");
    set_long("A large wolf with silvery grey fur. He looks at you with his "+
      "deeply golden eyes, with a serene expression which seems to "+
      "indicate that he knows all there is to know. Somewhere deep in "+
      "his eyes you catch a glimpse of an eternal yearning to the wild. "+
      "His sad, almost heartbraking, howl makes you feel very sad.");
    /*
	set_long("A beautiful white wolfcub with bright blue eyes. It has pink "+
	    "paws and sharp looking claws and fangs. Its fur soft and fuzzy, and "+
	    "feels warm. It has a black leather collar with diamond spikes and a "+
	    "plate attached by a chain. The plate has the name 'Solar' engraved "+
	    "on it.");
    */
    set_weight(1);
    set_value(0);
    set_pick_up_msg("Solar growls loudly!");
    set_speaking_pet(1);
    set_emoting_pet(1);
    set_can_change_style(1);
    set_pet_chats(7, ({
	/*
		"Solar raises its head and howls loudly.",
		"Solar sniffs the air and growls silently.",
		"Solar, the wolfcub, disappears into the shadows.",
		"Solar bites your leg! Grrwl!",
		"Solar runs around in circles, chasing its tail.",
	*/
	"Wolf howls deeply at the shining moon.",
	"Wolf smells the air, growling silently.",
	"Wolf disappears into the shadows.",
	"Wolf gnarls angrily at you!",
	"Wolf chews on a bloody bone.",
      }) );
    set_say_style("growls");
}
