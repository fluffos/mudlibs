#include <std.h>
#include <guild.h>
#include <boat.h>
inherit BARKEEP;
void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Dru");
    set_id( ({ "dru", "monster", "dr" }) );
    set_short("Dru");
    set_long("What appears to be an innocent young girl behind the counter is really not. Dru stands not high from the ground, but packs a mean bite. With long red hair and bright blue eyes, she looks at customers as she checks on her orders.");
    set_gender("female");
    set_alignment(-164);
    set_race( "vampire");
    set_body_type("vampire");
    set_currency("gold");
    set_menu_header("The following items are always on special:");
    set_menu_footer("<buy food_name> gets you food.");
    set_menu( ([
	"cornbread" : ([
	  "type" : "food",
	  "price" : 45, 
	  "strength" : 20, 
	  "short" : "Cornbread",
	  "long" : "The cornbread is bronzed lightly and smells delicious.",
	  "my_mess" : "Sweet and yummy cornbread!",
	  "your_mess" : "eats the cornbread and sighs happily."
	]),
	"pickled beak" : ([
	  "type" : "food",
	  "price" : 45, 
	  "strength" : 20,
	  "my_mess" : "The pickled beak stabs your throat as you choke it down.",
	  "your_mess" : "chokes as the pickled beak stabs their neck!",
	  "short" : "Pickled Beak",
	  "long" : "This looks disgusting.",
	]),
	"angelcake" : ([
	  "type" : "food",
	  "price" : 55, 
	  "strength" : 25,
	  "short" : "Angelcake",
	  "long" : "A glorious smell is coming from the angelcake, and it looks fluffy.",
	  "my_mess" : "The angelcake melts in your mouth and slides easily down to your stomach making you warm inside.",
	  "your_mess" : "moans happily at the taste of heaven.",
	]),
	"pygmy cupcake" : ([
	  "type" : "food",
	  "price" : 55, 
	  "strength" : 25,
	  "short" : "A Pygmy Cupcake",
	  "long" : "Is that a pygmy ear?",
	  "my_mess" : "Mmmmm...cupcake made from pygmies.",
	  "your_mess" : "feels the cupacke make a soft explosion in $P mouth, filling it with a vanilla cream.",
	]),
	"ribeye steak" : ([
	  "type" : "food",
	  "price" : 55, 
	  "strength" : 35,
	  "short" : "Ribeye Steak",
	  "long" : "Grilled to perfection, the steak is a prime meal!",
	  "my_mess" : "Grilled perfectly, the steak fills you up.",
	  "your_mess" : "stuffs the steak in their mouth barely tasting it.",
	])
      ]) );
}
