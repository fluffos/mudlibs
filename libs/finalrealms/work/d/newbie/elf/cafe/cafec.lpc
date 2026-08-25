inherit "std/pub";
#include "pub.h"
#include "path.h"

object katuran, virien;


void setup() {
	add_menu_item("Tea", SOFTDRINK, 8, 4, 4, 4, "sip your tea", "sips "
		      "at a cup of tea");

	add_menu_item("Mineral water", SOFTDRINK, 6, 3, 3, 3, "drink your "
		      "iced mineral water", "drinks iced mineral water");

	add_menu_item("Wine spritzer", ALCOHOL, 10, 5, 5, 5, "casually "
		      "drink a wine spritzer", "casually drinks a wine spritzer");

	add_menu_item("Ale", ALCOHOL, 20, 10, 10, 10, "take a healthy pull "
		      "from your tankard of ale", "drinks a tankard of ale");

	add_menu_item("Scone", FOOD, 10, 1, 4, 0, " butter a scone and eat it",
		      " eats a buttered scone");

	add_menu_item("Tea cake", FOOD, 20, 2, 8, 0, " nibble a couple of "
		      "tea cakes", " eats some tea cakes");

	add_menu_item("Sandwich", FOOD, 40, 10, 20, 0, " consume a plate of "
		      "tasty finger sandwiches", " eats several finger sandwiches");

	add_menu_item("Lembas waffers", FOOD, 80, 20, 40, 0, " consume some "
		      "delicious Lembas Waffers", " eats some Lembas Waffers");

	add_menu_alias("tea", "Tea");
	add_menu_alias("mineral water", "Mineral water");
	add_menu_alias("water", "Mineral water");
	add_menu_alias("wine spritzer", "Wine spritzer");
	add_menu_alias("spritzer", "Wine spritzer");
	add_menu_alias("Spritzer", "Wine spritzer");
	add_menu_alias("Wine", "Wine spritzer");
	add_menu_alias("wine", "Wine spritzer");
	add_menu_alias("ale", "Ale");
	add_menu_alias("beer", "Ale");
	add_menu_alias("Beer", "Ale");
	add_menu_alias("scones", "Scone");
	add_menu_alias("Scones", "Scone");
	add_menu_alias("scone", "Scone");
	add_menu_alias("tea cakes", "Tea cake");
	add_menu_alias("teacakes", "Tea cake");
	add_menu_alias("Tea cakes", "Tea cake");
	add_menu_alias("Teacakes" , "Tea cake");
	add_menu_alias("tea cake" , "Tea cake");
	add_menu_alias("teacake", "Tea cake");
	add_menu_alias("sandwich", "Sandwich");
	add_menu_alias("Sandwiches", "Sandwich");
	add_menu_alias("sandwiches", "Sandwich");
	add_menu_alias("lembas", "Lembas waffers");
	add_menu_alias("waffers", "Lembas waffers");
	add_menu_alias("lembas waffers", "Lembas waffers");

   add_property("no_undead",1);
	set_short("Realm of the Elf:  Tree-top Cafe");
   set_long("\n   Realm of the Elf:  Tree-top Cafe.\n\n"
            "     Sunlight filters through the canopy of leaves above "
            "your "
		 "head, bathing the scene before you in dappled brightness.  "
		 "A charming open-air cafe is nestled among the branches.  "
		 "Tables are scattered here and there across the wide floor, "
		 "and a menu seems to grow naturally from the tree trunk.  "
              "You may sit at table1, table2, or table3."
              "\n\n");

	set_light(60);
	set_zone("pub");

	add_alias("tables", "table");
	add_alias("chairs", "chair");
	add_alias("thrushes", "thrush");

	add_item("floor", "The floor is made of thick interlocking branches.\n");

	add_item("table", "These are round oaken pedestal tables with chairs "
			  "scattered haphazardly around them.\n");

	add_item("chair", "This simple frame chair is made of oak, with a lightly "
		          "padded seat.\n");

	add_item( ({"seat", "cushion"}), "The seat is covered with leather, "
		    "dyed the dappled green of foliage.\n");

	add_item("table1", "This table occupies the sunniest part of the cafe. "
		           " The leaves around it glisten a luminous green.  "
			   "Patrons often sit here to watch the bustle of the "
			   "forest village, or merely to bask in the sunlight.\n");
	add_item("table2", "Sunlight through the canopy above forms a "
			   "light-and-shadow mosaic on this table.  A slight "
			   "breeze filters through the leaves, carrying the "
			   "cool loamy smell of the forest, and a family of "
			   "thrushes sing sweetly from a nearby branch.\n");

	add_item("thrush", "The birds cock their heads curiously at you and "
			   "continue their song.\n");

	add_item("table3", "Shadows enfold this table, giving it a very "
			   "private air.  It seems the very place for a "
			   "serious conversation or a romantic rendezvous.  "
			   "A small beeswax candle sheds a warm light on the "
			   "faces of those seated here.\n");

	add_item("candle", "Sweet herbs mixed into the beeswax give the candle "
		           "a light but tangy scent.\n");

	add_exit("down", CAFE + "cafeb", "standard");
  add_clone(CHAR+"katuran",1);
   add_clone(CHAR+"virien",1);
}

void init() {
	::init();
	add_action("sit", "sit");
}

int sit(string str) {
	if (str == "table1") {
		write("You sit at a sun-drenched table.\n");
		say(this_player()->query_cap_name()+ " sits at a sun-drenched "
						     "table.\n");
		return 1;
	}

	if (str == "table2") {
		write("You sit at a pleasantly shaded table.\n");
		say(this_player()->query_cap_name()+ " sits at a pleasantly "
						     "shaded table.\n");
		return 1;
	}

	if (str == "table3") {
		write("You sit at a more private table, standing in full "
	      "shadow.\n");
		say(this_player()->query_cap_name()+ " sits at a more private "
						     "table.\n");
		return 1;
	}

	if (!str) {
		write("You must first choose a table.\n");
		return 1;
	}
}

