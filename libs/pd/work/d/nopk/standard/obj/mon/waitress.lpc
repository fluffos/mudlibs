inherit "/std/barkeep";

create() {
 ::create();
   set_name("waitress");
   set_id( ({ "waitress", "friendly waitress" }) );
   set_short("a friendly waitress");
   set("aggressive", 0);
   set_level(12);
   set_long("The young girl was hired by the Weeping Willow to serve the "
     "customers. She happily does her job, and waits to help you.");
   set_gender("female");
   set_alignment(164);
   set("race", "nymph");
   set_hp(270);
   add_money("copper", random(200));
   set_skill("melee", 90);
   set_body_type("human");
   set_currency("gold");
   set_menu(
	({
	  "vennison", "stew", "duck", "fries", "quail"
	}),
	({ "food", "food", "food", "food", "food" }),
	({ 25, 15, 20, 3, 10 })
    );
    set_my_mess(
	({
	"Grilled to perfection, though it tastes oddly like deer..\n",
	"You devour the stew quickly, how wonderful!\n",
	"A bit salty, but delicious nonetheless.\n",
	"You eat the fries one by one, enjoying the taste.\n",
	"You savor every bite of the roasted quail.\n"
	})
    );
    set_your_mess(
	({
	"eats some vennison and ponders the taste.\n",
	"quickly devours the rabbit stew.\n",
	"enjoys some BBQ duck.\n",
	"eats some fries one by one.\n",
	"happily savors every bite of roasted quail.\n"
    	})
    );
    set_menu_short(
	({
	"grilled vennison",
	"bowl of rabbit stew",
	"BBQ duck",
	"fries",
	"roasted quail"
	})
    );
    set_menu_long(
	({
	"The vennison was grilled in the Weeping Willow Restaurant, it looks "
	"great!\n",
	"Rabbit stew in a thick broth with some spices.\n",
	"The duck was barbequed to perfection. It looks a lot like chicken..\n",
	"Not all too many, but enough for a good snack.\n",
	"Roasted on the Weeping Willow grills, quail makes a good meal."
   	})
    );
}
