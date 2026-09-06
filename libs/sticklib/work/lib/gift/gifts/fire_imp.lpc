//
// Fire Imp -- Created for Floyd
// Base Object    100 000  (with show)
// Acting Object  100 000  (5 * 20 000)
// Talking Object 150 000
// Emoting Object 150 000
// Say change      20 000
//               --------
//  Total Cost    200 000
//
// 20-Jan-98, Kieve

#include <pet.h>

void create_pet() {
    set_name("A fire imp");
    set_id( ({ "imp", "fire imp", }) );
    set_short("A fire imp");
    set_long("You see a whisp of a creature before you. It is more flames "+
      "than creature. The form of a body is barely visible through the "+
      "flame's changing colour and shape. A spark leaps off the imp, and "+
      "lands near your feet. You worry that your armour may be flamable.");
    set_weight(1);
    set_value(0);
    set_pick_up_msg("A fire imp sparks!");
    set_speaking_pet(1);
    set_emoting_pet(1);
    set_can_change_style(1);
    set_pet_chats(7, ({
	"A fire imp leaps up on Floyd's shoulder and gnaws on his ear.",
	"A fire imp sets you on fire, then runs around screaming 'FIRE! "+
	"FIRE!'",
	"A fire imp gets angry, and pisses flames on you.",
	"A fire imp notices rain falling, and runs for cover under Floyd.",
	"A fire imp pulls out a large stoogy, and lights it with a snap of "+
	"his fingers.",
      }) );
    set_say_style("says");
}
