#include <std.h>
#include <amun.h>
#include <daemons.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Kelesia");
    set_id( ({ "kelesia", "monster" }) );
    set_short("%^BOLD%^%^WHITE%^K%^BLUE%^e%^WHITE%^les%^BLUE%^i%^WHITE%^a%^RESET%^");
    set_level(500);
    set_long("%^BOLD%^%^WHITE%^K%^BLUE%^e%^WHITE%^les%^BLUE%^i%^WHITE%^a stands tall behind a small stand that has drinks spread on it. Her long %^BLACK%^dark hair %^WHITE%^blows with the cool breeze, and her long %^GREEN%^green dress %^WHITE%^moves like the waves of the ocean. She is very gorgeous with her %^RESET%^%^MAGENTA%^violet eyes%^BOLD%^%^WHITE%^.%^RESET%^");
    set_gender("female");
    set_race("archangel");
    set_stats("charisma" , 200);
    set_body_type("archangel");
    set_hp(query_max_hp());
    set_sp(query_max_sp());
    set_mp(query_max_mp());
    set_alignment(1500);
    set_currency("gold");
    set_menu_header("The following drinks are on special:");
    set_menu_footer("<buy drink_name> gets you a drink.");
    set_menu( ([
	"water" : ([
	  "type" : "soft drink",
	  "price" : 80, 
	  "strength" : 80, 
	  "short" : "A Water",
	  "long" : "A Water from the Cathedral Drink Shop.",
	  "my_mess" : "%^BOLD%^%^CYAN%^The water cools your stomach as it refreshes you.%^RESET%^",
	  "your_mess" : "%^BOLD%^%^CYAN%^drinks the water and $P are refreshed.%^RESET%^"
	]),
	"red slushie" : ([
	  "type" : "soft drink",
	  "price" : 55, 
	  "strength" : 55,
	  "my_mess" : "%^BOLD%^%^RED%^The slushie slides down your throat and you get a slight headache.%^RESET%^",
	  "your_mess" : "%^BOLD%^%^RED%^feels their head slightly hurt as the slushie slides down $P throat.%^RESET%^",
	  "short" : "A %^BOLD%^%^RED%^Red Slushie%^RESET%^",
	  "long" : "A Red Slushie from the Cathedral Drink Shop.",
	]),
	"lemon slushie" : ([
	  "type" : "soft drink",
	  "price" : 55, 
	  "strength" : 55,
	  "short" : "A %^BOLD%^%^YELLOW%^Lemon Slushie%^RESET%^",
	  "long" : "A Lemon Slushie from the Cathedral Drink Shop.",
	  "my_mess" : "%^BOLD%^%^YELLOW%^The slushie tastes so yummy!%^RESET%^",
	  "your_mess" : "%^BOLD%^%^YELLOW%^yells YUMMY!%^RESET%^",
	]),
      ]) );
}
