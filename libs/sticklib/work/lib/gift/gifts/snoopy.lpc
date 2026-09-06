// Second pet --  12-30-97   Kieve
// Modified to become Dolphie's pet
//    01-14-97   Kieve
// Cost:
//   100 000  -- initial gift cost
//   100 000  -- 5 random emotes
//   150 000  -- speaking ability 'say'
//    20 000  -- ability to change 'says' at any time
//  ~~~~~~~~
//   370 000  Total Cost
//         0  Paid by Dolphie

#include <pet.h>

void create_pet() {
    set_name("snoopy dog");
    set_id( ({ "dog", "snoopy", "snoopy dog", "beagle" }) );
    set_short("Snoopy, the beagle");
    set_long("Snoopy is a cute little beagle dog. She's about 1 foot long "+
      "and has the look in her eyes of a sock eater. The sock in her mouth "+
      "is just begging for you to pull on, and play tug of war with her.");
    set_weight(1);
    set_value(0);
    set_pick_up_msg("Snoopy growls loudly!");
    set_speaking_pet(1);
    //    set_emoting_pet(1);
    set_can_change_style(1);
    set_pet_chats(7, ({
	"Snoopy chews on her sock.",
	"Snoopy looks up at you with her doggie eyes.",
	"Snoopy growls and tries to be ferocious.",
	"Snoopy wants you to play tug of war with her!",
	"Snoopy rolls on her back, and wants you to rub her belly.",
      }) );
    set_say_style("pants");
}
