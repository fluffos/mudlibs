/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("add_attack is perhaps the most important"
      " function of weapons.  It gives the weapon an attack"
      " and determines how much damage the attack does and"
      " what skill to use with that attack.\n\nThe syntax is:\n"
      "add_attack(\"name\",chance,({ base, num"
      ", size }),\"type\",\"skill\",func);\n\n"
      "For example:\nadd_attack(\"slash\",90,({"
      " 5, 3, 10 }),\"sharp\",\"sharp\");\n\n"
      "Let's break this up into steps:\n1. The attack name"
      " - Can be anything, but please make it a sensible"
      " name and suggest what type of damage the weapon does.\n"
      "2. The attack chance - The chance that"
      " the attack will happen\n3. The damage"
      " - It consists of three number that make the damage roll."
      "  In this case it would roll a 10 sided dice 3 times and add the result"
      " to the base damage of 5, ie. 5+3d10\n4. The damage type"
      " - This determines what type of damage does the attack do."
      "  A sharp sword is unlikely to cause blunt damage for example.\n"
      "5.The skill used - This determines what skill"
      " to use for this attack\n6.The function"
      " - You could set a function that would be called when"
      " the attack is used.  It can be a string in which"
      " case the function would be in this weapon or an array of two strings,"
      " the other being the object on which to call the function and the other"
      " the function name to call on that object.\n\n"
      "Help add_attack contains additional information on this function.\n");


    add_exit("back",ITEMSC+"wep_start","path");

} /* setup() */
