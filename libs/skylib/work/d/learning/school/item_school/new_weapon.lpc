/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("new_weapon(),setup_clothing() and setup_armour()"
      " are for the exact same purpose, giving the item "
      "\"hitpoints\", it sets the amount of damage the "
      "item can take before it breaks down. Syntaxes:\n"
      "new_weapon(amount);\nsetup_armour(amount);\n"
      "setup_clothing(amount);\nJust replace 'amount' "
      "with the value you decide to be the best for the"
      " item at hand.  Remember, if you have a high"
      " set_damage_chance set and these are low, the"
      " item will break fast.\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
