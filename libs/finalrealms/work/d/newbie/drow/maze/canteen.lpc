inherit "std/pub";
#include "pub.h"
#include "path.h"
 
int query_underground() { return 1; }
 
void setup() {
        add_menu_item("cave water", SOFTDRINK, 8, 4, 4, 4, "force yourself to choke down "
        "the thick mineral-soaked liquid", "chokes down a ladle of the gray liquid.");
 
        add_menu_item("rothes' milk", SOFTDRINK, 6, 3, 3, 3, "pretend to enjoy "
                      "the slightly sour milk", "smiles grimly and empties a glass "
                      "of lukewarm rothe's milk." );
 
add_menu_item("moonshine", ALCOHOL, 10, 5, 5, 5, " "
                      "sip your elixer slowly, ignoring the burning "
                      "sensation it causes in your stomach", "painfully drinks "
                      "a tin cup of Moonshine, and then mutters I'm fine, I'm fine, "
                      "I'm fine.");
 
        add_menu_item("homemade brew", ALCOHOL, 20, 10, 10, 10, "take large, healthy "
                      "gulps of the alcohol, ignoring the thickness of the liquid", "drinks  "
                      "a mug of the brew quickly, ignoring the many small particles that "
                      "float within it.");
 
        add_menu_item("bread crust", FOOD, 10, 1, 4, 0, "chew on a bread crust, covering yourself "
                      "with crumbs", "eats a bread crust and spreads crumbs everywhere.");
 
        add_menu_item("dried biscuit", FOOD, 20, 2, 8, 0, "nibble, edges first, on a rock-hard "
                      "biscuit", "eats a biscuit hard enough to qualify for a weapon.");
 
        add_menu_item("porridge", FOOD, 40, 10, 20, 0, "quickly eat up a generous serving "
                      "of lumpy porridge", "lifts a bowl of porridge to his mouths and inhales it.");
 
        add_menu_item("dried jerky", FOOD, 80, 20, 40, 0, "chew endlessly on "
                      "a strip of dried meat", "chews and chews and chews on a piece "
                      "of cured meat.");
 
        add_menu_alias("Cave water", "cave water");
        add_menu_alias("water", "cave water");
        add_menu_alias("Rothe's milk", "rothe's milk");
add_menu_alias("Rothes' milk","rothes' milk");
add_menu_alias("rothe's milk","rothes' milk");
add_menu_alias("rothes milk","rothes' milk");
        add_menu_alias("milk", "rothes' milk");
        add_menu_alias("Moonshine elixer", "moonshine elixer");
        add_menu_alias("elixer", "moonshine");
        add_menu_alias("Homemade brew", "homemade brew");
        add_menu_alias("brew", "homemade brew");
        add_menu_alias("Bread crust", "bread crust");
        add_menu_alias("crust", "bread crust");
        add_menu_alias("Dried biscuit", "dried biscuit");
        add_menu_alias("biscuit", "dried biscuit");
        add_menu_alias("Porridge", "porridge");
        add_menu_alias("Dried jerky", "dried jerky");
        add_menu_alias("jerky", "dried jerky");
 
set_short("Realm of the Drow:  Observation Canteen");
set_long("\n   Realm of the Drow:  Observation Canteen.\n\n"
         "     A dark stove with several large pots hisses and bubbles "
                  "angrily at you, as you enter a room where you probably do "
                 "not belong.  You are not noticed, luckily, by the dour-faced "
                 "guards, spooning out gruel to be left around the maze for the "
                 "captives -- not so that they won't die, but so their pain and "
                "torture may continue.  The nobles, wearing their piwafis "
                 "and neck pouches, disinterestedly ignore you.  "
                 "You start at their presence here, for they "
                 "certainly are not expected to prove themselves like you are,  "
                 "and you puzzle even more over their apparent interest at staring "
                 "at the drab, gray coated walls.   A hand-scrawled list "
                 "of the limited food options flutters atop the "
                 "stove, for the guards have no difficulties in skimming the "
                 "food for the captives to give to visitors such as yourself -- as long "
                 "as the right amount of money is involved."
                 "\n\n");
   add_item("stove","A black-looking stove, it looks to be where the "
      "food is cooked.\n");
   add_item("pots","Large iron pots, they sit on the stove sizzling and bubbling. "
      "It is difficult to see from here what they contain.\n");
   add_item("walls","Grey and drab, they are totally uninteresting.\n");
        set_light(30);
        set_zone("pub");
 
   add_exit("east", MAZE+"maze05", "corridor");
   add_exit("northeast", MAZE+"maze04", "corridor");
}
