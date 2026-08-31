#include <std.h>
#include <amun.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Summer");
    set_id( ({ "summer", "monster" }) );

    set_short("%^BOLD%^%^CYAN%^S%^WHITE%^u%^CYAN%^m%^WHITE%^m%^CYAN%^e%^WHITE%^r%^RESET%^");
    set("aggressive", 0);
    set_long("%^BOLD%^%^CYAN%^S%^WHITE%^u%^CYAN%^m%^WHITE%^m%^CYAN%^e%^WHITE%^r floats slightly in mid-air as her bright %^YELLOW%^hair %^WHITE%^flows in the cool breeze that is flowing through the open door. Her %^RED%^f%^RESET%^%^RED%^i%^BOLD%^%^RED%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^y %^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^BOLD%^%^RED%^e%^RESET%^%^RED%^y%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^BOLD%^%^WHITE%^glow softly as the light peeks through the windows. Her wings wrap around her, covering her clothless body, and she greets all customers with a smile.%^RESET%^");
    set_gender("female");
    set_race("archangel");
    set_body_type("archangel");
  set_class("clergy");
  set_subclass("cleric");
    set_level(500);
    set_stats("charisma" , 200);
  set_hp(query_max_hp());
  set_sp(query_max_sp());
    set_alignment(1500);
    add_money("gold", random(60));
    set_currency("gold");
    set_menu_header("The following items are always on special at the Vineyard:");
    set_menu_footer("<buy drink_name> gets you a drink.");
    set_menu( ([
	"white wine" : ([
	  "type" : "alcoholic",
	  "price" : 75, 
	  "strength" : 100,
	  "my_mess" : "You smile happily as the white wine soothes your entire body.",
	  "your_mess" : "smiles happily as the white wine soothes $P entire body.",
	  "short" : "A Special Vintage 1062 White Wine Amporia",
	  "long" : "A Special Vintage 1062 White Wine Amporia from the Vineyard.",
	]),
	"red wine" : ([
	  "type" : "alcoholic",
	  "price" : 100, 
	  "strength" : 150,
	  "short" : "A Special Vintage 1062 Red Wine Amporia",
	  "long" : "A Special Vintage 1062 Red Wine Amporia from the Vineyard.",
	  "my_mess" : "The red wine soothes your entire body, making your fingertips tingle.",
	  "your_mess" : "fingertips tingle as the red wine soothes $P entire body.",
	]),
      ]) );
}
