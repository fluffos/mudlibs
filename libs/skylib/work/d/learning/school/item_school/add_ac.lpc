/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("add_ac() adds an armour class for the"
      " armour.  It determines how much protection the"
      " armour actually gives against different damage"
      " types.  The function takes three arguments,"
      " the name of the ac, type of damage it protects"
      " against, and the amount, the bigger it is is,"
      " the better the protection.  The name of the"
      " ac can be anything but please use something"
      " meaningful.\nSyntax:\nadd_ac(\"name\",\"type\","
      "amount);\nExample:\nadd_ac(\"pierce\",\"pierce\","
      "55);\nThe amount can also be an array of one, two"
      " or three numbers.  If it is a number, the ac will"
      " be random(number), if it is a one element array,"
      " the ac will be exactly the value of that element,"
      " if it's an array of two numbers the ac is "
      " first number+random(second number), in case of "
      "three elements, first element+(second element amount"
      " rolls of a dice with sides as many as third element shows),"
      " for example 10 + 2D15.\nHelp add_ac for more details.\n");

    add_exit("back",ITEMSC+"arm_start","path");

} /* setup() */
