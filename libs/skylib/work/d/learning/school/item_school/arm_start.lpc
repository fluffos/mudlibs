/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("Welcome to the armour section, you "
      "have now received an armour in your inventory."
      " Type 'more byrnie' to see the code, after that"
      " if you have any doubts on what each of those"
      " functions do, take the appropriate exit here.\n"
      "Note that even if you _think_ you know what the"
      " function does, you might not know exactly how"
      " it works and when should it be used.\n");

    add_exit("back",ITEMSC "start","path");
    add_exit("add_ac",ITEMSC "add_ac","path");


} /* setup() */

void event_enter(object ob, string mess, object from){
    object *bings;
    object bing;
    int ping = 0;
    bings = deep_inventory(ob);
    foreach(bing in bings){
        if(file_name(bing)[25..30] == "ex_arm"){
            ping = 1;
        }
    }
    if(!ping){
        clone_object("/d/learning/school/items/ex_arm")->move(ob);
    }
} /* event_enter() */
