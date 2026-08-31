#include <std.h>
#include <amun.h>
#include <daemons.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Spring");
    set_id( ({ "spring", "monster" }) );
    set_short("%^BOLD%^%^WHITE%^S%^MAGENTA%^p%^WHITE%^ring%^RESET%^");
    set("aggressive", 0);
    set_level(500);
    set_long("%^BOLD%^%^WHITE%^S%^MAGENTA%^p%^WHITE%^ring is a short Angel of about 5'0 feet, but has long gorgeous wings that spread out far whenever she flies up to the top of a shelf to get a delicious dessert for a customer. She has long soft %^YELLOW%^golden hair%^WHITE%^ that covers her bare back. %^BOLD%^%^WHITE%^S%^MAGENTA%^p%^WHITE%^ring flys back behind the counter and you notice that she is wearing a short top that leaves little to the imagination, and a long %^MAGENTA%^pink %^WHITE%^skirt that flows down to her bare feet. She looks up at you, entrapping you with her %^RESET%^%^MAGENTA%^deep purple eyes%^BOLD%^%^WHITE%^. She is one of the most beautiful Angels anyone has ever seen.%^RESET%^");
    set_gender("female");
    set("race", "archangel");
    set_body_type("archangel");
    set_alignment(1500);
    set_stats("charisma", 200);
    set_hp(query_max_hp());
    set_sp(query_max_sp());
    set_mp(query_max_mp());
    add_money("gold", random(60));
    set_currency("gold");
    set_menu_header("The following items are always on special:");
    set_menu_footer("<buy food_name> gets you food.");
    set_menu( ([
	"angel cake" : ([
	  "type" : "food",
	  "price" : 45, 
	  "strength" : 45, 
	  "short" : "An Angel Cake",
	  "long" : "An Angel Cake from the Sky Bakery.",
	  "my_mess" : "You eat the angel cake and your body tingles with goodness.",
	  "your_mess" : "eats the angel cake and $P body tingles with goodness."
	]),
	"ice cream sandwich" : ([
	  "type" : "food",
	  "price" : 45, 
	  "strength" : 45,
	  "my_mess" : "Your head begins to hurt from an ice cream headache.",
	  "your_mess" : "head begins to hurt from an icecream headache.",
	  "short" : "An Ice Cream Sandwich",
	  "long" : "An Ice Cream Sandwich from the Sky Bakery.",
	]),
	"pygmy puff" : ([
	  "type" : "food",
	  "price" : 55, 
	  "strength" : 55,
	  "short" : "A Pygmy Puff",
	  "long" : "A Pygmy Puff from the Sky Bakery.",
	  "my_mess" : "The puff makes a soft explosion in your mouth, filling it with a vanilla cream.",
	  "your_mess" : "feels the puff make a soft explosion in $P mouth, filling it with a vanilla cream.",
	])
      ]) );
}
