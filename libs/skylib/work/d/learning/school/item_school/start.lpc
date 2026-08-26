/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("Welcome to the item school. Take"
      " the appropriate exit depending on what you"
      " want to learn. The basic exit here gives information"
      " on all of the functions that are the same in all of"
      " these items, information on specific functions to each"
      " item is found in it's own room.\n");

    add_exit("back", SCHOOL "school","path");
    add_exit("basic",ITEMSC "basic_start","path");
    add_exit("weapon",ITEMSC "wep_start","path");
    add_exit("armour",ITEMSC "arm_start","path");
    add_exit("clothing",ITEMSC "clo_start","path");

} /* setup() */
