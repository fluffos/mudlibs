/*    /std/food.c
 *    from Nightmare IV
 *    a standard food item
 *    created by Bohemund@Nightmare 940403
 */

#include <std.h>
#include <config.h>
#include "food.h"

inherit OBJECT;

private int __Strength;
private function __EatFunction;
private mapping __Messages;

void create() {
    __EatFunction = 0;
    ::create();
    set_eat("You eat $O.", "$N eats $O.");
    set_vendor_type("food");
    set_prevent_put("You cannot store food in there!");
}

void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("cmd_eat", "eat");
}

int cmd_eat(string str) {
    string tmp;

    if(present(str = lower_case(str), this_player()) != this_object())
      return notify_fail("Eat what?\n");
    if((object)this_player()->query_current_attacker()) 
      return notify_fail("You cannot eat while fighting!\n");
    if(__EatFunction) {
        if(!((int)this_player()->add_stuffed(query_strength())))
          return notify_fail("You are way too full for that!\n");
        (*__EatFunction)();
    }
    else {
        if(!((int)this_player()->add_stuffed(query_strength())))
          return notify_fail("You are way too full for that!\n");
        tmp = replace_string(__Messages["my"], "$N", "You");
        tmp = replace_string(tmp, "$O", query_short());
        message("my_action", tmp, this_player());
        tmp = replace_string(__Messages["other"], "$N",
          (string)this_player()->query_cap_name());
        tmp = replace_string(tmp, "$O", query_short());
        message("other_action", tmp, environment(this_player()),
          ({ this_player() }));
    }
    this_player()->heal(query_strength());
    this_object()->remove();
    return 1;
}

varargs void set_eat(mixed val, string str) {
    if(!str && !functionp(val))
      error("Wrong number of arguments to set_eat().\n");
    else if(str) {
        if(!stringp(val)) error("Bad argument 1 to set_eat().\n");
        else if(!stringp(str)) error("Bad argument 2 to set_eat().\n");
    }
    if(functionp(val)) __EatFunction = copy(val);
    else __Messages = ([ "my" : val, "other" : str ]);
}

function query_eat_function() {
    return (__EatFunction ? copy(__EatFunction) : 0);
}

string query_my_msg() { return (__EatFunction ? 0 : __Messages["my"]); }

string query_other_msg() { return (__EatFunction ? 0 : __Messages["other"]); }

void set_strength(int x) { __Strength = x; }

int query_strength() { return __Strength; }

int query_food() { return 1; }

#ifdef __OLD_FOOD__

void set_my_mess(string str) {
    if(!__Messages) __Messages = allocate_mapping(2);
    __Messages["my"] = str;
}

void set_your_mess(string str) {
    if(!__Messages) __Messages = allocate_mapping(2);
    __Messages["other"] = "$N "+str;
}

#endif /* __OLD_FOOD__ */
