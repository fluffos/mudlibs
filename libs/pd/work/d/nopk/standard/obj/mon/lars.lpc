#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("lars");
    set_id( ({ "lars", "barkeep" }) );
    set_short("Lars, the proprietor");
   set("aggressive", 0);
  set_level(12);
    set_long("He tends bar and he listens to the stories of soldiers, citizens, and any "
      "others that venture into his bar. Lars would be an excellent source of information "
      "and gossip if he would chat with anyone for once.");
   set_gender("male");
   set_alignment(122);
   set("race", "human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
	({
 	 "firebreather", "special", "ale", "quickening"
	}),
	({ "alcoholic", "alcoholic", "alcoholic",  "alcoholic" }),
	({ 23, 15, 3, 30 })
    );
    set_my_mess(
	({
	"The firebreather burns your throat!",
	"Wow! Lars sure knew how to make drinks when he invented that!",
	"You down some ale.",
        "The shot of quickening burns like no other drink!"
	})
    );
    set_your_mess(
	({
	"winces from the burning of a drink of a firebreather.",
	"drinks a special of the house.",
	"drinks some ale.",
        "screams at the horrible burning of the drinking of quickening."
    	})
    );
    set_menu_short(
	({
	"A firebreather",
	"A special of the house",
	"A pale ale",
        "A %^BOLD%^%^WHITE%^sho%^CYAN%^t of%^BLUE%^ Qu%^BOLD%^%^BLUE%^i%^CYAN%^cke%^WHITE%^ning%^RESET%^",
	})
    );
    set_menu_long(
	({
	"A firebreather from the Lars Pub.",
	"A classic special of the house from the Lars Pub.",
	"A pale ale brewed in the farming fields outside Tirun.",
        "A shot of a pale blue alcoholic beverage called quickening. Quickening burns "
        "like nothing else you'll ever feel. A strong mixture, the pride of the Lars' pub."
   	})
    );
}
