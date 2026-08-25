/*    /std/drink.c
 *    from Nightmare IV
 *    standard drink code
 *    created by Bohemund of NH 940403
 */

#include <std.h>
#include <config.h>
#include "drink.h"

inherit OBJECT;

private int __Strength;
private string __Type, __EmptyName;
private function __DrinkFunction;
private mapping __Messages;

void create() {
    __Type = "alcoholic";
    __EmptyName = "bottle";
    __DrinkFunction = 0;
    ::create();
    set_vendor_type("drink");
    set_drink("$N drink $O.", "$N drinks $O");
}

void init() {
    ::init();
    if(environment(this_object()) != this_player()) return;
    add_action("cmd_drink", "drink");
}

int cmd_drink(string str) {
    object ob;
    string tmp;

    if(present(lower_case(str), this_player()) != this_object()) return 0;
    if((object)this_player()->query_current_attacker())
      return notify_fail("You cannot drink while in combat!\n");
    switch(query_type()) {
        case "soft drink":
            if(!((int)this_player()->add_quenched(query_strength())))
              return notify_fail("You are too bloated to drink!\n");
            break;
        case "caffeine":
            if((int)this_player()->query_intox() < query_strength())
              return notify_fail("You do not feel the need for that right now.\n");
            if(!((int)this_player()->add_quenched(query_strength())))
              return notify_fail("You are too bloated to drink that!\n");
            this_player()->add_intox(-query_strength()/2);
            break;
        case "alcoholic":
            if(!((int)this_player()->add_intox(query_strength())))
              return notify_fail("You are already about to pass out!\n");
            break;
    }
    this_player()->heal(query_strength());
    if(!__DrinkFunction || !functionp(__DrinkFunction)) {
        tmp = replace_string(replace_string(__Messages["my"], "$N", "you"),
          "$O", query_short());
        message("my_action", capitalize(tmp), this_player());
        tmp = replace_string(replace_string(__Messages["other"], "$N",
          (string)this_player()->query_cap_name()), "$O", query_short());
        message("other_action", capitalize(tmp), environment(this_player()),
          ({ this_player() }));
    }
    else (*__DrinkFunction)();
    ob = new(OBJECT);
    tmp = query_empty_name();
    ob->set_name(sprintf("an empty %s", tmp));
    ob->set_id( ({ tmp, "container", "empty container" }) );
    ob->set_short(sprintf("an empty %s", tmp));
    ob->set_long(sprintf("An empty %s which used to hold something.", tmp));
    ob->set_value(10);
    ob->set_mass(100);
    ob->set_destroy();
    if((int)ob->move(this_player())) {
        message("my_action", sprintf("You drop an empty %s!", tmp),
          this_player());
        message("other_action", sprintf("%s drops an empty %s", 
          (string)this_player()->query_cap_name(), tmp), 
          environment(this_player()), ({ this_player() }));
        ob->move(environment(this_player()));
    }
    this_object()->remove();
    return 1;
}

varargs void set_drink(mixed val, string str) {
    if(!str && !functionp(val))
      error("Wrong number of arguments to set_drink().\n");
    else if(str) {
        if(!stringp(val)) error("Bad argument 1 to set_drink().\n");
        else if(!stringp(str)) error("Bad argument 2 to set_drink().\n");
        __Messages = ([ "my" : (string)val, "other" : str ]);
    }
    else __DrinkFunction = (function)val;
}

function query_drink_function() {
    return (__DrinkFunction ? copy(__DrinkFunction) : 0);
}

string query_my_msg() {
    return (__DrinkFunction ? 0 : __Messages["my"]);
}

string query_other_msg() {
    return (__DrinkFunction ? 0 : __Messages["other"]);
}

void set_strength(int x) { __Strength = x; }

int query_strength() { return __Strength; }

void set_type(string str) { __Type = str; }

string query_type() { return __Type; }

void set_empty_name(string str) { __EmptyName = str; }

string query_empty_name() { return __EmptyName; }

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
